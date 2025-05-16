#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

/**
 * @brief оператор выбоа способа заполнения массива
 * @param RANDOM = 0 автоматическое заполнение
 * @param MANUALLY =1 ручное заполнение
 */
enum SELECT 
{
    RANDOM = 0,
    MANUALLY = 1
};
/**
 * @brief считывает значение типа int
 * @return считанное значение
 */
int getValue();

/**
 * @brief заполнение массива вручную
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillArray(int** arr, int const rows, int const cols, int const min, int const max);

/**
 * @brief Выводит массив на экран
 * @param arr - массив
 * @param n - кол-во строк
 * @param m - кол-во столбцов
 */
void printArray(int** arr, int const n, int const m);

/**
 * @brief заменяет минимальные абсолютные значения на нули.
 * @param arr - массив
 * @param n - размер массива
 * @param m - кол-во столбцов
 */
void replaceMaxWithNegative(int** arr, int const n, int const m);


void insertZeroColumns(int**& arr, int rows, int cols);

/**
 * @brief заполнение массива автоматически случайнвми числами в заданном диапазоне
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillArrayRandom(int** arr, int const rows, int const cols, int const min, int const max);

/**
 * @brief проверяет диапазон
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void checkRange(int const min, int const max);

/**
 * @brief проверяет правильность введенного размера массива.
 * @param n - размер массива
 */
void checkN(int const n);

/**
 * @brief проверяет диапазон
 * @param arr - массив
 * @param rows - кол-во строк
 */
void delArray(int** arr, int const rows);

/**
 * @brief создает новый массив.
 * @param rows - кол-во строк массива
 * @param cols - кол-во столбцов массива
 * @return - новый массив
 */
int** getNewArray(int const rows, int const cols);

/**
* @brief точка входа в программу
* @return 0 - если программма выполнена корректно, инече - 1
*/
int main() {
    setlocale(LC_ALL, "rus");
    cout << "Введите количество строк в массиве: ";
    int rows = getValue();
    checkN(rows);
    cout << "Введите количество столбцов в массиве: ";
    int cols = getValue();
    checkN(cols);

    int** arr = getNewArray(rows, cols);

    cout << "Введите минимальное и максимальное значения диапазона: " << endl;
    int minValue = getValue();
    int maxValue = getValue();
    checkRange(minValue, maxValue);

    cout << "Введите свой выбор для заполнения массива: " << endl
        << RANDOM << " заполнить случайно" << endl
        << MANUALLY << " заполнить вручную" << endl;

    int choice = getValue();

    switch (static_cast<SELECT>(choice)) {
    case RANDOM:
        fillArrayRandom(arr, rows, cols, minValue, maxValue);
        break;
    case MANUALLY:
        fillArray(arr, rows, cols, minValue, maxValue);
        break;
    default:
        cout << "Ваш выбор неправильный" << endl;
        delArray(arr, rows); // Освобождение памяти
        return 1;
    }

    printArray(arr, rows, cols);

    // Заменяем максимальные элементы на противоположные
    replaceMaxWithNegative(arr, rows, cols);
    cout << "Массив после замены максимальных элементов на противоположные:" << endl;
    printArray(arr, rows, cols);

    // Вставляем столбцы из нулей после максимальных элементов
    insertZeroColumns(arr, rows, cols);
    cout << "Массив после вставки столбцов из нулей:" << endl;
    printArray(arr, rows, cols);

    // Освобождение памяти
    delArray(arr, rows);

    return 0;
}

int getValue() {
    int value;
    cin >> value;
    return value;
}

void fillArray(int** arr, int const rows, int const cols, int const min, int const max) {
    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "arr[" << i << "][" << j << "]: ";
            arr[i][j] = getValue();
        }
    }
}

void printArray(int** arr, int const n, int const m) {
    cout << "Массив:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << setw(4) << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void fillArrayRandom(int** arr, int const rows, int const cols, int const min, int const max) {
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = rand() % (max - min + 1) + min;
        }
    }
}

void checkRange(int const min, int const max) {
    if (min >= max) {
        cout << "Некорректный диапазон!" << endl;
        exit(1);
    }
}

void checkN(int const n) {
    if (n <= 0) {
        cout << "Размер должен быть больше нуля!" << endl;
        exit(1);
    }
}

void delArray(int** arr, int const rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}

int** getNewArray(int const rows, int const cols) {
    int** arr = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
    }
    return arr;
}

// Функция для замены максимального элемента каждой строки на противоположный по знаку
void replaceMaxWithNegative(int** arr, int const n, int const m) {
    for (int i = 0; i < n; ++i) {
        int maxIndex = 0;
        for (int j = 1; j < m; ++j) {
            if (arr[i][j] > arr[i][maxIndex]) {
                maxIndex = j;
            }
        }
        arr[i][maxIndex] = -arr[i][maxIndex];
    }
}

// Функция для вставки столбца из нулей после всех столбцов, содержащих максимальный элемент
void insertZeroColumns(int**& arr, int rows, int cols) {
    int newCols = cols;
    for (int i = 0; i < rows; ++i) {
        int maxIndex = 0;
        for (int j = 1; j < cols; ++j) {
            if (arr[i][j] > arr[i][maxIndex]) {
                maxIndex = j;
            }
        }
        // Если нашли максимальный элемент, вставляем столбец из нулей
        for (int j = 0; j < cols; ++j) {
            if (j == maxIndex) {
                newCols++; // Увеличиваем количество столбцов
                int** newArr = getNewArray(rows, newCols);

                // Копируем старый массив в новый, добавляя столбец из нулей
                for (int r = 0; r < rows; ++r) {
                    for (int c = 0; c < newCols; ++c) {
                        if (c < maxIndex) {
                            newArr[r][c] = arr[r][c];
                        }
                        else if (c == maxIndex) {
                            newArr[r][c] = 0; // Вставляем ноль
                        }
                        else {
                            newArr[r][c] = arr[r][c - 1]; // Копируем оставшиеся элементы
                        }
                    }
                }
                delArray(arr, rows); // Освобождаем старый массив
                arr = newArr; // Указываем на новый массив
                cols = newCols; // Обновляем количество столбцов
                break;
            }
        }
    }
}