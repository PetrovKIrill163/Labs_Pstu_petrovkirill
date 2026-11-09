//LABA7.2
#include <iostream>
#include <cstdarg> // Для работы с переменным числом 
using namespace std;

// Вспомогательная функция: Наибольший общий делитель (НОД)
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Вспомогательная функция: Наименьшее общее кратное (НОК) для двух чисел
int lcm(int a, int b)
{
    if (a == 0 || b == 0) return 0;
    // Делим сначала, чтобы избежать переполнения типа int при умножении
    return (a / gcd(a, b)) * b; 
}

// Основная функция с переменным числом параметров
// Первый параметр count (обязательный) - количество передаваемых чисел
int nok(int count, ...)
{
    if (count <= 0) return 0;
    
    va_list args;         // Указатель на список аргументов
    va_start(args, count); // Инициализация списка (начинаем после параметра count)
    
    // Получаем первое число из списка
    int result = va_arg(args, int); 
    
    // Проходим по оставшимся числам
    for (int i = 1; i < count; ++i) {
        int next_number = va_arg(args, int); // Получаем следующее число
        result = lcm(result, next_number);   // Вычисляем НОК текущего результата и нового числа
    }
    
    va_end(args); // Завершаем работу со списком аргументов
    return result;
}

int main()
{
    system("chcp 65001 > nul ");
    cout << "=== Проверка функции nok ===" << endl;

    // 1. Вызов с 3 параметрами
    int n1 = 12, n2 = 18, n3 = 24;
    cout << "НОК(" << n1 << ", " << n2 << ", " << n3 << ") = " 
         << nok(3, n1, n2, n3) << endl;

    // 2. Вызов с 5 параметрами
    int m1 = 5, m2 = 7, m3 = 11, m4 = 13, m5 = 2;
    cout << "НОК(5, 7, 11, 13, 2) = " 
         << nok(5, m1, m2, m3, m4, m5) << endl;

    // 3. Вызов с 6 параметрами
    int k1 = 4, k2 = 6, k3 = 8, k4 = 10, k5 = 12, k6 = 14;
    cout << "НОК(4, 6, 8, 10, 12, 14) = " 
         << nok(6, k1, k2, k3, k4, k5, k6) << endl;

    return 0;
}