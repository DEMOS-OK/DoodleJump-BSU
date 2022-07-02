#include "GameModel.h";
#include "../engine/helpers.h";

/// <summary>
/// ����������� ������ ������
/// </summary>
/// <param name="config"> GameConfig ����� ������������ </param>
GameModel::GameModel(GameConfig* config)
{
	this->config = config;

	this->initGameObjects();
}

/// <summary>
/// �������������� ������� �������
/// </summary>
void GameModel::initGameObjects()
{
	for (short i = 0; i < PLATFORMS_COUNT; i++) {
		float posX = helpers::randint(this->config->getScreenWidth() * 0.1, this->config->getScreenWidth()*0.9);
		float posY = helpers::randint(this->config->getScreenHeight() * 0.1, this->config->getScreenHeight() * 0.75);
		this->platforms.push_back(new Platform(posX, posY));
	}
}

void GameModel::update()
{
	this->updateCamera();
	this->checkPlatformsPositions();
}


void GameModel::updateCamera()
{
	float doodlerSpeedY = this->doodler.getSpeedY();

	if (doodlerSpeedY < 0 && (this->doodler.bottom() < this->config->getScreenHeight() * 0.5)) {
		for (auto platform : this->platforms) {
			platform->setSpeedY(doodlerSpeedY);
			platform->update();
		}
	}
}

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