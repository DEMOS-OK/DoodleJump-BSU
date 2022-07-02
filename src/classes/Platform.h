#pragma once

#include "SFML/Graphics.hpp";
#include "GraphicObject.h";

using namespace sf;

/// <summary>
/// Класс платформы, от которой дудлер может отталкиваться
/// </summary>
class Platform : public GraphicObject
{
public:
	Platform(float posX, float posY);
	Sprite getSprite();
	Texture getTexture();

	float top();
	float right();
	float left();
	float bottom();

	void update();
	void setSpeedY(float speedY);

protected:
	// Позиция платформы
	Vector2f position;

	// Спрайт платформы
	Sprite sprite;

	// Текстура платформы
	Texture texture;

	float speedY;

	float gravitySpeedUp;

	float scaleX;
	float scaleY;

	void initProperties();
	void initSprite();
	void initPosition(float posX, float posY);

	void move();

};