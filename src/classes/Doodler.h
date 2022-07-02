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

	// �������� ����������� �� Y
	float speedY;

protected:
	// ������� �������
	Vector2f position;

	// ������ �������
	Sprite sprite;

	// �������� �������
	Texture texture;

	// �������� ������������ ������� �� X
	float scaleX;

	// �������� ������������ ������� �� Y
	float scaleY;
	
	// ���� ������� �� ������ �������� ������
	bool rightPressed;

	// ���� ������� �� ������ �������� �����
	bool leftPressed;

	// ����� ����������� �������� ������
	bool directionRight;

	// ���� ����������� �������� �����
	bool directionLeft;

	// �������� ����������� �� X
	float speedX;

	// ��������� ���������� �������
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