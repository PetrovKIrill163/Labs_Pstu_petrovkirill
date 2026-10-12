// #include <iostream>

// using namespace std;

// int main() {
//     // 1 n++ * m
//     int n1 = 5, m1 = 3;
//     int res1 = n1++ * m1;
//     cout << "1 n++ * m = " << res1 << endl;

//     // 2 n++ < m
//     int n2 = 5, m2 = 3;
//     bool res2 = (n2++ < m2);
//     cout << "2 n++ < m = " << (res2 ? "true" : "false") << endl;

//     // 3 m-- > m
//     int m3 = 3;
//     bool res3 = (m3-- > m3);
//     cout << "3 m-- > m = " << (res3 ? "true" : "false") << endl;

//     return 0;
// }

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