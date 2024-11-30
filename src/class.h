#pragma once
#include "vars_func.h"

class obj {
public:
	float m;
	float r = 0;
	float x;
	float y;
	double Rg;
	float x1;
	float x2;
	bool isboom = 0;
	bool isBlackHole = 0;
	std::vector<float> vec = {0,0};
	sf::CircleShape object;
	std::vector<sf::Color> colors = {sf::Color::Blue, sf::Color::Yellow, sf::Color::Green, 
									sf::Color::White, sf::Color::Magenta, sf::Color::Red, 
									sf::Color::Transparent};
	
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
		object.setPosition(sf::Vector2f(this->x - r, this->y - r));
		object.setFillColor(sf::Color::Cyan);
		this->object = object;
		
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
		if(!isboom){
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
	}

	void col(int k) {
		if(isBlackHole){
			r += 4;
			object.setFillColor(sf::Color::Black);
			object.setOutlineThickness(4);
			object.setOutlineColor(sf::Color(0xff, 0xa5, 0x00));
			
		}
		else{
			object.setFillColor(colors[k]);
		}
	}

	void boom(obj& planet1, obj& planet2){ // kostil +- kogda ne len buded ispravlu poka normalno rabotaet
		if(!isboom){
				if(planet1.x <= planet2.x + planet2.r   && planet1.x  >= planet2.x - planet2.r ){
					if(planet1.y <= planet2.y + planet2.r  && planet1.y >= planet2.y - planet2.r  ){
						if(planet1.isboom != 1 && planet2.isboom != 1){
							if (planet2.m > planet1.m){
								planet1.isboom = 1;
								planet1.col(7);
								planet2.m += planet1.m;
								planet1.m = 0.1;
						}
					}
				}
			}
		}
	}

};
