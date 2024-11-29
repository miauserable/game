#pragma once

#ifndef UTIL_H
#define UTIL_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

void _INIT(sf::RenderWindow& w);
void _RENDERMENU(sf::RenderWindow& w);
void _RENDERGAME(sf::RenderWindow& w);
bool checkTCollision(sf::RenderWindow& w, const std::string& s);
void MovePlayer(sf::RenderWindow& w, const std::string& s);
#endif
