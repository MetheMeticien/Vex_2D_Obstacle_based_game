#include "GameState.h"


void GameState::initKeybinds()
{
	this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
	this->keybinds["MOVE_LEFT"] = this->supportedKeys->at("A");
	this->keybinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
	this->keybinds["MOVE_UP"] = this->supportedKeys->at("W");
	this->keybinds["MOVE_DOWN"] = this->supportedKeys->at("S");
}

GameState::GameState(RenderWindow* window, map<string, int>* supportedKeys, stack<State*>* states)
	:State(window,supportedKeys,states)
{
	this->initKeybinds();
}

GameState::~GameState()
{

}

void GameState::endState()
{
	cout << "ending current state" << endl;
}

/*
void GameState::checkForQuit()
{

}
*/

void GameState::updateInput(const float& dt)
{
	this->checkForQuit(); 

	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->player.move(dt, -1.f, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->player.move(dt, 1.f, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		this->player.move(dt, 0.f, 1.f);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_UP"))))
		this->player.move(dt, 0.f, -1.f);
}

void GameState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);	

	
	this->player.update(dt);
}

void GameState::render(RenderTarget* target)
{
	if (!target)
		target = this->window;
	this->player.render(target);
}
