#include "GameState.h"


void GameState::initKeybinds()
{
	this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
	this->keybinds["MOVE_LEFT"] = this->supportedKeys->at("A");
	this->keybinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
	this->keybinds["MOVE_UP"] = this->supportedKeys->at("W");
	this->keybinds["MOVE_DOWN"] = this->supportedKeys->at("S");
}

void GameState::initTextures()
{
	Texture temp;
	temp.loadFromFile("images/2D_SL_Knight_v1.0/Run.png");
	this->textures["PLAYER_IDLE"] = temp;
}

void GameState::initPlayers()
{
	this->player = new Player(0, 0, &this->textures["PLAYER_IDLE"]);
}

/***************************************************************

                    CONSTRUCTOR/DESTRUCTOR

***************************************************************/

GameState::GameState(RenderWindow* window, map<string, int>* supportedKeys, stack<State*>* states)
	:State(window,supportedKeys,states)
{
	this->initKeybinds();
	this->initTextures();
	this->initPlayers();
	
}

GameState::~GameState()
{
	delete this->player;
}

void GameState::endState()
{
	this->quit = true;
}


void GameState::updateInput(const float& dt)
{ 

	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->player->move(dt, -1.f, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->player->move(dt, 1.f, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		this->player->move(dt, 0.f, 1.f);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_UP"))))
		this->player->move(dt, 0.f, -1.f);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("CLOSE"))))
		this->endState();
}

void GameState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);	

	
	this->player->update(dt);
}

void GameState::render(RenderTarget* target)
{
	if (!target)
		target = this->window;
	this->player->render(target);
}
