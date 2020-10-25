#include "Quadratic_Solve.h"
#include "test.h"
#include "error.h"

double Func_Parabola (double a, double b, double c, double x)
{
    double value = a * x * x + b * x + c;
    return value;
}

bool Roots_Checks (double a, double b, double c, double x1, double x2)
{
    if ((Func_Parabola(a, b, c, x1) == 0) && (Func_Parabola(a, b, c, x2) == 0))
        return true;

    return false;
}


void TestingFromFile( char* name){
    FILE *in = fopen(name, "r");
    double a = 0, b = 0, c =0;

    if (in != NULL) {
        while ( !feof(in)){
            fscanf(in, "%lg %lg %lg", &a, &b, &c);
            TestEquation(a, b, c);
        }
    }
    else{
        perror("fopen");
        //printf("%s %s %s", "file", name, "dont open\n");
    }

    fclose(in);


}


void TestEquation (double a, double b, double c){
    double x1 = 0, x2 = 0;
    int testSolNumb = QuadrSolve (a, b, c, &x1, &x2);

    printf ("For a = %lf, b = %lf, c = %lf coefficients\n", a, b, c);

    switch (testSolNumb)
    {
        case 0:
            printf ("No roots\n");
            printf ("Test passed\n");
            break;

        case INF_ROOTS:
            printf ("Infinite solution number\n");
            printf ("Test passed\n");
            break;

        default:
            printf ("root1 = %lf, root2 = %lf\n", x1, x2);

            if (Roots_Checks(a, b, c, x1, x2))
            {
                printf ("Test passed!\n \n");
            }
            else
            {
                printf ("Failed\n");
            }
    }
}
