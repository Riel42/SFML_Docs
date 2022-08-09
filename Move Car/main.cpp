#include "SFML/Graphics.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>

int main(){

    sf::RenderWindow window(sf::VideoMode(320, 480), "Move Car");

    sf::Event event;

    sf::Texture texture;
    texture.loadFromFile("resources/car.png");

    sf::Sprite sprite(texture);
    sprite.setPosition(60, 300); //Posição onde aparecerá o meu carro
    
    while (window.isOpen()){

        while(window.pollEvent(event)){

            if (event.type == sf::Event::EventType::Closed){ 
                window.close(); 
            }
        }

        window.clear(sf::Color::Cyan); //Defino uma cor para o fundo do meu jogo 

        window.draw(sprite);

        window.display();
    }


}
