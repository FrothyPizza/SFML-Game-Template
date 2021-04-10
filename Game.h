#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "State.h"
#include "PlayingState.h"

class Game {

public:
	Game();
	void run();

private:
	void update(sf::Time delta);
	void render();
	void handleInput();

	sf::RenderWindow m_window;

	int m_currentStateIndex;
	std::vector<std::unique_ptr<State>> m_states;


	const sf::Time m_frameLength = sf::seconds(1.f / 60.f);



};

