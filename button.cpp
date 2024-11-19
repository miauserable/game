#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include "button.h"
using namespace sf;
using namespace std;
bool checkButtonCollision(Text t, RenderWindow& w) 
{
    Vector2i mousePos = Mouse::getPosition(w);
    FloatRect boxBounds = t.getGlobalBounds();

    if (boxBounds.contains(static_cast<sf::Vector2f>(mousePos))) { return true; }
    else {return false;}
};

bool optionsCheck()
{
    FILE* file;

    file = fopen("options.txt", "r");
    if (file!=NULL) { return true; }
    else { return false; }
}

void makeOptions()
{
    FILE* file;
    file = fopen("options.txt", "w");
    return;
}