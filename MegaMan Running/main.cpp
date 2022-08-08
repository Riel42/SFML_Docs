#include "SFML/Graphics.hpp"
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

  sf::Sprite sprite(texture, sf::IntRect(0,0,85,70));



  while (window.isOpen()) {

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::EventType::Closed) {
        window.close();
      }
    }

    window.clear();
    window.draw(sprite);
    window.display();
  }
}