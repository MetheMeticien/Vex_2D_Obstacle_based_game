#pragma once
#include "Player.h"

using namespace sf;
using namespace std;


class State
{
private:
	
protected:

	

	stack<State*>* states;
	RenderWindow* window;
	map<string, int>* supportedKeys;
	map<string, int> keybinds;
	bool quit;
	bool mainMenu;

	Vector2i mousePosScreen;
	Vector2i mousePosWindow;
	Vector2f mousePosView;


	map<string, Texture> textures;

	virtual void initKeybinds() = 0;


public:
	State(RenderWindow* window, map<string, int>* supportedKeys, stack<State*>* states);
	virtual ~State();

	const bool& getQuit() const;
	const bool& isMainMenu() const;

	//virtual void endStateUpdate() = 0;
	
	virtual void endState() = 0;
	virtual void updateMousePositions();
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(RenderTarget* target = nullptr) = 0;

};

