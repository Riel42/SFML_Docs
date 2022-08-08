#include "SFML/Graphics.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>

int main() {

  sf::RenderWindow window(sf::VideoMode(1280, 720), "MegaMan");

  sf::Event event;

  sf::Texture texture;
  texture.loadFromFile("resources/mega.png");

  sf::IntRect rect(0,0,85,70); 

  sf::Sprite sprite(texture, sf::IntRect(rect));
  //Ao invés de colocar os valores dentro desse InteRect, eu coloco seu objeto correspondente,
  //assim, eu consigo variá-los conforme o player se move

  sf::Clock clock; //objeto para medir o tempo do jogo

  while (window.isOpen()) {

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::EventType::Closed) {
        window.close();
      }
    }

    if (clock.getElapsedTime().asSeconds() > 0.2f){ //Quanto maior o valor, mais lenta a animação
    
    //Se tempo decorrido em segundos for maior do que 0.2 segundos
        if (rect.left == 255){
        //Se o RectLeft for igual a 255 (85*3, que corresponde ao RectLeft do 4º sprite):
            rect.left = 0; 
            //RectLeft recebe 0 (o RectLeft volta para o início, ou seja, volta para o 1º sprite)
        }
        else rect.left += 85;

        sprite.setTextureRect(rect); //Atualiza o sprite a cada frame
        
        clock.restart(); //Passou de 0.2 segundos, o clock volta para zero, para não deixar o nosso
                         //personagem correndo infinitamente
    }

    window.clear();
    window.draw(sprite);
    window.display();
  }
}