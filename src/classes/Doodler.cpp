#include <iostream>
#include <vector>
#include "Doodler.h";

using std::vector;
using namespace sf;

/// <summary>
/// ����������� ������ Doodler
/// </summary>
Doodler::Doodler()
{
	this->initProperties();
	this->initSprite();
	this->setPosition(660, 100);
}

/// <summary>
/// ������������� ������� �������
/// </summary>
void Doodler::initProperties()
{
	scaleX = 0.9;
	scaleY = 0.9;

	rightPressed = false;
	leftPressed = false;

	speedX = 10;
	speedY = 1.5;

	directionLeft = true;
	directionRight = false;

	gravitySpeedUp = 0.25;

	onJumpSpeedY = -10;
}

/// <summary>
/// ������������� ����������� �������
/// </summary>
void Doodler::initSprite()
{
	// ��������� ��������, ��������� ������ � ��������
	texture.loadFromFile("data/doodler-left.png");
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setScale(scaleX, scaleY);
}


/// <summary>
/// ������������� ������� �������
/// </summary>
void Doodler::setPosition(float posX, float posY)
{
	position.x = posX;
	position.y = posY;
	sprite.setPosition(position);
}

/// <summary>
/// ���������� ������ Sprite ��� ���������
/// </summary>
/// <returns></returns>
Sprite Doodler::getSprite()
{
	return sprite;
}

/// <summary>
/// ��������� �������
/// </summary>
void Doodler::update(vector<Platform*>* platforms)
{
	for (size_t i = 0; i < platforms->size(); i++) {
		if (this->checkCollisions((*platforms)[i]) && this->checkFallDirection()) {
			this->jump((*platforms)[i]);
		}
	}

	this->move();
	sprite.setPosition(position);
}

/// <summary>
/// �������� �� �������� �������
/// </summary>
void Doodler::move()
{
	position.y = position.y + speedY; // ������� �������

	if (rightPressed) // �������� ������
		position.x += speedX;

	if (leftPressed) // �������� �����
		position.x -= speedX;

	speedY += this->gravitySpeedUp; // ���������� �������� �������
}

/// <summary>
/// ��������� �������� ������
/// </summary>
void Doodler::moveRight()
{
	this->changeDirectionRight();
	rightPressed = true;
}

/// <summary>
/// ������ ������ ��� �����������
/// </summary>
void Doodler::changeDirectionRight()
{
	if (jumpImg || !directionRight) {
		texture.loadFromFile("data/doodler-right.png");
		jumpImg = false;
	}

	if (!directionRight) {
		directionRight = true;
		directionLeft = false;
	}
}

/// <summary>
/// ������������� �������� ������
/// </summary>
void Doodler::stopRight()
{
	rightPressed = false;
}

/// <summary>
/// ��������� �������� �����
/// </summary>
void Doodler::moveLeft()
{
	this->changeDirectionLeft();
	leftPressed = true;
}

/// <summary>
/// ������ ������ ��� �����������
/// </summary>
void Doodler::changeDirectionLeft()
{
	if (jumpImg || !directionLeft) {
		texture.loadFromFile("data/doodler-left.png");
		jumpImg = false;
	}
	if (!directionLeft) {
		directionRight = false;
		directionLeft = true;
	}
}

/// <summary>
/// ������������� �������� �����
/// </summary>
void Doodler::stopLeft()
{
	leftPressed = false;
}

/// <summary>
/// ���������� ���������� ������ ������� �������
/// </summary>
/// <returns>float</returns>
float Doodler::bottom()
{
	return position.y + (texture.getSize().y * scaleY);
}

float Doodler::right()
{
	return position.x + (texture.getSize().x * scaleX);
}

float Doodler::left()
{
	return position.x;
}

float Doodler::width()
{
	return texture.getSize().x * scaleX;
}

float Doodler::getSpeedY()
{
	return this->speedY;
}

/// <summary>
/// ���������� ��������� ������������ � �����������
/// </summary>
/// <param name="platform"></param>
/// <returns></returns>
bool Doodler::checkCollisions(Platform *platform)
{
	return (this->bottom() > platform->top() && this->bottom() < platform->bottom())
		&& (this->left() < platform->right())
		&& (this->right() > platform->left());
}

/// <summary>
/// ������ ��������� "������"
/// </summary>
/// <param name="platform"></param>
void Doodler::jump(Platform *platform)
{
	if (directionLeft)
		texture.loadFromFile("data/doodler-left-jump.png");
	else
		texture.loadFromFile("data/doodler-right-jump.png");

	jumpImg = true;
	position.y = platform->top() - 1 - texture.getSize().y * scaleY;
	this->speedY = this->onJumpSpeedY;
}

/// <summary>
/// ��������� ����������� �������� �� Y
/// </summary>
/// <returns>true, ���� ������ �������� ����</returns>
bool Doodler::checkFallDirection()
{
	return this->speedY >= 0;
}
