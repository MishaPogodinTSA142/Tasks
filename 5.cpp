#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

/**
 * @brief Вычисляет сумму членов последовательности от 1 до n.
 * Эта функция вычисляет сумму членов последовательности (-1)^k * k^4 / k!
 * для k от 1 до n.
 * @param n Положительное целое число, определяющее количество членов для суммирования.
 * @return Сумма членов последовательности как double.
 */
double sumIntegral(const int n);

/**
 * @brief Вычисляет факториал числа k.
 * Эта функция вычисляет факториал заданного числа k (k!).
 * @param k Целое число, для которого нужно вычислить факториал.
 * @return Факториал числа k как double.
 */
double factorial(const int k);

/**
 * @brief Проверяет корректность ввода значения n.
 * Эта функция запрашивает у пользователя значение n и проверяет,
 * что оно является положительным целым числом.
 * @return Положительное целое число n или -1 в случае ошибки.
 */
int getValidN();

/**
 * @brief Проверяет корректность ввода значения e.
 * Эта функция запрашивает у пользователя значение e и проверяет,
 * что оно является неотрицательным числом.
 * @return Неотрицательное число e как double.
 */
double getValidE();

/**
 * @brief Вычисляет сумму первых n членов последовательности.
 * Эта функция вычисляет сумму первых n членов последовательности
 * (-1)^k * k^4 / k!.
 * @param n Положительное целое число, определяющее количество членов для суммирования.
 * @return Сумма первых n членов последовательности как double.
 */
double sumFirstN(const int n);

/**
 * @brief Вычисляет сумму членов последовательности по модулю не меньших заданного числа e.
 * Эта функция вычисляет сумму членов последовательности (-1)^k * k^4 / k!
 * для k от 1 до n, которые по модулю не меньше e.
 * @param n Положительное целое число, определяющее количество членов для проверки.
 * @param e Неотрицательное число, по модулю которого проверяются члены последовательности.
 * @return Сумма членов по модулю не меньших e как double.
 */
double sumByMagnitude(const int n, const double e);

/**
 * @brief Точка входа для программы
 * @return 0
 */
int main()
{
    setlocale(LC_ALL, "Russian");

    int n = getValidN();
    if (n == -1)
    {
        return 1; // Возвращаем код ошибки
    }

    cout << "Сумма интеграла от k=1 до " << n << " для выражения (-1)^k * k^4 / k!: " << sumIntegral(n) << endl;

    double e = getValidE();
    cout << "Сумма первых " << n << " членов последовательности: " << sumFirstN(n) << endl;
    cout << "Сумма членов по модулю не меньших " << e << ": " << sumByMagnitude(n, e) << endl;

    return 0;
}

int getValidN()
{
    int n;
    cout << "Введите значение n: ";
    cin >> n;

    if (cin.fail() || n <= 0)
    {
        cout << "Ошибка: n должно быть положительным числом." << endl;
        return -1; // Возвращаем -1 для обработки ошибки
    }

    return n;
}

double getValidE()
{
    double e;
    cout << "Введите значение e: ";
    cin >> e;

    if (cin.fail() || e < 0)
    {
        cout << "Ошибка: e должно быть неотрицательным числом." << endl;
        exit(1); // Завершаем программу при ошибке
    }

    return e;
}

double sumIntegral(const int n)
{
    double sum = 0.0;

    for (int k = 1; k <= n; ++k)
    {
        double term = pow(-1, k) * pow(k, 4) / factorial(k);
        sum += term;
    }

    return sum;
}

double factorial(const int k)
{
    if (k == 0 || k == 1) return 1.0;
    double result = 1.0;
    for (int i = 2; i <= k; ++i)
    {
        result *= i;
    }
    return result;
}

double sumFirstN(const int n)
{
    double sum = 0.0;

    for (int k = 1; k <= n; ++k)
    {
        double term = pow(-1, k) * pow(k, 4) / factorial(k);
        sum += term; // Суммируем все члены от 1 до n
    }

    return sum;
}

double sumByMagnitude(const int n, const double e)
{
    double sum = 0.0;

    for (int k = 1; k <= n; ++k)
    {
        double term = pow(-1, k) * pow(k, 4) / factorial(k);
        if (fabs(term) >= e) // Проверяем, по модулю ли член больше или равен e
        {
            sum += term;
        }
    }

    return sum;
}