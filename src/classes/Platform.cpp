#include "Platform.h";


/// <summary>
/// ����������� ������ ���������. ����� ���������� ������������� �������� �������
/// </summary>
Platform::Platform(float posX, float posY)
{
	this->initProperties();
	this->initSprite();
	this->setPosition(posX, posY);
}

/// <summary>
/// ������������� ����������
/// </summary>
void Platform::initProperties()
{
	scaleX = 0.6;
	scaleY = 0.6;

	speedY = 0;

	gravitySpeedUp = 0.15;
}

/// <summary>
/// ������������� �����������
/// </summary>
void Platform::initSprite()
{
	// ��������� ��������, ��������� ������ � ��������
	texture.loadFromFile("data/platform.png");
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setScale(scaleX, scaleY);
}


/// <summary>
/// ������������� �������
/// </summary>
void Platform::setPosition(float posX, float posY)
{
	position.x = posX;
	position.y = posY;
	sprite.setPosition(position);
}

/// <summary>
/// ���������� ������ Sprite ��� ���������
/// </summary>
/// <returns></returns>
Sprite Platform::getSprite()
{
	return sprite;
}

/// <summary>
/// ���������� ��������� �� �������� ���������
/// </summary>
/// <returns></returns>
Texture Platform::getTexture()
{
	return texture;
}

float Platform::width()
{
	return texture.getSize().x * scaleX;
}

float Platform::height()
{
	return texture.getSize().y * scaleY;
}

float Platform::top()
{
	return position.y;
}

float Platform::right()
{
	return position.x + this->width();
}

float Platform::left()
{
	return position.x;
}

float Platform::bottom()
{
	return position.y + this->height();
}

void Platform::update()
{
	this->move();
}

void Platform::setSpeedY(float speedY)
{
	this->speedY = speedY;
}

void Platform::move()
{
	position.y -= speedY;
	sprite.setPosition(position);
	if (speedY != 0) {
		this->speedY -= this->gravitySpeedUp;
	}

}