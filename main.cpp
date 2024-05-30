#include "SFML/Graphics.hpp"
#include <math.h>
#include <vector>

const int resulution[] = { 1000, 1000 };
sf::RenderWindow win(sf::VideoMode(resulution[0], resulution[1]), "gravity");
class obj {
public:
	float m;
	float r = 0;
	float x;
	float y;
	std::vector<float> vec = {0,0};
	sf::CircleShape object;
	void set(float m, float r, float x =0, float y =0, float vecx =0,float vecy =0) {
		this->m = m;
		this->r = r;
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
		float r = sqrt(powf(x,2) + powf(y,2));
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
		if (k == 0)
			object.setFillColor(sf::Color::Blue);
		else if (k == 1)
			object.setFillColor(sf::Color::Yellow);
		else if (k == 2)
			object.setFillColor(sf::Color::Green);
		else if (k == 3)
			object.setFillColor(sf::Color::White);
		else if (k == 4)
			object.setFillColor(sf::Color::Magenta);
		else if (k == 5)
			object.setFillColor(sf::Color::Red);
	}
};

int main() {
	const int countPlanet = 3;
	//float time = clock();
	srand(0);
	obj planet[countPlanet];
	planet[0].set(1.6, 7,-500, -400, 12);
	planet[1].set(500, 11);
	planet[2].set(1.6, 7, 500, 400, -12);

	for (int i = 0; i < countPlanet; i++) {
		planet[i].col(rand()%6);
	}
	while (win.isOpen()){
		sf::Event event;
		while (win.pollEvent(event)) {
			if (event.type == sf::Event::Closed) { 
				win.close();
			}
		}
		win.clear();
		for (int i = 0; i < countPlanet; i++) 
			for (int j = 0; j < countPlanet; j++)
				if(i != j)
					planet[i].setvec(planet[j].x - planet[i].x, planet[j].y - planet[i].y, planet[j].m);
		for(int i = 0; i < countPlanet; i++)
			planet[i].mov(0.002, 0.002);
		for(int i = 0; i < countPlanet; i++)
			planet[i].draw();
		win.display();
	}
}
