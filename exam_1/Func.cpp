#include<iostream>
#include<iomanip>
#include<Windows.h>
#define gor 10
#define ver 5
#define dist 3

enum ConsoleColor
{
    Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8,
    LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15
};

void SetColor(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void go(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void board()
{
    std::cout << "\n\n\n";
    for (size_t j = 0, g = 0; j < 8; j++)
    {
        for (size_t k = 0; k < 5; k++)
        {
            SetColor(15, 0);
            std::cout << "   ";
            for (size_t i = 0 + g; i < 8 + g; i++)
            {
                if (i % 2 == 0)
                    SetColor(15, 15);
                if (i % 2 == 1)
                    SetColor(8, 8);
                std::cout << "          ";
            }
            SetColor(15, 0);
            std::cout << std::endl;
        }
        if (j % 2 == 1)
            g = 0;
        if (j % 2 == 0)
            g = 1;
    }

    SetColor(15, 0);
    for (size_t i = 0, j = gor; i < 8; i++, j += gor)
    {
        go(j - 2, 1);
        std::cout << (char)('a' + i);
    }
    for (size_t i = 0, j = ver; i < 8; i++, j += ver)
    {
        go(1, j);
        std::cout << 8 - i;
    }
    go(88, 36);
    std::cout << "Нажмите: ";
    go(88, 37);
    std::cout << "\x18 - вверх;";
    go(88, 38);
    std::cout << "\x19 - вниз;";
    go(88, 39);
    std::cout << "<- - влево;";
    go(88, 40);
    std::cout << "-> - вправо;";
    go(88, 41);
    std::cout << "Spacebar - выбрать фигуру, сделать ход;";
    go(88, 42);
    std::cout << "Esc - завершить игру;";
    SetColor(15, 0);
}

bool Check(int x, int y)
{
    if (x < dist || y < dist)
        return false;
    if (x > 8 * gor || y > 8 * ver)
        return false;
    return true;
}

int atox(char a)
{
    return (a - 96) * gor - gor + dist;
}

int numtoy(int num)
{
    return (ver * 8) - (num * ver) + dist;
}

char xtoa(int x)
{
    int j = 0;
    while (x > 0)
    {
        x -= gor;
        j++;
    }
    return 96 + j;
}

int ytonum(int y)
{
    int j = 0;
    while (y > 0)
    {
        y -= ver;
        j++;
    }
    return 9 - j;
}

int color(int x, int y)
{
    if (((x - gor - 3) % 20 == 0 && (y - ver - 3) % 10 == 0) || ((x - gor - 3) % 20 == 10 && (y - ver - 3) % 10 == 5))
        return 15;
    if (((x - gor - 3) % 20 == 10 && (y - ver - 3) % 10 == 0) || ((x - gor - 3) % 20 == 0 && (y - ver - 3) % 10 == 5))
        return 8;
    else
    {
        if ((x == 3 && (y - 3) % 10 == 0) || ((x - 3) % 20 == 0 && y == 3))
            return 15;
        if ((x == 3 && (y - 3) % 10 != 0) || ((x - 3) % 20 != 0 && y == 3))
            return 8;
    }
    return -1;
}

void printRed(int x, int y)
{
    for (size_t i = 0; i < 5; i++)
    {
        SetColor(4, 4);
        go(x, y + i);
        std::cout << "          ";
    }
}

void printWB(int x, int y)
{
    int col = color(x, y);
    SetColor(col, col);
    for (size_t i = 0; i < 5; i++)
    {
        go(x, y + i);
        std::cout << "          ";
    }
}