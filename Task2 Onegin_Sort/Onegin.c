#include "onegin.h"
#include "sort.h"


void Onegin_sort(char *input_name, char *output_name, int n, int(*compar)(const void *, const void *))
{
    // Выделение памяти в массиве под текст
    char **A;
    int i = 0;
    int str_count = 0;
    A = malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
        A[i] = malloc(100 * sizeof(char));

    // Открытие input и output file.
    FILE *input, *output;

    if ((input = fopen(input_name, "r")) == NULL)
    {
        perror("fopen");
        return;
    }
    if ((output = fopen(output_name, "w")) == NULL)
    {
        perror("fopen");
        return;
    }

    // Считываем в массив А строки из файла.
    while(fgets(A[str_count], 100, input) != NULL)
        str_count++;

    // Сортировка текста
    qsort(A, str_count, sizeof(A[0]), compar);

    // Запись в output_file, освобождение памяти и закрытие файлов
    for (i = 0; i < str_count; i++)
        fprintf(output,"%s", A[i]);

    for (i = 0; i < n; i++)
        free(A[i]);
    free(A);

    if (fclose(input) == EOF)
    {
        perror("fclose");
        return;
    }
    if (fclose(output) == EOF)
    {
        perror("fclose");
        return;
    }
}


void Onegin_first(char *input_name, char *output_name, int n)
{
    Onegin_sort(input_name, output_name, n, sort_first);
}


void Onegin_last(char *input_name, char *output_name, int n)
{
    Onegin_sort(input_name, output_name, n, sort_second);
}


void Onegin_all(char *input_name, char *output_name, int n)
{
    // Выделение памяти в массиве под текст
    char **A;
    int i = 0;
    int str_count = 0;
    A = malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
        A[i] = malloc(100 * sizeof(char));

    // Открытие input и output file.
    FILE *input, *output;
    if ((input = fopen(input_name, "r")) == NULL)
    {
        perror("fopen");
        return;
    }
    if ((output = fopen(output_name, "w")) == NULL)
    {
        perror("fopen");
        return;
    }

    // Считываем в массив А строки из файла.
    while(fgets(A[str_count], 100, input) != NULL)
        str_count++;

    // Сортировка с начала строки
    qsort(A, str_count, sizeof(A[0]), sort_first);
    // Запись в output_file
    for (i = 0; i < str_count; i++)
        fprintf(output,"%s", A[i]);
    // Отступ
    fprintf(output,"%s", "\n");

    //Сортировка с конца строки
    qsort(A, str_count, sizeof(A[0]), sort_second);
    // Запись в output_file
    for (i = 0; i < str_count; i++)
        fprintf(output,"%s", A[i]);
    // Отступ
    fprintf(output,"%s", "\n");

    //Начинаем читать файл с начала
    rewind(input);

    str_count = 0;
    while(fgets(A[str_count], 100, input) != NULL)
        str_count++;

    // Запись в output_file
    for (i = 0; i < str_count; i++)
        fprintf(output,"%s", A[i]);

    // Освобождение памяти и закрытие файлов
    for (i = 0; i < n; i++)
        free(A[i]);
    free(A);

    if (fclose(input) == EOF)
    {
        perror("fclose");
        return;
    }
    if (fclose(output) == EOF)
    {
        perror("fclose");
        return;
    }
}
