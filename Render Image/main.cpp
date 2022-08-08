#include "SFML/Graphics.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>

int main(){

    sf::RenderWindow window(sf::VideoMode(256, 256), "Render Img");
    //Crio uma janela que recebe a alta, largura e nome

    sf::Event event;
    //Eventos executados pelo usuário

    sf::Texture texture; //Crio uma textura
    texture.loadFromFile("resources/red.png"); //Local da textura

    sf::Sprite sprite(texture,sf::IntRect(0,0,32,32));
    //sprite recebe a textura e um retângulo interior

    //Nesse caso: x=0, y=0, quant. de pixels de x=32, quant. de pixels de y=32
    //Cada carrinho tem o tamanho de 32x32, por isso que a quant. de pixels de x e y são ambos 32 

    //crio um sprite (o sprite é o que vai ser renderizado, e precisamos de uma texta para isso ocorrer)

    while (window.isOpen()){ //Enquanto a janela está aberta:

        while(window.pollEvent(event)){

            if (event.type == sf::Event::EventType::Closed){ 
            //Se o tipo de evento for igual a fechar a janela
                window.close(); //feche a janela
            }
        }

        window.clear(); //Limpar a tela (senão, ficaria um monte de imagens acumuladas)

        window.draw(sprite);

        window.display(); //mostrar os elementos da tela
    }


}