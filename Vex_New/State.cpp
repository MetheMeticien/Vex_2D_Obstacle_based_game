#include "State.h"

State::State(RenderWindow* window, map<string, int>* supportedKeys, stack<State*>* states)
{
	this->window = window;
	this->supportedKeys = supportedKeys;
	this->states = states;
	this->quit = false;
	
}

State::~State()
{
}

const bool &State::getQuit() const
{
	return this->quit;
}

const bool& State::isMainMenu() const
{
	// TODO: insert return statement here
	return this->mainMenu;
}




void State::updateMousePositions()
{
	mousePosScreen = Mouse::getPosition();
	mousePosWindow = Mouse::getPosition(*this->window);
	mousePosView = this->window->mapPixelToCoords(Mouse::getPosition(*this->window));
}


