#include "Food.h"

#define WIDTH 50
#define HEIGHT 25

Food::Food()
{
	gen_food();
}

void Food::gen_food()
{
	position.X = rand() % WIDTH + 1;
	position.Y = rand() % HEIGHT + 1;
}

COORD Food::get_position() { return position; }