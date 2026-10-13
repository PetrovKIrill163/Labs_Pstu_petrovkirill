#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;// пространство имён
template <typename r>
void zadaia1() {
    r a= 1000;
    r b= 0.0001;           // услввия задачи
                            //  Промежуточные переменные для числителя: (a - b)^3 - a^3 
    r sub= a - b;
    r part1= pow(sub,3);
    r part2= pow(a,3);
    r numerator= part1 - part2;
                            //  Промежуточные переменные для знаменателя: b^3 - 3ab^2 - 3a^2b 
    r f= pow(b, 3);        // b^3
    r d= 3*a*b*b;    // 3ab^2
    r e= 3*a*a*b;    // 3a^2b
    r denominator = f - d - e;

    r result = numerator / denominator;         // итоговый результат деления
    cout << setprecision(12);
    cout << "Числитель:" << numerator << endl;
    cout << "Знаменатель:" << denominator << endl;
    cout << "Результат:" << result << endl;
}
int main() {
    system("chcp 65001 > nul");

    cout << "\n Результаты для float " << endl;
    zadaia1<float>();
    cout << "\n Результаты для double " << endl;
    zadaia1<double>();
    
    return 0;
}
// Задание 2 

#include <iostream>
using namespace std;

int main() {
    //Пункт 1: n++ * m
    int m = 10, n = 8;
    cout << "n++ * m = " << (n++ * m) << endl;

    //Пункт 2: n++ < m
    m = 10; n = 8;
    cout << "n++ < m = " << (n++ < m) << endl;

    //Пункт 3: m-- > m
    m = 10; n = 8;
    int left = m--;   
    cout << "m-- > m = " << (left > m) << endl;

    return 0;
}
