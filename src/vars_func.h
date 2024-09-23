#pragma once

#include "SFML/Graphics.hpp"
#include <math.h>
#include <vector>
#include <iostream>

const int resulution[] = { 1000, 1000 };

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

