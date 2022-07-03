#pragma once

#include <vector>
#include "GameConfig.h";
#include "../classes/Doodler.h";
#include "../classes/Platform.h";

using std::vector;


/// <summary>
/// Класс модели, содержит в себе основную логику игры
/// </summary>
class GameModel
{

public:
	GameModel(GameConfig* config);

	// Класс дудлера
	Doodler doodler;

	// Вектор с указателями на платформы
	vector<Platform*> platforms;

	void update();


protected:
	
	// Класс с настройками игры
	GameConfig* config;

	const int PLATFORMS_COUNT = 8;

	void initGameObjects();
	void initPlatformsFreePositions();

	// Метод, обновляющий позицию камеры
	void updateCamera();

	void checkPlatformsPositions();

	void checkDoodlerPosition();

	vector<int> platformsFreePositionsX;
	vector<int> platformsFreePositionsY;

};