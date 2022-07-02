#pragma once

#include <SFML/Graphics.hpp>
#include "GameView.h";
#include "GameModel.h";

/// <summary>
/// ���������� �����������, ��������� ����������
/// </summary>
class GameController
{

public:
	GameController(GameView* view, GameModel* model);
	void run();

private:
	// ������, ������������ ������������ �������� �� ������
	GameView* view;

	// ������ ����, �������� � ���� ������ ������ ����
	GameModel* model;

	void checkEvents();
	void checkDoodlerEvents();
	void update();

};