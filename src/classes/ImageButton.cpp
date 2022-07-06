#include "ImageButton.h";

ImageButton::ImageButton()
{

}

/// <summary>
/// Конструктор класса кнопки. Здесь происходит инициализация основных свойств
/// </summary>
ImageButton::ImageButton(float posX, float posY, std::string imgDefault, std::string imgHover)
{
	this->textureDefaultPath = imgDefault;
	this->textureHoverPath = imgHover;

	this->initProperties();
	this->initSprite();
	this->setPosition(posX, posY);
}

void ImageButton::initProperties()
{
	scaleX = 1;
	scaleY = 1;
}

/// <summary>
/// Инициализация изображения
/// </summary>
void ImageButton::initSprite()
{
	// Загружаем текстуру, связываем спрайт и текстуру
	texture.loadFromFile(this->textureDefaultPath);
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setScale(scaleX, scaleY);
}

/// <summary>
/// Инициализация позиции
/// </summary>
void ImageButton::setPosition(float posX, float posY)
{
	position.x = posX - texture.getSize().x / 2;
	position.y = posY - texture.getSize().y / 2;
	sprite.setPosition(position);
}

/// <summary>
/// Возвращает объект Sprite для отрисовки
/// </summary>
/// <returns></returns>
Sprite ImageButton::getSprite()
{
	return sprite;
}

/// <summary>
/// Возвращает указатель на текстуру
/// </summary>
/// <returns></returns>
Texture ImageButton::getTexture()
{
	return texture;
}

float ImageButton::width()
{
	return texture.getSize().x * scaleX;
}

float ImageButton::height()
{
	return texture.getSize().y * scaleY;
}

float ImageButton::top()
{
	return position.y;
}

float ImageButton::right()
{
	return position.x + this->width();
}

float ImageButton::left()
{
	return position.x;
}

float ImageButton::bottom()
{
	return position.y + this->height();
}

bool ImageButton::checkMousePosition(float posX, float posY)
{
	return posX >= this->left() && posX <= this->right() && posY >= this->top() && posY <= this->bottom();
}

void ImageButton::setPlayBtnDefault()
{
	texture.loadFromFile(this->textureDefaultPath);
}

void ImageButton::setPlayBtnHover()
{
	texture.loadFromFile(this->textureHoverPath);
}