// snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <Windows.h>

//#define sq(x) x*x

using namespace std;

const int WIDTH = 50, HEIGHT = 25;

void board()
{
    // Luodaan reunat pelikentälle
    for (int i = 0; i < HEIGHT; i++)
    {
        cout << "\t\t\t\t#";
        for (int j = 0; j < WIDTH - 2; j++)
        {
            if (i == 0 || i == HEIGHT - 1) cout << '#';
            else if (i == y && j == x) cout << 'o';
            else cout << ' ';
        }
        cout << "#\n";
    }
}

int main()
{
    while (true)
    {
        board();
        x++;
        //system("cls");
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
    }

}