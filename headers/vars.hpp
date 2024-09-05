#pragma once

#include "SFML/Graphics.hpp"
#include <math.h>
#include <vector>
#include <iostream>

const int resulution[] = { 1000, 1000 };
sf::RenderWindow win(sf::VideoMode(resulution[0], resulution[1]), "gravity");
bool stop = false;
double  Earhtmass= 6 * 1000 * 1000;
double sunmass = 333030 * Earhtmass;
double blackhole = sunmass * 4;
double moon = Earhtmass * 0.12;
double au = 150000000;
double pixel = au/400;
double c = 300000;






class obj {
public:
	float m;
	float r = 0;
	float x;
	float y;
	double Rg;
	bool isBlackHole = 0;
	std::vector<float> vec = {0,0};
	sf::CircleShape object;
	void set(float m, float r, float x =0, float y =0, float vecx =0,float vecy =0) {
		this->m = m;
		this->r = r;
		if(m >= sunmass*3.04){
			isBlackHole = true;
			Rg = 2 * m  / powf(c, 2);
			Rg = Rg/10;
			r = Rg;
		}
		
		this->x = resulution[0] / 2 + x;
		this->y = resulution[1] / 2 + y;
		this->vec[0] = vecx;
		this->vec[1] = vecy;
		sf::CircleShape object(r);
		object.setPosition(sf::Vector2f(this->x - r/2, this->y - r/2));
		object.setFillColor(sf::Color::Cyan);
		this->object = object;	
		this->x += r / 2;
		this->y += r / 2;
	}
	void mov(float x, float y) {
		object.move(x * vec[0], y * vec[1]);
		this->x += x * vec[0];
		this->y += y * vec[1];
	}
	void draw() {
		win.draw(object);
	}
	void setvec(double x, double y, double m2) {
		float r = sqrt(powf(x*pixel,2) + powf(y*pixel,2));
		if (x > 0)
			vec[0] += (m * m2 / powf(r, 2)) / m;
		else if(x != 0 )
			vec[0] -= (m * m2 / powf(r, 2)) / m;
		if (y > 0 ) 
			vec[1] += (m * m2 / powf(r, 2)) / m;
		else if(y != 0)
			vec[1] -= (m * m2 / powf(r, 2)) / m;
	}
	void col(int k) {
		if(isBlackHole){
			object.setFillColor(sf::Color::Black);
			object.setOutlineThickness(4);
			object.setOutlineColor(sf::Color(0xff, 0xa5, 0x00));
		}
		else{
			 switch(k){
				case 0: 
					object.setFillColor(sf::Color::Blue);
					break;
				case 1:
					object.setFillColor(sf::Color::Yellow);
					break;
				case 2:
					object.setFillColor(sf::Color::Green);
					break;
				case 3:
					object.setFillColor(sf::Color::White);
					break;
				case 4:
					object.setFillColor(sf::Color::Magenta);
					break;
				case 5:
					object.setFillColor(sf::Color::Red);
					break;
				case 7:
					object.setFillColor(sf::Color::Transparent);
					break;
				default:
					break;			
			}
		}
	}
	void boom(obj& planet1, obj& planet2){ // kostil 
	
		if(planet1.x + planet1.r/2 < planet2.x + planet2.r/2 && planet1.x - planet1.r/2 > planet2.x - planet2.r/2){
			if(planet1.y  + planet1.r/2 < planet2.y + planet2.r/2&& planet1.y  - planet1.r/2 > planet2.y - planet2.r/2){
				if(planet1.r > planet2.r){
					if(planet1.m > planet2.m){
						planet2.col(7);					
						planet2.r = 0;
						planet1.m += planet2.m;
						planet2.m = 0;
					}
				}
				else if(planet1.r , planet2.r){
					if (planet1.m < planet2.m){
						planet1.col(7);					
						planet1.r = 0;
						
					}
				}
			}
		}
	}

};


