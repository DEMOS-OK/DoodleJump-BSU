
#include "vector";
#include "SFML/Graphics.hpp";

#include "GameView.h";
#include "../classes/Doodler.h";
#include "../classes/Platform.h";
#include "../classes/ImageButton.h";

using std::vector;
using namespace sf;

/// <summary>
/// Конструктор класса-представления игры
/// </summary>
/// <param name="config"></param>
GameView::GameView(GameConfig* config)
{
	// Создаём объект окна
	RenderWindow window;

	// Инициализируем объект конфигурации
	this->config = config;

	Doodler doodler;

	// Запускаем инициализацию отображения
	this->initScreenSettings();
	this->initGameBackground();
	this->initMenuButtons();
	this->initMenuBackground();
}

/// <summary>
/// Инициализация настроек экрана
/// </summary>
void GameView::initScreenSettings()
{
	// Устанавливаем настройки окна
	window.create(sf::VideoMode(this->config->getScreenWidth(),
		this->config->getScreenHeight()), this->config->getProjectTitle(), sf::Style::Close);

	// Устанавливаем ограничение частоты кадров
	window.setFramerateLimit(this->config->getScreenFramerate());

	// Устанавливаем иконку
	Image image = Image{};
	image.loadFromFile(this->config->getWindowIconPath());
	window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());
}

void GameView::initGameBackground()
{
	// Создаем текстуру фонового изображения
	backgroundGameTexture.loadFromFile("data/background.png");

	auto textureSize = backgroundGameTexture.getSize(); // Получаем размер текстуры
	auto windowSize = window.getSize(); // Получаем размер окна

	float scaleX = (float) windowSize.x / textureSize.x;
	float scaleY = (float) windowSize.y / textureSize.y; // Рассчитываем параметры скалирования

	// Связываем спрайт и текстуру
	backgroundGameSprite.setTexture(backgroundGameTexture);
	backgroundGameSprite.setScale(scaleX, scaleY); // Скалируем изображение
}

/// <summary>
/// Инициализирует фоновое изображение меню
/// </summary>
void GameView::initMenuBackground()
{
	// Создаем текстуру фонового изображения
	backgroundMenuTexture.loadFromFile("data/menu_background.png");

	auto textureSize = backgroundMenuTexture.getSize(); // Получаем размер текстуры
	auto windowSize = window.getSize(); // Получаем размер окна

	float scaleX = (float) windowSize.x / textureSize.x;
	float scaleY = (float) windowSize.y / textureSize.y; // Рассчитываем параметры скалирования

	// Связываем спрайт и текстуру
	backgroundMenuSprite.setTexture(backgroundMenuTexture);
	backgroundMenuSprite.setScale(scaleX, scaleY); // Скалируем изображение
}

/// <summary>
/// Инициализирует кнопки меню
/// </summary>
void GameView::initMenuButtons()
{
	float posX = this->config->getScreenWidth() / 2;
	float posY = this->config->getScreenHeight() / 2;

	this->playBtn = new ImageButton(posX, posY, "data/play_btn.png", "data/play_btn_hover.png");
}

/// <summary>
/// Возвращает спрайт кнопки запуска игры
/// </summary>
/// <returns></returns>
ImageButton* GameView::getPlayBtn()
{
	return playBtn;
}

/// <summary>
/// Возвращает объект окна
/// </summary>
/// <returns></returns>
sf::RenderWindow& GameView::getWindow()
{
	return window;
}

/// <summary>
/// Занимается отрисовкой элементов на экране
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
/// Занимается отрисовкой элементов меню
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