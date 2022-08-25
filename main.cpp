#include "header.h"

int main(int argc, char *argv[])
{
    //#define DEBUG
    #ifdef DEBUG

    debug();

    #endif
    #ifndef DEBUG

    int num = 0, ch = 'q';
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;



    printf("# Square equation solver\n");
    printf("# Petrin.aa 2022\n\n");

    printf("You have: a*X^2 + b*X + c = 0\n");
    printf("To quit type q, to stay type c\n");

    while ((ch = getchar()) != 'q')
    {
        if (ch == 'c')
        {
            getabc(&a, &b, &c);

            num = square_equasion_solve(a, b, c, &x1, &x2);

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
