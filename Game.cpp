#include "Game.h"

#include <iostream>

#include "PlayingState.h"
#include "MenuState.h"


Game* Game::m_instance = 0;
Game::StateName Game::m_currentState = StateName::Menu;
std::map<Game::StateName, std::unique_ptr<State>> Game::m_states;

size_t Game::width = 1280;
size_t Game::height = 720;

Game::Game() : m_window{ { width, height }, "Game" } {


	m_states.insert(
		std::make_pair(StateName::Menu, std::make_unique<MenuState>())
	);
	m_states.insert(
		std::make_pair(StateName::Playing, std::make_unique<PlayingState>())
	);
	m_currentState = StateName::Menu;

}

void Game::setCurrentState(StateName state) {
	if (m_states.count(state) > 0) // if it contains this state
		m_currentState = state;
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
	m_states[m_currentState]->update(delta);
}

void Game::render() {
	m_window.clear(sf::Color::Black);
	m_states[m_currentState]->render(m_window);
	m_window.display();
}

void Game::handleInput() {
	sf::Event event;
	while (m_window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			m_window.close();
		m_states[m_currentState]->handleEvent(m_window, event);
	}

	m_states[m_currentState]->handleInput(m_window);

}
