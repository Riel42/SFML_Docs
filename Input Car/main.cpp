#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>
#include <exception>

int main(){
    sf::RenderWindow window(sf::VideoMode(1024,512), "Input Car");
    window.setFramerateLimit(60);

    float currentFrame = 0; //Variável que vai nos auxiliar nas animações

    sf::Texture texture;
    texture.loadFromFile("resources/red.png");

    sf::IntRect rect(160,224,32,32);

    sf::Sprite sprite(texture,rect);
    sprite.setPosition(96,96);
    sprite.setScale(2,2); //Dobrei o tamanho x e y do sprite

    //sf::Clock clock;

    sf::Event event;

    while(window.isOpen()){
        while(window.pollEvent(event)){
            if (event.type == sf::Event::EventType::Closed){
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            
            sprite.move(-2,0);

            currentFrame = 1;
            sprite.setTextureRect(sf::IntRect(32 * int(currentFrame),224,32,32));

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){

            sprite.move(2,0);

            currentFrame = 5;
            sprite.setTextureRect(sf::IntRect(32 * int(currentFrame),224,32,32));
        }

        window.clear(sf::Color(135,206,235)); 
        //Cor RGB
        window.draw(sprite);
        window.display();
    }

}