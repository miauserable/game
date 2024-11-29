#include "util.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace sf;
Font font;
float XSET;
float YSET;
bool _SET;
std::unordered_map<std::string, FloatRect> textBoundsMap;

void _INIT(sf::RenderWindow& w){
    if (!font.loadFromFile("font.ttf")) {
        std::cerr << "Error loading font" << std::endl;
    }
    XSET = 320 * 0.02;
    YSET = 240;
}
void _RENDERMENU(sf::RenderWindow& w){
    Text g("game", font, 36);
    Text p("play", font, 24);
    Text q("quit", font, 24);

    g.setPosition(XSET / 0.02, YSET / 2);
    p.setPosition(XSET, YSET - 40);
    q.setPosition(XSET, YSET + 40);

    w.draw(g);
    w.draw(p);
    w.draw(q);

    textBoundsMap["game"] = g.getGlobalBounds();
    textBoundsMap["play"] = p.getGlobalBounds();
    textBoundsMap["quit"] = q.getGlobalBounds();
}

void _RENDERGAME(sf::RenderWindow& w) {
}

bool checkCollision(sf::RenderWindow& w, const std::string& s) {
    Vector2i _MOUSEPOS = Mouse::getPosition(w);

    // Check if the text object exists in the map
    if (textBoundsMap.find(s) != textBoundsMap.end()) {
        // Check if the mouse is in the text box
        if (textBoundsMap[s].contains(static_cast<sf::Vector2f>(_MOUSEPOS))) {
            return true;
        }
    }
    return false;
}
