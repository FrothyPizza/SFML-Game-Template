#pragma once
#include "State.h"
#include "Button.h"
#include "Game.h"

class MenuState : public State {

public:

	MenuState();

	void update(sf::Time delta) override;
	void handleInput(sf::RenderWindow& window) override;
	void handleEvent(sf::RenderWindow& window, sf::Event e) override;
	void render(sf::RenderWindow& window) override;
	void reset() override;


private:
	Button m_startButton;


};

