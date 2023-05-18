#pragma once


#include "MainMenuState.h"

class Game
{
private:

	//Variables
	RenderWindow *window;
	Event event;
	vector<VideoMode> videoMode;
	ContextSettings window_settings;
	bool fullscreen = false;


	Clock clock;
	float dt;

	stack <State*> states;

	map<string, int> supportedKeys;

	//Initialization
	void initVariables();
	void initWindow();
	void initKeys();
	void initStates();
	


public:
	Game();
	virtual ~Game();

	//Functions
	void updateDt();
	void updateSFMLevents();
	void update();
	void render();
	void run();

};

