#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
using namespace std;

int main(){
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1000,75),"ASCII VS TEXT",sf::Style::Titlebar | sf::Style::Close | sf::Style::Default, settings);
    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text text;
    sf::Text baslik;
    sf::Text ascii_baslik;
    sf::Text ascii_text;

    ascii_baslik.setFillColor(sf::Color::Green);
    ascii_baslik.setCharacterSize(24);
    ascii_baslik.setPosition(0,40);
    ascii_baslik.setFont(font);
    ascii_baslik.setStyle(sf::Text::Bold | sf::Text::Underlined);
    ascii_baslik.setString("ASCII: ");

    ascii_text.setFillColor(sf::Color::Green);
    ascii_text.setCharacterSize(24);
    ascii_text.setPosition(75,40);
    ascii_text.setFont(font);
    ascii_text.setStyle(sf::Text::Bold);

    text.setFillColor(sf::Color::Green);
    text.setCharacterSize(24);
    text.setPosition(75,0);
    text.setFont(font);
    text.setStyle(sf::Text::Bold);

    baslik.setFillColor(sf::Color::Green);
    baslik.setFont(font);
    baslik.setCharacterSize(24);
    baslik.setPosition(0,0);
    baslik.setString("TEXT: ");
    baslik.setStyle(sf::Text::Bold | sf::Text::Underlined);

    std::string a = "";
    std::string h = "";
    text.setString(a);
    ascii_text.setString(h);
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if (event.type == sf::Event::TextEntered){
                if (event.text.unicode < 128){
                    a += static_cast<char>(event.text.unicode);
                    h.append(std::to_string(event.key.code));
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)){
                a =- static_cast<char>(event.text.unicode);
                h =- static_cast<char>(event.key.code);
            }
        }
        text.setString(a);
        ascii_text.setString(h);
        window.clear(sf::Color::Black);
        window.draw(text);
        window.draw(baslik);
        window.draw(ascii_baslik);
        window.draw(ascii_text);
        window.display();
    }
}
