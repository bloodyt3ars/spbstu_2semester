using namespace std;
#include <iostream>


void str_hash(char char_arr[255], long long* hash_array)
{

	int symbol;
	int m = 84761;
	const int first_hash = 37;
	int res = 0, k = 0;
	for (int i = 0; i < (int)strlen(char_arr);)
	{
		int j = 0;
		long long hash_result = 0, p_pow = 1;
		while (j < 10)
		{
			symbol = int(char_arr[i]);
			hash_result += (symbol - 'a' + 1) * p_pow;
			p_pow *= first_hash;
			j++;
			i++;
			if (char_arr[i] == NULL)
			{
				break;
			}
		}
		hash_result = hash_result % m;
		cout << "hash " << (res++) + 1 << "-ой декады элементов: " << hash_result << endl;
		hash_array[k] = hash_result;
		k++;
	}
	cout << "---------------------------------" << endl;
}


void search(long long* first_array, long long* second_array, int first_array_size, int second_array_size)
{
	int collision_counter = 0;
	int bool_var;
	cout << "Введите 0, если хотите найти коллизию. Введите 1, если хотите найти элемент. Ввод: ";
	cin >> bool_var;
	if (bool_var == false)
	{
		for (int i = 0; i < first_array_size; i++)
		{
			for (int j = 0; j < second_array_size; j++)
			{
				if (first_array[i] == second_array[j])
				{
					cout << "Коллизия найдена в индексе i: " << i << " j: " << j << endl;
					collision_counter++;
				}
			}
		}
		cout << "Всего коллизий найдено: " << collision_counter << endl;
		cout << "---------------------------------" << endl;
	}
	else if (bool_var == true)
	{
		int counter = 0;
		int i, j;
		for (i = 0; i < first_array_size; i++)
		{
			for (j = 0; j < second_array_size; j++)
			{
				if (first_array[i] == second_array[j])
				{
					cout << "Элемент " << j << " найден в ячейке под индексом" << i << endl;
					counter++;
					cout << "---------------------------------" << endl;
				}
			}
		}
		if (counter==0)
		{
			cout << "Элемент найден не был" << endl;
		}
	}
}




int get_size(char char_arr[255])
{
	int size;
	if ((strlen(char_arr) / 10) == 0)
	{
		size = (strlen(char_arr) / 10);
	}
	else if ((strlen(char_arr) / 10) != 0)
	{
		size = ((strlen(char_arr) / 10) + 1);
	}
	return size;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	char char_array[255] =
	{
		"Some say the world will end in fire, Some say in ice. From what I’ve tasted of desire I hold with those who favor fire. But if it had to perish twice, I think I know enough of hate To say that for destruction ice Is also great And would suffice"
	};
	char test_array[255] = {
		"say Some world the end will fire in, say Some ice in. Form what tasted I’ve fo erised I dloh those with ohw fire favor. tuB eciffus dluow dnA taerg osla sI eci noitcurtsed rof taht yas oT etah fo hguone wonk I kniht I ,eciwt hsirep ot dah ti fi"
	};
	int size, test_size;
	size = get_size(char_array);
	test_size = get_size(test_array);
	long long* hash_array = new long long[size];
	long long* test_hash_array = new long long[test_size];
	str_hash(char_array, hash_array);
	str_hash(test_array, test_hash_array);
	search(hash_array, test_hash_array, size, test_size);
	
	delete[] test_hash_array;
	delete[] hash_array;
}


