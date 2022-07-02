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

protected:
	void virtual initSprite() = 0;
	void virtual initPosition(float posX, float posY) = 0;

};