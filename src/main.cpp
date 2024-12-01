#include "class.h"


int main(void) {

	srand(clock());

	sf::Texture texture;
	texture.loadFromFile("../img/fon.png");
	sf::Sprite fon;
	fon.setTexture(texture);
	fon.setPosition(0, 0);
	const int countPlanet = rand() % 20 + 2;

	obj planet[countPlanet];

	for(int i = 1; i < countPlanet; i++){
		if(rand() % 2 == 0){
			planet[i].set(Earhtmass * (rand() % 20), rand()%7 + 6,randomcord(0), randomcord(1), randomvec(), randomvec());
		}
		else{
			planet[i].set(moon * (rand() % 20), rand()%4  + 4,randomcord(0), randomcord(1), randomvec(), randomvec());
		}
	}

	planet[0].set(sunmass, 40);
	// old ver \|/
	// planet[0].set(blackhole*2, 1, -300 + rand() % 1000, -100, -10, 0);
	// planet[1].set(sunmass / 10, 6, 400, 200, -4, 3);
	// planet[2].set(moon*1000, 3, -100,-200, 20);
	
	for(int i = 0; i < countPlanet; i++) {
		planet[i].col(rand()%6);
	}

	double t = clock();

	while (win.isOpen()){
			check_win();
		if((clock() - t)/CLOCKS_PER_SEC >= 1/5){
			t = clock();
		
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
				planet[i].mov(0.005, 0.005);

			for(int i = 0; i < countPlanet; i++)
				planet[i].draw();
				
			win.display();
		}
	}
}
