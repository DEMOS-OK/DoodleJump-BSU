
#include "vector";
#include "SFML/Graphics.hpp";

#include "GameView.h";
#include "../classes/Doodler.h";
#include "../classes/Platform.h";

using std::vector;
using namespace sf;

/// <summary>
/// ����������� ������-������������� ����
/// </summary>
/// <param name="config"></param>
GameView::GameView(GameConfig* config)
{
	// ������ ������ ����
	RenderWindow window;

	// �������������� ������ ������������
	this->config = config;

	Doodler doodler;

	// ��������� ������������� �����������
	this->initScreenSettings();
	this->initBackground();
}

/// <summary>
/// ������������� �������� ������
/// </summary>
void GameView::initScreenSettings()
{
	// ������������� ��������� ����
	window.create(sf::VideoMode(this->config->getScreenWidth(),
		this->config->getScreenHeight()), this->config->getProjectTitle(), sf::Style::Close);

	// ������������� ����������� ������� ������
	window.setFramerateLimit(this->config->getScreenFramerate());

	// ������������� ������
	Image image = Image{};
	image.loadFromFile(this->config->getWindowIconPath());
	window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());
}

void GameView::initBackground()
{
	// ������� �������� �������� �����������
	backgroundTexture.loadFromFile("data/background.png");

	auto textureSize = backgroundTexture.getSize(); // �������� ������ ��������
	auto windowSize = window.getSize(); // �������� ������ ����

	float scaleX = (float) windowSize.x / textureSize.x;
	float scaleY = (float) windowSize.y / textureSize.y; // ������������ ��������� ������������

	// ��������� ������ � ��������
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setScale(scaleX, scaleY); // ��������� �����������
}

/// <summary>
/// ���������� ������ ����
/// </summary>
/// <returns></returns>
sf::RenderWindow& GameView::getWindow()
{
	return window;
}

/// <summary>
/// ���������� ���������� ��������� �� ������
/// </summary>
void GameView::render(Doodler *doodler, vector<Platform*>* platforms)
{
	window.clear(); 
	
	window.draw(backgroundSprite);
	window.draw(doodler->getSprite());

	for (short i = 0; i < platforms->size(); i++)
		window.draw((*platforms)[i]->getSprite());

	window.display();
}
