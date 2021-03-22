#include <complex.h>
using namespace std;
#include <iostream>
#include <string>





template <typename T>
void linear_search(T* arr[], int rows, int cols, T symbol)
{
	int counter = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j]==symbol)
			{
				cout << "Первый из встреченных элементов стоит в " << (i + 1) << " строке и в " << (j + 1) << " столбце" << endl;
				counter++;
				break;
			}
		}
		if (counter>0)
		{
			break;
		}
	}
	
}


void binary_search(int arr[], int left, int right, int key)
{
	int mid;
	bool bool_var = true;
	while (bool_var)
	{
		mid = (left + right) / 2;
		if (key < arr[mid])
		{
			right = mid - 1;
		}
		else if (key > arr[mid])
		{
			left = mid + 1;
		}
		else
		{
			cout << "Искомое значение находиться в ячейке с индексом: " << mid << endl;
			bool_var = false;
		}
		if (left > right)
		{
			bool_var = false;
		}
	}	
}


void linear_search1(char arr[255][255])
{
	setlocale(LC_ALL, "Ru");
	int counter, result;
	char symbol, next_symbol, next_next_symbol;
	counter = 0, result = 0;
	for (int i = 0; i < 27; i++)
	{
		for (int j = 0; j < 255; j++)
		{
			arr[i][j] = tolower(arr[i][j]);
			symbol = int(arr[i][j]);
			next_symbol = int(arr[i][j+1]);
			next_next_symbol = int(arr[i][j + 2]);
			if ((((symbol >= 97) && (symbol <= 122)) || ((symbol >= 192) && (symbol <= 255))) && ((symbol + 1) == (next_symbol)))
			{
				counter++;
			}
			if ((counter>1)&&((next_symbol + 1) != (next_next_symbol)))
			{
				result++;
				counter = 0;
			}
		}
	}
	cout << "Число фрагментов слов, в которых буквы идут по-алфавиту: " << result << endl;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	char array[255][255] =
	{
		"Some say the world will end in fire,",
		"Some say in ice.",
		"From what I’ve tasted of desire",
		"I hold with those who favor fire.",
		"But if it had to perish twice,",
		"I think I know enough of hate",
		"To say that for destruction ice",
		"Is also great",
		"And would suffice."
	};
	char array1[255][255] = 
	{
		"Что же ? будет ли вино ?",
		"Лайон, жду его давно.",
		"Знаешь ли какого рода ?",
		"У меня закон один :",
		"Жажды полная свобода",
		"И терпимость всяких вин.",
		"Погреб мой гостеприимный",
		"Рад мадере золотой",
		"И под пробкой смоляной",
		"St Пере бутылке длинной.",
		"В лета красные мои,",
		"В лета юности безумной,",
		"Поэтической Аи",
		"Нравился мне пеной шумной,",
		"Сим подобием любви!",
		"вспомнил о поэте",
		"И напененный бокал",
		"Я тогда всему на свете,",
		"Милый брат, предпочитал.",
		"Ныне нет во мне пристрастья —",
		"Без разбора за столом,",
		"Друг разумный сладострастья,",
		"Вина обхожу кругом",
		"Все люблю я понемногу —",
		"Часто двигаю стакан,",
		"Часто пью — но, слава богу,",
		"Редко, редко лягу пьян. абв"
	};

	linear_search1(array);

	int key, size;
	input1:
	cout << "Размер массива: ";
	cin >> size;
	if ((cin.fail()) || (size <= 0))
	{
		cout << "Ввод неверный, попробуйте еще раз" << endl;
		cin.clear();
		cin.ignore(32767, '\n');
		goto input1;
	}
	cout << endl;
	
	input2:
	cout << "Введите искомое значение От 1 до "<<size<<": ";
	cin >> key;
	if ((cin.fail()) || (key < 0)||(key>size))
	{
		cout << "Ввод неверный, попробуйте еще раз" << endl;
		cin.clear();
		cin.ignore(32767, '\n');
		goto input2;
	}
	cout << endl;
	
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = i + 1;
	}
	binary_search(arr, 0, size, key);
	delete[] arr;
	
}


