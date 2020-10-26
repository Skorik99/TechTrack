#include "sort.h"

char Up_to_low_case(char a)
{
    if (a < 'a')
        a += 'a' - 'A';
    return a;
}


int check_punc(char a)
{
    if (a == '.' || a == ',' || a == ';' || a == ':' || a == '!' || a == '?'
            || a == '.' || a == '.' || a == '"' || a == '.' || a == '(' || a == ')' || a == '\'' || a == '-')
        return 1;
    return 0;
}


int sort_first(const void * a, const void * b)
{
    int i = 0, j = 0;
    char A, B;
    char *str1 = *(char**)a;
    char *str2 = *(char**)b;

    do
    {
        while (check_punc(str1[i]) == 1) //Исключаем заки препинания
            i++;
        while (check_punc(str2[j]) == 1)
            j++;

        A = Up_to_low_case(str1[i]); //Приводим к нижнему регистру
        B = Up_to_low_case(str2[j]);
        if (A != B)
            return A - B;

        i++;//В случае, если символы оказались одинаковыми, переходим к следующим.
        j++;
    }
    while (str1[i] != '\n' || str2[j] != '\n');
    return str1[i] - str2[j]; //Код \n меньше, чем у печатных символов.
}


int sort_second(const void * a, const void * b)
{
    int i = 0, j = 0;
    char A, B;
    char *str1 = *(char**)a;
    char *str2 = *(char**)b;

    for (i = 0; str1[i] != '\n'; i++);
    for (j = 0; str2[j] != '\n'; j++);


    while (i >= 0 && j >= 0) // Последним символом всегда будет '\0'
    {
        A = Up_to_low_case(str1[i]);
        B = Up_to_low_case(str2[j]);
        if (A != B)
            return A - B;

        i--;
        j--;

        while(check_punc(str1[i]) == 1)
            i--;
        while(check_punc(str2[j]) == 1)
            j--;
    }
    return i - j;
}
