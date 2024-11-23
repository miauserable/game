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
    _Sprite.setScale(0.25f, 0.25f);
}

Sprite Player::getSprite() const
{
    return _Sprite;
}

void Player::moveLeft() {
    _Sprite.move(-5, 0);
}
void Player::moveRight() {
    _Sprite.move(5, 0);
}
void Player::moveUp() {
    _Sprite.move(0, 5);
}
void Player::moveDown() {
    _Sprite.move(0, -5);
}
void Player::heal(int x) { _Health + x; }