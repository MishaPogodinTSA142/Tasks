#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>

using namespace std;

/**
 * @brief оператор выбора способа заполнения массива
 * @param RANDOM = 0 автоматическое заполнение
 * @param MANUALLY = 1 ручное заполнение
 */
enum SELECT
{
    RANDOM = 0,
    MANUALLY = 1
};

/**
 * @brief считывает значение типа int
 * @return считанное значение целочисленное
 */
int getNumber();

/**
 * @brief проверяет размер массива
 * @param n - размер массива
 */
void checkN(const int n);

/**
 * @brief проверяет диапазон
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void checkRange(const int min, const int max);

/**
 * @brief возвращает новый двумерный массив.
 * @param rows - кол-во строк массива
 * @param cols - кол-во столбцов массива
 * @return - новый массив
 */
int** getNewArray(int const rows, int const cols);

/**
 * @brief заполнение массива вручную
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillArray(int** arr, int const rows, int const cols, int const min, int const max);

/**
 * @brief заполнение массива автоматически случайными числами в заданном диапазоне
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillArrayRandom(int** arr, int const rows, int const cols, int const min, int const max);

/**
 * @brief Выводит массив на экран
 * @param arr - массив
 * @param n - кол-во строк
 * @param m - кол-во столбцов
 */
void printArray(int** arr, int const n, int const m);

/**
 * @brief изменяет знак у каждого максимального элемента в столбце.
 * @param arr - массив
 * @param rows - размер массива
 * @param cols - кол-во столбцов
 */
void replaceMaxWithNegative(int** arr, int const rows, int const cols);

/**
 * @brief Возвращает новый массив с добавленными столбцами из нулей после максимального элемента массива в столбце.
 * @param arr - массив
 * @param rows - размер массива
 * @param cols - кол-во столбцов
 * @return - новый массив
 */
int** insertZeroColumns(int**& arr, const int rows, const int cols);

/**
 * @brief проверяет диапазон
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void checkRange(const int min, const int max);

/**
 * @brief проверяет диапазон
 * @param arr - массив
 * @param rows - кол-во строк
 */
void delArray(int** arr,const int rows);

/**
* @brief точка входа в программу
* @return 0 - если программма выполнена корректно, инече - 1
*/
int main() {
    setlocale(LC_ALL, "rus");

    cout << "Введите количество строк в массиве: ";
    int rows = getNumber();
    checkN(rows);
    cout << "Введите количество столбцов в массиве: ";
    int cols = getNumber();
    checkN(cols);

    int** arr = getNewArray(rows, cols);

    cout << "Введите минимальное и максимальное значение диапазона: ";
    int minValue = getNumber();
    int maxValue = getNumber();
    checkRange(minValue, maxValue);

    cout << "Введите выбор для заполнения двумерного массива: " << endl
        << RANDOM << " Для случайного заполнения" << endl
        << MANUALLY << " Для ручного заполнения" << endl;

    int choice = getNumber();

    switch ((enum SELECT)choice) {
    case RANDOM:
        fillArrayRandom(arr, rows, cols, minValue, maxValue);
        break;
    case MANUALLY:
        fillArray(arr, rows, cols, minValue, maxValue);
        break;
    default:
        cout << "Ваш выбор неправильный" << endl;
        delArray(arr, rows); // Освобождение памяти
        return 0;
    }

    cout << "Элементы двумерного массива:" << endl;
    printArray(arr, rows, cols);

    // Заменяем максимальные элементы на противоположные
    cout << "Новый массив с замененными элементами:" << endl;
    replaceMaxWithNegative(arr, rows, cols);

    // Вставляем столбцы из нулей после максимальных элементов
    cout << "Новый массив со столбцами из нулей после максимального элемента в столбце:" << endl;
    int** arrWithZeros = insertZeroColumns(arr, rows, cols);

    // Освобождение памяти
    delArray(arr, rows);
    delArray(arrWithZeros, rows);

    return 0;
}

int getNumber()
{
    int number = 0;
    cin >> number;
    if (cin.fail())
    {
        cout << "Неправильный ввод данных";
        abort();
    }
    return number;
}

void checkN(const int n)
{
    if (n <= 0)
    {
        cout << "Неправильный размер массива" << endl;
        abort();
    }
}

void checkRange(const int min, const int max)
{
    if (min > max)
    {
        cout << "Введен неправильный диапазон" << endl;
        abort();
    }
}

int** getNewArray(int const rows, int const cols)
{
    int** arr = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
    }
    return arr;
}

void fillArrayRandom(int** arr, int const rows, int const cols, int const min, int const max)
{
    srand((time(0)));
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            arr[i][j] = rand() % (max - min + 1) + min;
        }
    }
}

void fillArray(int** arr, const int rows, const int cols, const int min, const int max)
{
    cout << "Введите элементы массива (диапазон [" << min << ".." << max << "]):" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            while (true) {  // Повторяем ввод, пока не получим корректное значение
                cout << "arr[" << i << "][" << j << "]: ";
                int value = getNumber();  // Предполагается, что getNumber() возвращает int

                if (value >= min && value <= max) {
                    arr[i][j] = value;
                    break;  // Выходим из цикла while при успешном вводе
                } else {
                    cout << "Ошибка: значение должно быть между " << min << " и " << max
                         << ". Пожалуйста, повторите ввод." << endl;
                }
            }
        }
    }
}

void printArray(int** arr, const int rows, const int cols)
{
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            cout << setw(5) << arr[i][j];
        }
        cout << '\n';
    }
    cout << endl;
}

void replaceMaxWithNegative(int** arr, int const rows, int const cols)
{
    // Копируем элементы из исходного массива в новый
    int** newArr = new int*[rows];
    for (size_t i = 0; i < rows; ++i) {
        newArr[i] = new int[cols];
        copy(arr[i], arr[i] + cols, newArr[i]);
    }

    // В каждой строке находим максимум и меняем знак
    for (size_t i = 0; i < rows; ++i) {
        int max_pos = max_element(newArr[i], newArr[i] + cols) - newArr[i];
        newArr[i][max_pos] = -newArr[i][max_pos];
    }

    printArray(newArr, rows, cols);
    delArray(newArr, rows);
}

int** insertZeroColumns(int** arr, int rows, int cols)
{
    // Находим максимальный элемент
    int maxElement = arr[0][0];
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (arr[i][j] > maxElement) {
                maxElement = arr[i][j];
            }
        }
    }

    // Находим индексы столбцов, содержащих максимальный элемент
    bool* isColumnWithMax = new bool[cols]();
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            if (arr[i][j] == maxElement) {
                isColumnWithMax[j] = true;
                break;
            }
        }
    }

    // Подсчитываем, сколько столбцов нужно добавить
    int newCols = cols;
    for (int j = 0; j < cols; ++j) {
        if (isColumnWithMax[j]) {
            newCols++; // +1 нулевой столбец после каждого "максимального"
        }
    }

    // Создаём новый массив с увеличенным количеством столбцов
    int** newArr = new int*[rows];
    for (size_t i = 0; i < rows; ++i) {
        newArr[i] = new int[newCols];
        int newJ = 0;
        for (size_t j = 0; j < cols; ++j) {
            newArr[i][newJ++] = arr[i][j]; // копируем текущий элемент
            if (isColumnWithMax[j]) {
                newArr[i][newJ++] = 0; // вставляем нулевой столбец
            }
        }
    }

    delete[] isColumnWithMax;
    printArray(newArr, rows, newCols);

    return newArr;
}

void delArray(int** arr, int const rows)
{
    for (size_t i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}
