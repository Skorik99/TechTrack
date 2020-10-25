#include "Quadratic_Solve.h"
#include "test.h"
#include <stdio.h>
#include <time.h>
#include <conio.h>

/**
 * @file main.c
 *
 * @brief Программа-интерфейс для решения квадратного уравнения
 *
 * @author Скорик Сергей, студент МФТИ, группа Б05-875, базовая кафедра -- ИСП
 *
 * @date 9/26/2020
 */


int main()
{
    printf ("This is quadratic equation solver!\n");
    printf ("Please, input a, b, c in format:a b c\n");


    double a = 0, b = 0, c = 0;
    char str[64];
    fgets(str, 63, stdin);
    while(!Check_and_parse_input(str, &a, &b, &c)) {
        printf("Incorrect input. Try it again. Enter 3 numbers separated by a space.\n");
        fgets(str, 63, stdin);
    }
    double x1 = 0, x2 = 0;
    int rootNumber = QuadrSolve (a, b, c, &x1, &x2);

    switch (rootNumber)
    {
    case 0:
        printf ("No roots!\n");
        break;
    case 1:
        printf ("%lf is the only root of the given equation\n", x1);
        break;
    case 2:
        printf ("%lf, %lf are roots of the given equation\n", x1, x2);
        break;
    case INF_ROOTS:
        printf ("Ooh! Infinite number of roots!\n");
        break;
    default:
        printf ("Something went wrong...\n");
    }

    int answer = -1;
    printf ("Would you like to see our unit tests from file? (1 -- yes or 0 -- no) \n");

    while (scanf ("%d", &answer) != 1)
        printf("Try again(enter a correct input)\n");

    if(answer == 0) {
        printf("OK! Goodbye!");
    }

    else if(answer == 1) {
        TestingFromFile("tests.txt");
    }

    else {
        printf("Your input is incorrect."
               "Please run the program again and enter the correct input\n");
    }

    getch(); ///Wait before close


    return 0;
}
