#include "Game.h"


//Static Functions


//Initializer Functions


//Constructor / Destructor

void Game::initVariables()
{
	this->window = NULL;
	this->fullscreen = false;
	this->dt = 0.f;
}

void Game::initWindow()
{
	//Creates window based on window.ini file
	
	ifstream ifs("Config/window.ini");
	this->videoMode = VideoMode::getFullscreenModes();

	string title = "None";
	VideoMode window_bounds = VideoMode::getDesktopMode();
	bool fullscreen = false;
	unsigned frame_rate_limit = 120;
	bool vertical_sync_enabled = false;
	unsigned antialiasing_level = 0;


	if (ifs.is_open())
	{
		getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> fullscreen;
		ifs >> frame_rate_limit;
		ifs >> vertical_sync_enabled;
		ifs >> antialiasing_level;
	}

	ifs.close();

	this->fullscreen = fullscreen;
	this->window_settings.antialiasingLevel = antialiasing_level;

	if (this->fullscreen) {
		this->window = new RenderWindow(window_bounds, title, Style::Fullscreen, window_settings);
	}
	else {
		this->window = new RenderWindow(window_bounds, title, Style::Titlebar | Style::Close, window_settings);
	}
		
	this->window->setFramerateLimit(frame_rate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);

}

void Game::initKeys()
{
	this->supportedKeys["Escape"] = Keyboard::Key::Escape;
	this->supportedKeys["A"] = Keyboard::Key::A;
	this->supportedKeys["D"] = Keyboard::Key::D;
	this->supportedKeys["W"] = Keyboard::Key::W;
	this->supportedKeys["S"] = Keyboard::Key::S;

	//cout << this->supportedKeys.at("D") << endl;
}

void Game::initStates()
{
	this->states.push(new MainMenuState(this->window, &this->supportedKeys, &this->states));
}



Game::Game()
{
	this->initWindow();
	this->initKeys();
	this->initStates();
	
}

Game::~Game()
{
	delete this->window;

	while (!this->states.empty()) {
		delete this->states.top();
		this->states.pop();
		
	}
	
}

void Game::updateDt()
{
	// Updates dt for update and render 1 frame
	
	this->dt = this->clock.restart().asSeconds();


	
}

void Game::updateSFMLevents()
{
	
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		}
	}
	
}

void Game::update()
{
	this->updateSFMLevents();

	if (!this->states.empty())
	{
		this->states.top()->update(this->dt);
		
		if (this->states.top()->getQuit())
		{
			if (this->states.top()->isMainMenu()) {
				this->window->close();
			}
			
			delete this->states.top();
			this->states.pop();
			
			
			//this->window->close();
		}
	}
}

void Game::render()
{
	this->window->clear();

	//Render items
	if (!this->states.empty())
	{
		this->states.top()->render();
	}



	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
		
	}
}
