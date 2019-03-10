#define _CRT_SECURE_NO_WARNINGS // дл€ использовани€ strcpy()
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
using namespace std;

/*
1.	— клавиатуры вводитс€ целое число в диапазоне от 0 до 1000000.
Ќеобходимо вывести его прописной строковый эквивалент.
*/
void captcha(int num, char *s) // num Ч число, s Ч указатель на строку
{
	int position = 0; // позици€ в строке
	int x[4]; // массив разр€дов
	int div = 1000; // делитель на разр€ды
	int var = num; // частное от делени€
	int rest; // остаток от делени€
	for (int i = 0; i < 4; i++)
	{
		rest = (int)(var / div);
		x[i] = rest;
		var = var - rest * div;
		div = div / 10;
	}
	// “ыс€чи
	switch (x[0])
	{
	case 1: strcpy(s, "ќдна тыс€ча "); break;
	case 2: strcpy(s, "ƒве тыс€чи "); break;
	case 3: strcpy(s, "“ри тыс€чи "); break;
	case 4: strcpy(s, "„етыре тыс€чи "); break;
	case 5: strcpy(s, "ѕ€ть тыс€ч "); break;
	case 6: strcpy(s, "Ўесть тыс€ч "); break;
	case 7: strcpy(s, "—емь тыс€ч "); break;
	case 8: strcpy(s, "¬осемь тыс€ч "); break;
	case 9: strcpy(s, "ƒев€ть тыс€ч "); break;
	default: break;
	}
	position = strlen(s);
	// —отни
	switch (x[1])
	{
	case 1: strcpy(s + position, "сто "); break;
	case 2: strcpy(s + position, "двести "); break;
	case 3: strcpy(s + position, "триста "); break;
	case 4: strcpy(s + position, "четыреста "); break;
	case 5: strcpy(s + position, "п€тьсот "); break;
	case 6: strcpy(s + position, "шестьсот "); break;
	case 7: strcpy(s + position, "семьсот "); break;
	case 8: strcpy(s + position, "восемьсот "); break;
	case 9: strcpy(s + position, "дев€тьсот "); break;
	default: break;
	}
	position = strlen(s);
	// ƒес€тки
	switch (x[2])
	{
	case 1:
		// „исла от 10 до 19
		switch (x[3])
		{
		case 0: strcpy(s + position, "дес€ть "); break;
		case 1: strcpy(s + position, "одиннадцать "); break;
		case 2: strcpy(s + position, "двенадцать "); break;
		case 3: strcpy(s + position, "тринадцать "); break;
		case 4: strcpy(s + position, "четырнадцать "); break;
		case 5: strcpy(s + position, "п€тнадцать "); break;
		case 6: strcpy(s + position, "шестнадцать "); break;
		case 7: strcpy(s + position, "семнадцать "); break;
		case 8: strcpy(s + position, "восемнадцать "); break;
		case 9: strcpy(s + position, "дев€тнадцать "); break;
		}
		x[3] = 0;
		position = strlen(s);
		break;
	case 2: strcpy(s + position, "двадцать "); break;
	case 3: strcpy(s + position, "тридцать "); break;
	case 4: strcpy(s + position, "сорок "); break;
	case 5: strcpy(s + position, "п€тьдес€т "); break;
	case 6: strcpy(s + position, "шестьдес€т "); break;
	case 7: strcpy(s + position, "семьдес€т "); break;
	case 8: strcpy(s + position, "восемьдес€т "); break;
	case 9: strcpy(s + position, "дев€носто "); break;
	default: break;
	}
	position = strlen(s);
	// ≈диницы
	switch (x[3]) {
	case 1: strcpy(s + position, "один "); break;
	case 2: strcpy(s + position, "два "); break;
	case 3: strcpy(s + position, "три "); break;
	case 4: strcpy(s + position, "четыре "); break;
	case 5: strcpy(s + position, "п€ть "); break;
	case 6: strcpy(s + position, "шесть "); break;
	case 7: strcpy(s + position, "семь "); break;
	case 8: strcpy(s + position, "восемь "); break;
	case 9: strcpy(s + position, "дев€ть "); break;
	default: break;
	}
	position = strlen(s);
}
int main()
{
	int m;
	srand(time(NULL));
	system("chcp 1251");
	system("cls");
	char s[80];
	for (int i = 0; i < 10; i++)
	{
		m = rand() % (10000 - 1000) + 1000;
		captcha(m, s);
		cout << m << " " << s << endl << endl;
	}
	cin.get();
	return 0;
}