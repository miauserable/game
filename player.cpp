#include "player.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;
int _Health = 100;
Sprite _Sprite;
Player::Player() {}

Player::Player(Texture& TTEXTURE) {
    _Sprite.setTexture(TTEXTURE);
    _Sprite.setPosition(0,0);
    _Sprite.setScale(1.5f, 1.5f);
}

Sprite Player::getSprite() const
{
    return _Sprite;
}

void moveLeft() {
    _Sprite.move(-5, 0);
}
void moveRight() {
    _Sprite.move(5, 0);
}
void moveUp() {
    _Sprite.move(0, 5);
}
void moveDown() {
    _Sprite.move(0, -5);
}
void heal(int x) { _Health + x; }