#ifndef _Numerical_H
#define _Numerical_H

#include <iostream>
#include <cmath>
#include <limits>
#include <sstream>

#ifdef WIN32   //should be true on: MinGW (32bit + 64bit) & MSVS compiler
  double log2(double x);
  int isnan(double x);
  int isinf(double x);
#endif

using namespace std;

const double Pi = 3.14159;

class Numerical
{
 public:
  Numerical()
    {
      epsilon = 1e-9;
    }
  Numerical(double eps)
    {
      epsilon = eps;
    }

  bool isPos(double d) const;
  bool isNonpos(double d) const;
  bool isNeg(double d) const;
  bool isNonneg(double d) const;
  bool isZero(double d) const;
  bool isNonzero(double d) const;
  bool isEqual(double a, double b) const;
  bool isInequal(double a, double b) const;

  bool isDifferentSign(double a, double b) const;

  double epsilon;

  static double inf()
  {
    return numeric_limits<double>::infinity();
  }
  static double logAdd(double logA, double logB)
  {
    // returns log(a+b) given log(a) and log(b)
    if ( logA > logB )
      swap(logA, logB);

    // assume logA <= logB

    // when one of the terms is very small, then just use the other term
    if ( isinf(logA) && logA < 0 )
      return logB;

    return log2( 1 + pow(2, logB-logA) ) + logA;
  }
};

#endif

