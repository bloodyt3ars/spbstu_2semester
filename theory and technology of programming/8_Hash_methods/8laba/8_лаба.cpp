using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <fstream>
//Дана таблица текстовой базы данных записями : фамилия; имя; отчество. Произвести хэширование вместе трех полей и поиск по запросу «Фамилия Имя Отчество»

void str_hash(vector<string>& arr, vector<long long>& hash_result)
{
	int symbol;
	const int first_hash = 37;
	int m = 84761;
	for (int i = 0; i < arr.size(); i++)
	{
		long long temp_hash = 0;
		int p_pow = 1;
		for (int j=0; j<arr[i].size();j++)
		{
			symbol = int(arr[i][j]);
			temp_hash += (symbol - 'a' + 1) * p_pow;
			p_pow *= first_hash;
		}
		hash_result.push_back(temp_hash);
		cout << "hash: " << hash_result[i] % m << "\tФамилия Имя Отчество: " << arr[i] << endl;
	}
	cout << "---------------------------------" << endl;
}


void search(vector<string>& arr, vector<long long>& hash_result)
{
	int counter = 0;
	char choice;
	string result, search_item;
input:
	cout << "Введите ФИО для взаимодействия" << endl; "Ввод: ";
	getline(cin, search_item);
	cout << "Введите 0, если хотите найти коллизию. Введите 1, если хотите найти элемент." << endl; "Ввод: ";
	cin >> choice;
	if ((choice != '1') && (choice != '0'))
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Ввод неверный, попробуйте еще раз." << endl;
		goto input;
	}
	else if (choice == '0')
	{
		vector<string> temp_vector;
		vector<long long> temp_hash;
		temp_vector.push_back(search_item);
		str_hash(temp_vector, temp_hash);
		for (int i = 0; i < hash_result.size(); i++)
		{
			if ((hash_result[i] == temp_hash[0])&&(arr[i]!=temp_vector[0]))
			{
				cout << "Коллизия найден в ячейке под индексом " << i << endl;
				counter++;
			}
		}
		if (counter == 0)
		{
			cout << "Коллизий не обнаружено" << endl;
		}

	}
	else if (choice == '1')
	{
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i] == search_item)
			{
				cout << "Элемент " << search_item << " найден в ячейке под индексом " << i << endl;
				counter++;
				cout << "---------------------------------" << endl;
			}
		}
		if (counter == 0)
		{
			cout << "Элемент найден не был" << endl;
		}
	}

}






int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector<string> arr{ "Фамилия Имя Отчество", "Абросимов Петр Васильевич", "Амайри Юсеф Бассамович", "Антонов Владимир Антонович", "Болсуновский Никита Александрович", "Голубь Алиса Константиновна",
	"Давыдов Даниил Сергеевич", "Денисенко Александ Владимирович", "Долгова Анна Андреевна", "Драчевский Артём Максимович", "Иванова Елизавета Владимировна"};
	vector<long long> hash_result;
	str_hash(arr, hash_result);
	search(arr, hash_result);
}


