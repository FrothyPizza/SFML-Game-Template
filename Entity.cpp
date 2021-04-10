#include "Entity.h"

Entity::Entity(Type type, const sf::Vector2f& position) :
	m_type{ type }, m_position{ position } {


}

sf::Vector2f Entity::getPosition() const {
	return m_position;
}

Entity::Type Entity::getType() const {
	return m_type;
}
