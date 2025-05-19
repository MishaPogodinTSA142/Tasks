#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

/**
*@brief Считывает значиния с клавиатуры с проверкой ввода
*@return возвращает значение, если оно правильное , иначе завершает программу
*/
double getValue();

/**
*@brief  Функция для вычисления значения функции y = cos(2/x) - 2*sin(1/x) + 1/x
*@return cos(2/x) - 2*sin(1/x) + 1/x
*/

double calculate_expression(const double x);
/**
*@brief  Функция для проверки, что шаг положительный
*@param step шаг с которым идёт постороение графика
*@return step
*/
double getPositiveStep();

/**
 *@brief  запрашивает у пользователя ввод положительного значения x,
 * и продолжает запрашивать значение до тех пор, пока не будет введено положительное число.
 * @return Возвращает введенное положительное значение x.
 */
double getPositiveX();

/**
*@brief  Функция для проверки, что значение x является ООФ
*@param x значение x
*@return true, если x является ООФ, иначе false
*/
bool isOOF(double x);

/**
*@brief  точка хода в программу
*@return 0
*/
int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Введите начальное значение x: ";
    double startX = getPositiveX();

    cout << "Введите конечное значение x: ";
    double endX = getPositiveX();

    if (startX > endX)
    {
        cout << "Ошибка: xstart должно быть меньше, чем xend" << endl;
        return 1;
    }

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
    double value;
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
    double step;
    do {
        cout << "Введите шаг: ";
        step = getValue();
        if (step <= 0)
        {
            cout << "Ошибка. Шаг должен быть положительным. Повторите ввод." << endl;
        }
    } while (step <= 0);
    return step;
}

double getPositiveX()
{
    double x;
    do {
        cout << "Введите положительное значение x: ";
        x = getValue();
        if (x <= 0)
        {
            cout << "Ошибка. X должно быть положительным. Повторите ввод." << endl;
        }
    } while (x <= 0);
    return x;
}

bool isOOF(double x)
{
    if (x == 0) 
    {
        cout << "x не должен быть равен 0." << endl;
        return false;
    }
    return x;
}