
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
        this->checkGlobalEvents(); // �������� � ��������� �������

        if (model->gameStatus) {
            this->checkGameEvents();
            this->update();
            view->renderGame(&model->doodler, &model->platforms, model->getScore()); // ��������� ����������
        } else {
            this->checkMenuEvents();
            view->renderMenu();
        }

    }
}

/// <summary>
/// ��������� ��� �������
/// </summary>
void GameController::checkGlobalEvents()
{
    Event event; // ������������� ������� �������
    while (view->getWindow().pollEvent(event)) // ����, ��������� �������
    {
        if (event.type == Event::Closed)
            view->getWindow().close();

    }
}

/// <summary>
/// ������������ ������� �������� ����
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
    model->update();
}