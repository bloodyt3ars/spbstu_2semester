using namespace std;
#include <iostream>
#include <random>
#include <ctime>   
#include <cassert>

long fibonacci(int n)
{
	if (n < 1)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	return fibonacci(n - 1) + fibonacci(n - 2);
}


long fibonacci_iteration(int n)
{
	long long a = 0;
	long long b = 1;
	for (long long i = 0; i < n; i++)
	{
		a = a + b;
		b = a - b;
	}
	return a;
}


bool prime(long n)
{
	for (long index = 2; index < n; index++)
	{
		if (n % index == 0)
		{
			return  false;
		}
	}
	return true;
}


bool func_value_equality(long func, int n)
{
	if (func == n)
	{
		return true;
	}
	return false;
}


bool func_square_value_equality(long  func, int n)
{
	if (func == n * n)
	{
		return true;
	}
	return false;
}


void fill_array(long  arr[], int i, long n)
{
	arr[i] = n;
}


void print_array(long  arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << " " << arr[i] << " ";
	}
}


 long gcd_Euclid(long  a,  long b)
{
	while (a != b)
	{
		if (a > b)
		{
			long tmp = a;
			a = b;
			b = tmp;
		}
		b = b - a;
	}
	return a;
}


void test()
{
	setlocale(LC_ALL, "Russian");
	assert(fibonacci(5) == 5);
	assert(fibonacci(10) == 55);
	assert(fibonacci(20) == 6765);
	assert(fibonacci(15) == 610);
	assert(fibonacci(18) == 2584);
	assert(fibonacci_iteration(5) == 5);
	assert(fibonacci_iteration(10) == 55);
	assert(fibonacci_iteration(20) == 6765);
	assert(fibonacci_iteration(15) == 610);
	assert(fibonacci_iteration(18) == 2584);
	assert(prime(1) == true);
	assert(prime(3) == true);
	assert(prime(7) == true);
	assert(prime(22) == false);
	assert(prime(99) == false);
	assert(func_value_equality(fibonacci(5), 5) == true);
	assert(func_value_equality(fibonacci(1), 1) == true);
	assert(func_value_equality(fibonacci_iteration(5), 7) == false);
	assert(func_value_equality(20, 20) == true);
	assert(func_value_equality(fibonacci_iteration(5), 5) == true);
	assert(func_square_value_equality(fibonacci(5), 5) == false);
	assert(func_square_value_equality(fibonacci(1), 1) == true);
	assert(func_square_value_equality(fibonacci(12), 12) == true);
	assert(func_square_value_equality(fibonacci_iteration(12), 12) == true);
	assert(func_square_value_equality(16, 4) == true);
	assert(gcd_Euclid(21, 17) == 1);
	assert(gcd_Euclid(119, 147) == 7);
	assert(gcd_Euclid(9, 6) == 3);
	assert(gcd_Euclid(565, 795) == 5);
	assert(gcd_Euclid(3007, 291) == 97);


	cout << "Тесты выполнены успешно!" << endl;
	cout << endl;
}


int main()
{
	test();
	random_device rd;
	mt19937 rndm(rd());
	setlocale(LC_ALL, "Russian");
	long i, year, month, mounth;
	int count_equality = 0, count_square_equality = 0, count_prime = 0;
	cout << "Введите кол-во месяцев: ";
	cin >> i;
	cout << endl;

	for (month = 1; month <= i; ++month)
	{
		long value = fibonacci_iteration(month);
		double fibonacci_division = (double(fibonacci_iteration(month + 1)) / double(fibonacci_iteration(month)));

		year = month / 12;
		mounth = month % 12;
		cout << "Прошел " << year << " лет и " << mounth << " месяцев" << endl;
		cout << "Количество пар кроликов: " << value << endl;
		cout << "Значение F(n+1)/F(n): " << fibonacci_division << endl;
		cout << "Приближенное значение номера числа Фибоначчи: " << month << endl;

		if (func_value_equality(value, month))
		{
			cout << "F(N) = N" << endl;
			count_equality += 1;
		}

		if (func_square_value_equality(value, month))
		{
			cout << "F(N) = N*N" << endl;
			count_square_equality += 1;
		}

		if (prime(value))
		{
			cout << "F(N) - Простое" << endl;
			count_prime += 1;
		}

		cout << endl;
		cout << endl;
	}

	long* arr_equality = new long[count_equality];
	long* arr_square_equality = new long[count_square_equality];
	long* arr_prime = new long[count_prime];

	int index1 = 0, index2 = 0, index3 = 0;

	for (month = 1; month <= i; ++month)
	{
		long value = fibonacci_iteration(month);

		if (func_value_equality(value, month))
		{
			fill_array(arr_equality, index1, value);
			index1 += 1;
		}
		if (func_square_value_equality(value, month))
		{
			fill_array(arr_square_equality, index2, value);
			index2++;
		}
		if (prime(value))
		{
			fill_array(arr_prime, index3, value);
			index3++;
		}
	}

	cout << "Элементы, где F(N)=N " << endl;
	print_array(arr_equality, count_equality);
	cout << endl;
	cout << "Элементы, где F(N)=N*N " << endl;
	print_array(arr_square_equality, count_square_equality);
	cout << endl;
	cout << "Элементы, где F(N) - Простое " << endl;
	print_array(arr_prime, count_prime);
	cout << endl;
	cout << endl;

	int m, nod1, nod2;

	m = ((int(rndm()) % i) + 1);
	nod1 = gcd_Euclid(fibonacci_iteration(i), fibonacci_iteration(m));
	nod2 = gcd_Euclid(i, m);
	cout << "Сгенерировалось число m = " << m << " n = " << i << endl;
	if (nod1 == nod2)
	{
		cout << "Показать, что НОД (Fn, Fm) = НОД (n,m) " << nod1 << " = " << nod2 << endl;
	}
	else
	{
		cout << "Показать, что НОД (Fn, Fm) != НОД (n,m)" << nod1 << " = " << nod2 << endl;
	}

	delete[] arr_equality;
	delete[] arr_square_equality;
	delete[] arr_prime;
	cout << endl;
	cout << endl;
	cout << "runtime = " << clock() / 1000.0 << endl;
}