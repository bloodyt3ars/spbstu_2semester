#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <iomanip>
using namespace std;


const char colorEmpty = 'E';
const char colorRed = 'R';
const char colorGreen = 'G';
const char colorBlue = 'B';
const char colorDark = 'D';

char getColumn1(int val) { return val & 0xFF; } //берем цвет из опр. колонки
char getColumn2(int val) { return (val >> 8) & 0xFF; }
char getColumn3(int val) { return (val >> 16) & 0xFF; }

void setColumn1(int& val, char color) { val &= ~0xFF;  val |= color; }//ставим цвет из опр. колонки
void setColumn2(int& val, char color) { val &= ~0xFF00; val |= color << 8; }
void setColumn3(int& val, char color) { val &= ~0xFF0000; val |= color << 16; }
int fillColumns(char color1, char color2, char color3)
{

	int val = 0;
	val |= color1 | (color2 << 8) | (color3 << 16);
	return val;
} // все колонки вместе 


void initializeLevels(vector<int>& arrLevels) // Создание массива
{/*Функция заполнения массива символом буквами R,G или B. Сначала вводиться кол-во уровней, затем происходит проверка.
	После создается динамический массив символов. И пользователь вводит с клавиатуры значения, с проверкой на ввод.*/

	cout << "Введите кол-во уровней от 2 до 6: ";
	int levelLength;
	cin >> levelLength; // ввод кол-ва уровней

	arrLevels.resize(levelLength);//создание нужного кол-ва уровней
	for (int i = 0; i < levelLength; ++i)
	{
	
		cout << i << ":";
		char chColumn1;
		char chColumn2;
		char chColumn3;
		cin >> chColumn1 >> chColumn2 >> chColumn3;
		arrLevels[i] = fillColumns(chColumn1, chColumn2, chColumn3);
	}

}

bool find(char clrFind, vector<int>& arrLevels, int& nResultLevel, char& chResultColumn)

{
	int nMax = arrLevels.size() - 1;
	for (int i = 0; i < nMax; )
	{
		if (getColumn1(arrLevels[i]) == clrFind)
		{
			if (getColumn2(arrLevels[i]) == colorEmpty)
			{
				++i;
				
			}
			else
			{
				nResultLevel = i;
				chResultColumn = 1;
				return true;
			}
		}
		else
		{
			if (getColumn3(arrLevels[i]) == clrFind)
			{
				if (getColumn2(arrLevels[i]) == colorEmpty)
				{
					++i;
					
				}
				else
				{
					nResultLevel = i;
					chResultColumn = 3;
					return true;
				}
			}
			else
			{
				++i;
			}
		}
		//cout << i << ":" << getColumn1(*it) << getColumn2(*it) << getColumn3(*it) << endl;
	}
	for (int i = 0; i < nMax;)
	{
		if (getColumn2(arrLevels[i]) == clrFind)
		{
			if ((getColumn1(arrLevels[i]) == colorEmpty) || (getColumn3(arrLevels[i]) == colorEmpty))
			{
				++i;
			}
			else
			{
				nResultLevel = i;
				chResultColumn = 2;
				return true;
			}
		}
		else
		{
			++i;
		}
	}
	return false;


}

bool checking(vector<int>& arrLevels)
{
	int counter = 0;
	for (int i = 0; i < (size(arrLevels) - 1); ++i)
	{
		if (((getColumn1(arrLevels[i]) == colorEmpty) && (getColumn3(arrLevels[i]) == colorEmpty)) || ((getColumn2(arrLevels[i]) == colorEmpty)))
		{
			++counter;
		}
	}
	if (size(arrLevels) - 1 == counter)
	{
		return false;
	}
}






int main()
{
	setlocale(LC_ALL, "Russian");
	vector< int > arrLevels;
	initializeLevels(arrLevels);
	double Result = 0;
	int i = 0;
	double chance = 0;
	for (vector< int >::iterator it = arrLevels.begin(); it != arrLevels.end(); ++it, ++i)
	{
		cout << i << ":" << getColumn1(*it) << getColumn2(*it) << getColumn3(*it) << endl;
	}

	char lstCubik[6] = { 'B','G','B','R','G','D' };

	for (int i = 0; checking(arrLevels); ++i, Result += chance)
	{

		char tmp = rand() % 6;
		cout << "tmp=" << (int)tmp << " color=" << lstCubik[tmp] << endl;
		if ((((int)tmp == 3) || ((int)tmp == 5)))
		{
			chance = 0.16666666666;
		}
		else
		{
			chance = 0.33333333333;
		}
		

		int nResultLevel;
		char chResultColumn;
		if (find(lstCubik[tmp], arrLevels, nResultLevel, chResultColumn))
		{
			cout << "find lev=" << nResultLevel << "clm=" << (int)chResultColumn << endl;

			int idxTop = arrLevels.size() - 1;
			if (getColumn1(arrLevels[idxTop]) != colorEmpty && getColumn2(arrLevels[idxTop]) != colorEmpty && getColumn3(arrLevels[idxTop]) != colorEmpty)//добавляем уровень с пустыми значениями
			{
				arrLevels.push_back(fillColumns(colorEmpty, colorEmpty, colorEmpty));
				++idxTop;
			}

			//убираем цвет
			switch (chResultColumn)
			{
			case 1:
				setColumn1(arrLevels[nResultLevel], colorEmpty); break;
			case 2:
				setColumn2(arrLevels[nResultLevel], colorEmpty); break;
			default:
				setColumn3(arrLevels[nResultLevel], colorEmpty); break;
			}
			//убираем цвет

			//устанавливаем цвет
			if (getColumn1(arrLevels[idxTop]) == colorEmpty)
				setColumn1(arrLevels[idxTop], lstCubik[tmp]);
			else if (getColumn2(arrLevels[idxTop]) == colorEmpty)
				setColumn2(arrLevels[idxTop], lstCubik[tmp]);
			else
				setColumn3(arrLevels[idxTop], lstCubik[tmp]);
			//устанавливаем цвет

			{
				int n = 0;
				for (vector< int >::iterator it = arrLevels.begin(); it != arrLevels.end(); ++it, ++n)
				{
					cout << n << ":" << getColumn1(*it) << getColumn2(*it) << getColumn3(*it) << endl;
				}

			}

		}
	}
	cout << "Result: " << Result << endl;

	system("pause");
	return 0;
}

