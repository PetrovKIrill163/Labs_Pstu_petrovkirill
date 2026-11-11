#include <iostream>
#include <cstring>      // strlen, strcmp, strcpy, strcat
#include <cctype>       // isalpha
#include <clocale>
using namespace std;

int main()
{
    system("chcp 65001 > nul");
    char s[256];             // исходная строка (не более 255 символов)
    char words[128][256];    // слова строки
    char res[256];           // строка-результат
    int  idx[128];           // номера слов, начинающихся с буквы

    cout << "Введите строку (в конце точка): ";
    cin.getline(s, 256);     // аналог gets(s)

    // 1. Убираем точку и пробелы в конце строки
    int len = strlen(s);
    while (len > 0 && (s[len - 1] == '.' || s[len - 1] == ' '))
    {
        s[len - 1] = '\0';
        len--;
    }

    // 2. Разбиваем строку на слова
    int n = 0;               // количество слов
    int i = 0;
    while (s[i] != '\0')
    {
        while (s[i] == ' ') i++;            // пропускаем пробелы
        if (s[i] == '\0') break;

        int j = 0;
        while (s[i] != '\0' && s[i] != ' ') // копируем слово
        {
            words[n][j] = s[i];
            j++; i++;
        }
        words[n][j] = '\0';                 // нуль-терминатор
        n++;
    }

    // 3. Номера слов, которые начинаются с буквы
    int k = 0;
    for (i = 0; i < n; i++)
        if (isalpha((unsigned char)words[i][0]))
            idx[k++] = i;

    // 4. Сортировка выбранных слов по алфавиту (простой обмен)
    for (i = 0; i < k - 1; i++)
        for (int j = i + 1; j < k; j++)
            if (strcmp(words[idx[i]], words[idx[j]]) > 0)
            {
                char tmp[256];
                strcpy(tmp, words[idx[i]]);
                strcpy(words[idx[i]], words[idx[j]]);
                strcpy(words[idx[j]], tmp);
            }

    // 5. Собираем строку обратно
    res[0] = '\0';
    for (i = 0; i < n; i++)
    {
        if (i > 0) strcat(res, " ");
        strcat(res, words[i]);
    }
    strcat(res, ".");

    cout << "Результат: " << res << endl;
    return 0;
}