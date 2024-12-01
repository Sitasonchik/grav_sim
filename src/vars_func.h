#pragma once

#include "SFML/Graphics.hpp"
#include <math.h>
#include <vector>
#include <iostream>

const int resulution[] = { 1800, 900 };

sf::RenderWindow win(sf::VideoMode(resulution[0], resulution[1]), "gravity");

double  Earhtmass= 6 * 1000 * 1000;
double sunmass = 333030 * Earhtmass;
double blackhole = sunmass * 4;
double moon = Earhtmass * 0.12;
double au = 150000000;
double pixel = au/400;
double c = 300000;


void check_win(){
    sf::Event event;
    while (win.pollEvent(event)) {
        if (event.type == sf::Event::Closed) { 
            win.close();
        }
    }

}

int randomcord(int a){
    return -resulution[a]/2 + (rand() % (resulution[a]));
}
int randomvec(){
    if(rand()%2 == 1)
        return -rand()%4;
    else
        return rand()%4;    
}
