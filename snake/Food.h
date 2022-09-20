#pragma once

#include <Windows.h>
#include <cstdlib>

class Food
{
	private:
		COORD position;
	public:
		void gen_food();
		COORD get_position();

};

