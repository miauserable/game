#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include "util.h"
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
    //file.close();
    return;
}

/*int readL(int l)
{
    FILE* file;
    fstream file("options.txt");
    while (fgets(line, sizeof line, file) != NULL) /* read a line
    {
        if (count == lineNumber)
        {
            //use line or in a function return it
            //in case of a return first close the file with "fclose(file);"
        }
        else
        {
            count++;
        }
    }
}*/