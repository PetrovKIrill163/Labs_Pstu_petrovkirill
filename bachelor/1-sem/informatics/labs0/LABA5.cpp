// LaBA 5
#include <iostream>
using namespace std;

const int N = 5;                        // размер матрицы

// вывод матрицы на экран
void printMatrix(int a[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}

// поиск максимального элемента в подмассиве:
// строки top..N-1, столбцы 0..right;
// координаты возвращаются через ссылки r и c
void findMax(int a[][N], int top, int right, int &r, int &c)
{
    r = top; c = 0;
    for (int i = top; i < N; i++)
        for (int j = 0; j <= right; j++)
            if (a[i][j] > a[r][c]) { r = i; c = j; }
}

// перестановка строк r1 и r2 целиком
void swapRows(int a[][N], int r1, int r2)
{
    for (int j = 0; j < N; j++)
    {
        int t = a[r1][j]; a[r1][j] = a[r2][j]; a[r2][j] = t;
    }
}

// перестановка столбцов c1 и c2 целиком
void swapCols(int a[][N], int c1, int c2)
{
    for (int i = 0; i < N; i++)
    {
        int t = a[i][c1]; a[i][c1] = a[i][c2]; a[i][c2] = t;
    }
}

// проверка: убывает ли последовательность на побочной диагонали
bool isDecreasing(int a[][N])
{
    for (int i = 0; i < N - 1; i++)
        if (a[i][N - 1 - i] <= a[i + 1][N - 2 - i])
            return false;
    return true;
}

int main()
{
    system("chcp 65001 > nul ");
    int a[N][N] = {
        { 5, 12,  7,  1,  9},
        { 3, 20,  4, 15,  6},
        {35, 11, 25,  2, 10},
        {14, 17, 30,  6, 13},
        {19, 22, 28, 16, 24}
    };

    cout << "Исходная матрица:" << endl;
    printMatrix(a);

    for (int i = 0; i < N; i++)
    {
        int r, c;
        findMax(a, i, N - 1 - i, r, c);   // максимум в подмассиве № i
        swapRows(a, i, r);                // его строку - наверх подмассива
        swapCols(a, N - 1 - i, c);        // его столбец - вправо подмассива
        cout << "Шаг " << i + 1 << ": max = " << a[i][N - 1 - i]
             << " перемещён в позицию (" << i << ", " << N - 1 - i << ")" << endl;
    }

    cout << endl << "Матрица после обработки:" << endl;
    printMatrix(a);

    cout << "Побочная диагональ: ";
    for (int i = 0; i < N; i++)
        cout << a[i][N - 1 - i] << " ";
    cout << endl;

    if (isDecreasing(a))
        cout << "На побочной диагонали получилась убывающая последовательность." << endl;
    else
        cout << "Последовательность на побочной диагонали не убывает." << endl;

    return 0;
}