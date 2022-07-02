#include "engine/GameController.h";
#include "engine/GameConfig.h";
#include "engine/GameView.h";
#include "engine/GameModel.h";


int main()
{
	srand(time(NULL));

	// ������ ����� � ����������� ����������
	GameConfig config;

	// ������ ����� ������
	GameModel model(&config);

	// ������ �����-�������������
	GameView view(&config);

	// ��������� ����������
	GameController controller(&view, &model);
	controller.run();

    return 0;
}