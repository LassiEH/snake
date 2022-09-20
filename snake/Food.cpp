#include "Food.h"

#define WIDTH 50
#define HEIGHT 25

void Food::gen_food()
{
	position.X = (rand() % WIDTH - 3) + 1;
	position.Y = (rand() % HEIGHT - 3) + 1;
}

COORD Food::get_position() { return position; }