#include <iostream>
#include <locale>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * @brief Считывает целое значение с клавиатуры с проверкой ввода.
 * @return Введённое целое значение.
 * @note Если ввод некорректен, программа завершается с ошибкой.
 */
int getIntValue();

/**
 * @brief Считывает вещественное значение с клавиатуры с проверкой ввода.
 * @return Введённое вещественное значение.
 * @note Если ввод некорректен, программа завершается с ошибкой.
 */
double getDoubleValue();

/**
 * @brief Проверяет, что число положительное.
 * @param value Число для проверки.
 * @note Если число не положительное, программа завершается с ошибкой.
 */
void checkPositive(const int value);

/**
 * @brief Проверяет, что число положительное.
 * @param value Число для проверки.
 * @note Если число не положительное, программа завершается с ошибкой.
 */
void checkPositive(const double value);

/**
 * @brief Вычисляет сумму первых n членов ряда \(\sum_{k=1}^n (-1)^k \frac{k^4}{k!}\).
 * @param n Количество членов ряда.
 * @return Сумма ряда.
 */
double calculateFirstNSeriesSum(const int n);

/**
 * @brief Вычисляет сумму всех членов ряда \(\sum (-1)^k \frac{k^4}{k!}\), по модулю не меньших ε.
 * @param epsilon Заданная точность (положительное число).
 * @return Сумма членов ряда, удовлетворяющих условию.
 */
double calculateSeriesSumAboveEpsilon(const double epsilon);


/**
 * @brief Точка входа в программу.
 * @return 0.
 */
int main() {
    setlocale(LC_ALL, "rus");

    cout << "Часть a: Сумма первых n членов ряда" << endl;
    cout << "Введите количество элементов ряда (n > 0): ";
    int n = getIntValue();
    checkPositive(n);
    cout << "Сумма первых " << n << " членов ряда: "
        << fixed << setprecision(10) << calculateFirstNSeriesSum(n) << endl;

    cout << "\nЧасть b: Сумма членов ряда, не меньших по модулю ε" << endl;
    cout << "Введите значение e (e > 0): ";
    double epsilon = getDoubleValue();
    checkPositive(epsilon);
    cout << "Сумма членов ряда, не меньших по модулю " << epsilon << ": "
        << fixed << setprecision(10) << calculateSeriesSumAboveEpsilon(epsilon) << endl;

    return 0;
}

int getIntValue() {
    int value = 0;
    cin >> value;
    if (cin.fail()) {
        cerr << "Ошибка: введено некорректное значение!" << endl;
        abort();
    }
    return value;
}

double getDoubleValue() {
    double value = 0;
    cin >> value;
    if (cin.fail()) {
        cerr << "Ошибка: введено некорректное значение!" << endl;
        abort();
    }
    return value;
}

void checkPositive(const int value) {
    if (value <= 0) {
        cerr << "Ошибка: значение должно быть положительным!" << endl;
        abort();
    }
}

void checkPositive(const double value) {
    if (value <= 0) {
        cerr << "Ошибка: значение должно быть положительным!" << endl;
        abort();
    }
}

double calculateFirstNSeriesSum(const int n) {
    double sum = 0.0;
    double term = -1.0;

    for (int k = 1; k <= n; ++k) {
        sum += term;
        term *= -1 * (pow(k + 1, 3) / pow(k, 4));
    }

    return sum;
}

double calculateSeriesSumAboveEpsilon(const double epsilon) {
    double sum = 0.0;
    int k = 1;
    double term = -1.0;

    while (fabs(term) >= epsilon) {
        sum += term;
        term *= -1 * (pow(k + 1, 3) / pow(k, 4));
        k++;
    }

    return sum;
}
