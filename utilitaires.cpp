#include "utilitaires.h"

int random(int min, int max)
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<> distance(min, max);
	return distance(rng);
}
