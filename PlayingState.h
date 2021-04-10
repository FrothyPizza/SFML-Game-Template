#pragma once

#include "State.h"
#include "Button.h"


class PlayingState : public State {

public:
	PlayingState();

	void update(sf::Time delta) override;
	void handleInput(sf::RenderWindow& window) override;
	void handleEvent(sf::RenderWindow& window, sf::Event e) override;
	void render(sf::RenderWindow& window) override;
	void reset() override;


private:


};

