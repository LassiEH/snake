#pragma once
#include <Windows.h>


class Snake
{
	private:
		COORD pos;
		int length;
		int velocity;
		char direction;

	public:
		Snake(COORD pos, int velocity);
		void change_direction(char dir); //Metodi k‰‰rmeen suunnan vaihtamiselle
		void move_snake(); //Metodi k‰‰rmeen liikkumiselle
		COORD get_pos(); //Metodi k‰‰rmeen sijainnin saamiselle
};

