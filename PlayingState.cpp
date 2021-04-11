#include "PlayingState.h"




PlayingState::PlayingState() {
	reset();
}

void PlayingState::update(sf::Time delta) {
	
}

void PlayingState::handleInput(sf::RenderWindow& window) {

}

void PlayingState::handleEvent(sf::RenderWindow& window, sf::Event e) {

}

void PlayingState::render(sf::RenderWindow& window) {
	window.clear(sf::Color{ 255, 0, 0 });
}

void PlayingState::reset() {

}
