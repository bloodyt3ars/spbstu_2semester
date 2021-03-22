using namespace std;
#include <iostream>
#include <random>
#include <ctime>   


void circle_circle_intersection(double x1, double y1, double  r1, double  x2, double  y2, double  r2)
{
	const double PI = 3.141592653589793;
	double d, d1, d2, area;
	d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	d1 = (r1 * r1 - r2 * r2 + d * d) / (2*d);
	d2 = d - d1;
	area = ((r1 * r1 * acos(d1 / r1)) - (d1 * sqrt(r1 * r1 - d1 * d1)) + (r2 * r2 * acos(d2 / r2)) - (d2 * sqrt(r2 * r2 - d2 * d2)));
	//https://diego.assencio.com/?index=8d6ca3d82151bad815f78addf9b5c1c6#mjx-eqn-post_8d6ca3d82151bad815f78addf9b5c1c6_A_intersection
	if (d>r1+r2)
	{
		cout << "Пересечений нет." << endl;
	}
	else if (d<=abs(r1-r2))
	{
		cout << "Второй круг находится внутри первого" << endl;
		cout << "Площадь пересечения равна = " << PI * r1 * r1 << endl;
	}
	else if (d <= abs(r2 - r1))
	{
		cout << "Первый круг находится внутри второго" << endl;
		cout << "Площадь пересечения равна = " << PI * r2 * r2 << endl;
	}
	else
	{
		cout << "Площадь пересечения равна = " << area << endl;
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	double x1, y1, R1, x2, y2, R2;
	cout << "Введите x1: ";
	cin >> x1;
	cout << endl << "Введите y1: ";
	cin >> y1;
	cout << endl << "Введите R1: ";
	cin >> R1;
	cout << endl << "Введите x2: ";
	cin >> x2;
	cout << endl << "Введите y2: ";
	cin >> y2;
	cout << endl << "Введите R2: ";
	cin >> R2;
	cout << endl;
	circle_circle_intersection(x1, y1, R1, x2, y2, R2);
}

