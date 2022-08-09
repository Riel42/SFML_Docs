#include "SFML/Graphics.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>

int main(){

    sf::RenderWindow window(sf::VideoMode(320, 480), "Move Car");
    
    window.setFramerateLimit(60); //Limito o FPS para 60

    //Temos que colocar essa limitação para que em todas as máquinas, 
    //o jogo tenha a mesma taxa de frames por segundo (senão, os sprites teriam um movimentação
    //diferente para cada máquina).

    sf::Texture texture;
    texture.loadFromFile("resources/car2.png");

    sf::IntRect rect(0,0,250,140);

    sf::Sprite sprite(texture, rect);
    sprite.setPosition(60, 300); //Posição onde aparecerá o meu carro
    
    sf::Clock clock;

    sf::Event event;

    while (window.isOpen()){

        while(window.pollEvent(event)){

            if (event.type == sf::Event::EventType::Closed){ 
                window.close(); 
            }
        }

        
        

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){ //Se tecla pressionada for para cicma:
            sprite.move(0,-2.0); //Eixo X não se move, o eixo Y se move para cima
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            sprite.move(0,2.0); //Eixo X não se move, o eixo Y se move para baixo
        }

        if (clock.getElapsedTime().asSeconds() > 0.2f){
            if (rect.left == 250){
                rect.left = 0;
            }
            else{
                rect.left += 250;
            }
            sprite.setTextureRect(rect);
            clock.restart();
        }
        window.clear(sf::Color::White); //Defino uma cor para o fundo do meu jogo 

        window.draw(sprite);

        window.display();
    }


}
