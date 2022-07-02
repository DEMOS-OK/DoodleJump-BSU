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

	float width();
	float height();

	void update();
	void setSpeedY(float speedY);
	void setPosition(float posX, float posY);

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

	void move();

};