#pragma once

#include <vector>
#include "SFML/Graphics.hpp";

#include "GraphicObject.h";
#include "Platform.h";

using std::vector;
using namespace sf;

class Doodler : public GraphicObject
{
public:
	Doodler();
	Sprite getSprite();
	void setPosition(float posX, float posY);

	void update(vector<Platform*>* platforms);
	void moveLeft();
	void stopLeft();
	void moveRight();
	void stopRight();

	float bottom();
	float right();
	float left();

	float getSpeedY();

	// Скорость перемещения по Y
	float speedY;

protected:
	// Позиция дудлера
	Vector2f position;

	// Спрайт дудлера
	Sprite sprite;

	// Текстура дудлера
	Texture texture;

	// Параметр скалирования спрайта по X
	float scaleX;

	// Параметр скалирования спрайта по Y
	float scaleY;
	
	// Флаг нажатия на кнопку движения вправо
	bool rightPressed;

	// Флаг нажатия на кнопку движения влево
	bool leftPressed;

	// Флаги направления движения вправо
	bool directionRight;

	// Флаг направления движения влево
	bool directionLeft;

	// Скорость перемещения по X
	float speedX;

	// Ускорение свободного падения
	float gravitySpeedUp;

	void move();
	void changeDirectionLeft();
	void changeDirectionRight();

	void initSprite();
	void initProperties();

	bool checkCollisions(Platform *platform);
	bool checkFallDirection();
	void jump(Platform *platform);
};