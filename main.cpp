#include <SFML/Graphics.hpp>
#include <iostream>
#include "util.h"
using namespace sf;
int main() {
    enum _STATE { m, p };
    _STATE _GSTATE = _STATE::m;
    RenderWindow window(VideoMode(640, 480), "hi");
    window.setFramerateLimit(240);

    _INIT(window);
    while (window.isOpen()) {
        window.clear();
        Event event;
        while (window.pollEvent(event)) {
        switch (event.type) {
        case Event::Closed:
            window.close();
            break;
        case Event::MouseButtonPressed:
            if (event.mouseButton.button == Mouse::Left) {
                if (checkCollision(window, "play")) {
                    _GSTATE = _STATE::p;
                } else if (checkCollision(window, "quit")) {
                    window.close();
                } else if (checkCollision(window, "play")) {
                    _GSTATE = _STATE::m;
                } break;
            }
        }

        if (_GSTATE == _STATE::m) { _RENDERMENU(window); }
        if (_GSTATE == _STATE::p) { _RENDERGAME(window); }
        window.display();
    }
    }
    return 0;
}
