using namespace std;
#include <iostream>
#include <random>
#include <ctime>   
#include <cassert>


void fill_array(int *arr[], int rows, int cols) //Заполняем массив случайными значениями
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


void print_array(int *arr[], int rows, int cols) //Выводим массив на экран
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout <<arr[i][j] << "\t";
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


void swap(int* a, int* b) //Для обмена местами переменных
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


void bubble_sort(int *arr[], int rows, int cols) //Сортировка пузырьком
{
	cout << "============================================" << endl;
	double t, time;
	t = clock();
	int count_of_comparisons = 0, count_of_permutations = 0;
	for (int i = 0; i<cols; i++)
	{
		for (int j = i + 1; j < cols; j++)
		{
			if(arr[i]>  arr[j])
			{
				swap(arr[i], arr[j]);
				count_of_permutations++;
			}
			count_of_comparisons++;
		}
	}
	cout << endl;
	cout << "Сортировка методом <<пузырька>> выполнена" << endl;
	cout << "Кол-во перестановок: " << count_of_permutations << endl;
	cout << "Кол-во сравнений: " << count_of_comparisons << endl;
	cout << "Отсортированный массив: " << endl;
	print_array(arr, size);
	cout << endl;
	time = (clock() - t) * 1. / CLOCKS_PER_SEC;
	cout << "runtime = " << time << endl << endl << endl;
}


//void selection_sort(int arr[], int size) //Сортировка выбором
//{
//	cout << "============================================" << endl;
//	double t, time;
//	t = clock();
//	int count_of_comparisons = 0, count_of_permutations = 0;
//	for (int i = 0; i < (size - 1); i++)
//	{
//		int min = i;
//		for (int j = i + 1; j < size; j++)
//		{
//			if (arr[j]<arr[min])
//			{
//				min = j;
//				count_of_comparisons++;
//			}
//		}
//		if (min == i)
//		{
//			continue;
//		}
//		swap(arr[min], arr[i]);
//		count_of_permutations++;
//		
//	}
//	cout << endl;
//	cout << "Сортировка методом <<выбора>> выполнена выполнена" << endl;
//	cout << "Кол-во перестановок: " << count_of_permutations << endl;
//	cout << "Кол-во сравнений: " << count_of_comparisons << endl;
//	cout << "Отсортированный массив: " << endl;
//	print_array(arr, size);
//	cout << endl;
//	time = (clock() - t) * 1. / CLOCKS_PER_SEC;
//	cout << "runtime = " << time << endl << endl << endl;
//}
//
//
//void insertion_sort(int arr[], int size) //Сортировка вставками
//{
//	cout << "============================================" << endl;
//	double t, time;
//	t = clock();
//	int count_of_comparisons = 0, count_of_permutations = 0;
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = i-1;j >= 0; j--)
//		{
//			if (arr[j] > arr[j+1])
//			{
//				count_of_permutations++;
//				swap(arr[j], arr[j+1]);
//			}
//			count_of_comparisons++;
//		}
//	}
//	cout << endl;
//	cout << "Сортировка методом <<вставки>> выполнена выполнена" << endl;
//	cout << "Кол-во перестановок: " << count_of_permutations << endl;
//	cout << "Кол-во сравнений: " << count_of_comparisons << endl;
//	cout << "Отсортированный массив: " << endl;
//	print_array(arr, size);
//	cout << endl;
//	time = (clock() - t) * 1. / CLOCKS_PER_SEC;
//	cout << "runtime = " << time << endl << endl << endl;
//	
//}
//
//
//void shell_sort(int arr[], int size) //Сортировка Шелла
//{
//	cout << "============================================" << endl;
//	double t, time;
//	t = clock();
//	int count_of_comparisons = 0, count_of_permutations = 0;
//	for (int step = size / 2; step > 0; step = step / 2)
//	{
//		for (int i = 0; i < size; i++)
//		{
//			for (int j = i + step;j < size; j = j + step)
//			{
//				if (arr[i] > arr[j])
//				{
//					swap(arr[j], arr[i]);
//					count_of_permutations++;
//				}
//				count_of_comparisons++;
//			}
//			
//		}
//	}
//	cout << endl;
//	cout << "Сортировка методом <<Шелла>> выполнена выполнена" << endl;
//	cout << "Кол-во перестановок: " << count_of_permutations << endl;
//	cout << "Кол-во сравнений: " << count_of_comparisons << endl;
//	cout << "Отсортированный массив: " << endl;
//	print_array(arr, size);
//	cout << endl;
//	time = (clock() - t) * 1. / CLOCKS_PER_SEC;
//	cout << "runtime = " << time << endl << endl << endl;
//}
//
//
//void quick_sort(int arr[], int left_tip, int right_tip, int *p_count_of_comparisons, int *p_count_of_permutations)
//{
//	int i_left, j_right, mid;
//	i_left = left_tip;
//	j_right = right_tip;
//	mid = arr[(left_tip + right_tip) / 2];
//	while (i_left <= j_right)
//	{
//		while (arr[i_left] < mid)
//		{
//			i_left++;
//			(*p_count_of_comparisons)++;
//		}
//		while (arr[j_right] > mid)
//		{
//			j_right--;
//			(*p_count_of_comparisons)++;
//		}
//		if (i_left <= j_right)
//		{
//			swap(arr[i_left], arr[j_right]);
//			i_left++;
//			j_right--;
//			(*p_count_of_permutations)++;
//		}
//	}
//	if (left_tip < j_right)
//	{
//		quick_sort(arr, left_tip, j_right, p_count_of_comparisons, p_count_of_permutations);
//	}
//	if (i_left < right_tip)
//	{
//		quick_sort(arr, i_left, right_tip, p_count_of_comparisons, p_count_of_permutations);
//	}
//}
//
//
//void quick_sort_main(int arr[], int left_tip, int right_tip) //Быстрая сортировка
//{
//	cout << "============================================" << endl;
//	double t, time;
//	t = clock();
//	int count_of_comparisons = 0, count_of_permutations = 0;
//	quick_sort(arr, left_tip, right_tip, &count_of_comparisons, &count_of_permutations);
//	cout << endl;
//	cout << "Сортировка методом <<быстрой сортировки>> выполнена выполнена" << endl;
//	cout << "Кол-во перестановок: " << count_of_permutations << endl;
//	cout << "Кол-во сравнений: " << count_of_comparisons << endl;
//	cout << "Отсортированный массив: " << endl;
//	print_array(arr, right_tip);
//	cout << endl;
//	time = (clock() - t) * 1. / CLOCKS_PER_SEC;
//	cout << "runtime = " << time << endl << endl << endl;
//}


int main()
{
	int array_rows, array_cols;
	setlocale(LC_ALL, "Russian");
	cout << "Введите колличество строк: ";
	cin >> array_rows;
	cout << "Введите колличество столбцов: ";
	cin >> array_cols;
	cout << endl;
	int** array = new int*[array_rows];
	for (int i = 0; i < array_rows; i++)
	{
		array[i] = new int[array_cols];
	}
	fill_array(array, array_rows, array_cols);
	cout << "Неотсортированный массив" << endl;
	print_array(array, array_rows, array_cols);
	cout << endl << endl;
	int** copied_array = new int* [array_rows];
	for (int i = 0; i < array_rows; i++)
	{
		copied_array[i] = new int[array_cols];
	}
	copy_array(array, copied_array, array_rows, array_cols);



	/*bubble_sort(copied_array, array_length);
	copy_array(array, copied_array, array_length);
	selection_sort(copied_array, array_length);
	copy_array(array, copied_array, array_length);
	insertion_sort(copied_array, array_length);
	copy_array(array, copied_array, array_length);
	shell_sort(copied_array, array_length);
	copy_array(array, copied_array, array_length);
	quick_sort_main(copied_array, 0, (array_length-1));*/

	for (int i = 0; i < array_rows; i++)
	{
		delete[] array[i];
		delete[] copied_array[i];
	}
	
	delete[] copied_array;
	delete[] array;
} 


