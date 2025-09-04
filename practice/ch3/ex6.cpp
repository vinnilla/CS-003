#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
using namespace std;

/*
🟢
Assignment: Pi Approximation Calculator
Programming Project 8: 3_P_8_Pi: See more on Canvas.

This program calculates an approximation of pi using the series:
pi = 4 [ 1 – 1/3 + 1/5 – 1/7 + 1/9 ... + ((–1)n)/(2n + 1) ]

Input format:
- Integer n: number of terms to use in the approximation
- Character y/n: whether to continue with another calculation

Output format:
- Approximate value of pi to 6 decimal places

Example Interaction:

Enter the number of terms (n): [xx]
Approximation of pi with [xx] terms: [X.xxxxxx]
Continue? (y/n): [Y]

Enter the number of terms (n): [xx]
Approximation of pi with [xx] terms: [X.xxxxxx]
Continue? (y/n): [y]

Enter the number of terms (n): [xx]
Approximation of pi with [xx] terms: [X.xxxxxx]
Continue? (y/n): [n]

*/

int main() {
  // variables
  int n;
  double pi, series, val;
  bool neg;

  char repeat;

  // repeat loop
  do {
    // user input
    cout << "Enter the number of terms (n): ";
    cin >> n;

    // calculate pi approximation series
    series = 1;
    neg = true;
    for (double i = 3; i <= n * 2; i += 2) {
      if (neg) {
        series -= 1 / i;
      } else {
        series += 1 / i;
      }
      // flip flop 
      neg = !neg;
    }

    // calculate pi approximation
    pi = 4 * series;
  
    // output pi approximation
    cout << setprecision(6) << fixed
        << "Approximation of pi with [" << n << "] terms: " << pi << endl << endl;

    cout << "Continue? (y/n): ";
    cin >> repeat;
  } while (repeat == 'Y' || repeat == 'y');

  return 1;
}