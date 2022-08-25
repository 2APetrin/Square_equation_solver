#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <math.h>
#include <assert.h>

enum nRoots
{
    ZEROROOTS = 0,
    ONEROOT   = 1,
    TWOROOTS  = 2,
    SS_INF    = -1
};

const double Epsylon = 0.0001;

double getdouble(void);
int square_equasion_solve(double a, double b, double c, double* x1, double* x2);
int equal(double a, double b);
char getch(void);
void print_solvings(int num, double x1, double x2);
int solve_linear(double b, double c, double* x1);
void debug(void);
void getabc(double* a, double* b, double* c);


#endif // HEADER_H_INCLUDED
