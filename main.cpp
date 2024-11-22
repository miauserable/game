#include <SFML/Graphics.hpp>
#include <iostream>

#include "util.h"
#include "player.h"
using namespace sf;
int main()
{
    enum class State {
        m,p,o};

    char key[4]
      = { 'w', 's', 'a', 'd'};
    State state = State::m;
    RenderWindow window(VideoMode(640, 480), "hi");
    window.setFramerateLimit(240);
    Font font;
    float XSET = window.getSize().x*0.02;
    float YSET = window.getSize().y/2;
    bool notSet;
    if (!font.loadFromFile("font.ttf")) {return EXIT_FAILURE;}
    if (!optionsCheck) { notSet = true; } else { notSet = false; }
    Text g("game", font, 36);
    Text p("play", font, 24);
    Text o("options", font, 24);
    Text q("quit", font, 24);
    Text e("!!", font, 24);
    Text xu("move left:", font, 24);
    Text xd("move right:", font, 24);
    Text yu("move up:", font, 24);
    Text yd("move down:", font, 24);
    Text xuk(key[2], font, 24);
    Text xdk(key[3], font, 24);
    Text yuk(key[0], font, 24);
    Text ydk(key[1], font, 24);
    Text cxu("<- click me!", font, 24);
    Text cxd("<- click me!", font, 24);
    Text cyu("<- click me!", font, 24);
    Text cyd("<- click me!", font, 24);
    Text b("back", font, 24);
    g.setPosition(window.getSize().x/2, YSET / 2);
    p.setPosition(XSET, YSET - 40);
    o.setPosition(XSET, YSET);
    q.setPosition(XSET,YSET + 40);
    e.setPosition(XSET+o.getGlobalBounds().width+10, YSET);
    e.setColor(sf::Color::Red);
    xu.setPosition(XSET,YSET + 40);
    xd.setPosition(XSET,YSET + 80);
    yu.setPosition(XSET,YSET - 80);
    yd.setPosition(XSET,YSET - 40);
    xuk.setPosition(XSET+10+xu.getGlobalBounds().width, YSET + 40);
    xdk.setPosition(XSET+10+xd.getGlobalBounds().width, YSET + 80);
    yuk.setPosition(XSET+10+yu.getGlobalBounds().width, YSET - 80);
    ydk.setPosition(XSET+10+yd.getGlobalBounds().width, YSET - 40);
    b.setPosition(XSET, window.getSize().y - b.getGlobalBounds().height - 16);
    cxu.setPosition(XSET+10+xu.getGlobalBounds().width+xuk.getGlobalBounds().width+15, YSET + 40);
    cxd.setPosition(XSET+10+xd.getGlobalBounds().width+xdk.getGlobalBounds().width+15, YSET + 80);
    cyu.setPosition(XSET+10+yu.getGlobalBounds().width+yuk.getGlobalBounds().width+15, YSET - 80);
    cyd.setPosition(XSET+10+yd.getGlobalBounds().width+ydk.getGlobalBounds().width+15, YSET - 40);
    cxu.setColor(Color(242, 130, 221));
    cxd.setColor(Color(242, 130, 221));
    cyu.setColor(Color(242, 130, 221));
    cyd.setColor(Color(242, 130, 221));

    Texture _PTEXTURE;
    if (!_PTEXTURE.loadFromFile("s1.png"))
        std::cout << "Texture Error, please make sure all files are present." << std::endl;

    Player _player(_PTEXTURE);
    Sprite _PSPRITE = _player.getSprite();
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
                        state = State::p;
                    }
                    else if (checkButtonCollision(o, window)) {
                        if (notSet) {makeOptions();}
                        state = State::o;
                    }
                    else if (checkButtonCollision(q, window)) {
                        window.close();
                    } else if (checkButtonCollision(b, window)) {
                        state = State::m;
                    }
                } break;
            case Event::KeyPressed:
                if (event.key.code == sf::Keyboard::W) {
                    _PSPRITE.move(0, -5);
                } if (event.key.code == sf::Keyboard::S) {
                    _PSPRITE.move(0, 5);
                } if (event.key.code == sf::Keyboard::A) {
                    _PSPRITE.move(-5, 0);
                } if (event.key.code == sf::Keyboard::D) {
                    _PSPRITE.move(5, 0);
                }
            }
        }

        window.clear();
        if (state == State::m) {
            window.draw(g);
            window.draw(p);
            window.draw(o);
            if (notSet) {window.draw(e);}
            window.draw(q); }
        if (state == State::o) {
            window.draw(xu);
            window.draw(xd);
            window.draw(yu);
            window.draw(yd);
            window.draw(xuk);
            window.draw(xdk);
            window.draw(yuk);
            window.draw(ydk);
            window.draw(b);
            if (notSet) {
                window.draw(cxu);
                window.draw(cxd);
                window.draw(cyu);
                window.draw(cyd);
            }
        } if (state == State:: p) {
            window.draw(_PSPRITE);
            window.draw(b);
        }
        window.display();
        /*if (state == State::m) {
            std::cout << "m" << std::endl;
        } else if (state == State::o) {
            std::cout << "o" << std::endl;
        } else if (state == State::p) {
            std::cout << "p" << std::endl;
        }*/
    }

    return 0;
}
