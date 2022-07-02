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

protected:
	void virtual initSprite() = 0;
	void virtual initPosition(float posX, float posY) = 0;

};