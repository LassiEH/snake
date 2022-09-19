#pragma once
#include <Windows.h>


class Snake
{
	private:
		COORD pos;
		int lenght;
		int velocity;
		char direction;

	public:
		Snake(COORD pos, int velocity);
		void change_direction(char dir);
		void move_snake();
};

