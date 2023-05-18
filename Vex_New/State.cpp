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

void State::checkForQuit()
{
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("CLOSE"))))
	{
		this->quit = true;
	}
}

void State::updateMousePositions()
{
	mousePosScreen = Mouse::getPosition();
	mousePosWindow = Mouse::getPosition(*this->window);
	mousePosView = this->window->mapPixelToCoords(Mouse::getPosition(*this->window));
}


