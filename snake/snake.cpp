#include "Snake.h"

#define WIDTH 50
#define HEIGHT 25

Snake::Snake(COORD pos, int velocity)
{
	this->pos = pos;
	this->velocity = velocity;
	length = 1;
	direction = 'n';

	body.push_back(pos);
}

void Snake::change_direction(char dir) { direction = dir; }

vector<COORD> Snake::get_body() { return body; }

void Snake::move_snake()
{
	switch (direction)
	{
	case 'u': pos.Y -= velocity; break;
	case 'd': pos.Y += velocity; break;
	case 'l': pos.X -= velocity; break;
	case 'r': pos.X += velocity; break;
	}

	body.push_back(pos);
	if (body.size() > length) body.erase(body.begin());
}

COORD Snake::get_pos() { return pos; }

bool Snake::eaten(COORD food_position)
{
	if (food_position.X == pos.X && food_position.Y == pos.Y) return true;
	return false;
}

void Snake::grow() { length++; }

bool Snake::collided()
{
	if (pos.X < 1 || pos.X > WIDTH-2 || pos.Y < 1 || pos.Y > HEIGHT-2) return true;
	
	/*
	for (int i = 0; i < length - 1; i++)
	{
		if (pos.X == body[i].X && pos.Y == body[i].Y) return true;
	}
	*/
	return false;
}
