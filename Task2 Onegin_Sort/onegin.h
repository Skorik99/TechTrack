#ifndef ONEGIN_H
#define ONEGIN_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/**
* @file onegin.h
*
*@brief Заголовочный файл с объявленными функциями и их описанием
*
*@author Скорик Сергей, студент МФТИ, группа Б05-875, базовая кафедра -- ИСП
*
*@date 26/10/2020
*/


/**
 * Функция считывает данные с input_name, сортирует их функцией compar и записывает в output_name
 *
 * @param [in] input_name -- указатель на имя файла
 * @param [in] compar -- указатель на функцию, по которой будет производится сортировка алгоритмом qsort
 * @param [in] n -- количество строк в input_name
 *
 * @param [out] output_name -- указатель на имя файла
 */
void Onegin_sort(char *input_name, char *output_name, int n, int(*compar)(const void *, const void *));


/**
 * Функция для решения задания 1. Используется в main.c.
 * Запускает Onegin_sort с указателем на функцию сортировки с начала строки sort_first
 *
 * @param [in] input_name -- указатель на имя файла
 * @param [in] n -- количество строк в input_name
 *
 * @param [out] output_name -- указатель на имя файла
 */
void Onegin_first(char *input_name, char *output_name, int n);


/**
 * Функция для решения задания 2. Используется в main.c.
 * Запускает Onegin_sort с указателем на функцию сортировки с конца строки sort_last
 *
 * @param [in] input_name -- указатель на имя файла
 * @param [in] n -- количество строк в input_name
 *
 * @param [out] output_name -- указатель на имя файла
 */
void Onegin_last(char *input_name, char *output_name, int n);


/**
 * Функция считывает данные с input_name, сортирует их с начала строки, записывает в output_name,
 * сортирует с конца строки, дозаписывает в output_name,
 * не производит сортировки и дозаписывает исходный файл в output_name
 *
 * @param [in] input_name -- указатель на имя файла
 * @param [in] n -- количество строк в input_name
 *
 * @param [out] output_name -- указатель на имя файла
 */
void Onegin_all(char *input_name, char *output_name, int n);



#endif // ONEGIN_H
