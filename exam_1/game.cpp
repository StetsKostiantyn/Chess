#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<conio.h>
#include<vector>
#include"Func.h"
#include"Menu.h"


using namespace std;

struct Chess
{
    char* name;
    char let;
    int num;
    int color;
    int move;
    bool life;

    void print()
    {
        int x = (let - 96) * 10 - 10 + 3, y = (5 * 8) - (num * 5) + 3;
        if (strcmp(name, "king") == 0 && life == true)
        {
            if (color == 1)
                SetColor(0, 0);
            else
                SetColor(7, 7);
            go(x + 2, y);
            cout << " ";
            go(x + 4, y);
            cout << "  ";
            go(x + 7, y);
            cout << " ";
            go(x + 1, y + 1);
            cout << " ";
            go(x + 3, y + 1);
            cout << "    ";
            go(x + 8, y + 1);
            cout << " ";
            go(x + 2, y + 2);
            cout << " ";
            go(x + 4, y + 2);
            cout << "  ";
            go(x + 7, y + 2);
            cout << " ";
            go(x + 3, y + 3);
            cout << "    ";
            go(x + 1, y + 4);
            cout << "        ";
        }
        if (strcmp(name, "queen") == 0 && life == true)
        {
            if (color == 1)
                SetColor(0, 0);
            else
                SetColor(7, 7);
            go(x + 3, y);
            cout << " ";
            go(x + 6, y);
            cout << " ";
            go(x + 1, y + 1);
            cout << " ";
            go(x + 4, y + 1);
            cout << "  ";
            go(x + 8, y + 1);
            cout << " ";
            go(x + 2, y + 2);
            cout << "      ";
            go(x + 3, y + 3);
            cout << "    ";
            go(x + 1, y + 4);
            cout << "        ";
        }
        if (strcmp(name, "bishop") == 0 && life == true)
        {
            if (color == 1)
                SetColor(0, 0);
            else
                SetColor(7, 7);
            go(x + 4, y);
            cout << " ";
            go(x + 3, y + 1);
            cout << "  ";
            go(x + 6, y + 1);
            cout << " ";
            go(x + 2, y + 2);
            cout << "   ";
            go(x + 6, y + 2);
            cout << "  ";
            go(x + 3, y + 3);
            cout << "    ";
            go(x + 1, y + 4);
            cout << "        ";
        }
        if (strcmp(name, "knight") == 0 && life == true)
        {
            if (color == 1)
                SetColor(0, 0);
            else
                SetColor(7, 7);
            go(x + 3, y);
            cout << " ";
            go(x + 2, y + 1);
            cout << "     ";
            go(x + 1, y + 2);
            cout << "  ";
            go(x + 4, y + 2);
            cout << "    ";
            go(x + 3, y + 3);
            cout << "    ";
            go(x + 1, y + 4);
            cout << "        ";
        }
        if (strcmp(name, "rook") == 0 && life == true)
        {
            if (color == 1)
                SetColor(0, 0);
            else
                SetColor(7, 7);
            go(x + 2, y);
            cout << " ";
            go(x + 4, y);
            cout << "  ";
            go(x + 7, y);
            cout << " ";
            go(x + 2, y + 1);
            cout << "      ";
            go(x + 3, y + 2);
            cout << "    ";
            go(x + 3, y + 3);
            cout << "    ";
            go(x + 2, y + 4);
            cout << "      ";
        }
        if (strcmp(name, "pawn") == 0 && life == true)
        {
            if (color == 1)
                SetColor(0, 0);
            else
                SetColor(7, 7);
            go(x + 4, y);
            cout << "  ";
            go(x + 3, y + 1);
            cout << "    ";
            go(x + 4, y + 2);
            cout << "  ";
            go(x + 3, y + 3);
            cout << "    ";
            go(x + 2, y + 4);
            cout << "      ";
        }
    }

    void findLeadChess(Chess* white, Chess* black)
    {
        for (int i = 0; i < 16; i++)
        {
            if (white[i].let == let && white[i].num == num)
            {
                white[i].print();
                for (size_t i = 0; i < 3; i++)
                {
                    SetColor(4, 4);
                    go(atox(let), numtoy(num) + 1 + i);
                    cout << " ";
                }
                for (size_t i = 0; i < 3; i++)
                {
                    SetColor(4, 4);
                    go(atox(let) + 9, numtoy(num) + 1 + i);
                    cout << " ";
                }
                break;
            }
            if (black[i].let == let && black[i].num == num)
            {
                black[i].print();
                for (size_t i = 0; i < 3; i++)
                {
                    SetColor(4, 4);
                    go(atox(let), numtoy(num) + 1 + i);
                    cout << " ";
                }
                for (size_t i = 0; i < 3; i++)
                {
                    SetColor(4, 4);
                    go(atox(let) + 9, numtoy(num) + 1 + i);
                    cout << " ";
                }
                break;
            }
        }
    }

	bool checkChess(int x, int y, Chess* white, Chess* black, int color)
	{
		if (color == 1)
		{
			for (int i = 0; i < 16; i++)
			{
				if (white[0].check(x, y, atox(white[i].let), numtoy(white[i].num), white, black, i) == false)
					return false;
			}
		}
		if (color == 0)
		{
			for (int i = 0; i < 16; i++)
			{
				if (black[0].check(x, y, atox(black[i].let), numtoy(black[i].num), white, black, i) == false)
					return false;
			}
		}
		return true;
	}

    bool check(int x, int y, int x1, int y1, Chess* white, Chess* black, int i)
    {
        int j = 0, g = 0;
        if ((strcmp(white[i].name, "king") == 0 && life == true) || (strcmp(black[i].name, "king") == 0 && life == true))
        {
			if ((y1 - y == 5 && (x1 - x == 10 || x1 == x || x - x1 == 10)) || (y1 == y && (x1 - x == 10 || x - x1 == 10)) || (y - y1 == 5 && (x1 - x == 10 || x1 == x || x - x1 == 10)))
				return false;
			else
				return true;
        }
        if ((strcmp(white[i].name, "queen") == 0 && life == true) || strcmp(black[i].name, "queen") == 0 && life == true)
        {
            if (x1 == x && y1 != y)
            {
                if (y1 - y > 0)
                    j = 5;
                if (y1 - y < 0)
                    j = -5;
                for (int i = y + j; i != y1; i += j)
                {
                    for (int g = 0; g < 16; g++)
                    {
                        if (white[g].let == xtoa(x) && white[g].num == ytonum(i))
                            return true;
                        if (black[g].let == xtoa(x) && black[g].num == ytonum(i))
                            return true;
                    }
                }
                return false;
            }
            if (x1 != x && y1 == y)
            {
                if (x1 - x > 0)
                    j = 10;
                if (x1 - x < 0)
                    j = -10;
                for (int i = x + j; i != x1; i += j)
                {
                    for (int g = 0; g < 16; g++)
                    {
                        if (white[g].let == xtoa(i) && white[g].num == ytonum(y))
                            return true;
                        if (black[g].let == xtoa(i) && black[g].num == ytonum(y))
                            return true;
                    }
                }
                return false;
            }
            if (abs(((x1 - 3) / 2) - ((x - 3) / 2)) == abs((y1 - 3) - (y - 3)))
            {
                if (x1 - x > 0 && y1 - y > 0) {
                    j = 10; g = 5;
                }
                if (x1 - x > 0 && y1 - y < 0) {
                    j = 10; g = -5;
                }
                if (x1 - x < 0 && y1 - y < 0) {
                    j = -10; g = -5;
                }
                if (x1 - x < 0 && y1 - y > 0) {
                    j = -10; g = 5;
                }
                for (int n = x + j, m = y + g; n != x1 || m != y1; n += j, m += g)
                {
                    for (int i = 0; i < 16; i++)
                    {
                        if (white[i].let == xtoa(n) && white[i].num == ytonum(m))
                            return true;
                        if (black[i].let == xtoa(n) && black[i].num == ytonum(m))
                            return true;
                    }
                }
                return false;
            }
            return true;
        }
        if ((strcmp(white[i].name, "bishop") == 0 && life == true) || strcmp(black[i].name, "bishop") == 0 && life == true)
        {
            if (abs(((x1 - 3) / 2) - ((x - 3) / 2)) == abs((y1 - 3) - (y - 3)))
            {
                if (x1 - x > 0 && y1 - y > 0) {
                    j = 10; g = 5;
                }
                if (x1 - x > 0 && y1 - y < 0) {
                    j = 10; g = -5;
                }
                if (x1 - x < 0 && y1 - y < 0) {
                    j = -10; g = -5;
                }
                if (x1 - x < 0 && y1 - y > 0) {
                    j = -10; g = 5;
                }
                for (int n = x + j, m = y + g; n != x1 || m != y1; n += j, m += g)
                {
                    for (int i = 0; i < 16; i++)
                    {
                        if (white[i].let == xtoa(n) && white[i].num == ytonum(m))
                            return true;
                        if (black[i].let == xtoa(n) && black[i].num == ytonum(m))
                            return true;
                    }
                }
                return false;
            }
			return true;
        }
        if ((strcmp(white[i].name, "knight") == 0 && life == true) || strcmp(black[i].name, "knight") == 0 && life == true)
        {
            if (((x1 - x == 10 || x - x1 == 10) && (y1 - y == 10 || y - y1 == 10)) || ((x1 - x == 20 || x - x1 == 20) && (y1 - y == 5 || y - y1 == 5)))
                return false;
            else
                return true;
        }
        if ((strcmp(white[i].name, "rook") == 0 && life == true) || strcmp(black[i].name, "rook") == 0 && life == true)
        {
            if (x1 == x && y1 != y)
            {
                if (y1 - y > 0)
                    j = 5;
                if (y1 - y < 0)
                    j = -5;
                for (int i = y + j; i != y1; i += j)
                {
                    for (int g = 0; g < 16; g++)
                    {
                        if (white[g].let == xtoa(x) && white[g].num == ytonum(i))
                            return true;
                        if (black[g].let == xtoa(x) && black[g].num == ytonum(i))
                            return true;
                    }
                }
                return false;
            }
            if (x1 != x && y1 == y)
            {
                if (x1 - x > 0)
                    j = 10;
                if (x1 - x < 0)
                    j = -10;
                for (int i = x + j; i != x1; i += j)
                {
                    for (int g = 0; g < 16; g++)
                    {
                        if (white[g].let == xtoa(i) && white[g].num == ytonum(y))
                            return true;
                        if (black[g].let == xtoa(i) && black[g].num == ytonum(y))
                            return true;
                    }
                }
                return false;
            }
			return true;
        }
        if ((strcmp(white[i].name, "pawn") == 0 && life == true) || strcmp(black[i].name, "pawn") == 0 && life == true)
        {
            if ((((x1 - x == 10 && y1 - y == 5) || (x1 - x == -10 && y1 - y == 5)) && color == 0) || (((x - x1 == 10 && y - y1 == 5) || (x - x1 == -10 && y - y1 == 5)) && color == 1))
                return false;
            return true;
        }
    }

    void show(int x, int y, Chess* white, Chess* black)
    {
        int res = 0, x1 = x, y1 = y, j = 0, g = 0, tempnum;
		char tempa;
		while (true)
		{
			findLeadChess(white, black);
			if (_kbhit())
			{
				switch (_getch())
				{
				case 72:
					if (Check(x, y - 5) == false)
						break;
					y -= 5;
					break;
				case 80:
					if (Check(x, y + 5) == false)
						break;
					y += 5;
					break;
				case 75:
					if (Check(x - 10, y) == false)
						break;
					x -= 10;
					break;
				case 77:
					if (Check(x + 10, y) == false)
						break;
					x += 10;
					break;
				case 32:
					if (strcmp(name, "king") == 0 && life == true)
					{
						if ((y1 - y == 5 && (x1 - x == 10 || x1 == x || x - x1 == 10)) || (y1 == y && (x1 - x == 10 || x - x1 == 10)) || (y - y1 == 5 && (x1 - x == 10 || x1 == x || x - x1 == 10)))
						{		
							if (color == 0)
							{
								for (int i = 0; i < 16; i++)
								{
									if (white[i].let == xtoa(x) && white[i].num == ytonum(y))
										return;
									if (black[i].let == xtoa(x) && black[i].num == ytonum(y))
									{
										black[i].life = false;
										black[i].let = 'z';
										black[i].num = 999;
										let = xtoa(x);
										num = ytonum(y);
										if (checkChess(x, y, white, black, color) == false)
										{
											black[i].life = true;
											black[i].let = xtoa(x);
											black[i].num = ytonum(y);
											let = xtoa(x1);
											num = ytonum(y1);
											return;
										}
										move++;
										printWB(x, y);
										white[i].print();
										return;
									}
									res++;
								}
							}
							else
							{
								for (int i = 0; i < 16; i++)
								{
									if (black[i].let == xtoa(x) && black[i].num == ytonum(y))
										return;
									if (white[i].let == xtoa(x) && white[i].num == ytonum(y))
									{
										white[i].life = false;
										white[i].let = 'z';
										white[i].num = 999;
										let = xtoa(x);
										num = ytonum(y);
										if (checkChess(x, y, white, black, color) == false)	
										{
											white[i].life = true;
											white[i].let = xtoa(x);
											white[i].num = ytonum(y);
											let = xtoa(x1);
											num = ytonum(y1);
											return;
										}
										move++;
										printWB(x, y);
										black[i].print();
										return;
									}
									res++;
								}
							}
							if (res == 16)
							{
								let = xtoa(x);
								num = ytonum(y);
								move++;
								return;
							}
						}
						if (color == 1 && black[0].move == 0 && (black[6].move == 0 || black[7].move == 0))
						{
							if ((x == x1 - 20 && y == numtoy(black[6].num)) || (x == x1 + 20 && y == numtoy(black[7].num)))
							{
								if (x1 - x > 0)
								{
									j = 10;
									for (int i = x + j - 20; i != x1; i += j)
									{
										for (int g = 0; g < 16; g++)
										{
											if (white[g].let == xtoa(i) && white[g].num == ytonum(y))
												return;
											if (black[g].let == xtoa(i) && black[g].num == ytonum(y))
												return;
											if (checkChess(i, y, white, black, 1) == false)
												return;
										}
									}
									black[0].let = xtoa(x);
									black[0].move++;
									black[0].print();
									printWB(x - 20, y);
									black[7].let = xtoa(x + 10);
									black[7].move++;
									black[7].print();
									return;
								}
								if (x1 - x < 0)
								{
									j = -10;
									for (int i = x + j + 10; i != x1; i += j)
									{
										if (checkChess(i, y, white, black, 1) == false)
											return;
										for (int g = 0; g < 16; g++)
										{
											if (white[g].let == xtoa(i) && white[g].num == ytonum(y))
												return;
											if (black[g].let == xtoa(i) && black[g].num == ytonum(y))
												return;
										}
									}
									black[0].let = xtoa(x);
									black[0].move++;
									black[0].print();
									printWB(x + 10, y);
									black[7].let = xtoa(x - 10);
									black[7].move++;
									black[7].print();
									return;
								}
							}
						}
						if (color == 0 && white[0].move == 0 && (white[6].move == 0 || white[7].move == 0))
						{
							if ((x == x1 - 20 && y == numtoy(white[6].num)) || (x == x1 + 20 && y == numtoy(white[7].num)))
							{
								if (x1 - x > 0)
								{
									j = 10;
									for (int i = x + j - 20; i != x1; i += j)
									{
										if (checkChess(i, y, white, black, 0) == false)
											return;
										for (int g = 0; g < 16; g++)
										{
											if (white[g].let == xtoa(i) && white[g].num == ytonum(y))
												return;
											if (black[g].let == xtoa(i) && black[g].num == ytonum(y))
												return;
										}
									}
									white[0].let = xtoa(x);
									white[0].move++;
									white[0].print();
									printWB(x - 20, y);
									white[7].let = xtoa(x + 10);
									white[7].move++;
									white[7].print();
									return;
								}
								if (x1 - x < 0)
								{
									j = -10;
									for (int i = x + j + 10; i != x1; i += j)
									{
										for (int g = 0; g < 16; g++)
										{
											if (white[g].let == xtoa(i) && white[g].num == ytonum(y))
												return;
											if (black[g].let == xtoa(i) && black[g].num == ytonum(y))
												return;
											if (
												checkChess(i, y, white, black, 0) == false)
												return;
										}
									}
									white[0].let = xtoa(x);
									white[0].move++;
									white[0].print();
									printWB(x + 10, y);
									white[7].let = xtoa(x - 10);
									white[7].move++;
									white[7].print();
									return;
								}
							}
						}
					}
					if (strcmp(name, "queen") == 0 && life == true)
					{
						if (x1 == x && y1 != y)
						{
							if (y1 - y > 0)
								j = 5;
							if (y1 - y < 0)
								j = -5;
							for (int i = y + j; i != y1; i += j)
							{
								for (int g = 0; g < 16; g++)
								{
									if (white[g].let == xtoa(x) && white[g].num == ytonum(i))
										return;
									if (black[g].let == xtoa(x) && black[g].num == ytonum(i))
										return;
								}
							}
							if (color == 0)
							{
								for (int i = 0; i < 16; i++)
								{
									if (white[i].let == xtoa(x) && white[i].num == ytonum(y))
										return;
									if (black[i].let == xtoa(x) && black[i].num == ytonum(y))
									{
										tempa = black[i].let;
										tempnum = black[i].num;
										black[i].life = false;
										black[i].let = 'z';
										black[i].num = 999;
										let = xtoa(x);
										num = ytonum(y);
										if (checkChess(atox(white[0].let), numtoy(white[0].num), white, black, 0) == false)
										{
											black[i].life = true;
											black[i].let = tempa;
											black[i].num = tempnum;
											let = xtoa(x1);
											num = ytonum(y1);
											return;
										}
										move++;
										printWB(x, y);
										white[i].print();
										return;
									}
									res++;
								}
							}
							else
							{
								for (int i = 0; i < 16; i++)
								{
									if (black[i].let == xtoa(x) && black[i].num == ytonum(y))
										return;
									if (white[i].let == xtoa(x) && white[i].num == ytonum(y))
									{
										tempa = white[i].let;
										tempnum = white[i].num;
										white[i].life = false;
										white[i].let = 'z';
										white[i].num = 999;
										let = xtoa(x);
										num = ytonum(y);
										if (checkChess(atox(black[0].let), numtoy(black[0].num), white, black, 1) == false)
										{
											white[i].life = true;
											white[i].let = tempa;
											white[i].num = tempnum;
											let = xtoa(x1);
											num = ytonum(y1);
											return;
										}
										move++;
										printWB(x, y);
										black[i].print();
										return;
									}
									res++;
								}
							}
						}
						if (x1 != x && y1 == y)
						{
							if (x1 - x > 0)
								j = 10;
							if (x1 - x < 0)
								j = -10;
							for (int i = x + j; i != x1; i += j)
							{
								for (int g = 0; g < 16; g++)
								{
									if (white[g].let == xtoa(i) && white[g].num == ytonum(y))
										return;
									if (black[g].let == xtoa(i) && black[g].num == ytonum(y))
										return;
								}
							}
							if (color == 0)
							{
								for (int i = 0; i < 16; i++)
								{
									if (white[i].let == xtoa(x) && white[i].num == ytonum(y))
										return;
									if (black[i].let == xtoa(x) && black[i].num == ytonum(y))
									{
										tempa = black[i].let;
										tempnum = black[i].num;
										black[i].life = false;
										black[i].let = 'z';
										black[i].num = 999;
										let = xtoa(x);
										num = ytonum(y);
										if (checkChess(atox(white[0].let), numtoy(white[0].num), white, black, 0) == false)
										{
											black[i].life = true;
											black[i].let = tempa;
											black[i].num = tempnum;
											let = xtoa(x1);
											num = ytonum(y1);
											return;
										}
										move++;
										printWB(x, y);
										white[i].print();
										return;
									}
									res++;
								}
							}
							else
							{
								for (int i = 0; i < 16; i++)
								{
									if (black[i].let == xtoa(x) && black[i].num == ytonum(y))
										return;
									if (white[i].let == xtoa(x) && white[i].num == ytonum(y))
									{
										tempa = white[i].let;
										tempnum = white[i].num;
										white[i].life = false;
										white[i].let = 'z';
										white[i].num = 999;
										let = xtoa(x);
										num = ytonum(y);
										if (checkChess(atox(black[0].let), numtoy(black[0].num), white, black, 1) == false)
										{
											white[i].life = true;
											white[i].let = tempa;
											white[i].num = tempnum;
											let = xtoa(x1);
											num = ytonum(y1);
											return;
										}
										move++;
										printWB(x, y);
										black[i].print();
										return;
									}
									res++;
								}
							}
						}
						if (abs(((x1 - 3) / 2) - ((x - 3) / 2)) == abs((y1 - 3) - (y - 3)))
						{
							if (x1 - x > 0 && y1 - y > 0) {
								j = 10; g = 5;
							}
							if (x1 - x > 0 && y1 - y < 0) {
								j = 10; g = -5;
							}
							if (x1 - x < 0 && y1 - y < 0) {
								j = -10; g = -5;
							}
							if (x1 - x < 0 && y1 - y > 0) {
								j = -10; g = 5;
							}
							for (int n = x + j, m = y + g; n != x1 || m != y1; n += j, m += g)
							{
								for (int i = 0; i < 16; i++)
								{
									if (white[i].let == xtoa(n) && white[i].num == ytonum(m))
										return;
									if (black[i].let == xtoa(n) && black[i].num == ytonum(m))
										return;
								}
							}
							if (color == 0)
							{
								for (int i = 0; i < 16; i++)
								{
									if (white[i].let == xtoa(x) && white[i].num == ytonum(y))
										return;
									if (black[i].let == xtoa(x) && black[i].num == ytonum(y))
									{
										tempa = black[i].let;
										tempnum = black[i].num;
										black[i].life = false;
										black[i].let = 'z';
										black[i].num = 999;
										let = xtoa(x);
										num = ytonum(y);
										if (checkChess(atox(white[0].let), numtoy(white[0].num), white, black, 0) == false)
										{
											black[i].life = true;
											black[i].let = tempa;
											black[i].num = tempnum;
											let = xtoa(x1);
											num = ytonum(y1);
											return;
										}
										move++;
										printWB(x, y);
										white[i].print();
										return;
									}
									res++;
								}
							}
							else
							{
								for (int i = 0; i < 16; i++)
								{
									if (black[i].let == xtoa(x) && black[i].num == ytonum(y))
										return;
									if (white[i].let == xtoa(x) && white[i].num == ytonum(y))
									{
										tempa = white[i].let;
										tempnum = white[i].num;
										white[i].life = false;
										white[i].let = 'z';
										white[i].num = 999;
										let = xtoa(x);
										num = ytonum(y);
										if (checkChess(atox(black[0].let), numtoy(black[0].num), white, black, 1) == false)
										{
											white[i].life = true;
											white[i].let = tempa;
											white[i].num = tempnum;
											let = xtoa(x1);
											num = ytonum(y1);
											return;
										}
										move++;
										printWB(x, y);
										black[i].print();
										return;
									}
									res++;
								}
							}
						}
						if (res == 16)
						{
							let = xtoa(x);
							num = ytonum(y);
							if (color == 1 && checkChess(atox(black[0].let), numtoy(black[0].num), white, black, 1) == false)
							{
								let = xtoa(x1);
								num = ytonum(y1);
								return;
							}
							if (color == 0 && checkChess(atox(white[0].let), numtoy(white[0].num), white, black, 0) == false)
							{
								let = xtoa(x1);
								num = ytonum(y1);
								return;
							}
							move++;
							return;
						}
					}
					if (strcmp(name, "bishop") == 0 && life == true)
					{
						if (abs(((x1 - 3) / 2) - ((x - 3) / 2)) == abs((y1 - 3) - (y - 3)))
						{
							if (x1 - x > 0 && y1 - y > 0) {
								j = 10; g = 5;
							}
							if (x1 - x > 0 && y1 - y < 0) {
								j = 10; g = -5;
							}
							if (x1 - x < 0 && y1 - y < 0) {
								j = -10; g = -5;
							}
							if (x1 - x < 0 && y1 - y > 0) {
								j = -10; g = 5;
							}
							for (int n = x + j, m = y + g; n != x1 || m != y1; n += j, m += g)
							{
								for (int i = 0; i < 16; i++)
								{
									if (white[i].let == xtoa(n) && white[i].num == ytonum(m))
										return;
									if (black[i].let == xtoa(n) && black[i].num == ytonum(m))
										return;
								}
							}
							if (color == 0)
							{
								for (int i = 0; i < 16; i++)
								{
									if (white[i].let == xtoa(x) && white[i].num == ytonum(y))
										return;
									if (black[i].let == xtoa(x) && black[i].num == ytonum(y))
									{
										tempa = black[i].let;
										tempnum = black[i].num;
										black[i].life = false;
										black[i].let = 'z';
										black[i].num = 999;
										let = xtoa(x);
										num = ytonum(y);
										if (checkChess(atox(white[0].let), numtoy(white[0].num), white, black, 0) == false)
										{
											black[i].life = true;
											black[i].let = tempa;
											black[i].num = tempnum;
											let = xtoa(x1);
											num = ytonum(y1);
											return;
										}
										move++;
										printWB(x, y);
										white[i].print();
										return;
									}
									res++;
								}
							}
							else
							{
								for (int i = 0; i < 16; i++)
								{
									if (black[i].let == xtoa(x) && black[i].num == ytonum(y))
										return;
									if (white[i].let == xtoa(x) && white[i].num == ytonum(y))
									{
										tempa = white[i].let;
										tempnum = white[i].num;
										white[i].life = false;
										white[i].let = 'z';
										white[i].num = 999;
										let = xtoa(x);
										num = ytonum(y);
										if (checkChess(atox(black[0].let), numtoy(black[0].num), white, black, 1) == false)
										{
											white[i].life = true;
											white[i].let = tempa;
											white[i].num = tempnum;
											let = xtoa(x1);
											num = ytonum(y1);
											return;
										}
										move++;
										printWB(x, y);
										black[i].print();
										return;
									}
									res++;
								}
							}
							if (res == 16)
							{
								let = xtoa(x);
								num = ytonum(y);
								if (color == 1 && checkChess(atox(black[0].let), numtoy(black[0].num), white, black, 1) == false)
								{
									let = xtoa(x1);
									num = ytonum(y1);
									return;
								}
								if (color == 0 && checkChess(atox(white[0].let), numtoy(white[0].num), white, black, 0) == false)
								{
									let = xtoa(x1);
									num = ytonum(y1);
									return;
								}
								move++;
								return;
							}
						}
					}
					if (strcmp(name, "knight") == 0 && life == true)
					{
						if (((x1 - x == 10 || x - x1 == 10) && (y1 - y == 10 || y - y1 == 10)) || ((x1 - x == 20 || x - x1 == 20) && (y1 - y == 5 || y - y1 == 5)))
						{
							if (color == 0)
							{
								for (int i = 0; i < 16; i++)
								{
									if (white[i].let == xtoa(x) && white[i].num == ytonum(y))
										return;
									if (black[i].let == xtoa(x) && black[i].num == ytonum(y))
									{
										tempa = black[i].let;
										tempnum = black[i].num;
										black[i].life = false;
										black[i].let = 'z';
										black[i].num = 999;
										let = xtoa(x);
										num = ytonum(y);
										if (checkChess(atox(white[0].let), numtoy(white[0].num), white, black, 0) == false)
										{
											black[i].life = true;
											black[i].let = tempa;
											black[i].num = tempnum;
											let = xtoa(x1);
											num = ytonum(y1);
											return;
										}
										move++;
										printWB(x, y);
										white[i].print();
										return;
									}
									res++;
								}
							}
							else
							{
								for (int i = 0; i < 16; i++)
								{
									if (black[i].let == xtoa(x) && black[i].num == ytonum(y))
										return;
									if (white[i].let == xtoa(x) && white[i].num == ytonum(y))
									{
										tempa = white[i].let;
										tempnum = white[i].num;
										white[i].life = false;
										white[i].let = 'z';
										white[i].num = 999;
										let = xtoa(x);
										num = ytonum(y);
										if (checkChess(atox(black[0].let), numtoy(black[0].num), white, black, 1) == false)
										{
											white[i].life = true;
											white[i].let = tempa;
											white[i].num = tempnum;
											let = xtoa(x1);
											num = ytonum(y1);
											return;
										}
										move++;
										printWB(x, y);
										black[i].print();
										return;
									}
									res++;
								}
							}
							if (res == 16)
							{
								let = xtoa(x);
								num = ytonum(y);
								if (color == 1 && checkChess(atox(black[0].let), numtoy(black[0].num), white, black, 1) == false)
								{
									let = xtoa(x1);
									num = ytonum(y1);
									return;
								}
								if (color == 0 && checkChess(atox(white[0].let), numtoy(white[0].num), white, black, 0) == false)
								{
									let = xtoa(x1);
									num = ytonum(y1);
									return;
								}
								move++;
								return;
							}
						}
					}
					if (strcmp(name, "rook") == 0 && life == true)
					{
						if (x1 == x && y1 != y)
						{
							if (y1 - y > 0)
								j = 5;
							if (y1 - y < 0)
								j = -5;
							for (int i = y + j; i != y1; i += j)
							{
								for (int g = 0; g < 16; g++)
								{
									if (white[g].let == xtoa(x) && white[g].num == ytonum(i))
										return;
									if (black[g].let == xtoa(x) && black[g].num == ytonum(i))
										return;
								}
							}
							if (color == 0)
							{
								for (int i = 0; i < 16; i++)
								{
									if (white[i].let == xtoa(x) && white[i].num == ytonum(y))
										return;
									if (black[i].let == xtoa(x) && black[i].num == ytonum(y))
									{
										tempa = black[i].let;
										tempnum = black[i].num;
										black[i].life = false;
										black[i].let = 'z';
										black[i].num = 999;
										let = xtoa(x);
										num = ytonum(y);
										if (checkChess(atox(white[0].let), numtoy(white[0].num), white, black, 0) == false)
										{
											black[i].life = true;
											black[i].let = tempa;
											black[i].num = tempnum;
											let = xtoa(x1);
											num = ytonum(y1);
											return;
										}
										move++;
										printWB(x, y);
										white[i].print();
										return;
									}
									res++;
								}
							}
							else
							{
								for (int i = 0; i < 16; i++)
								{
									if (black[i].let == xtoa(x) && black[i].num == ytonum(y))
										return;
									if (white[i].let == xtoa(x) && white[i].num == ytonum(y))
									{
										tempa = white[i].let;
										tempnum = white[i].num;
										white[i].life = false;
										white[i].let = 'z';
										white[i].num = 999;
										let = xtoa(x);
										num = ytonum(y);
										if (checkChess(atox(black[0].let), numtoy(black[0].num), white, black, 1) == false)
										{
											white[i].life = true;
											white[i].let = tempa;
											white[i].num = tempnum;
											let = xtoa(x1);
											num = ytonum(y1);
											return;
										}
										move++;
										printWB(x, y);
										black[i].print();
										return;
									}
									res++;
								}
							}
						}
						if (x1 != x && y1 == y)
						{
							if (x1 - x > 0)
								j = 10;
							if (x1 - x < 0)
								j = -10;
							for (int i = x + j; i != x1; i += j)
							{
								for (int g = 0; g < 16; g++)
								{
									if (white[g].let == xtoa(i) && white[g].num == ytonum(y))
										return;
									if (black[g].let == xtoa(i) && black[g].num == ytonum(y))
										return;
								}
							}
							if (color == 0)
							{
								for (int i = 0; i < 16; i++)
								{
									if (white[i].let == xtoa(x) && white[i].num == ytonum(y))
										return;
									if (black[i].let == xtoa(x) && black[i].num == ytonum(y))
									{
										tempa = black[i].let;
										tempnum = black[i].num;
										black[i].life = false;
										black[i].let = 'z';
										black[i].num = 999;
										let = xtoa(x);
										num = ytonum(y);
										if (checkChess(atox(white[0].let), numtoy(white[0].num), white, black, 0) == false)
										{
											black[i].life = true;
											black[i].let = tempa;
											black[i].num = tempnum;
											let = xtoa(x1);
											num = ytonum(y1);
											return;
										}
										move++;
										printWB(x, y);
										white[i].print();
										return;
									}
									res++;
								}
							}
							else
							{
								for (int i = 0; i < 16; i++)
								{
									if (black[i].let == xtoa(x) && black[i].num == ytonum(y))
										return;
									if (white[i].let == xtoa(x) && white[i].num == ytonum(y))
									{
										tempa = white[i].let;
										tempnum = white[i].num;
										white[i].life = false;
										white[i].let = 'z';
										white[i].num = 999;
										let = xtoa(x);
										num = ytonum(y);
										if (checkChess(atox(black[0].let), numtoy(black[0].num), white, black, 1) == false)
										{
											white[i].life = true;
											white[i].let = tempa;
											white[i].num = tempnum;
											let = xtoa(x1);
											num = ytonum(y1);
											return;
										}
										move++;
										printWB(x, y);
										black[i].print();
										return;
									}
									res++;
								}
							}
						}
						if (res == 16)
						{
							let = xtoa(x);
							num = ytonum(y);
							if (color == 1 && checkChess(atox(black[0].let), numtoy(black[0].num), white, black, 1) == false)
							{
								let = xtoa(x1);
								num = ytonum(y1);
								return;
							}
							if (color == 0 && checkChess(atox(white[0].let), numtoy(white[0].num), white, black, 0) == false)
							{
								let = xtoa(x1);
								num = ytonum(y1);
								return;
							}
							move++;
							return;
						}
					}
					if (strcmp(name, "pawn") == 0 && life == true)
					{
						if ((x1 - x == 0 && y1 - y == 5) || (x - x1 == 0 && y - y1 == 5))
						{
							for (int i = 0; i < 16; i++)
							{
								if (white[i].let == xtoa(x) && white[i].num == ytonum(y))
									return;
								if (black[i].let == xtoa(x) && black[i].num == ytonum(y))
									return;
								res++;
							}
						}
						if (x1 - x == 0 && y1 - y == 10 && move == 0 && color == 0)
						{
							for (int i = 0; i < 16; i++)
							{
								if (white[i].let == xtoa(x) && white[i].num == ytonum(y1 - 5))
									return;
								if (black[i].let == xtoa(x) && black[i].num == ytonum(y1 - 5))
									return;
								res++;
							}
						}
						if (x - x1 == 0 && y - y1 == 10 && move == 0 && color == 1)
						{
							for (int i = 0; i < 16; i++)
							{
								if (black[i].let == xtoa(x) && black[i].num == ytonum(y1 + 5))
									return;
								if (black[i].let == xtoa(x) && black[i].num == ytonum(y1 + 5))
									return;
								res++;
							}
						}
						if (res == 16)
						{
							let = xtoa(x);
							num = ytonum(y);
							if (color == 1 && checkChess(atox(black[0].let), numtoy(black[0].num), white, black, 1) == false)
							{
								let = xtoa(x1);
								num = ytonum(y1);
								return;
							}
							if (color == 0 && checkChess(atox(white[0].let), numtoy(white[0].num), white, black, 0) == false)
							{
								let = xtoa(x1);
								num = ytonum(y1);
  							    return;
							}
							if ((num == 8 && color == 0) || (num == 1 && color == 1))
							{
								printWB(x, y);
								SetColor(15, 0);
								go(88, 3);
								cout << "На какую фигуру поменять пешку?";
								go(88, 4);
								cout << "Нажмите:";
								go(88, 5);
								cout << "1. Ферзь;";
								go(88, 6);
								cout << "2. Ладья;";
								go(88, 7);
								cout << "3. Слон;";
								go(88, 8);
								cout << "4. Конь;";
								delete[]name;
								while (true)
									switch (_getch())
									{
									case 49:
										name = new char[6];
										strcpy(name, "queen");
										for (int h = 0; h < 6; h++)
										{
											go(88, 3 + h);
											cout << "                                   ";
										}
										return;
									case 50:
										name = new char[5];
										strcpy(name, "rook");
										for (int h = 0; h < 6; h++)
										{
											go(88, 3 + h);
											cout << "                                   ";
										}
										return;
									case 51:
										name = new char[7];
										strcpy(name, "bishop");
										for (int h = 0; h < 6; h++)
										{
											go(88, 3 + h);
											cout << "                                   ";
										}
										return;
									case 52:
										name = new char[7];
										strcpy(name, "knight");
										for (int h = 0; h < 6; h++)
										{
											go(88, 3 + h);
											cout << "                                   ";
										}
										return;
									default:
										break;
									}
							}
							move++;
							return;
						}
						if ((((x1 - x == 10 && y1 - y == 5) || (x1 - x == -10 && y1 - y == 5)) && color == 0) || (((x - x1 == 10 && y - y1 == 5) || (x - x1 == -10 && y - y1 == 5)) && color == 1))
						{
							for (size_t i = 0; i < 16; i++)
							{
								if (color == 0)
								{
									if (black[i].let == xtoa(x) && black[i].num == ytonum(y))
									{ 
										tempa = black[i].let;
										tempnum = black[i].num;
										black[i].life = false;
										black[i].let = 'z';
										black[i].num = 999;
										let = xtoa(x);
										num = ytonum(y);
										if (checkChess(atox(white[0].let), numtoy(white[0].num), white, black, 0) == false)
										{
											black[i].life = true;
											black[i].let = tempa;
											black[i].num = tempnum;
											let = xtoa(x1);
											num = ytonum(y1);
											return;
										}
										if (num == 8)
										{
											printWB(x, y);
											SetColor(15, 0);
											go(88, 3);
											cout << "На какую фигуру поменять пешку?";
											go(88, 4);
											cout << "Нажмите:";
											go(88, 5);
											cout << "1. Ферзь;";
											go(88, 6);
											cout << "2. Ладья;";
											go(88, 7);
											cout << "3. Слон;";
											go(88, 8);
											cout << "4. Конь;";
											delete[]name;
											while (true)
												switch (_getch())
												{
												case 49:
													name = new char[6];
													strcpy(name, "queen");
													for (int h = 0; h < 6; h++)
													{
														go(88, 3 + h);
														cout << "                                   ";
													}
													return;
												case 50:
													name = new char[5];
													strcpy(name, "rook");
													for (int h = 0; h < 6; h++)
													{
														go(88, 3 + h);
														cout << "                                   ";
													}
													return;
												case 51:
													name = new char[7];
													strcpy(name, "bishop");
													for (int h = 0; h < 6; h++)
													{
														go(88, 3 + h);
														cout << "                                   ";
													}
													return;
												case 52:
													name = new char[7];
													strcpy(name, "knight");
													for (int h = 0; h < 6; h++)
													{
														go(88, 3 + h);
														cout << "                                   ";
													}
													return;
												default:
													break;
												}
										}
										move++;
										printWB(x, y);
										white[i].print();
										return;
									}
								}
								else
								{
									if (white[i].let == xtoa(x) && white[i].num == ytonum(y))
									{
										tempa = white[i].let;
										tempnum = white[i].num;
										white[i].life = false;
										white[i].let = 'z';
										white[i].num = 999;
										let = xtoa(x);
										num = ytonum(y);
										if (checkChess(atox(black[0].let), numtoy(black[0].num), white, black, 1) == false)
										{
											white[i].life = true;
											white[i].let = tempa;
											white[i].num = tempnum;
											let = xtoa(x1);
											num = ytonum(y1);
											return;
										}
										if (num == 1)
										{
											printWB(x, y);
											SetColor(15, 0);
											go(88, 3);
											cout << "На какую фигуру поменять пешку?";
											go(88, 4);
											cout << "Нажмите:";
											go(88, 5);
											cout << "1. Ферзь;";
											go(88, 6);
											cout << "2. Ладья;";
											go(88, 7);
											cout << "3. Слон;";
											go(88, 8);
											cout << "4. Конь;";
											delete[]name;
											while (true)
												switch (_getch())
												{
												case 49:
													name = new char[6];
													strcpy(name, "queen");
													for (int h = 0; h < 6; h++)
													{
														go(88, 3 + h);
														cout << "                                   ";
													}
													return;
												case 50:
													name = new char[5];
													strcpy(name, "rook");
													for (int h = 0; h < 6; h++)
													{
														go(88, 3 + h);
														cout << "                                   ";
													}
													return;
												case 51:
													name = new char[7];
													strcpy(name, "bishop");
													for (int h = 0; h < 6; h++)
													{
														go(88, 3 + h);
														cout << "                                   ";
													}
													return;
												case 52:
													name = new char[7];
													strcpy(name, "knight");
													for (int h = 0; h < 6; h++)
													{
														go(88, 3 + h);
														cout << "                                   ";
													}
													return;
												default:
													break;
												}
										}
										move++;
										printWB(x, y);
										black[i].print();
										return;
									}
								}

							}
						}
					}
					return;
					break;
				default:
					break;
				}
			}
			else
			{
			printRed(x, y);
			Sleep(500);
			printWB(x, y);
			go(x - 10, y - 5);
			if (x == x1 && y == y1)
				findLeadChess(white, black);
			else
			{
				for (int i = 0; i < 16; i++)
				{
					if (white[i].let == xtoa(x) && white[i].num == ytonum(y))
					{
						white[i].print();
						break;
					}
					if (black[i].let == xtoa(x) && black[i].num == ytonum(y))
					{
						black[i].print();
						break;
					}
				}
			}
			Sleep(500);
			}
		}
	}
};

void findPrintChess(int x, int y, Chess* white, Chess* black)
{
	for (int i = 0; i < 16; i++)
	{
		if (white[i].let == xtoa(x) && white[i].num == ytonum(y))
		{
			white[i].print();
			break;
		}
		if (black[i].let == xtoa(x) && black[i].num == ytonum(y))
		{
			black[i].print();
			break;
		}
	}
}


void printChess(int x, int y, Chess* white, Chess* black)
{
	printRed(x, y);
	Sleep(500);
	printWB(x, y);
	go(x, y);
	findPrintChess(x, y, white, black);
	Sleep(500);
}

int checkEnd(Chess* white, Chess* black)
{
	int tempnum, res = 0, num;
	char tempa, let;
	if (white[0].checkChess(atox(white[0].let), numtoy(white[0].num), white, black, 0) == false)
	{
		for (int i = 0; i < 16; i++)
		{
			for (int j = 3; j < 8 * 5; j += 5)
			{
				for (int g = 3; g < 8 * 10; g += 10)
				{
					if (white[i].life == true && white[0].check(g, j, atox(white[i].let), numtoy(white[i].num), white, black, i) == false)
					{
						res = 0;
						for (int h = 0; h < 16; h++)
						{
							if (white[h].let == xtoa(g) && white[h].num == ytonum(j))
								break;
							if (black[h].let == xtoa(g) && black[h].num == ytonum(j))
							{
								tempa = black[h].let;
								tempnum = black[h].num;
								let = white[i].let;
								num = white[i].num;
								black[h].life = false;
								black[h].let = 'z';
								black[h].num = 999;
								white[i].let = xtoa(g);
								white[i].num = ytonum(j);
								if (white[0].checkChess(atox(white[0].let), numtoy(white[0].num), white, black, 0) == false)
								{
									black[h].life = true;
									black[h].let = tempa;
									black[h].num = tempnum;
									white[i].let = let;
									white[i].num = num;
								}
								else
								{
									black[h].life = true;
									black[h].let = tempa;
									black[h].num = tempnum;
									white[i].let = let;
									white[i].num = num;
									return 0;
								}							
							}
							res++;
						}
						if (res == 16 && i < 8)
						{
							let = white[i].let;
							num = white[i].num;
							white[i].let = xtoa(g);
							white[i].num = ytonum(j);
							if (white[0].checkChess(atox(white[0].let), numtoy(white[0].num), white, black, 0) == false)
							{
								white[i].let = let;
								white[i].num = num;
							}
							else
							{
								white[i].let = let;
								white[i].num = num;
								return 0;
							}
						}
					}
					if (i > 7)
					{
						res = 0;
						if (atox(white[i].let) - g == 0 && numtoy(white[i].num) - j == 5)
						{
							for (int h = 0; h < 16; h++)
							{
								if (white[h].let == xtoa(g) && white[h].num == ytonum(j))
									break;;
								if (black[h].let == xtoa(g) && black[h].num == ytonum(j))
									break;;
								res++;
							}
						}
						if (atox(white[i].let) - g == 0 && numtoy(white[i].num) - j == 10 && white[i].move == 0 && white[i].color == 0)
						{
							for (int h = 0; h < 16; h++)
							{
								if (white[h].let == xtoa(g) && white[h].num == ytonum(j + 5))
									break;
								if (black[h].let == xtoa(g) && black[h].num == ytonum(j + 5))
									break;;
								if (white[h].let == xtoa(g) && white[h].num == ytonum(j))
									break;;
								if (black[h].let == xtoa(g) && black[h].num == ytonum(j))
									break;;
							}
							res++;
						}
						if (res == 16)
						{
							let = white[i].let;
							num = white[i].num;
							white[i].let = xtoa(g);
							white[i].num = ytonum(j);
							if (white[0].checkChess(atox(white[0].let), numtoy(white[0].num), white, black, 0) == false)
							{
								white[i].let = let;
								white[i].num = num;
							}
							else
							{
								white[i].let = let;
								white[i].num = num;
								return 0;
							}
						}
					}
				}
			}
		}
		return 2;
	}
	if (black[0].checkChess(atox(black[0].let), numtoy(black[0].num), white, black, 1) == false)
	{
		for (int i = 0; i < 16; i++)
		{
			for (int j = 3; j < 8 * 5; j += 5)
			{
				for (int g = 3; g < 8 * 10; g += 10)
				{
					if (black[i].life == true && black[0].check(g, j, atox(black[i].let), numtoy(black[i].num), white, black, i) == false)
					{
						res = 0;
						for (int h = 0; h < 16; h++)
						{
							if (black[h].let == xtoa(g) && black[h].num == ytonum(j))
								break;
							if (white[h].let == xtoa(g) && white[h].num == ytonum(j))
							{
								tempa = white[h].let;
								tempnum = white[h].num;
								let = black[i].let;
								num = black[i].num;
								white[h].life = false;
								white[h].let = 'z';
								white[h].num = 999;
								black[i].let = xtoa(g);
								black[i].num = ytonum(j);
								if (black[0].checkChess(atox(black[0].let), numtoy(black[0].num), white, black, 1) == false)
								{
									white[h].life = true;
									white[h].let = tempa;
									white[h].num = tempnum;
									black[i].let = let;
									black[i].num = num;
								}
								else
								{
									white[h].life = true;
									white[h].let = tempa;
									white[h].num = tempnum;
									black[i].let = let;
									black[i].num = num;
									return 0;
								}
							}
							res++;
						}
						if (res == 16 && i < 8)
						{
							let = black[i].let;
							num = black[i].num;
							black[i].let = xtoa(g);
							black[i].num = ytonum(j);
							if (black[0].checkChess(atox(black[0].let), numtoy(black[0].num), white, black, 1) == false)
							{
								black[i].let = let;
								black[i].num = num;
							}
							else
							{
								black[i].let = let;
								black[i].num = num;
								return 0;
							}
						}
					}
					if (i > 7)
					{
						res = 0;
						if (g - atox(black[i].let) == 0 && j - numtoy(black[i].num) == 5)
						{
							for (int h = 0; h < 16; h++)
							{
								if (white[h].let == xtoa(g) && white[h].num == ytonum(j))
									break;;
								if (black[h].let == xtoa(g) && black[h].num == ytonum(j))
									break;;
								res++;
							}
						}
						if (g - atox(black[i].let) == 0 && j - numtoy(black[i].num) == 10 && black[i].move == 0)
						{
							for (int h = 0; h < 16; h++)
							{
								if (white[h].let == xtoa(g) && white[h].num == ytonum(j - 5))
									break;
								if (black[h].let == xtoa(g) && black[h].num == ytonum(j - 5))
									break;;
								if (white[h].let == xtoa(g) && white[h].num == ytonum(j))
									break;;
								if (black[h].let == xtoa(g) && black[h].num == ytonum(j))
									break;;
							}
							res++;
						}
						if (res == 16)
						{
							let = black[i].let;
							num = black[i].num;
							black[i].let = xtoa(g);
							black[i].num = ytonum(j);
							if (black[0].checkChess(atox(black[0].let), numtoy(black[0].num), white, black, 1) == false)
							{
								black[i].let = let;
								black[i].num = num;
							}
							else
							{
								black[i].let = let;
								black[i].num = num;
								return 0;
							}
						}
					}
				}
			}
		}
		return 3;
	}
	res = 0;
	for (int i = -5; i < 10; i += 5)
	{
		for (int j = -10; j < 20; j += 10)
		{
			if (atox(white[0].let) + j > 0 && numtoy(white[0].num) + i > 0 && atox(white[0].let) + j < 83 && numtoy(white[0].num) + i < 38)
			{
				if (white[0].checkChess(atox(white[0].let) + j, numtoy(white[0].num) + i, white, black, 0) == true)
				{
					res++;
					for (int h = 1; h < 16; h++)
					{
						if (white[h].let == xtoa(atox(white[0].let) + j) && white[h].num == ytonum(numtoy(white[0].num) + i))
						{
							res--;
							break;
						}
					}
				}	
			}
		}
	}
	if (res == 0)
	{
		for (int i = 1; i < 16; i++)
		{
			for (int j = 3; j < 8 * 5; j += 5)
			{
				for (int g = 3; g < 8 * 10; g += 10)
				{
					if (white[i].life == true && i < 8 && white[0].check(g, j, atox(white[i].let), numtoy(white[i].num), white, black, i) == false)
					{
						let = white[i].let;
						num = white[i].num;
						white[i].let = xtoa(g);
						white[i].num = ytonum(j);
						if (white[0].checkChess(atox(white[0].let), numtoy(white[0].num), white, black, 0) == true)
						{
							white[i].let = let;
							white[i].num = num;
							for (int h = 0; h < 16; h++)
							{
								if (white[h].let != xtoa(g) || white[h].num != ytonum(j))
									res++;
							}
						}
						else
						{
							white[i].let = let;
							white[i].num = num;
						}
						if (res == 16)
							return 0;
						else
							res = 0;
					}
					if (i > 7)
					{
						res = 0;
						if (white[i].life == true)
						{
							for (int h = 0; h < 16; h++)
							{
								if (white[i].let != white[h].let || numtoy(white[i].num) - 5 != numtoy(white[h].num))
									res++;
								if (white[i].let != black[h].let || numtoy(white[i].num) - 5 != numtoy(black[h].num))
									res++;
							}
							if (res == 32)
								return 0;
							else
								res = 0;
						}
						if (white[i].life == true && white[0].check(g, j, atox(white[i].let), numtoy(white[i].num), white, black, i) == false)
						{
							for (int h = 0; h < 16; h++)
							{
								if ((atox(white[i].let) - 10 == atox(black[h].let) || atox(white[i].let) + 10 == atox(black[h].let)) && numtoy(white[i].num) - 5 == numtoy(black[h].num))
									return 0;
							}
						}
					}
				}
			}
		}
		return 1;
	}
	res = 0;
	for (int i = -5; i < 10; i += 5)
	{
		for (int j = -10; j < 20; j += 10)
		{
			if (atox(black[0].let) + j > 0 && numtoy(black[0].num) + i > 0 && atox(black[0].let) + j < 83 && numtoy(black[0].num) + i < 38)
			{
				if (black[0].checkChess(atox(black[0].let) + j, numtoy(black[0].num) + i, white, black, 1) == true)
				{
					res++;
					for (int h = 1; h < 16; h++)
					{
						if (black[h].let == xtoa(atox(black[0].let) + j) && black[h].num == ytonum(numtoy(black[0].num) + i))
						{
							res--;
							break;
						}
					}
				}
			}
		}
	}
	if (res == 0)
	{
		for (int i = 1; i < 16; i++)
		{
			for (int j = 3; j < 8 * 5; j += 5)
			{
				for (int g = 3; g < 8 * 10; g += 10)
				{
					if (black[i].life == true && i < 8 && black[0].check(g, j, atox(black[i].let), numtoy(black[i].num), white, black, i) == false)
					{
						let = black[i].let;
						num = black[i].num;
						black[i].let = xtoa(g);
						black[i].num = ytonum(j);
						if (black[0].checkChess(atox(black[0].let), numtoy(black[0].num), white, black, 0) == true)
						{
							black[i].let = let;
							black[i].num = num;
							for (int h = 0; h < 16; h++)
							{
								if (black[h].let != xtoa(g) || black[h].num != ytonum(j))
									res++;
							}
						}
						else
						{
							black[i].let = let;
							black[i].num = num;
						}
						if (res == 16)
							return 0;
						else
							res = 0;
					}
					if (i > 7)
					{
						res = 0;
						if (black[i].life == true)
						{
							for (int h = 0; h < 16; h++)
							{
								if (black[i].let != black[h].let || numtoy(black[i].num) + 5 != numtoy(black[h].num))
									res++;
								if (black[i].let != white[h].let || numtoy(black[i].num) + 5 != numtoy(white[h].num))
									res++;
							}
							if (res == 32)
								return 0;
							else
								res = 0;
						}
						if (black[i].life == true && black[0].check(g, j, atox(black[i].let), numtoy(black[i].num), white, black, i) == false)
						{
							for (int h = 0; h < 16; h++)
							{
								if ((atox(black[i].let) - 10 == atox(white[h].let) || atox(black[i].let) + 10 == atox(white[h].let)) && numtoy(black[i].num) + 5 == numtoy(white[h].num))
									return 0;
							}
						}
					}
				}
			}
		}
		return 1;
	}
	return 0;
}

struct Game
{
    Chess white[16], black[16];

    void load(Chess* arr, int color)
    {
        int place1 = 1, place2 = 2;
        if (color == 1)
        {
            place1 = 8;
            place2 = 7;
        }
        if (color == 0)
        {
            place1 = 1;
			place2 = 2;
        }
		arr[1] = { new char[6] {"queen"}, 'd', place1, color, 0, true };
		arr[0] = { new char[5] {"king"}, 'e', place1, color, 0, true };
        arr[2] = { new char[7] {"knight"}, 'b', place1, color, 0, true };
        arr[3] = { new char[7] {"knight"}, 'g', place1, color, 0, true };
        arr[4] = { new char[7] {"bishop"}, 'c', place1, color, 0, true };
        arr[5] = { new char[7] {"bishop"}, 'f', place1, color, 0, true };
        arr[6] = { new char[5] {"rook"}, 'a', place1, color, 0, true };
        arr[7] = { new char[5] {"rook"}, 'h', place1, color, 0, true };
        for (int i = 0; i < 8; i++)
        {
            arr[8 + i] = { new char[5] {"pawn"}, (char)('a' + i), place2, color, 0, true };
        }

		/*if (color == 0)          // пат: пешка а3-а4
		{
			arr[1] = { new char[6] {"queen"}, 'h', 2, color, 0, true };
			arr[0] = { new char[5] {"king"}, 'e', 1, color, 0, true };
			arr[2] = { new char[7] {"knight"}, 'd', 2, color, 0, true };
			arr[3] = { new char[7] {"knight"}, 'g', 1, color, 0, true };
			arr[4] = { new char[7] {"bishop"}, 'c', 1, color, 0, true };
			arr[5] = { new char[7] {"bishop"}, 'f', 1, color, 0, true };
			arr[6] = { new char[5] {"rook"}, 'g', 3, color, 0, true };
			arr[7] = { new char[5] {"rook"}, 'h', 1, color, 0, true };
			arr[8] = { new char[5] {"pawn"}, 'a', 3, color, 0, true };
			arr[9] = { new char[5] {"pawn"}, 'b', 2, color, 0, true };
			arr[10] = { new char[5] {"pawn"}, 'c', 4, color, 0, true };
			arr[11] = { new char[5] {"pawn"}, 'd', 5, color, 0, true };
			arr[12] = { new char[5] {"pawn"}, 'e', 2, color, 0, true };
			arr[13] = { new char[5] {"pawn"}, 'f', 3, color, 0, true };
			arr[14] = { new char[5] {"pawn"}, 'g', 2, color, 0, true };
			arr[15] = { new char[5] {"pawn"}, 'h', 3, color, 0, true };
		}
		if (color == 1)
		{
			arr[1] = { new char[6] {"queen"}, 'a', 5, color, 0, true };
			arr[0] = { new char[5] {"king"}, 'e', 8, color, 0, true };
			arr[2] = { new char[7] {"knight"}, 'b', 8, color, 0, true };
			arr[3] = { new char[7] {"knight"}, 'g', 8, color, 0, true };
			arr[4] = { new char[7] {"bishop"}, 'b', 3, color, 0, true };
			arr[5] = { new char[7] {"bishop"}, 'h', 4, color, 0, true };
			arr[6] = { new char[5] {"rook"}, 'a', 8, color, 0, true };
			arr[7] = { new char[5] {"rook"}, 'h', 8, color, 0, true };
			arr[8] = { new char[5] {"pawn"}, 'a', 7, color, 0, true };
			arr[9] = { new char[5] {"pawn"}, 'b', 7, color, 0, true };
			arr[10] = { new char[5] {"pawn"}, 'c', 5, color, 0, true };
			arr[11] = { new char[5] {"pawn"}, 'd', 6, color, 0, true };
			arr[12] = { new char[5] {"pawn"}, 'e', 3, color, 0, true };
			arr[13] = { new char[5] {"pawn"}, 'f', 4, color, 0, true };
			arr[14] = { new char[5] {"pawn"}, 'g', 7, color, 0, true };
			arr[15] = { new char[5] {"pawn"}, 'h', 7, color, 0, true };
		}*/
    }

    void game()
    {
        board();
        for (size_t i = 0; i < 16; i++)
        {
            if (white[i].life == true)
                white[i].print();
        }
        for (size_t i = 0; i < 16; i++)
        {
            if (black[i].life == true)
                black[i].print();
        }

        int x = 3, y = 38, turn = 0, numWhite = 16, numBlack = 16, tempWhite = 16, tempBlack = 16;

        while (checkEnd(white, black) == 0)
        {
			if (white[0].checkChess(atox(white[0].let), numtoy(white[0].num), white, black, 0) == false)
			{
				go(88, 5);
				SetColor(15, 0);
				cout << "Белый король в опастности!";
			}
			else
			{
				if (black[0].checkChess(atox(black[0].let), numtoy(black[0].num), white, black, 1) == false)
				{
					go(88, 5);
					SetColor(15, 0);
					cout << "Чёрный король в опастности!";
				}
				else
				{
					go(88, 5);
					SetColor(15, 0);
					cout << "                           ";
				}
			}
            if (_kbhit())
                switch (_getch())
                {
                case 72:
                    if (Check(x, y - 5) == false)
                        break;
                    y -= 5;
                    break;
                case 80:
                    if (Check(x, y + 5) == false)
                        break;
                    y += 5;
                    break;
                case 75:
                    if (Check(x - 10, y) == false)
                        break;
                    x -= 10;
                    break;
                case 77:
                    if (Check(x + 10, y) == false)
                        break;
                    x += 10;
                    break;
                case 32:
					for (int i = 0; i < 16; i++)
					{
						if (white[i].let == xtoa(x) && white[i].num == ytonum(y) && turn % 2 == 0)
						{
							white[i].show(x, y, white, black);
							white[i].print();
							printWB(x, y);
							if (white[i].let != xtoa(x) || white[i].num != ytonum(y))
							{
								turn++;
								SetColor(15, 0);
								go(88 + (turn % 92 / 46 * 25), 10 + ((turn % 92 / 2) % 23));
								cout << "                    ";
								go(88 + (turn % 92 / 46 * 25), 10 + ((turn % 92 / 2) % 23));
								cout << (turn + 1) / 2 << ".";
								if (strcmp(white[i].name, "king") == 0)
									cout << "Kg";
								if (strcmp(white[i].name, "queen") == 0)
									cout << "Q";
								if (strcmp(white[i].name, "bishop") == 0)
									cout << "B";
								if (strcmp(white[i].name, "knight") == 0)
									cout << "N";
								if (strcmp(white[i].name, "rook") == 0)
									cout << "R";
								cout << xtoa(x) << ytonum(y);
								for (int j = 0; j < 16; j++)
								{
									if (black[j].life == false)
										tempBlack--;
								}
								if (numBlack != tempBlack)
									cout << ":";
								else
									cout << "-";
								cout << white[i].let << white[i].num;
								if (checkEnd(white, black) == 3)
									cout << "x";
								else
								    if (black[0].checkChess(atox(black[0].let), numtoy(black[0].num), white, black, 1) == false)
									    cout << "+";
							}
							break;
						}
					}
					

					for (int i = 0; i < 16; i++)
					{
						if (black[i].let == xtoa(x) && black[i].num == ytonum(y) && turn % 2 == 1)
						{
							black[i].show(x, y, white, black);
							black[i].print();
							printWB(x, y);
							if (black[i].let != xtoa(x) || black[i].num != ytonum(y))
							{
								turn++;
								SetColor(15, 0);
								go(99 + ((turn - 1) % 92 / 46 * 25), 10 + (((turn - 1) % 92 / 2) % 23));
								if (strcmp(black[i].name, "king") == 0)
									cout << "Kg";
								if (strcmp(black[i].name, "queen") == 0)
									cout << "Q";
								if (strcmp(black[i].name, "bishop") == 0)
									cout << "B";
								if (strcmp(black[i].name, "knight") == 0)
									cout << "N";
								if (strcmp(black[i].name, "rook") == 0)
									cout << "R";
								cout << xtoa(x) << ytonum(y);
								for (int j = 0; j < 16; j++)
								{
									if (white[j].life == false)
										tempWhite--;
								}
								if (numWhite != tempWhite)
								{
									cout << ":";
									numWhite = tempWhite;
								}
								else
									cout << "-";
								cout << black[i].let << black[i].num;
								if (checkEnd(white, black) == 2)
									cout << "x";
								else
									if (white[0].checkChess(atox(white[0].let), numtoy(white[0].num), white, black, 0) == false)
										cout << "+";
							}
							break;
						}
					}					
                    break;
				case 27:
					return;
					break;
                default:
                    break;
                }
            else
            {
                printChess(x, y, white, black);
            }
        }
		int ind = checkEnd(white, black);
		if (ind == 1)
		{
			SetColor(15, 0);
			go(88, 5);
			cout << "Пат!";
			go(0, 45);
			system("pause");
		}
		if (ind == 2)
		{
			SetColor(15, 0);
			go(88, 5);
			cout << "Чёрные победили!";
			go(0, 45);
			system("pause");
		}
		if (ind == 3)
		{
			SetColor(15, 0);
			go(88, 5);
			cout << "Белые победили!";
			go(0, 45);
			system("pause");
		}
    }

    void menu()
    {
		while (true)
		{
			load(white, 0);
			load(black, 1);
			system("cls");
			vector<string> v = { "Начать игру", "Выход" };
			Menu m;
			int ch = m.select_vertical(v);
			switch (ch)
			{
			case 0:
				system("cls");
				game();
				break;
			case 1:
				exit(0);
				break;
			default:
				break;
			}
		}
    }
};

int main()
{
    system("MODE CON COLS=135 LINES=50");
    setlocale(LC_ALL, "");
    srand(time(0));


    Game game;
    game.menu();

    go(0, 45);
    SetColor(0, 0);

    return 0;
}