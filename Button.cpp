#include "Button.h"
#include <SFML\Graphics.hpp>

#include <iostream>
#include <string>

#include "Button.h"

Button::Button(const std::string& imageName, sf::Vector2f position)
    : m_position(position) {
    if (!m_texture.loadFromFile(imageName)) {
        m_texture.create(50, 50);
    }
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position);

    
}

void Button::handleEvent(const sf::RenderWindow& window, sf::Event e){
    auto pos = sf::Mouse::getPosition(window);

    switch (e.type) {
    case sf::Event::MouseButtonPressed:
        switch (e.mouseButton.button) {
        case sf::Mouse::Left:
            if (getBounds().contains((float)pos.x, (float)pos.y)) {
                m_function();
            }

        default:
            break;
        }

    default:
        break;
    }
}

sf::Vector2u Button::getSize() const {
	return m_texture.getSize();
}

sf::FloatRect Button::getBounds() const {
	return m_sprite.getGlobalBounds();
}

sf::Vector2f Button::getPosition() const {
	return m_sprite.getPosition();
}

void Button::setPosition(sf::Vector2f position) {
	m_sprite.setPosition(position);
}

void Button::setPosition(float x, float y) {
	m_sprite.setPosition(x, y);
}

void Button::setFunction(std::function<void()> func) {
	m_function = func;
}

void Button::render(sf::RenderWindow& window) {
	window.draw(m_sprite);
}