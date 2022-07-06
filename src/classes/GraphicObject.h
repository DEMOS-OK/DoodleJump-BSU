#pragma once

#include "SFML/Graphics.hpp";

using namespace sf;

/// <summary>
/// Абстрактный класс графического объекта, отображаемого на экране
/// </summary>
class GraphicObject
{
public:
	// Позиция графического объекта на экране
	Vector2f position;

	// Спрайт графического объекта
	Sprite sprite;

	// Текстура графического объекта
	Texture texture;

	// Виртуальный метод, который в дочернем классе должен возвращать спрайт объекта
	Sprite virtual getSprite() = 0;

	Texture virtual getTexture() = 0;

	virtual void setPosition(float posX, float posY) = 0;

	virtual float top() = 0;
	virtual float right() = 0;
	virtual float left() = 0;
	virtual float bottom() = 0;

	virtual float width() = 0;
	virtual float height() = 0;

protected:
	void virtual initSprite() = 0;

};