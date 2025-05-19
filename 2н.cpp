#include <iostream>
#include <limits>

using namespace std;

/**
 * @brief  для перевода граммов в унции
 * @param grams вес в граммах 
 * @return вес в унциях 
 */
double gramsToOunces(const double grams);

/**
 * @brief  получения корректного ввода от пользователя
 * @param grams вес в граммах
 * @return орректный ввод пользователя 
 */
double getValidInput();

/**
* @brief точка входа в программу
* @return 0 - если программма выполнена корректно, инече - 1
*/
int main() {
   
    setlocale(LC_ALL, "Russian");
    // Получаем вес в граммах от пользователя
    double grams = getValidInput();

    // Переводим граммы в унции
    double ounces = gramsToOunces(grams);

    // Выводим результат
    cout << grams << " граммов = " << ounces << " унций." << endl;

    return 0;
}

double gramsToOunces(const double grams)
{
    return grams / 28.3;
}

double getValidInput() {
    double input;
    cout << "Введите вес в граммах: ";
    cin >> input;

    // Проверка на ошибки ввода
    if (cin.fail()) {
        cout << "Ошибка: введите число." << endl;
        return -1; // Возвращаем -1 или любое другое значение для обозначения ошибки
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка ввода
    return input;