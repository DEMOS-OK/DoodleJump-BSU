#include "engine/GameController.h";
#include "engine/GameConfig.h";
#include "engine/GameView.h";
#include "engine/GameModel.h";


int main()
{
	srand(time(NULL));

	// Создаём класс с настройками приложения
	GameConfig config;

	// Создаём класс модели
	GameModel model(&config);

	// Создаём класс-представление
	GameView view(&config);

	// Запускаем приложение
	GameController controller(&view, &model);
	controller.run();

    return 0;
}