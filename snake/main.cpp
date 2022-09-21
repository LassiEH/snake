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

int score = 0;

void board()
{
    COORD snake_pos = snake.get_pos();
    COORD food_position = food.get_position();
    vector<COORD> snake_body = snake.get_body();

    cout << "Score: " << score << "\n\n";
    // Luodaan reunat pelikentälle
    for (int i = 0; i < HEIGHT; i++)
    {
        cout << "\t\t\t\t#";
        for (int j = 0; j < WIDTH - 2; j++)
        {
            if (i == 0 || i == HEIGHT - 1) cout << '#';

            else if (i == snake_pos.Y && j+1 == snake_pos.X) cout << 'o';
            else if (i == food_position.Y && j+1 == food_position.X) cout << '*';
            
            else
            {
                bool isBodyPart = false;
                for (int k = 0; k < snake_body.size()-1; k++)
                {
                    if (i == snake_body[k].Y && j + 1 == snake_body[k].X)
                    {
                        cout << 'o';
                        isBodyPart = true;
                        break;
                    }
                }
                if (!isBodyPart) cout << ' ';
            }
        }
        cout << "#\n";
    }
}

int main()
{
    srand(time(NULL));

    food.gen_food();

    bool game_over = false;

    while (!game_over)
    {
        board();

        // Otetaan vastaan näppäimistön painalluksia,
        // switch-lauseessa sitten määritellään mitä
        // mistäkin painalluksesta tapahtuu.
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

        if (snake.eaten(food.get_position()))
        {
            food.gen_food();
            snake.grow();
            score++;
        }

        if (snake.collided()) game_over = true;

        snake.move_snake();

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
    }

}