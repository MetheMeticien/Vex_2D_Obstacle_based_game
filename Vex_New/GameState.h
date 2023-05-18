#pragma once
#include "State.h"



class GameState :
    public State 
{
private:
    Entity player;

    void initKeybinds();

public:
    GameState(RenderWindow* window, map<string, int>* supportedKeys, stack<State*>* states);
    virtual ~GameState();



    //Functions


    void endState();



    //void checkForQuit();

    void updateInput(const float& dt);
    void update(const float& dt);
    void render(RenderTarget* target = nullptr);
};

