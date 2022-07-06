
// Подключение используемых компонентов
#include "SFML/Graphics.hpp";
#include "GameController.h";
#include "GameView.h";

/// <summary>
/// Конструктор класса GameController
/// </summary>
/// <param name="view"> объект, занимающийся отображением графики приложения </param>
GameController::GameController(GameView *view, GameModel *model)
{
    this->view = view;
    this->model = model;
}

/// <summary>
/// Запускает основной цикл приложения, обновление объектов, обработку событий, отрисовку объектов
/// </summary>
void GameController::run()
{
    // Запуск основного цикла приложения
    while (view->getWindow().isOpen())
    {
        this->checkGlobalEvents(); // Слушание и обработка событий

        if (model->gameStatus) {
            this->checkGameEvents();
            this->update();
            view->renderGame(&model->doodler, &model->platforms, model->getScore()); // Отрисовка приложения
        } else {
            this->checkMenuEvents();
            view->renderMenu();
        }

    }
}

/// <summary>
/// Проверяет все события
/// </summary>
void GameController::checkGlobalEvents()
{
    Event event; // Инициализация объекта события
    while (view->getWindow().pollEvent(event)) // Цикл, слушающих события
    {
        if (event.type == Event::Closed)
            view->getWindow().close();

    }
}

/// <summary>
/// Отслеживание событий главного меню
/// </summary>
void GameController::checkMenuEvents()
{
    float posX = Mouse::getPosition(view->getWindow()).x;
    float posY = Mouse::getPosition(view->getWindow()).y;

    if (view->getPlayBtn()->checkMousePosition(posX, posY)) {
        view->getPlayBtn()->setPlayBtnHover();
        
        if (Mouse::isButtonPressed(Mouse::Left))
            model->initGame();
    } else {
        view->getPlayBtn()->setPlayBtnDefault();
    }
}

void GameController::checkGameEvents()
{
    this->checkDoodlerEvents();
}

/// <summary>
/// Проверяет события объекта doodler
/// </summary>
void GameController::checkDoodlerEvents()
{
    // Обрабатываем нажатие клавиш движения
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        model->doodler.moveLeft();
    } else {
        model->doodler.stopLeft();
    }

    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        model->doodler.moveRight();
    } else {
        model->doodler.stopRight();
    }
}

/// <summary>
/// Обновляет все игровые объекты
/// </summary>
void GameController::update()
{
    model->update();
}