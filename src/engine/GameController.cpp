
// ����������� ������������ �����������
#include "SFML/Graphics.hpp";
#include "GameController.h";
#include "GameView.h";

/// <summary>
/// ����������� ������ GameController
/// </summary>
/// <param name="view"> ������, ������������ ������������ ������� ���������� </param>
GameController::GameController(GameView *view, GameModel *model)
{
    this->view = view;
    this->model = model;
}

/// <summary>
/// ��������� �������� ���� ����������, ���������� ��������, ��������� �������, ��������� ��������
/// </summary>
void GameController::run()
{
    // ������ ��������� ����� ����������
    while (view->getWindow().isOpen())
    {
        this->checkEvents(); // �������� � ��������� �������

        this->update();
        view->render(&model->doodler, &model->platforms); // ��������� ����������
    }
}

/// <summary>
/// ��������� ��� �������
/// </summary>
void GameController::checkEvents()
{
    sf::Event event; // ������������� ������� �������
    while (view->getWindow().pollEvent(event)) // ����, ��������� �������
    {
        if (event.type == sf::Event::Closed)
            view->getWindow().close();

        this->checkDoodlerEvents();
    }
}

/// <summary>
/// ��������� ������� ������� doodler
/// </summary>
void GameController::checkDoodlerEvents()
{
    // ������������ ������� ������ ��������
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
/// ��������� ��� ������� �������
/// </summary>
void GameController::update()
{
    model->doodler.update(&model->platforms);
    model->updateCamera();
}