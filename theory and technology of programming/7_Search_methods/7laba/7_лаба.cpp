using namespace std;
#include <complex.h>
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <vector>
//Дан текст. Определить число палиндромов в тексте.


void binary_search()
{
	cout << "Бинарный поиск в отсортированной заранее заданой последовательности" << endl;
	vector<int> arr{ 1,2,3,4,5,6,7,8,9,10 };
	int mid, left, right, key;
	left = 0, right = arr.size();
	input:
	cout << "Дан отсортрованный массив от 1 до " << right << endl << "Введите искомое значение От 1 до " << right << ": ";
	cin >> key;
	if ((cin.fail()) || (key < 0) || (key > arr.size()))
	{
		cout << "Ввод неверный, попробуйте еще раз" << endl;
		cin.clear();
		cin.ignore(32767, '\n');
		goto input;
	}
	cout << endl;
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
	cout << "---------------------------------------" << endl;
}


void linear_search(string arr)
{
	cout << "Поиск паллиндромов в тексте" << endl;
	setlocale(LC_ALL, "Ru");
	int counter, result, word_length, word_start_index;
	counter = 0, result = 0; word_length = 0;
	for (int i = 0; i < arr.size();)
	{
		word_start_index = i;
		for (int j = i; ((j < arr.size()) && (arr[i] != ' ')); j++)
		{
			arr[i] = tolower(arr[i]);
			word_length++;
			i++;
		}
		int lenght = word_length+word_start_index-1;
		for (int k = word_start_index; k < lenght; k++, lenght--)
		{
			if (arr[k] != arr[lenght])
			{
				break;
			}
			counter++;
		}
		if ((counter > 0) && (counter == (word_length / 2)))
		{
			result++;
			cout << "Слово-паллиндром: ";
			for (int k = word_start_index; k < word_length + word_start_index; k++)
			{
				cout << arr[k];
			}
			cout << "\t";
		}
		counter = 0;
		word_length = 0;
		i++;
	}
	cout<< endl << "Число палиндромов в тексте: " << result << endl;
	cout << "---------------------------------------" << endl;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string test_arr = "aba k hellolleh водоводов";

	string eng_arr = "It is a long established fact that a reader will be distracted by the readable content of a page when looking at its layout. The point of using Lorem Ipsum is that it has a more-or-less normal distribution of letters, as opposed to using 'Content here, content here', making it look like readable English. Many desktop publishing packages and web page editors now use Lorem Ipsum as their default model text, and a search for 'lorem ipsum' will uncover many web sites still in their infancy. Various versions have evolved over the years, sometimes by accident, sometimes on purpose (injected humour and the like).";

	string ru_arr = "Таким образом, сплочённость команды профессионалов требует определения и уточнения вывода текущих активов. Мы вынуждены отталкиваться от того, что начало повседневной работы по формированию позиции не оставляет шанса для новых предложений. Лишь ключевые особенности структуры проекта являются только методом политического участия и своевременно верифицированы. Повседневная практика показывает, что постоянное информационно-пропагандистское обеспечение нашей деятельности предоставляет широкие возможности для форм воздействия. В своём стремлении повысить качество жизни, они забывают, что внедрение современных методик не даёт нам иного выбора, кроме определения кластеризации усилий. Также как укрепление и развитие внутренней структуры способствует повышению качества укрепления моральных ценностей. Кстати, независимые государства функционально разнесены на независимые элементы. Банальные, но неопровержимые выводы, а также базовые сценарии поведения пользователей являются только методом политического участия и в равной степени предоставлены сами себе. Равным образом, постоянное информационно-пропагандистское обеспечение нашей деятельности обеспечивает актуальность позиций, занимаемых участниками в отношении поставленных задач. Идейные соображения высшего порядка, а также постоянное информационно-пропагандистское обеспечение нашей деятельности позволяет выполнить важные задания по разработке прогресса профессионального сообщества. Для современного мира дальнейшее развитие различных форм деятельности обеспечивает широкому кругу (специалистов) участие в формировании благоприятных перспектив. Безусловно, реализация намеченных плановых заданий обеспечивает широкому кругу (специалистов) участие в формировании вывода текущих активов. Учитывая ключевые сценарии поведения, сплочённость команды профессионалов требует от нас анализа переосмысления внешнеэкономических политик. Мы вынуждены отталкиваться от того, что дальнейшее развитие различных форм деятельности говорит о возможностях глубокомысленных рассуждений! Являясь всего лишь частью общей картины, активно развивающиеся страны третьего мира, превозмогая сложившуюся непростую экономическую ситуацию, представлены в исключительно положительном свете.,";

	linear_search(ru_arr);
	binary_search();
	

}


