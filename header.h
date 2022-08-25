#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define ASSERT(cond)                                               \
if (!(cond))                                                       \
{                                                                  \
    printf("\nError in %s in line %d in function %s in file %s\n", \
           #cond, __LINE__, __PRETTY_FUNCTION__, __FILE__),        \
    abort();                                                       \
}                                                                                                                                       \

enum nRoots
{
    ZEROROOTS = 0,
    ONEROOT   = 1,
    TWOROOTS  = 2,
    SS_INF    = -1
};


const double Epsylon = 0.0001;
///-------------------------------------------------------------------------------------
/// @brief   Gets a number from user, prevents user to type in not a number
///
/// @return  double
///-------------------------------------------------------------------------------------

double getdouble(void);



int square_equasion_solve(double a, double b, double c, double* x1, double* x2);
int equal(double a, double b);
char getch(void);
void print_solvings(int num, double x1, double x2);
int solve_linear(double b, double c, double* x1);
void sq_eq_test(void);
void getabc(double* a, double* b, double* c);
void greeting(void);

void flag_check(int argc, char **argv);


#endif // HEADER_H_INCLUDED
