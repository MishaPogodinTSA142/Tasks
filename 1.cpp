#include <iostream>
#include <cmath>
using namespace std;

/**
 *@brief - Функция для вычисления A по заданному уравнению 
 *@param x - значение переменной x
 *@param y - значение переменной y 
 *@param z - значение переменной z
 *@return - возвращает рассчитанное значение
 */
double getA(const double x, const double y, const double z);

/**
 *@brief - Функция для вычисления B по заданному уравнению 
 *@param x - значение переменной x
 *@param y - значение переменной y 
 *@param z - значение переменной z
 *@return - возвращает рассчитанное значение
 */
double getB(const double x, const double y, const double z);
/**
 *@brief - Точка входа в программу 
 *@return - возвращает 0, если программа выполнена корректно
 */
int main()
{
    const double x = 0.5;
    const double y = 1.7;
    const double z = 0.44;
    cout<<"A = "<<getA(x,y,z)<<endl;
    cout<<"B = "<<getB(x,y,z);
    return 0;
}

double getA(const double x, const double y, const double z)
{
    return exp(-y*z)*sin(x*z-y)-sqrt(abs(y*z+x));
}

double getB(const double x, const double y, const double z)
{
    return y*sin(getA(x,y,z)*pow(z,2)*cos(2*z))-1;
}
