#pragma once

#include <string>

using std::string;

/// <summary>
/// Класс, инициализирующий настройки приложения
/// </summary>
class GameConfig
{

public:
	GameConfig();
	void initScreenConfiguration();
	int getScreenWidth();
	int getScreenHeight();
	int getScreenFramerate();
	string getWindowIconPath();
	string getProjectTitle();

private:
	int screenWidth;
	int screenHeight;
	int screenFramerate;
	string projectTitle;
	string windowIconPath;
};