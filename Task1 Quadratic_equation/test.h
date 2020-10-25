#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/**
 * @file test.h
 *
 * @brief Заголовочный файл с объявленными функциями для тестирования и их описанием
 *
 * @author Скорик Сергей, студент МФТИ, группа Б05-875, базовая кафедра -- ИСП
 *
 * @date 9/26/2020
 */


/**
 * Вычисляет значение функции f(x) = ax^2 + bx + c
 * в заданной точке с заданными коэффициентами
 *
 * @param [in] a коэффициент при x^2
 * @param [in] b коэффициент при x
 * @param [in] c свободный коэффициент
 *
 * @param [in] x некоторое значение из R
 *
 * @returns f(x) = ax^2 + bx + c
 */
double Func_Parabola (double a, double b, double c, double x);


/**
 * Проверяет равенство нулю функции Func_Parabola в точках x1, x2
 * Т.е. проверяет, что x1, x2 -- корни квадратного уравнения
 *
 * @param [in] a коэффициент при x^2
 * @param [in] b коэффициент при x
 * @param [in] c свободный коэффициент
 *
 * @param [in] x1 первый проверяемый корень
 * @param [in] x2 второй проверяемый корень
 *
 * @return true если x1, x2 -- корни, false иначе
 */
bool Roots_Checks (double a, double b, double c, double x1, double x2);


/**
 * Функция считывает тесты с файла
 *
 * @param name -- имя файла
 */
void TestingFromFile(char* name);


/**
 *
 * Функция проверяет решения уравнения ax^2 + bx + c = 0
 *
 * @param a
 * @param b
 * @param c
 */
void TestEquation(double a, double b, double c);


#endif // TEST_H
