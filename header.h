#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>


//! @brief   Own ASSERT by #define
//!
//! @param   [in] cond - condition
//!
//! @warning If cond is false kills working programm and prints where it was in code. If cond is true does nothing

#define ASSERT(cond)                                               \
if (!(cond))                                                       \
{                                                                  \
    printf("\nError in %s in line %d in function %s in file %s\n", \
           #cond, __LINE__, __PRETTY_FUNCTION__, __FILE__),        \
    abort();                                                       \
}                                                                                                                                       \

//! @brief Enumerated type for number of roots square_equation_solve() returns
//!
//! @note  SS_INF = -1 is for infinite number of roots

enum nRoots
{
    ZEROROOTS = 0,
    ONEROOT   = 1,
    TWOROOTS  = 2,
    SS_INF    = -1
};


//! @brief Epsylon is smallest difference between two double numbers, when they are considered equal

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
//! @param  [out] x1 - pointer to first root
//! @param  [out] x2 - pointer to second root
//!
//! @return Amount of roots
//!
//! @note   Function checks if input parameters a, b, c are finite and
//!         and for pointers x1 and x2 if they are not NULL

int square_equation_solve(double a, double b, double c, double* x1, double* x2);


//! @brief  Checks if two double numbers are close to each other enough to be equal
//!
//! @param  [in] a - first double number
//! @param  [in] b - second double number
//!
//! @return 1 if numbers are close enough, 0 if they aren't
//!
//! @note   Function checks if input parameter a is finite

int equal(double a, double b);


//! @brief Gets roots and prints them
//!
//! @param [in] num - Number of roots in that equation
//! @param [in] x1 - first root
//! @param [in] x2 - second root
//!
//! @warning Don't check if x1 and x2 are finite

void print_solvings(int num, double x1, double x2);


//! @brief If equation is linear (a = 0) solves it
//!
//! @param [in] b - coefficient b in equation
//! @param [in] c - coefficient c in equation
//! @param [out] x1 - pointer to root x1 in equation
//!
//! @note  checks if [in] parameters are finite and checks if pointer x1 is NULL

int solve_linear(double b, double c, double* x1);


//! @brief Unit tests for square_equation_solve()
//!
//! @note Uncomment #define DEBUG to activate debug mode, where it is working
//! @note Unit tests are located in tests.txt
//!       Example of test: 1 5 4  2 -4 -1 where a = 1, b = 5, c = 4, number of roots = 2, -4 - first root, -1 - second root
//!                        1 2 1  1 -1    where a = 1, b = 2, c = 1, number of roots = 1, -1 - first root
//!                        1 4 5  0       where a = 1, b = 4, c = 5, number of roots = 0
//!                        0 0 0 -1       where a = 0, b = 0, c = 0, number of roots = -1 (SS_INF)

void sq_eq_test(void);


//! @brief Gets  3 double numbers for a b c coefficients
//!
//! @param [out] a - coefficient a in equation
//! @param [out] b - coefficient b in equation
//! @param [out] c - coefficient c in equation
//!
//! @note  Function checks if input parameters are not NULL
//! @note  Uses getdouble()

void getabc(double* a, double* b, double* c);


//! @brief User greeting

void greeting(void);


//! @brief Checks if in command line arguments is "-h", if it's true gives full path to exe file
//!
//! @param [in] argc - Number of command line arguments
//! @param [in] argv - Array of command line arguments

void flag_check(int argc, char **argv);

#endif // HEADER_H_INCLUDED
