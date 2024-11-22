#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Player {
    private:
        //float _Speed;
        sf::Vector2f _Position;
        sf::Texture _pTexture;
        sf::Sprite _Sprite;
    public:
        Player();
        Player(sf::Texture&);
        sf::Sprite getSprite() const;
        void moveTo(int x, int y);
        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown(); 
        void heal(int x);
        int _Health;
};
#endif