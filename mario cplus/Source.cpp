#include <SFML\Graphics.hpp>
#include <vector>
#include <string>
#include "Character.hpp"
int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML :O ");
	window.setFramerateLimit(60);
	sf::Event event;
	sf::RectangleShape rectangle(sf::Vector2f(360,260));
	rectangle.setSize(sf::Vector2f(200, 200));
	rectangle.setFillColor(sf::Color::Blue);
	Game::Character c(sf::Vector2f(600, 600), sf::Vector2f());
	
	
	while (window.isOpen()) {
		
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			window.clear();
			
			window.draw(c.getSprite());
			window.display();
		}
	}
}