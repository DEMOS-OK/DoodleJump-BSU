
#include "vector";
#include "SFML/Graphics.hpp";

#include "GameView.h";
#include "../classes/Doodler.h";
#include "../classes/Platform.h";
#include "../classes/ImageButton.h";

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
	this->initGameBackground();
	this->initMenuButtons();
	this->initMenuBackground();
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

void GameView::initGameBackground()
{
	// ������� �������� �������� �����������
	backgroundGameTexture.loadFromFile("data/background.png");

	auto textureSize = backgroundGameTexture.getSize(); // �������� ������ ��������
	auto windowSize = window.getSize(); // �������� ������ ����

	float scaleX = (float) windowSize.x / textureSize.x;
	float scaleY = (float) windowSize.y / textureSize.y; // ������������ ��������� ������������

	// ��������� ������ � ��������
	backgroundGameSprite.setTexture(backgroundGameTexture);
	backgroundGameSprite.setScale(scaleX, scaleY); // ��������� �����������
}

/// <summary>
/// �������������� ������� ����������� ����
/// </summary>
void GameView::initMenuBackground()
{
	// ������� �������� �������� �����������
	backgroundMenuTexture.loadFromFile("data/menu_background.png");

	auto textureSize = backgroundMenuTexture.getSize(); // �������� ������ ��������
	auto windowSize = window.getSize(); // �������� ������ ����

	float scaleX = (float) windowSize.x / textureSize.x;
	float scaleY = (float) windowSize.y / textureSize.y; // ������������ ��������� ������������

	// ��������� ������ � ��������
	backgroundMenuSprite.setTexture(backgroundMenuTexture);
	backgroundMenuSprite.setScale(scaleX, scaleY); // ��������� �����������
}

/// <summary>
/// �������������� ������ ����
/// </summary>
void GameView::initMenuButtons()
{
	float posX = this->config->getScreenWidth() / 2;
	float posY = this->config->getScreenHeight() / 2;

	this->playBtn = new ImageButton(posX, posY, "data/play_btn.png", "data/play_btn_hover.png");
}

/// <summary>
/// ���������� ������ ������ ������� ����
/// </summary>
/// <returns></returns>
ImageButton* GameView::getPlayBtn()
{
	return playBtn;
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
void GameView::renderGame(Doodler *doodler, vector<Platform*>* platforms, int score)
{
	window.clear(); 
	
	window.draw(backgroundGameSprite);
	window.draw(doodler->getSprite());

	for (short i = 0; i < platforms->size(); i++)
		window.draw((*platforms)[i]->getSprite());

	Label scoreLabel("data/VinSlabPro.ttf", "Score: " + std::to_string(score), 20, 20, 30);
	window.draw(*(scoreLabel.getText()));

	window.display();
}

/// <summary>
/// ���������� ���������� ��������� ����
/// </summary>
void GameView::renderMenu()
{
	window.clear();

	window.draw(backgroundMenuSprite);
	window.draw(playBtn->getSprite());

	Label gameTitle("data/VinSlabPro.ttf", "Doodle Jump", 20, 20, 30);
	window.draw(*(gameTitle.getText()));

	window.display();
}