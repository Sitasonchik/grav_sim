#include "headers/vars.hpp"



int main() {
	srand(0);
	const int countPlanet = 4;
	sf::Texture texture;
	texture.loadFromFile("../img/fon.png");
	sf::Sprite fon;
	fon.setTexture(texture);
	fon.setPosition(0, 0);
	srand(0);
	obj planet[countPlanet];
	planet[0].set(Earhtmass, 4, -400, 0, 5, 10);
	planet[1].set(blackhole, 15);
	planet[2].set(moon, 2, -410, 10, 0, 5);
	planet[3].set(Earhtmass/2, 3, 200, 0, 1, -10);
	
	for(int i = 0; i < countPlanet; i++) {
		planet[i].col(rand()%6);
	}
	while (win.isOpen()){
		sf::Event event;
		if(stop == true)
			win.close();
		while (win.pollEvent(event)) {
			if (event.type == sf::Event::Closed or stop == true) { 
				win.close();
			}
		}
		win.clear();
		for (int i = 0; i < countPlanet; i++){ 
			for (int j = 0; j < countPlanet; j++){
				if(i != j){
					planet[i].setvec(planet[j].x - planet[i].x, planet[j].y - planet[i].y, planet[j].m);
					planet[i].boom(planet[i], planet[j]);
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
