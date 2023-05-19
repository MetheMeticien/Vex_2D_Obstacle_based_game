#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include <vector>


#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>

using namespace sf;
using namespace std;


class Entity
{
private:
	void initVariables();


protected:
	Sprite* sprite;
	Texture* texture;
	//RectangleShape shape;
	float movementSpeed;


public:
	Entity();
	virtual ~Entity();

	void createSprite(Texture* texture);

	//Functions
	virtual void setPosition(float x, float y);
	virtual void move(const float& dt,const float dir_x,const float dir_y);

	virtual void update(const float& dt);
	virtual void render(RenderTarget* target);

};

