#include "Button.h"



Button::Button(float x, float y, float width, float height, Font* font, string text)
{
	this->button.setPosition(Vector2f(x, y));
	this->button.setSize(Vector2f(width, height));
	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(Color::Cyan);
	this->text.setCharacterSize(20);
	this->text.setStyle(Text::Bold);

	this->text.setPosition(
		this->button.getPosition().x + (this->button.getGlobalBounds().width - this->text.getGlobalBounds().width)/2.f,
		this->button.getPosition().y + (this->button.getGlobalBounds().height - this->text.getGlobalBounds().height) / 2.f
	);

	this->button.setFillColor(idleColor);
}

Button::~Button()
{

}

const bool Button::isPressed() const
{
	if (this->clicked) 
		return true;
	return false;
}

const bool Button::isHovered() const
{
	if (!this->clicked && this->hovered)
		return true;
	return false;
}

void Button::update(const Vector2f mousePos)
{
	/*Update the booleans for hover and press*/

	this->clicked = false;
	this->hovered = false;

	if (this->button.getGlobalBounds().contains(mousePos))
	{
		this->hovered = true;
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			this->clicked = true;
		}
	}

	if (this->clicked)
	{
		this->button.setFillColor(clickedColor);
	}
	else if (this->hovered)
	{
		this->button.setFillColor(hoverColor);
	}
	else {
		this->button.setFillColor(idleColor);
	}
	
}

void Button::render(RenderTarget* target)
{
	target->draw(this->button);
	target->draw(this->text);
}
