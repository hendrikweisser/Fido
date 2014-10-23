#ifndef _COMBINATORICS_H
#define _COMBINATORICS_H

#include <cmath>
#ifdef WIN32   //should be true on: MinGW (32bit + 64bit) & MSVS compiler
#include <amp_math.h> // for lgamma()
using Concurrency::precise_math::lgamma;
#endif

class Combinatorics
{
 public:
  static double binomial(int n, int k)
  {
    //    cout << "Getting bin(" << n << "," << k << ")" << endl;
    return product(k+1,n)/product(2,n-k);
  }

  static double logBinomial(int n, int k)
  {
    return sumLogs(k+1, n) - sumLogs(2, n-k);
  }

#ifdef WIN32
  static double logGeneralizedBinomial(double n, double k) restrict(amp)
  {
    //    cout << "Getting bin(" << n << "," << k << ")" << endl;
    int dummy; 
    return lgamma(n+1, &dummy) - lgamma(k+1, &dummy) - lgamma(n-k+1, &dummy);
  }
#else
  static double logGeneralizedBinomial(double n, double k)
  {
    //    cout << "Getting bin(" << n << "," << k << ")" << endl;
    return lgamma(n+1) - lgamma(k+1) - lgamma(n-k+1);
  }  
#endif

  static double sumLogs(int a, int b)
  {
    double tot = 0.0;

    for (int k=a; k<=b; k++)
      {
	tot += log2( double(k) );
      }

    return tot;
  }

  static double product(int a, int b)
  {
    double prod = 1.0;

    for (int k=a; k<=b; k++)
      prod *= k;
    
    return prod;
  }
};

#endif
