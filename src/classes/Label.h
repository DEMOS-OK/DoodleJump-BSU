#pragma once

#include "SFML/Graphics.hpp";

using namespace sf;
using std::string;

class Label
{
	
public:
	Label();
	Label(string fontPath, string labelText, float posX = 0, float posY = 0, int fontSize = 48,
		Color color = Color::White, Text::Style textStyle = Text::Bold);

	void setPosition(float posX, float posY);
	void setText(string labelText);
	void setFont(string fontPath);
	void setCharacterSize(int fontSize);
	void setColor(Color color);
	void setStyle(Text::Style textStyle);

	Text* getText();

protected:
	Font font;
	Text text;

};