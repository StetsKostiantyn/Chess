#pragma once

void go(int x, int y);
enum ConsoleColor;
void SetColor(int text, int background);
void board();
bool Check(int x, int y);
int atox(char a);
int numtoy(int num);
char xtoa(int x);
int ytonum(int y);
int color(int x, int y);
void printRed(int x, int y);
void printWB(int x, int y);