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


//! @brief  Gets a number from user, prevents user to type in not a number
//!
//! @return double number

double getdouble(void);

//! @brief  Solves square equation
//!
//! @param  [in]  a - coefficient a in equation
//! @param  [in]  b - coefficient b in equation
//! @param  [in]  c - coefficient c in equation
//! @param  [out] x1 - first root
//! @param  [out] x2 - second root
//!
//! @return Amount of roots
//!
//! @note   Function checks if input parameters a, b, c are finite and
//!         and for pointers x1 and x2 if they are not NULL

int square_equasion_solve(double a, double b, double c, double* x1, double* x2);

//! @brief  Checks if two double numbers are close to each other enough to be equal
//!
//! @param  [in] a - first double number
//! @param  [in] b - second double number
//!
//! @return 1 if numbers are close enough, 0 if they aren't
//!
//! @note   Function checks if input parameter a is finite

int equal(double a, double b);
char getch(void);
void print_solvings(int num, double x1, double x2);
int solve_linear(double b, double c, double* x1);
void sq_eq_test(void);

//! @brief Gets  3 double numbers for a b c coefficients
//!
//! @param [out] a - coefficient a in equation
//! @param [out] b - coefficient b in equation
//! @param [out] c - coefficient c in equation
//!
//! @note  Function checks if input parameters are not NULL
//! @note  Uses getdouble

void getabc(double* a, double* b, double* c);

//! @brief User greeting

void greeting(void);

//! @brief Checks if in command line arguments is "-h", if it's true gives full path to exe file
//!
//! @param [in] argc - Number of command line arguments
//! @param [in] argv - Array of command line arguments

void flag_check(int argc, char **argv);


#endif // HEADER_H_INCLUDED
