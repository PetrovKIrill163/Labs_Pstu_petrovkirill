//LAbS 3
#include <iostream>   
#include <iomanip>    // setprecision для точности вывода (занки после запятой)
#include <cmath>      // для синуса косинуса и т.д 
using namespace std;

int main()
{
    system("chcp 65001 > nul");
    double a = 0.1, b = 0.8; 
    int k = 10,n = 50;
    double eps = 0.0001;
    double pi  = 3.14;
    double h = (b -a)/ k;

    for (int j = 0;j <= k; j++) // перебор икса
    {
        double x = a + j * h;
        double SN = 0.0;      // сумма из ровно n слагаемых

        for (int i = 1; i <= n; i++) // перебор слагаемых 
            SN = SN + cos(2 * i * x) / (4.0 * i * i - 1.0);

        double SE = 0.0;  // сумма до eps
        int i= 1;
        double term = cos(2 * i* x)/(4.0 *i *i-1.0);

        while (fabs(term) >= eps) // цикл пока a^n-ного не станет менньше e= 10 ^-4 
        {
            SE=SE +term;
            i = i+1;
            term = cos(2 * i * x)/(4.0 * i * i - 1.0);
        }

        double Y = 0.5-pi / 4.0*fabs(sin(x)); 
        cout << "X=" << setprecision(4) << x          // 4 знака после запятой
             << "  SN=" << setprecision(6) << SN      // 6 знаков после запятой
             << "  SE=" << SE
             << "  Y="  << Y << endl;
    }

    return 0;
}
