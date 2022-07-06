#pragma once

#include <vector>
#include "SFML/Graphics.hpp";

#include "GameConfig.h";
#include "../classes/Doodler.h";
#include "../classes/Platform.h";
#include "../classes/Label.h";
#include "../classes/ImageButton.h";

using std::vector;
using namespace sf;

/// <summary>
/// Класс-представление игры, занимается отображением элементов на экране
/// </summary>
class GameView
{

public:
	GameView(GameConfig *config);
	void renderGame(Doodler *doodler, vector<Platform*>* platforms, int score);
	void renderMenu();
	RenderWindow& getWindow();

	ImageButton* getPlayBtn();

private:
	GameConfig* config;
	RenderWindow window;

	Sprite backgroundGameSprite;
	Texture backgroundGameTexture;

	Sprite backgroundMenuSprite;
	Texture backgroundMenuTexture;

	ImageButton* playBtn;

	void initScreenSettings();
	void initGameBackground();
	void initMenuBackground();
	void initMenuButtons();
};