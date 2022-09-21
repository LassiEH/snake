#pragma once
#include <Windows.h>
#include <vector>

using namespace std;

class Snake
{
	private:
		COORD pos;
		int length;
		int velocity;
		char direction;
		vector<COORD> body;

	public:
		Snake(COORD pos, int velocity);
		void change_direction(char dir); //Metodi k‰‰rmeen suunnan vaihtamiselle
		void move_snake(); //Metodi k‰‰rmeen liikkumiselle
		COORD get_pos(); //Metodi k‰‰rmeen sijainnin saamiselle

		bool eaten(COORD food_position);

		void grow();

		bool collided();

		vector<COORD> get_body();
};

