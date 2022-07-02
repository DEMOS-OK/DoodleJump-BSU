#include <ctime>
#include <random>

namespace helpers {

	/// <summary>
	/// ¬озвращает случайное число из промежутка
	/// </summary>
	/// <param name="min"></param>
	/// <param name="max"></param>
	/// <returns></returns>
	int randint(int min, int max)
	{
		return min + (rand() % (max - min + 1));
	}
}