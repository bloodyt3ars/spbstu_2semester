using namespace std;
#include <iostream>
#include <windows.h>
#include <vector>
#include <cmath>
#include <string>
#include <iomanip>


long double factorial(int N)
{
    if (N < 0) 
        return 0; 
    if (N == 0) 
        return 1; 
    else 
        return N * factorial(N - 1); 
}


double input(double input_var, const string str)
{
    input:
    cout << str;
    cin >> input_var;
    if (cin.fail())
    {
        cout << "Ввод неверный, попробуйте еще раз" << endl;
        cin.clear();
        cin.ignore(32767, '\n');
        goto input;
    }
    return input_var;
}


void condition_check(double* x_start, double* x_end, double* delta_x, double* epsilon, double* x_ideal)
{
    const double PI = acos(-1.0);
    bool bool_var = true;
    while (bool_var)
    {
        while (*x_start > *x_end)
        {
            cout << "x_start не может быть больше x_end" << endl;
            *x_start = input(*x_start, "Введите x_start: ");
            *x_end = input(*x_end, "Введите x_end: ");
        }
        while ((*x_start > PI) || (*x_start < -PI))
        {
            cout << "x_start не может быть больше(меньше) числа PI" << endl;
            *x_start = input(*x_start, "Введите x_start: ");
        }
        while ((*x_end > PI) || (*x_end < -PI))
        {
            cout << "x_end не может быть больше(меньше) числа PI" << endl;
            *x_end = input(*x_end, "Введите x_end: ");
        }
        while (*delta_x < 0)
        {
            cout << "delta_x не может быть меньше 0" << endl;
            *delta_x = input(*delta_x, "Введите delta_x: ");
        }
        while ((*delta_x + *x_start) > *x_end)
        {
            cout << "Выражение delta_x + x_start должно быть НЕ больше Xend " << endl;
            *delta_x = input(*delta_x, "Введите delta_x: ");
        }
        while ((*epsilon > 1) || (*epsilon < 0.00001))
        {
            cout << "0.00001<=epsilon<=1 " << endl;
            *epsilon = input(*epsilon, "Введите epsilon: ");
        }
        while ((*x_ideal > 1000) || (*x_ideal < -1000))
        {
            cout << "-1000<x_ideal<1000" << endl;
            *x_ideal = input(*x_ideal, "Введите x_ideal: ");
        }
        /*if ((*x_start > *x_end) && ((*x_start > PI) || (*x_start < -PI)) && ((*x_end > PI) || (*x_end < -PI)) && (*delta_x < 0) && ((*delta_x + *x_start) > *x_end) && ((*epsilon > 1) || (*epsilon < 0.00001)) && ((*x_ideal > 1000) || (*x_ideal < -1000)))
        {
            bool_var = false;
            break;
        }*/
        bool_var = false;
    }
}


double mathematical_series(double x,int n)
{
    double first = -((pow(x, 3)) / 6);
    double series_increment = (-(pow(x, 2) / ((2 * n + 1) * 2 * n)));
    double my_function = x;
    for (int i = 1; i < n; i++)
    {
        my_function += first *series_increment;
    };
    return my_function; 
}


double function_sin(double x)
{
    return sin(x);
}

int decimal_places(double epsilon)
{
    int number_decimal_places = 0;
    for (; epsilon < 1; number_decimal_places++)
    {
        epsilon *= 10;
    }
    return number_decimal_places;
}


void print_table_1(double x_start, double x_end, double delta_x, double epsilon)
{
    int n = 1;
    double x;
    int decimal = decimal_places(epsilon);
    printf("+----------------------------------------------------------------------------------------+\n");
    printf("|       X      |     My Function(x)       |      Function(x)     |        Sigma X        |\n");
    printf("+----------------------------------------------------------------------------------------+\n");
    for (x = x_start; x<=x_end; x+=delta_x, n++)
    {
        double my_function = mathematical_series(x, n);
        double function = function_sin(x);
        double sigma = sqrt(abs(my_function * my_function - function * function));
        cout << "|" << std::setw(14) << fixed << std::setprecision(decimal) << x << 
            "|" << std::setw(26) << std::setprecision(decimal) << my_function << 
            "|" << std::setw(22) << std::setprecision(decimal) << function << "|" 
            << setw(23) << std::setprecision(decimal) << sigma << "|" << endl;
    }
    printf("+----------------------------------------------------------------------------------------+\n");
}


void print_table_2(double x_ideal)
{
    int n = 1;
    double x;
    int decimal = 1;
    double epsilon = 0.1;
    printf("+----------------------------------------------------------------------------------------+\n");
    printf("|    Epsilon   |     My Function(x)       |      Function(x)     |        Sigma X        |\n");
    printf("+----------------------------------------------------------------------------------------+\n");
    for (x = x_ideal; epsilon > 0.0000001; epsilon*=0.1, decimal++)
    {
        double my_function = mathematical_series(x, n);
        double function = function_sin(x);
        double sigma = sqrt(abs(my_function * my_function - function * function));
        cout << "|" << std::setw(14) << fixed << std::setprecision(decimal) << epsilon <<
            "|" << std::setw(26) << std::setprecision(decimal) << my_function <<
            "|" << std::setw(22) << std::setprecision(decimal) << function << "|"
            << setw(23) << std::setprecision(decimal) << sigma << "|" << endl;
    }
    printf("+----------------------------------------------------------------------------------------+\n");
}


int main()
{
    double x_start = 0, x_end = 0, delta_x = 0, epsilon = 0, x_ideal = 0;
    setlocale(LC_ALL, "Russian");
    cout << "Сейчас вам предложат ввести набор данных. Вот условия для этих данных:" << endl
        << "1. x_start не может быть больше x_end" << endl << "2. x_start не может равняться x_end"<< endl 
        << "3. delta_x должен быть больше 0" << endl << "4. x_start + delta_x не может быть больше x_end" << endl 
        << "5. epsilon - число вида 1 * 10 ^ (-n).Вам нужно указать epsilon в виде дроби" << endl
        << "6. 0,00001<=epsilon<=1" << endl 
        << "7. epsilon - число из пересечения промежутка [x_start; x_end] and { 0 }" << endl
        <<"8. x_start и x_end не должны быть больше модуля числа PI" <<endl;
    x_start = input(x_start, "Введите x_start: ");
    x_end = input(x_end, "Введите x_end: ");
    delta_x = input(delta_x, "Введите delta_x: ");
    epsilon = input(epsilon, "Введите epsilon: ");
    x_ideal = input(x_ideal, "Введите x_ideal: ");
    condition_check(&x_start, &x_end, &delta_x, &epsilon, &x_ideal);
    print_table_1(x_start, x_end, delta_x, epsilon);
    print_table_2(x_ideal);

}



