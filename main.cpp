#include <SFML/Graphics.hpp>
#include <iostream>

#include "button.h"
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(640, 480), "hi");
    Font font;
    if (!font.loadFromFile("font.ttf"))
        return EXIT_FAILURE;
    Text p("play", font, 24);
    Text o("options", font, 24);
    Text q("quit", font, 24);
    Text e("!!", font, 24);
    p.setPosition(window.getSize().x*0.02, window.getSize().y / 2 - 40);
    o.setPosition(window.getSize().x*0.02, window.getSize().y / 2);
    q.setPosition(window.getSize().x*0.02, window.getSize().y / 2 + 40);
    e.setPosition(window.getSize().x*0.02+o.getGlobalBounds().width+10, window.getSize().y / 2);
    e.setColor(sf::Color::Red);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case Event::Closed:
                window.close();
                break;
            

            case Event::MouseButtonPressed:
                if (event.mouseButton.button == Mouse::Left) {
                    if (checkButtonCollision(p, window)) {
                        std::cout << "play" << std::endl;
                    }
                    else if (checkButtonCollision(o, window)) {
                        std::cout << "opt" << std::endl;
                        if (!optionsCheck()) {makeOptions();}
                    }
                    else if (checkButtonCollision(q, window)) {
                        window.close();
                    }
                    else { std::cout << "error!" << std::endl; }
                }
                break;
            }
        }

        window.clear();
        window.draw(p);
        window.draw(o);
        if (!optionsCheck()) {window.draw(e);}
        window.draw(q);
        window.display();
    }

    return 0;
}