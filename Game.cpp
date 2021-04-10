#include "Game.h"

#include <iostream>

Game::Game() : m_window{ { 1280, 720 }, "Game" }, m_currentStateIndex{ 0 } {

	m_states.push_back(std::make_unique<PlayingState>());
}



void Game::run() {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate{ sf::Time::Zero };

	while (m_window.isOpen()) {
		sf::Time delta{ clock.restart() };
		timeSinceLastUpdate += delta;

		while (timeSinceLastUpdate > m_frameLength) {
			timeSinceLastUpdate -= m_frameLength;
			handleInput();
			update(m_frameLength);
		}

		render();

	}
}

void Game::update(sf::Time delta) {
	m_states[m_currentStateIndex]->update(delta);
}

void Game::render() {
	m_window.clear(sf::Color::Black);
	m_states[m_currentStateIndex]->render(m_window);
	m_window.display();
}

void Game::handleInput() {
	sf::Event event;
	while (m_window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			m_window.close();
		m_states[m_currentStateIndex]->handleEvent(m_window, event);
	}

	m_states[m_currentStateIndex]->handleInput(m_window);

}
