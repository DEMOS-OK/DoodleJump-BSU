#pragma once

#include <SFML/Graphics.hpp>
#include "GameView.h";
#include "GameModel.h";

/// <summary>
/// Контроллер прилложения, запускает приложение
/// </summary>
class GameController
{

public:
	GameController(GameView* view, GameModel* model);
	void run();

private:
	// Объект, занимающийся отображением объектов на экране
	GameView* view;

	// Модель игры, содержит в себе логику работы игры
	GameModel* model;

	void checkEvents();
	void checkDoodlerEvents();
	void update();

};