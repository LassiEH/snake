#include "Snake.h"

Snake::Snake(COORD pos, int velocity)
{
	this->pos = pos;
	this->velocity = velocity;
	lenght = 1;
	direction = 'n';
}

void Snake::change_direction(char dir) { direction = dir; }

void Snake::move_snake()
{
	switch (direction)
	{
	case 'u': pos.Y -= velocity; break;
	case 'd': pos.Y += velocity; break;
	case 'l': pos.X -= velocity; break;
	case 'r': pos.X += velocity; break;
	}
}
