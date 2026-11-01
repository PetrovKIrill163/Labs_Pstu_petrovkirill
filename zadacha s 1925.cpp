// Задача с числом 1925 
#include <iostream>
using namespace std;

int main() 
{
    system("chcp 65001 > nul"); 
    int N = 1925;
    int Z = 2;
    bool f = false;

    while ((N > 0) && !f) {
        int digit = N % 10;  // берем последнюю цифру
        if (digit == Z) {
            f = true;        // цифра найдена
        } else {
            N = N / 10;      // убираем последнюю цифру
        }
    }

    if (f) {
        cout << "Цифра " << Z << " встречается в числе" << endl;
    } else {
        cout << "Цифра " << Z << " не встречается в числе" << endl;
    }

    return 0;
}
