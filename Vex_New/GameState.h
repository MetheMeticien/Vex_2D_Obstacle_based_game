#pragma once
#include "State.h"



class GameState :
    public State 
{
private:
    Player* player;

    void initKeybinds();
    void initTextures();
    void initPlayers();

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

