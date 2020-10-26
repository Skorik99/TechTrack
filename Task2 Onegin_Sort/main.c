#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "onegin.h"
#include "sort.h"

int main()
{
    char input[]  = "C:/Infa/Sort_Onegin/Sort_Onegin/part1/Lucrece";
    char output1[] = "C:/Infa/Sort_Onegin/Sort_Onegin/part1/sort_first";
    char output2[] = "C:/Infa/Sort_Onegin/Sort_Onegin/part1/sort_last";
    char output3[] = "C:/Infa/Sort_Onegin/Sort_Onegin/part1/sort_all";

    printf("Please, enter the number of rows\n");
    int n = 0;
    while (scanf("%d", &n) != 1) {
        printf("Please, try again!");
    }

    Onegin_first(input, output1, n);
    Onegin_last(input, output2, n);
    Onegin_all(input, output3, n);
    puts("end");
    return 0;
}
