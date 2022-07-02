#include "Platform.h";


/// <summary>
/// Конструктор класса платформы. Здесь происходит инициализация основных свойств
/// </summary>
Platform::Platform(float posX, float posY)
{
	this->initProperties();
	this->initSprite();
	this->setPosition(posX, posY);
}

/// <summary>
/// Инициализация параметров
/// </summary>
void Platform::initProperties()
{
	scaleX = 0.6;
	scaleY = 0.6;

	speedY = 0;

	gravitySpeedUp = 0.15;
}

/// <summary>
/// Инициализация изображения
/// </summary>
void Platform::initSprite()
{
	// Загружаем текстуру, связываем спрайт и текстуру
	texture.loadFromFile("data/platform.png");
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setScale(scaleX, scaleY);
}


/// <summary>
/// Инициализация позиции
/// </summary>
void Platform::setPosition(float posX, float posY)
{
	position.x = posX;
	position.y = posY;
	sprite.setPosition(position);
}

/// <summary>
/// Возвращает объект Sprite для отрисовки
/// </summary>
/// <returns></returns>
Sprite Platform::getSprite()
{
	return sprite;
}

/// <summary>
/// Возвращает указатель на текстуру платформы
/// </summary>
/// <returns></returns>
Texture Platform::getTexture()
{
	return texture;
}

float Platform::top()
{
	return position.y;
}

float Platform::right()
{
	return position.x + (texture.getSize().x * scaleX);
}

float Platform::left()
{
	return position.x;
}

float Platform::bottom()
{
	return position.y + (texture.getSize().y * scaleY);
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