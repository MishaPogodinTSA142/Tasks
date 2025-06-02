#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

/**
* @brief Считывает значение с клавиатуры с проверкой ввода
* @return Введённое значение
*/
double getValue();

/**
* @brief Проверяет число на то, чтобы оно не было равно нулю или меньше нуля
* @return Введённое значение
*/
void checkValue(const int value);

/**
* @brief Вычисляет факториал числа с использованием гамма-функции
* @param n Число для вычисления факториала
* @return Значение факториала
*/
double factorial(const int n);

/**
* @brief Производит расчёт суммы ряда функции от 1 до n
* @param n - Число ряда, до которого будет посчитана сумма ряда
* @return Сумма ряда функций
*/
double getSum(const int n);

/**
* @brief Производит расчёт суммы ряда функции от 1 до n с минимальным числом для значения ряда
* @param n - Число ряда, до которого будет посчитана сумма ряда
* @param e - Число, с которым будет сравниваться каждое значение ряда
* @return Сумма ряда функций
*/
double getSumE(double const n, double const e);

/**
* @brief - точка входа в программу
* @return -возвращает 0, если функция выполнена верно, иначе 1.
*/
int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Введите количество элементов: ";
    int a = getValue();
    checkValue(a);
    cout << "Введите число, с которым будет сравниваться каждое значение ряда: ";
    double b = getValue();
    cout << "Сумма первых элементов: " << getSum(a) << endl;
    cout << "Сумма элементов после после сравнения: " << getSumE(a, b) << endl;
    return 0;
}

double getValue()
{
    double n;
    if (!(cin >> n))
    {
        cout << "Ошибка" << endl;
        abort();
    }
    return n;
}

void checkValue(const int value)
{
    if (value < 0)
    {
        cout << "Ошибка" << endl;
        abort();
    }
}

double getSum(const int n)
{
    if (n < 1)
    {
        return 0;
    }

    double result = pow(-1, n) * (pow(n, 4) / factorial(n));
    result += getSum(n - 1);

    return result;
}

double getSumE(double const n, double const e)
{
    if (n < 1)
    {
        return 0;
    }

    double result = pow(-1, n) * (pow(n, 4) / factorial(n));

    if (fabs(result) < e)
    {
        return 0;
    }


    result += getSumE(n - 1, e);

    return result;
}

double factorial(int n) {
    return std::tgamma(n + 1);
}