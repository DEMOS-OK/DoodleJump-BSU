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
	Texture getTexture();
	void setPosition(float posX, float posY);

	void update(vector<Platform*>* platforms);
	void moveLeft();
	void stopLeft();
	void moveRight();
	void stopRight();

	float bottom();
	float right();
	float left();
	float top();

	float width();
	float height();

	float getSpeedY();

	void initProperties();

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

	// Флаг, что у дудлера сейчас изображение в прыжке
	bool jumpImg;

	// Скорость перемещения по X
	float speedX;

	// Ускорение свободного падения
	float gravitySpeedUp;

	// Скорость дудлера при прыжке
	float onJumpSpeedY;

	void move();
	void changeDirectionLeft();
	void changeDirectionRight();

	void initSprite();

	bool checkCollisions(Platform *platform);
	bool checkFallDirection();
	void jump(Platform *platform);
};