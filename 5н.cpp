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
* @brief Производит расчёт суммы ряда функции от 1 до n
* @param n - Число ряда, до которого будет посчитана сумма ряда
* @return Сумма ряда функций
*/
double getSum(const int n);

/**
* @brief Подсчёт рекурентной функции
* @param current - прошлое значение функции
* @param i - порядковый номер ряда
* @return Полученное значение функции
*/
double getNext(const int k);

/**
* @brief Производит расчёт суммы ряда функции от 1 до n
* @param e - Число, до которого будет подсчитываться сумма ряда
* @return Сумма ряда функций до определённого числа
*/
double getSumE(double const e);

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
    cout << "Введите элемент, с которого начнется последовательность: ";
    double b = getValue();
    checkValue(b);
    cout << "Сумма первых элементов: " << getSum(a) << endl;
    cout << "Сумма элементов после отслеживаемого номера: " << getSumE(b) << endl;
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
    double result = 0;
    for (int i = 0; i <= n; i++)
    {
        result += getNext(i);
    }
    return result;
}

double getNext(const int k)
{
    // Вычисляем k! (факториал)
    double factorial = 1;
    for (int i = 1; i <= k; i++)
    {
        factorial *= i;
    }
    // Возвращаем значение по формуле
    return (pow(-1, k) * pow(k, 4)) / factorial;
}

double getSumE(double const e)
{
    double result = 0;
    double current = 1;
    for (int k = 0; (abs(current) > e - numeric_limits<double>::epsilon()); k++)
    {
        result += current;
        current = getNext(k);
    }
    return result;
}