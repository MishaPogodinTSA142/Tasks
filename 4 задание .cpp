#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

/**
 *@brief Считывает значения с клавиатуры с проверкой ввода
 *@return возвращает значение, если оно правильное , иначе завершает программу
 */
double getValue();

/**
 *@brief Функция для вычисления значения функции y = cos(2/x) - 2*sin(1/x) + 1/x
 *@return cos(2/x) - 2*sin(1/x) + 1/x
 */
double calculate_expression(const double x);

/**
 *@brief Функция для проверки, что шаг положительный
 *@param step шаг с которым идёт построение графика
 *@return step
 */
double getPositiveStep();

/**
 *@brief  Функция для проверки, что значение x является ООФ
 *@param x значение x
 *@return true, если x является ООФ, иначе false
 */
bool isOOF(double x);

/**
 *@brief Точка входа в программу
 *@return возвращает 0, если программа выполнена корректно
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите начальное значение x: ";
    double startX = getValue();
    cout << "Введите конечное значение x: ";
    double endX = getValue();
    cout << "Введите шаг: ";
    double step = getPositiveStep();

    cout << "x | y" << endl;
    cout << "--------" << endl;

    for (double x = startX; x < endX + step; x += step)
    {
        if (isOOF(x))
        {
            double y = calculate_expression(x);
            cout << x << " | " << y << endl;
        }
    }

    return 0;
}

double getValue()
{
    double value = 0;
    cin >> value;
    if (cin.fail())
    {
        cout << "Некорректное значение" << endl;
        abort();
    }
    return value;
}


double calculate_expression(const double x) {
    double y = cos(2 / x) - 2 * sin(1 / x) + 1 / x;
    return y;
}

double getPositiveStep()
{
    double step = getValue();
        if (step <= 0)
        {
            cout << "Шаг должен быть положительным" << endl;
            abort();
        }
    return step;
}

bool isOOF(double x)
{
    return (fabs(x) > std::numeric_limits<double>::epsilon());
}