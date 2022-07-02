
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
        this->checkEvents(); // Слушание и обработка событий

        this->update();
        view->render(&model->doodler, &model->platforms); // Отрисовка приложения
    }
}

/// <summary>
/// Проверяет все события
/// </summary>
void GameController::checkEvents()
{
    sf::Event event; // Инициализация объекта события
    while (view->getWindow().pollEvent(event)) // Цикл, слушающих события
    {
        if (event.type == sf::Event::Closed)
            view->getWindow().close();

        this->checkDoodlerEvents();
    }
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
    model->doodler.update(&model->platforms);
    model->updateCamera();
}