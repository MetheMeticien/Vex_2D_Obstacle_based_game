#include "MainMenuState.h"

void MainMenuState::initBackground()
{
	this->shape.setSize(Vector2f(window->getSize()));
	

	if (!this->backgroundTexture.loadFromFile("images/Background/back.jpg"))
	{
		throw "ERROR! Background Texture not Loaded";
	}
	this->shape.setTexture(&this->backgroundTexture);
}

void MainMenuState::initFont()
{
	if (!this->font.loadFromFile("SeasideResortNF/SEASRN__.ttf"))
	{
		throw("Error. Font couldn't load");
	}
}

void MainMenuState::initKeybinds()
{
	this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
	this->keybinds["MOVE_LEFT"] = this->supportedKeys->at("A");
	this->keybinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
	this->keybinds["MOVE_UP"] = this->supportedKeys->at("W");
	this->keybinds["MOVE_DOWN"] = this->supportedKeys->at("S");
}

void MainMenuState::initButtons()
{
	this->buttons["NEW GAME"] = new Button(100, 100, 150, 50,
		&this->font, "New Game");
	this->buttons["CONTINUE"] = new Button(100, 300, 150, 50,
		&this->font, "Continue");
	this->buttons["QUIT"] = new Button(100,400 , 150, 50,
		&this->font, "Quit");
}

MainMenuState::MainMenuState(RenderWindow* window, map<string, int>* supportedKeys, stack<State*>* states)
	:State(window, supportedKeys, states)
{
	
	this->mainMenu = true;
	this->initBackground();
	this->initFont();
	this->initKeybinds();
	this->initButtons();
	

	//shape.setTexture()
	
}

MainMenuState::~MainMenuState()
{
	for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

void MainMenuState::endState()
{
	this->quit = true;
}


void MainMenuState::updateInput(const float& dt)
{
	this->updateMousePositions();
	

}

void MainMenuState::updateButtons()
{
	
	for (auto &it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	if (this->buttons["NEW GAME"]->isPressed())
	{
		this->states->push(new GameState(this->window, this->supportedKeys, this->states));
	}

	if (this->buttons["QUIT"]->isPressed())
	{
		this->endState();
	}
	
}



void MainMenuState::update(const float& dt)
{
	this->updateInput(dt);
	this->updateButtons();

	
	
}

void MainMenuState::renderButtons(RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void MainMenuState::render(RenderTarget* target)
{
	
	if (!target)
		target = this->window;
	target->draw(this->shape);
	
	this->renderButtons(target);
	
}
