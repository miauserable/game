#include <SFML/Graphics.hpp>
#include <iostream>
#include "util.h"
using namespace sf;
int main() {
    enum _STATE { m, p };
    _STATE _GSTATE = _STATE::m;
    RenderWindow window(VideoMode(640, 480), "hi");
    _INIT(window);
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
        switch (event.type) {
        case Event::Closed:
            window.close();
            break;
        case Event::MouseButtonPressed:
            if (event.mouseButton.button == Mouse::Left) {
                if (checkTCollision(window, "play")) { _GSTATE = _STATE::p;
                } else if (checkTCollision(window, "quit")) { window.close(); } break;
            }
        case Event::KeyPressed:
            if (event.key.code == Keyboard::Escape && _GSTATE == _STATE::p) { _GSTATE = _STATE::m;
            } if (event.key.code == Keyboard::W) { MovePlayer(window, "up");
            } if (event.key.code == Keyboard::S) { MovePlayer(window, "down");
            } if (event.key.code == Keyboard::A) { MovePlayer(window, "left");
            } if (event.key.code == Keyboard::D) { MovePlayer(window, "right"); } break;
        }
        window.clear();
        if (_GSTATE == _STATE::m) { _RENDERMENU(window); }
        if (_GSTATE == _STATE::p) { _RENDERGAME(window); }
        window.display();
        }
    }
    return 0;
}
