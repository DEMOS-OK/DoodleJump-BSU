#include "GameModel.h";
#include "../engine/helpers.h";

/// <summary>
/// Конструктор класса модели
/// </summary>
/// <param name="config"> GameConfig класс конфигурации </param>
GameModel::GameModel(GameConfig* config)
{
	this->config = config;

	this->initPlatformsFreePositions();
	this->initGameObjects();
}

void GameModel::initPlatformsFreePositions()
{
	Platform platform(0, 0);

	for (int pos = 0; pos < this->config->getScreenWidth() - platform.width(); pos += platform.width() + 20)
		this->platformsFreePositionsX.push_back(pos);

	for (int pos = 0; pos < this->config->getScreenHeight() - platform.height(); pos += platform.height()*2)
		this->platformsFreePositionsY.push_back(pos);

}

/// <summary>
/// Инициализирует игровые объекты
/// </summary>
void GameModel::initGameObjects()
{
	for (short i = 0; i < PLATFORMS_COUNT; i++) {
		short posXIndex = helpers::randint(0, this->platformsFreePositionsX.size() - 1);
		short posYIndex = helpers::randint(0, this->platformsFreePositionsY.size() - 1);
		float posX = this->platformsFreePositionsX.at(posXIndex);
		float posY = this->platformsFreePositionsY.at(posYIndex);
		this->platforms.push_back(new Platform(posX, posY));
		this->platformsFreePositionsX.erase(this->platformsFreePositionsX.begin() + posXIndex);
		this->platformsFreePositionsY.erase(this->platformsFreePositionsY.begin() + posYIndex);
	}
}

/// <summary>
/// Следит за игровыми объектами
/// </summary>
void GameModel::update()
{
	this->updateCamera();
	this->checkPlatformsPositions();
	this->checkDoodlerPosition();
}


/// <summary>
/// Обновляет положение камеры
/// </summary>
void GameModel::updateCamera()
{
	float doodlerSpeedY = this->doodler.getSpeedY();

	if ((doodlerSpeedY < 0 && (this->doodler.bottom() < this->config->getScreenHeight() * 0.5))) {
		for (auto platform : this->platforms) {
			platform->setSpeedY(doodlerSpeedY*2);
			platform->update();
		}
	}
}

/// <summary>
/// Проверяет позиции платформ, меняет позицию, если платформа ушла вниз
/// </summary>
void GameModel::checkPlatformsPositions()
{
	for (auto platform : this->platforms) {
		if (platform->top() > this->config->getScreenHeight()) {
			float posX = helpers::randint(this->config->getScreenWidth() * 0.1, this->config->getScreenWidth() * 0.9);
			float posY = helpers::randint(-this->config->getScreenHeight()*0.1, 0);
			platform->setPosition(posX, posY);
		}
	}
}

/// <summary>
/// Проверяет позицию дудлера (выходы за границы)
/// </summary>
void GameModel::checkDoodlerPosition()
{
	if (this->doodler.right() < 0)
		this->doodler.setPosition(this->config->getScreenWidth() - this->doodler.width(), this->doodler.getSprite().getPosition().y);
	else if (this->doodler.left() > this->config->getScreenWidth())
		this->doodler.setPosition(0, this->doodler.getSprite().getPosition().y);
}