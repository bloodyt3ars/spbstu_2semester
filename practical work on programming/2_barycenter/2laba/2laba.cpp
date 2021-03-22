
using namespace std;
#include <iostream>
#include <vector>



int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите кол-во вершин: ";
	cin >> n;
	vector<int> x_coord(n);
	vector<int> y_coord(n);
	double square = 0, result = 0;
	for (int i = 0; i < n; i++)
	{
		cout << "x y: ";
		cin >> x_coord[i] >> y_coord[i];
	}
	for (int i = 1; i < n; i++)
	{
		square += (x_coord[i-1] * y_coord[i] - x_coord[i] * y_coord[i-1]);
	}
	square = square / 2;
	for (int i = 1; i < n; i++)
	{
		result += (x_coord[i-1] + x_coord[i])*(x_coord[i-1] * y_coord[i]- x_coord[i] * y_coord[i-1]);
	}
	result = result / (6 * square);
	printf("%.10f", result);
}


