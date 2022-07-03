#include <iostream>
#include <vector>
#include "Doodler.h";

using std::vector;
using namespace sf;

/// <summary>
/// Конструктор класса Doodler
/// </summary>
Doodler::Doodler()
{
	this->initProperties();
	this->initSprite();
	this->setPosition(660, 100);
}

/// <summary>
/// Инициализация свойств дудлера
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
/// Инициализация изображения дудлера
/// </summary>
void Doodler::initSprite()
{
	// Загружаем текстуру, связываем спрайт и текстуру
	texture.loadFromFile("data/doodler-left.png");
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setScale(scaleX, scaleY);
}


/// <summary>
/// Инициализация позиции дудлера
/// </summary>
void Doodler::setPosition(float posX, float posY)
{
	position.x = posX;
	position.y = posY;
	sprite.setPosition(position);
}

/// <summary>
/// Возвращает объект Sprite для отрисовки
/// </summary>
/// <returns></returns>
Sprite Doodler::getSprite()
{
	return sprite;
}

/// <summary>
/// Обновляет дудлера
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
/// Отвечает за движение дудлера
/// </summary>
void Doodler::move()
{
	position.y = position.y + speedY; // Падение дудлера

	if (rightPressed) // Движение вправо
		position.x += speedX;

	if (leftPressed) // Движение влево
		position.x -= speedX;

	speedY += this->gravitySpeedUp; // Увеличение скорости падения
}

/// <summary>
/// Запускает движение вправо
/// </summary>
void Doodler::moveRight()
{
	this->changeDirectionRight();
	rightPressed = true;
}

/// <summary>
/// Дудлер меняет своё направление
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
/// Останавливает движение вправо
/// </summary>
void Doodler::stopRight()
{
	rightPressed = false;
}

/// <summary>
/// Запускает движение влево
/// </summary>
void Doodler::moveLeft()
{
	this->changeDirectionLeft();
	leftPressed = true;
}

/// <summary>
/// Дудлер меняет своё направление
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
/// Останавливает движение влево
/// </summary>
void Doodler::stopLeft()
{
	leftPressed = false;
}

/// <summary>
/// Возвращает координату нижней границы Дудлера
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
/// Возвращает результат столкновений с платформами
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
/// Дудлер выполняет "прыжок"
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
/// Проверяет направление скорости по Y
/// </summary>
/// <returns>true, если дудлер движется вниз</returns>
bool Doodler::checkFallDirection()
{
	return this->speedY >= 0;
}
