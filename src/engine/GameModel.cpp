#include "GameModel.h";
#include "../engine/helpers.h";

/// <summary>
/// Конструктор класса модели
/// </summary>
/// <param name="config"> GameConfig класс конфигурации </param>
GameModel::GameModel(GameConfig* config)
{
	this->config = config;

	this->initGameObjects();
}

/// <summary>
/// Инициализирует игровые объекты
/// </summary>
void GameModel::initGameObjects()
{
	for (short i = 0; i < PLATFORMS_COUNT; i++) {
		float posX = helpers::randint(this->config->getScreenWidth() * 0.1, this->config->getScreenWidth()*0.9);
		float posY = helpers::randint(this->config->getScreenHeight() * 0.25, this->config->getScreenHeight() * 0.75);
		this->platforms.push_back(new Platform(posX, posY));
	}
}

void GameModel::updateCamera()
{
	float doodlerSpeedY = this->doodler.getSpeedY();

	if (doodlerSpeedY < 0)
		for (auto platform : this->platforms) {
			platform->setSpeedY(doodlerSpeedY);
			platform->update();
		}
}