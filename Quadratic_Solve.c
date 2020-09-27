#include "Quadratic_Solve.h"


/**
 * @file Quadratic_solve.c
 *
 * @brief Содержит реализацию функций для решения квадратного уравнения
 *
 * @author Скорик Сергей, студент МФТИ, группа Б05-875, базовая кафедра -- ИСП
 *
 * @date 9/26/2020
 */




int QuadrSolve (double a, double b, double c, double *x1, double *x2)
{

    if (!(isfinite (a)) || !(isfinite (b)) || !(isfinite (c)))
        exit (EXIT_FAILURE);

    assert (x1 != x2);
    assert (x1 != NULL);
    assert (x2 != NULL);

    Normalize(&a, &b, &c);

    if (IsZero(a))
    {
        if (IsZero(b))
        {
            return (IsZero(c)) ? INF_ROOTS : 0;
        }
        else
        {
            *x1 = - c / b;

            return 1;
        }
    }

    double D = b * b - 4 * a * c;

    if (D > 0)
    {
        *x1 = (-b + sqrt(D)) / (2 * a);
        *x2 = (-b - sqrt(D)) / (2 * a);

        return 2;
    }
    else if (IsZero(D))
    {
        *x1 = *x2 = - b / (2 * a);

        return 1;
    }
    else
    {
        return 0;
    }
}

bool IsZero (double value){
    if (fabs (value) < 1e-7){
        return true;
    } else {
        return false;
    }
}

bool Check_and_parse_input(char* str, double *a, double *b, double *c)
{
    char sep[2] = {' ', '\n'};
    char *istr;
    istr = strtok(str, sep); // парсим строку на подстроки
    int i = 0;
    while (istr != NULL) {
        bool flag = false;
        i++;
        for(int j = 0; istr[j] != '\0'; j++) {  // цикл проверяет корректность подстроки
            if(isdigit(istr[j])) {
                continue;
            }
            else if(istr[j] == '.') {
                if(j == 0 || flag == true) {
                    return false;
                }
                else {
                    flag = true;
                    continue;
                }
            }
            else if(istr[j] == '-') {
                if(j != 0) {
                    return false;
                }
                else {
                    continue;
                }
            }
            else {
                return false;
            }
        }
        double tmp = atof(istr); // введенное значение передаем в коэффициент
        switch (i) {
        case 1:
            *a = tmp;
            break;
        case 2:
            *b = tmp;
            break;
        case 3:
            *c = tmp;
            break;
        default:
            return false;
        }
        istr = strtok (NULL, sep);
    }
    if(i != 3) {  // условие для i < 3
        return false;
    }
    else {
        return true;
    }
}


int Normalize (double *a, double *b, double *c){
    double min = fmin(fmin(*a, *b), *c);
    int ex_min = 0;
    frexp (min , &ex_min);
    if (ex_min>-23) {
        return 1;
    }
    int ex_max = 0;
    double max = fmax(fmax(*a, *b), *c);
    frexp (max , &ex_max);

    if (1023-ex_max > -22 - ex_min){

        int p = -22 - ex_min;
        *a = ldexp(*a, p);
        *b = ldexp(*b, p);
        *c = ldexp(*c, p);
        return 0;
    }
    return 1;
}
