#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <map>

#include "State.h"


// singleton class
class Game {

public:
	enum class StateName {
		None,
		Menu,
		Playing,
		Pause
	};


	static Game* getInstance() {
		if (!m_instance)
			m_instance = new Game;
		return m_instance;
	}
	
	void run();
	static void startGame() { m_currentState = StateName::Playing; };
	static void pauseGame() { }

	static size_t width, height;


private:

	Game();
	static Game* m_instance;

	void update(sf::Time delta);
	void render();
	void handleInput();

	void setCurrentState(StateName state);

	sf::RenderWindow m_window;


	static std::map<StateName, std::unique_ptr<State>> m_states;
	static StateName m_currentState;


	const sf::Time m_frameLength = sf::seconds(1.f / 60.f);



};

