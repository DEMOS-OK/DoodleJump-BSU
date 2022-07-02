#include "GameConfig.h";

/// <summary>
/// Конструктор класса GameConfig. Здесь происходит инициализация всех параметров приложения
/// </summary>
GameConfig::GameConfig()
{
	this->initScreenConfiguration();
}

/// <summary>
/// Инициализация настроек окна
/// </summary>
void GameConfig::initScreenConfiguration()
{
	this->screenWidth = 1440;
	this->screenHeight = 768;
	this->screenFramerate = 60;
	this->projectTitle = "Doodle Jump BSU";
	this->windowIconPath = "data/icon.png";
}

/// <summary>
/// Возвращает значение ширины экрана
/// </summary>
/// <returns>int screenWidth</returns>
int GameConfig::getScreenWidth()
{
	return this->screenWidth;
}

/// <summary>
/// Возвращает значение высоты экрана
/// </summary>
/// <returns>int screenHeight</returns>
int GameConfig::getScreenHeight()
{
	return this->screenHeight;
}

/// <summary>
/// Возвращает допустимую частоту обновления экрана
/// </summary>
/// <returns></returns>
int GameConfig::getScreenFramerate()
{
	return this->screenFramerate;
}

/// <summary>
/// Возвращает название приложения
/// </summary>
/// <returns>int projectTitle</returns>
string GameConfig::getProjectTitle()
{
	return this->projectTitle;
}

/// <summary>
/// Возвращает путь к иконке окна 
/// </summary>
/// <returns>string windowIconPath</returns>
string GameConfig::getWindowIconPath()
{
	return this->windowIconPath;
}