#pragma once
#include<windows.h>
#include<vector>
#include<iostream>
#include<string>
#include"Func.h"
#include<conio.h>

using namespace std;

struct Menu
{
    int select_vertical(vector <string> menu)
    {
        char c;
        int pos = 0;
        do
        {
            for (int i = 0; i < menu.size(); i++)
            {
                if (i == pos)
                {
                    SetColor(0, 15);
                    go(45, 20 - menu.size() / 2 + i);
                    cout << "                             ";
                    int len = menu[i].length();
                    go(60 - len / 2, 20 - menu.size() / 2 + i);
                    cout << menu[i] << endl;
                    SetColor(15, 0);
                }
                else
                {
                    SetColor(15, 0);
                    go(45, 20 - menu.size() / 2 + i);
                    cout << "                             ";
                    int len = menu[i].length();
                    go(60 - len / 2, 20 - menu.size() / 2 + i);
                    cout << menu[i] << endl;
                    SetColor(0, 15);
                }

            }
            c = _getch();
            switch (c)
            {
            case 72:
                if (pos > 0)
                    pos--;
                break;
            case 80:
                if (pos < menu.size() - 1)
                    pos++;
                break;
            case 13:
                break;
            default:
                break;
            }
        } while (c != 13);
        SetColor(7, 0);
        return pos;
    }

    int select_gorizontal(vector<string> menu)
    {
        int max_len = 0;
        for (int i = 0; i < menu.size(); i++)
            max_len += menu[i].length();
        if (max_len > 80 - menu.size() - 1)
            int a = 1;
    }
};