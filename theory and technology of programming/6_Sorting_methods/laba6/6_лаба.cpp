using namespace std;
#include <iostream>
#include <random>
#include <ctime>   
#include <cassert>
int bubble_count_of_comparisons = 0, bubble_count_of_permutations = 0, selection_count_of_comparisons = 0, selection_count_of_permutations = 0, insertion_count_of_comparisons = 0, insertion_count_of_permutations = 0, shell_count_of_comparisons = 0, shell_count_of_permutations = 0, quick_count_of_comparisons = 0, quick_count_of_permutations = 0;

void fill_array(int* arr[], int rows, int cols) //Заполняем массив случайными значениями
{
	random_device rd;
	mt19937 rndm(rd());

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = (int(rndm()) % 1000);
		}
	}
}


void print_array(int* arr[], int rows, int cols) //Выводим массив на экран
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}


void copy_array(int* main_arr[], int* copied_arr[], int rows, int cols) //Копирование массива
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			copied_arr[i][j] = main_arr[i][j];
		}
	}
}


void print_table()
{
	printf("+---------------------------------------------------------------------------+\n");
	printf("|    Метод сортировки    |    Число сравнений    |    Число перестановок    |\n");
	printf("+---------------------------------------------------------------------------+\n");
	printf("|  Сортировка пузырьком  |%23d|%26d|\n", bubble_count_of_comparisons, bubble_count_of_permutations);
	printf("|   Сортировка выбором   |%23d|%26d|\n", selection_count_of_comparisons, selection_count_of_permutations);
	printf("|  Сортировка вставками  |%23d|%26d|\n", insertion_count_of_comparisons, insertion_count_of_permutations);
	printf("|    Сортировка Шелла    |%23d|%26d|\n", shell_count_of_comparisons, shell_count_of_permutations);
	printf("|   Быстрая сортировка   |%23d|%26d|\n", quick_count_of_comparisons, quick_count_of_permutations);
	printf("+---------------------------------------------------------------------------+\n");
}


void swap(int* a, int* b) //Для обмена местами переменных
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


void bubble_sort(int* arr[], int rows, int cols) //Сортировка пузырьком
{
	cout << "============================================" << endl;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			for (int k = j + 1; k < cols; k++)
			{
				if (arr[i][j] > arr[i][k])
				{
					swap(arr[i][j], arr[i][k]);
					bubble_count_of_permutations++;
				}
				bubble_count_of_comparisons++;
			}

		}
	}
	cout << endl;
	cout << "Сортировка методом <<пузырька>> выполнена" << endl;
	cout << "Кол-во перестановок: " << bubble_count_of_permutations << endl;
	cout << "Кол-во сравнений: " << bubble_count_of_comparisons << endl;
	cout << "Отсортированный массив: " << endl;
	print_array(arr, rows, cols);
	cout << endl;
}


void selection_sort(int* arr[], int rows, int cols) //Сортировка выбором
{
	cout << "============================================" << endl;
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < (cols - 1); j++)
		{
			int min = j;
			for (int k = j + 1; k < cols; k++)
			{
				if ((++selection_count_of_comparisons) && (arr[i][k] < arr[i][min]))
				{
					min = k;
				}
			}
			if (min == j)
			{
				continue;
			}
			swap(arr[i][min], arr[i][j]);
			selection_count_of_permutations++;
		}
	}
	cout << endl;
	cout << "Сортировка методом <<выбора>> выполнена выполнена" << endl;
	cout << "Кол-во перестановок: " << selection_count_of_permutations << endl;
	cout << "Кол-во сравнений: " << selection_count_of_comparisons << endl;
	cout << "Отсортированный массив: " << endl;
	print_array(arr, rows, cols);
	cout << endl;
	
}


void insertion_sort(int* arr[], int rows, int cols) //Сортировка вставками
{
	cout << "============================================" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 1; j < cols; j++)
		{
			for (int k = j; k > 0; k--)
			{
				if (arr[i][k - 1] > arr[i][k])
				{
					insertion_count_of_permutations++;
					swap(arr[i][k - 1], arr[i][k]);
				}
				insertion_count_of_comparisons++;
			}
		}
	}
	cout << endl;
	cout << "Сортировка методом <<вставки>> выполнена выполнена" << endl;
	cout << "Кол-во перестановок: " << insertion_count_of_permutations << endl;
	cout << "Кол-во сравнений: " << insertion_count_of_comparisons << endl;
	cout << "Отсортированный массив: " << endl;
	print_array(arr, rows, cols);
	cout << endl;
}


void shell_sort(int* arr[], int rows, int cols) //Сортировка Шелла
{
	cout << "============================================" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int step = cols / 2; step > 0; step = step / 2)
		{
			for (int j = 0; j < cols; j++)
			{
				for (int k = j + step; k < cols; k = k + step)
				{
					if (arr[i][j] > arr[i][k])
					{
						swap(arr[i][k], arr[i][j]);
						shell_count_of_permutations++;
					}
					shell_count_of_comparisons++;
				}

			}
		}
	}

	cout << endl;
	cout << "Сортировка методом <<Шелла>> выполнена выполнена" << endl;
	cout << "Кол-во перестановок: " << shell_count_of_permutations << endl;
	cout << "Кол-во сравнений: " << shell_count_of_comparisons << endl;
	cout << "Отсортированный массив: " << endl;
	print_array(arr, rows, cols);
	cout << endl;
}


void quick_sort(int* arr[], int left_tip, int right_tip, int* p_count_of_comparisons, int* p_count_of_permutations, int* i)
{
	int i_left, j_right, mid;
	i_left = left_tip;
	j_right = right_tip;
	mid = arr[*i][(left_tip + right_tip) / 2];
	do
	{
		while ((++(*p_count_of_comparisons)) && (arr[*i][i_left] < mid))
		{
			i_left++;
		}
		while ((++(*p_count_of_comparisons)) && (arr[*i][j_right] > mid))
		{
			j_right--;
		}
		if (i_left <= j_right)
		{
			if (arr[*i][i_left] != arr[*i][j_right])
			{
				swap(arr[*i][i_left], arr[*i][j_right]);
				++(*p_count_of_permutations);
			};
			i_left++;
			j_right--;
		}
	} while (i_left <= j_right);
	if (left_tip < j_right)
	{
		quick_sort(arr, left_tip, j_right, p_count_of_comparisons, p_count_of_permutations, i);
	}
	if (i_left < right_tip)
	{
		quick_sort(arr, i_left, right_tip, p_count_of_comparisons, p_count_of_permutations, i);
	}
}


void quick_sort_main(int* arr[], int rows, int left_tip, int right_tip) //Быстрая сортировка
{
	cout << "============================================" << endl;
	for (int i = 0; i < rows; i++)
	{
		quick_sort(arr, left_tip, (right_tip - 1), &quick_count_of_comparisons, &quick_count_of_permutations, &i);
	}

	cout << endl;
	cout << "Сортировка методом <<быстрой сортировки>> выполнена выполнена" << endl;
	cout << "Кол-во перестановок: " << quick_count_of_permutations << endl;
	cout << "Кол-во сравнений: " << quick_count_of_comparisons << endl;
	cout << "Отсортированный массив: " << endl;
	print_array(arr, rows, right_tip);
	cout << endl;
}


void task_sort(int* arr[], int rows, int cols)
{
	cout << "============================================" << endl;
	//Упорядочить диагональные элементы матрицы по возрастанию.
	for (int i = 0; i<rows-1;i++)
	{
		for (int j = i+1; j<rows;j++)
		{
			if (arr[i][i]>arr[j][j])
			{
				swap(arr[i][i], arr[j][j]);
			}
		}
	}
	cout << endl;
	cout << "Сортировка методом <<По заданию>> выполнена выполнена" << endl;
	cout << "Отсортированный массив: " << endl;
	print_array(arr, rows, cols);
}


int main()
{
	int array_rows, array_cols;
	setlocale(LC_ALL, "Russian");
input1:
	cout << "Введите колличество строк: ";
	cin >> array_rows;
	if ((cin.fail()) || (array_rows <= 0))
	{
		cout << "Ввод неверный, попробуйте еще раз" << endl;
		cin.clear();
		cin.ignore(32767, '\n');
		goto input1;
	}
input2:
	cout << "Введите колличество столбцов: ";
	cin >> array_cols;
	if ((cin.fail()) || (array_cols <= 0))
	{
		cout << "Ввод неверный, попробуйте еще раз" << endl;
		cin.clear();
		cin.ignore(32767, '\n');
		goto input2;
	}
	cout << endl;
	int** array = new int* [array_rows];
	int** copied_array = new int* [array_rows];
	for (int i = 0; i < array_rows; i++)
	{
		array[i] = new int[array_cols];
		copied_array[i] = new int[array_cols];
	}
	fill_array(array, array_rows, array_cols);
	cout << "Неотсортированный массив" << endl;
	print_array(array, array_rows, array_cols);
	cout << endl << endl;
	copy_array(array, copied_array, array_rows, array_cols);
	bubble_sort(copied_array, array_rows, array_cols);
	copy_array(array, copied_array, array_rows, array_cols);
	selection_sort(copied_array, array_rows, array_cols);
	copy_array(array, copied_array, array_rows, array_cols);
	insertion_sort(copied_array, array_rows, array_cols);
	copy_array(array, copied_array, array_rows, array_cols);
	shell_sort(copied_array, array_rows, array_cols);
	copy_array(array, copied_array, array_rows, array_cols);
	quick_sort_main(copied_array, array_rows, 0, array_cols);
	copy_array(array, copied_array, array_rows, array_cols);
	task_sort(copied_array, array_rows, array_cols);
	print_table();
	for (int i = 0; i < array_rows; i++)
	{
		delete[] array[i];
		delete[] copied_array[i];
	}

	delete[] copied_array;
	delete[] array;
}


