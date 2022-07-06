#pragma once

#include <vector>
#include "GameConfig.h";
#include "../classes/Doodler.h";
#include "../classes/Platform.h";

using std::vector;


/// <summary>
/// ����� ������, �������� � ���� �������� ������ ����
/// </summary>
class GameModel
{

public:
	GameModel(GameConfig* config);

	// ����� �������
	Doodler doodler;

	// ������ � ����������� �� ���������
	vector<Platform*> platforms;

	void initGame();

	void update();

	int getScore();

	bool gameStatus = 0;

protected:
	
	// ����� � ����������� ����
	GameConfig* config;

	const int PLATFORMS_COUNT = 8;
	int score;

	void initGameObjects();
	void initPlatformsFreePositions();

	// �����, ����������� ������� ������
	void updateCamera();

	void checkPlatformsPositions();

	void checkDoodlerPosition();

	vector<int> platformsFreePositionsX;
	vector<int> platformsFreePositionsY;

};