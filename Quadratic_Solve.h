#ifndef QUADRATIC_SOLVE_H
#define QUADRATIC_SOLVE_H


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>


/**
* @file Quadratic_solve.h
*
*@brief Заголовочный файл с объявленными функциями и их описанием
*
*@author Скорик Сергей, студент МФТИ, группа Б05-875, базовая кафедра -- ИСП
*
*@date 9/26/2020
*/


#define INF_ROOTS 47



/**
 * Этот метод проверяет правильность входных данных, а также парсит их.
 *
 * @param [in] str указатель на массив входных данных
 *
 * @param [out] a указатель на коэффициент при x^2
 * @param [out] b указатель на коэффициент при x
 * @param [out] c указатель на коэффициент свободного члена
 *
 * @return Возвращает true, если вход корректный и false в противном случае
 *
 * @note Под корректным входом понимается последовательность из 3-х чисел с плавающей точкой, разделенных одним пробелом.
 */
bool Check_and_parse_input(char* str, double *a, double *b, double *c);


/**
 * Эта функция решает квадратное уравнение
 *
 * @param [in]  a коэффициент при x^2
 * @param [in]  b коэффициент при x
 * @param [in]  c коэффициент свободного члена
 *
 * @param [out] x1 указатель на первый корень уравнения
 * @param [out] x2 указатель на второй корень уравнения
 *
 * @return Количество корней уравнения(без учета кратности)
 *
 * @note Если решение не является конечным числом, возвращает INF_ROOTS
 */
int QuadrSolve (double a, double b, double c, double *x1, double *x2);


/**
 * Эта функция сравнивает double с нулем с точностью 1e-7
 *
 * @param value
 * @return return true if value equals 0, false in an another case
 */
bool IsZero (double value);


/**
 * Эта функция производит нормализацию коэффициентов
 *
 * @param [in] a коэффициент при x^2
 * @param [in] b коэффициент при x
 * @param [in] c коэффициент свободного члена
 *
 * @return 0 если нормализация произошла, в  противном случае 1
 */
int Normalize (double *a, double *b, double *c);


#endif // QUADRATIC_SOLVE_H
