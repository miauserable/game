#pragma once

#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
bool checkButtonCollision(sf::Text t, sf::RenderWindow& w);
bool optionsCheck();
void makeOptions();

#endif