#pragma once

#include <SFML\Graphics.hpp>

#include <string>
#include <functional>


class Button {
public:
	Button(const std::string& imageFile, sf::Vector2f position);

	void render(sf::RenderWindow& window);

	sf::FloatRect getBounds() const;
	sf::Vector2u getSize() const;
	sf::Vector2f getPosition() const;

	void setPosition(sf::Vector2f position);
	void setPosition(float x, float y);
	void setFunction(std::function<void(void)> func);

	void handleEvent(const sf::RenderWindow& window, sf::Event e);

private:
	std::function<void(void)> m_function = []() {};
	
	sf::Vector2f m_position;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
};