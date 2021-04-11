#include "MenuState.h"




MenuState::MenuState() : 
	m_startButton{ "images/start_btn.png" } {

	m_startButton.setFunction(std::bind(&Game::startGame));
	m_startButton.setPosition(
		sf::Vector2f{ Game::width / 2.f - m_startButton.getBounds().width / 2, 
					  Game::height/ 2.f - m_startButton.getBounds().height / 2 }
	);
}

void MenuState::update(sf::Time delta) {
	
}

void MenuState::handleInput(sf::RenderWindow& window) {

}

void MenuState::handleEvent(sf::RenderWindow& window, sf::Event e) {
	m_startButton.handleEvent(window, e);
}

void MenuState::render(sf::RenderWindow& window) {
	m_startButton.render(window);
}

void MenuState::reset() {

}
