#pragma once

#include "SFML/Graphics.hpp";
#include "GraphicObject.h";

class ImageButton : public GraphicObject
{
public:
	ImageButton();
	ImageButton(float posX, float posY, std::string imgDefault, std::string imgHover);
	Sprite getSprite();
	Texture getTexture();
	void setPosition(float posX, float posY);

	float top();
	float right();
	float left();
	float bottom();

	float width();
	float height();

	bool checkMousePosition(float posX, float posY);
	void setPlayBtnHover();
	void setPlayBtnDefault();


protected:
	// Позиция кнопки
	Vector2f position;

	// Спрайт кнопки
	Sprite sprite;

	// Текстура кнопки
	Texture texture;

	// Путь к текстуре кнопки
	std::string textureDefaultPath;

	std::string textureHoverPath;



	float scaleX;
	float scaleY;

	void initProperties();
	void initSprite();

};