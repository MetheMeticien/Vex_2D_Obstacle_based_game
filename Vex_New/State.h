#pragma once
#include "Entity.h"

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

	Vector2i mousePosScreen;
	Vector2i mousePosWindow;
	Vector2f mousePosView;


	vector<Texture> textures;

	virtual void initKeybinds() = 0;


public:
	State(RenderWindow* window, map<string, int>* supportedKeys, stack<State*>* states);
	virtual ~State();

	const bool& getQuit() const;

	virtual void checkForQuit();
	virtual void endState() = 0;
	virtual void updateMousePositions();
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(RenderTarget* target = nullptr) = 0;

};
