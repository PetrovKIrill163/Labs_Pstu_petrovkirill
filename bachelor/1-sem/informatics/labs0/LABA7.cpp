// LABA 7
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
/*Чтобы продемонстрировать перегрузку, назовем обе функции одинаково
 например find_max, но они будут принимать разные типы параметров.*/

int find_max(int n, int a[])
{
    int max_val = a[0];
    for (int i = 1; i < n; ++i)
    {
        if (a[i] > max_val)
        {
            max_val = a[i];
        }
    }
    return max_val;
}

// находит длину самого длинного слова
int find_max(const string& str) {
    int max_len = 0;
    int current_len = 0;
    
    for (char c : str)
    {
        // Если символ является буквой или цифрой увеличиваем длину слова
        if (isalnum(c))
        {
            current_len++;
        } else
        {
            // Если встретили пробел или знак препинания, проверяем длину
            if (current_len > max_len)
            {
                max_len = current_len;
            }
            current_len = 0; // Сбрасываем счетчик
        }
    }
    // Проверка на случай, если самое длинное слово стоит в самом конце строки
    if (current_len > max_len)
    {
        max_len = current_len;
    }
    return max_len;
}

int main()
{
    system("chcp 65001 > nul ");
    // Тест для массива 
    int arr[] = {10, 45, 2, 89, 34, 12};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    cout << "Максимальный элемент массива: " << find_max(arr_size, arr) << endl;

    // Тест для строки 
    string text = "Программирование это очень Ужас";
    cout << "Длина самого длинного слова в строке: " << find_max(text) << endl;

    return 0;
}

