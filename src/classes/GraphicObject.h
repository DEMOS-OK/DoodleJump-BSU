#pragma once

#include "SFML/Graphics.hpp";

using namespace sf;

/// <summary>
/// ����������� ����� ������������ �������, ������������� �� ������
/// </summary>
class GraphicObject
{
public:
	// ������� ������������ ������� �� ������
	Vector2f position;

	// ������ ������������ �������
	Sprite sprite;

	// �������� ������������ �������
	Texture texture;

	// ����������� �����, ������� � �������� ������ ������ ���������� ������ �������
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