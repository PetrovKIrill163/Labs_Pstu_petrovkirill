#include <iostream>
using namespace std;
    
int main() {
    system("chcp 65001 > nul ");
    // Исходный массив 
    int mass[100];  // массив с запасом
    int n = 5;      // количество элементов
    int k = 2;      // начальный элемент для вывода 
    int i,j;
    
    mass[0]= 10;
    mass[1]= 15;
    mass[2]= 20;
    mass[3]= 25;
    mass[4]= 30;// Инициализация массива
    
    cout << "Исходный массив:" << endl;// 1) Вывод исходного массива
    for (i = 0; i < n; i++) {
        cout << mass[i] << " ";
    }
    cout << endl << endl;
    
    // 2) Распечатать начиная с K-го элемента до K-1 
    cout << "Массив начиная с " << k << "-го элемента (кольцо):" << endl;
    for (i = 0; i < n; i++) {
        int index = (k + i) % n;  // формула 
        cout << mass[index] << " ";
    }
    cout << endl << endl;
    
    int first = mass[0];
    int last = mass[n - 1];// первыйе и последние элементы
    
    for (i = n - 1; i >= 0; i--) {// Сдвиги элементов вправо на 2
        mass[i + 2] = mass[i];
    }
    
    mass[0] = first;
    mass[n + 1] = last;
    n = n + 2;
    
    cout << "После добавления первого и последнего элементов:" << endl;
    for (i = 0; i < n; i++) {
        cout << mass[i] << " ";
    }
    cout << endl << endl;
    
    
    int new_n = 0;
    for (i = 0; i < n; i++) {
        if (mass[i] % 2 != 0) {  // если нечетное
            mass[new_n] = mass[i];
            new_n++;  //  Удаление чёт элементов
        }
    }
    n = new_n;
    
    cout << "После удаления четных элементов" << endl;
    for (i = 0; i < n; i++) {
        cout << mass[i] << " ";
    }
    cout << endl << endl;
    
    // Распечатать начиная с K-го элемента до K-1
    cout << "Итоговый массив начиная с " << k << "-го элемента (кольцо)" << endl;
    if (n > 0) {
        for (i = 0; i < n; i++) {
            int index = (k + i) % n;  // формула для кольца
            cout << mass[index] << " ";
        }
    }
    cout << endl;
    
    return 0;
}