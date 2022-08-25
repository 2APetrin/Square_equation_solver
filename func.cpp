#include "header.h"

double getdouble(void)
{
    double num = NAN;

    while (scanf("%lf", &num) != 1)
    {
        scanf("%*s");
        printf("This is not a number, try again\n");
    }

    return num;
}

int square_equasion_solve(double a, double b, double c, double* x1, double* x2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);

    double discriminant = NAN;
    int num = 0;

    if (equal(a, 0.0))
    {
        return solve_linear(b, c, x1);
    }
    else
    {
        discriminant = b*b - 4*a*c;

        if (discriminant < 0.0)
            return 0;
        else if (equal(discriminant, 0.0))
        {
            if (equal(b, 0.0))
                *x1 = 0.0;
            else
                *x1 = -b / (2*a);
            return 1;
        }
        else
        {
            *x1 = (-b + sqrt(discriminant)) / (2*a);
            *x2 = (-b - sqrt(discriminant)) / (2*a);
            return 2;
        }
    }

    return num;
}

int equal(double a, double b)
{
    assert(isfinite(a));
    assert(isfinite(b));

    int flag = 0;

    if ((fabs(a - b)) < Epsylon)
        flag = 1;

    return flag;
}

void print_solvings(int num, double x1, double x2)
{
    switch (num)
    {
        case ZEROROOTS: printf("There are no roots\n");
                break;

        case ONEROOT: printf("There is one root: x1 = %f\n", x1);
                break;

        case TWOROOTS: printf("There are two roots: x1 = %f, x2 = %f\n", x1, x2);
                break;

        case SS_INF: printf("Any real number fits\n");
                break;

        default: break;
    }
    printf("-----------------------------------------\n");
}

int solve_linear(double b, double c, double* x1)
{
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1 != NULL);
    int num = 0;

    if (equal(b, 0.0) and equal(c, 0.0))
        return SS_INF;

    if (equal(b, 0.0) and !equal(c, 0.0))
        return 0;

    if (!(equal(b, 0.0)) and (equal(c, 0.0)))
    {
        *x1 = 0.0;
        return 1;
    }

    if (!(equal(b, 0.0)) and !(equal(c, 0.0)))
    {
        *x1 = -c / b;
        return 1;
    }

    return num;
}

void debug(void)
{
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN, px1 = NAN, px2 = NAN;
    int i = 0, num = 0;
    FILE *fp;

    if ((fp = fopen("tests.txt", "r")) != NULL)
    {
        while (fscanf(fp, "%lf %lf %lf %d", &a, &b, &c, &num) == 4)
        {
            if (num == square_equasion_solve(a, b, c, &x1, &x2))
            {
                if (num == ZEROROOTS or num == SS_INF)
                    printf("Test %d passed\n", ++i);

                if (num == ONEROOT)
                {
                    fscanf(fp, "%lf", &px1);
                    if (equal(px1, x1))
                        printf("Test %d passed\n", ++i);

                    else
                        printf("Test %d not passed\n", ++i);
                }

                if (num == TWOROOTS)
                {
                    fscanf(fp, "%lf %lf", &px1, &px2);
                    if ((equal(px1, x1) and equal(px2, x2)) or (equal(px1, x2) and equal(px2, x1)))
                        printf("Test %d passed\n", ++i);

                    else
                        printf("Test %d not passed\n", ++i);
                }
            }
            else
                printf("Test %d not passed\n", ++i);

            while (getc(fp) != '\n')
                continue;
        }
    }
    printf("Number of tests = %d\n", i);
    getchar();
}

void getabc(double* a, double* b, double* c)
{
    printf("Enter a\n");
    *a = getdouble();

    printf("Enter b\n");
    *b = getdouble();

    printf("Enter c\n");
    *c = getdouble();
}
