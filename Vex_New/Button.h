#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>



#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\Audio.hpp>


using namespace std;
using namespace sf;




class Button
{
private:
	bool clicked;
	bool hovered;
	
	
	RectangleShape button;
	Font* font;
	Text text;

	Color idleColor = Color::White;
	Color hoverColor = Color :: Cyan;
	Color clickedColor = Color::Blue;


public:
	Button(float x, float y, float width, float height, Font* font, string text);
	~Button();

	const bool isPressed() const;
	const bool isHovered() const;

	void update(const Vector2f mousePos);
	void render(RenderTarget* target);

};

