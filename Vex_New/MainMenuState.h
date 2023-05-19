#pragma once
//#include "State.h"
#include "GameState.h"
#include "Button.h"



class MainMenuState :
    public State
{
private:
   
    
    Texture backgroundTexture;
    RectangleShape shape;
    Font font;

    map<string, Button*> buttons;
    
    void initBackground();
    void initFont();
    void initKeybinds();
    void initButtons();

public:
    MainMenuState(RenderWindow* window, map<string, int>* supportedKeys, stack<State*>* states);
    virtual ~MainMenuState();



    //Functions


    void endState();



    //void checkForQuit();

    void updateInput(const float& dt);
    void updateButtons();
    void update(const float& dt);
    void renderButtons(RenderTarget* target = nullptr);
    void render(RenderTarget* target = nullptr);
};

