#ifndef _COMBINATORICS_H
#define _COMBINATORICS_H

#include <cmath>


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
