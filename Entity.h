#pragma once

#include <SFML\Graphics.hpp>

#include <memory>
#include <vector>


class Entity {
public:
	enum class Type {
		None
	};

	Entity(Type type, const sf::Vector2f& position = sf::Vector2f(0.f, 0.f));

	virtual void handleInput() = 0;
	virtual void update(sf::Time delta) = 0;
	virtual void render(sf::RenderWindow& window) = 0;

	virtual void checkCollisions(std::vector<std::shared_ptr<Entity>>& entities) = 0;

	virtual sf::FloatRect getBounds() const = 0;
	sf::Vector2f getPosition() const;
	Type getType() const;

protected:
	sf::Vector2f m_position;

	Type m_type = Type::None;
};