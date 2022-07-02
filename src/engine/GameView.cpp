
#include "vector";
#include "SFML/Graphics.hpp";

#include "GameView.h";
#include "../classes/Doodler.h";
#include "../classes/Platform.h";

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
	this->initBackground();
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

void GameView::initBackground()
{
	// Создаем текстуру фонового изображения
	backgroundTexture.loadFromFile("data/background.png");

	auto textureSize = backgroundTexture.getSize(); // Получаем размер текстуры
	auto windowSize = window.getSize(); // Получаем размер окна

	float scaleX = (float) windowSize.x / textureSize.x;
	float scaleY = (float) windowSize.y / textureSize.y; // Рассчитываем параметры скалирования

	// Связываем спрайт и текстуру
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setScale(scaleX, scaleY); // Скалируем изображение
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
void GameView::render(Doodler *doodler, vector<Platform*>* platforms)
{
	window.clear(); 
	
	window.draw(backgroundSprite);
	window.draw(doodler->getSprite());

	for (short i = 0; i < platforms->size(); i++)
		window.draw((*platforms)[i]->getSprite());

	window.display();
}
