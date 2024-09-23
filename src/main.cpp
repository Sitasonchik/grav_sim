#include "class.h"
#include <unistd.h>


int main() {

	srand(0);

	sf::Texture texture;
	texture.loadFromFile("../img/fon.png");
	sf::Sprite fon;
	fon.setTexture(texture);
	fon.setPosition(0, 0);
	const int countPlanet = 2;
	obj planet[countPlanet];
	planet[0].set(blackhole*2, 1, 100);
	planet[1].set(moon*1000, 3, -100,-200, 20);
	
	for(int i = 0; i < countPlanet; i++) {
		planet[i].col(rand()%6);
	}

	while (win.isOpen()){
		check_win();
		win.clear();

		for (int i = 0; i < countPlanet; i++){ 
			for (int j = 0; j < countPlanet; j++){
				if(i != j){
					planet[i].boom(planet[i], planet[j]);
					planet[i].setvec(planet[j].x - planet[i].x, planet[j].y - planet[i].y, planet[j].m);
				}
			}
		}
		win.draw(fon);
		for(int i = 0; i < countPlanet; i++)
			planet[i].mov(0.001, 0.001);
		for(int i = 0; i < countPlanet; i++){
			planet[i].draw();
		}
		win.display();
	}
}
