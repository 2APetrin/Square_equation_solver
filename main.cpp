#include "header.h"

int main(int argc, char *argv[])
{
    flag_check(argc, argv);

    //#define DEBUG
    #ifdef DEBUG

    sq_eq_test();

    #endif
    #ifndef DEBUG

    int num = 0;
    int ch = 'q';

    double a =  NAN;
    double b =  NAN;
    double c =  NAN;
    double x1 = NAN;
    double x2 = NAN;

    greeting();

    while ((ch = getchar()) != 'q')
    {
        if (ch == 'c')
        {
            getabc(&a, &b, &c);

            num = square_equation_solve(a, b, c, &x1, &x2);

            print_solvings(num, x1, x2);

            while (getchar() != '\n')
                continue;

            printf("To quit type q, to stay type c\n");
        }
        else
        {
            printf("You can type in only c or q\n");

            while(getchar() != '\n')
                continue;
        }
    }
    #endif
    return 0;
}
