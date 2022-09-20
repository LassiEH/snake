// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Snake.h"
#include <conio.h>
#include "Food.h"
#include <ctime>

#define WIDTH 50
#define HEIGHT 25

using namespace std;

Snake snake({ WIDTH / 2, HEIGHT / 2 }, 1);
Food food;


void board()
{
    COORD snake_pos = snake.get_pos();
    COORD food_position = food.get_position();
    // Luodaan reunat pelikentälle
    for (int i = 0; i < HEIGHT; i++)
    {
        cout << "\t\t\t\t#";
        for (int j = 0; j < WIDTH - 2; j++)
        {
            if (i == 0 || i == HEIGHT - 1) cout << '#';
            else if (i == snake_pos.Y && j == snake_pos.X) cout << 'o';
            else if (i == food_position.Y && j == food_position.X) cout << '*';
            else cout << ' ';
        }
        cout << "#\n";
    }
}

int main()
{
    srand(time(NULL));

    bool game_over = false;

    while (!game_over)
    {
        board();

        if (_kbhit())
        {
            switch (_getch())
            {
            case 'w': snake.change_direction('u'); break;
            case 's': snake.change_direction('d'); break;
            case 'a': snake.change_direction('l'); break;
            case 'd': snake.change_direction('r'); break;
            }
        }
        snake.move_snake();

        if (snake.eaten(food.get_position()))
        {
            food.gen_food();
            snake.grow();
        }

        if (snake.collided()) game_over = true;

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
    }

}