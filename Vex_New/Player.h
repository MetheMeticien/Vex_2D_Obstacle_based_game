#pragma once
#include "Entity.h"


class Player :
    public Entity
{
private:

    //Variables
    

    //Initializor Functions
    void initVariables();
    void initComponents();

public:
    Player(float x, float y, Texture* texture);
    virtual ~Player(); 

    //Functions

};

