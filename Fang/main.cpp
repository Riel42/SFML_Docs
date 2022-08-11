#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Window/Keyboard.hpp>

int main(){
    sf::RenderWindow window(sf::VideoMode(800,600),"Fang");
    window.setFramerateLimit(60);

    float currentFrame = 0;

    sf::Texture texture;
    texture.loadFromFile("resources/fang.png");

    sf::IntRect rect(0,244,40,50);

    sf::Sprite sprite(texture, rect);
    sprite.setPosition(300,400);

    sf::Event event;

    while(window.isOpen()){
        while(window.pollEvent(event)){
            if(event.type == sf::Event::EventType::Closed){
                window.close();
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){

            if(sprite.getPosition().x > 0){ //Se a posição do x for > do que 0 (lado esquerdo da tela)
                sprite.move(-2,0); //Mova o sprite
            }
            currentFrame += 0.1; //currentFrame varia para haver a troca de sprites
            if (currentFrame > 6){
                currentFrame = 0;
            }
            sprite.setTextureRect(sf::IntRect(40 * int(currentFrame) + 40,244,-40,50));
            //pos do x = -40 inverte a figura
            //+40 para sair do lado esquerdo, e não do lado direito (porquê eu inverti a imagem)
            //se eu coloco +40, é como o rectLeft se tornasse um rectRight
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){

            if(sprite.getPosition().x < window.getSize().x - 40){ 
            //Se a posição do sprite for menor do que 800 - 40:

            //Tenho que tirar diferença da largura do player 
                sprite.move(2,0); //Mona o sprite para a direita
            }

            currentFrame += 0.1;
            if (currentFrame > 6){
                currentFrame = 0;
            }
            sprite.setTextureRect(sf::IntRect(40 * int(currentFrame),244,40,50));
            //pos do x = -40 inverte a figura
        }
        
        window.clear(sf::Color::White);
        window.draw(sprite);
        window.display();
    }
}