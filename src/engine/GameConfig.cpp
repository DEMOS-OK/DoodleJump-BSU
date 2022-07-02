#include "GameConfig.h";

/// <summary>
/// ����������� ������ GameConfig. ����� ���������� ������������� ���� ���������� ����������
/// </summary>
GameConfig::GameConfig()
{
	this->initScreenConfiguration();
}

/// <summary>
/// ������������� �������� ����
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
/// ���������� �������� ������ ������
/// </summary>
/// <returns>int screenWidth</returns>
int GameConfig::getScreenWidth()
{
	return this->screenWidth;
}

/// <summary>
/// ���������� �������� ������ ������
/// </summary>
/// <returns>int screenHeight</returns>
int GameConfig::getScreenHeight()
{
	return this->screenHeight;
}

/// <summary>
/// ���������� ���������� ������� ���������� ������
/// </summary>
/// <returns></returns>
int GameConfig::getScreenFramerate()
{
	return this->screenFramerate;
}

/// <summary>
/// ���������� �������� ����������
/// </summary>
/// <returns>int projectTitle</returns>
string GameConfig::getProjectTitle()
{
	return this->projectTitle;
}

/// <summary>
/// ���������� ���� � ������ ���� 
/// </summary>
/// <returns>string windowIconPath</returns>
string GameConfig::getWindowIconPath()
{
	return this->windowIconPath;
}