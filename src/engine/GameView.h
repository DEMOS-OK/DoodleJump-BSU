#pragma once

#include <vector>
#include "SFML/Graphics.hpp";

#include "GameConfig.h";
#include "../classes/Doodler.h";
#include "../classes/Platform.h";

using std::vector;
using namespace sf;

/// <summary>
/// Класс-представление игры, занимается отображением элементов на экране
/// </summary>
class GameView
{

public:
	GameView(GameConfig *config);
	void render(Doodler *doodler, vector<Platform*>* platforms);
	RenderWindow& getWindow();

private:
	GameConfig* config;
	RenderWindow window;

	Sprite backgroundSprite;
	Texture backgroundTexture;

	void initScreenSettings();
	void initBackground();


};