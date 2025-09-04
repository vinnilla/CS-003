#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cassert>
using namespace std;

/*
🟢
Assignment: e^x Calculator
Programming Project 7: 3_P_7_e_to_the_x. See more on Canvas

This program calculates e^x using the Taylor series expansion:
e^x = 1 + x + x^2/2! + x^3/3! + ... + x^n/n!

Input format:
- A real number x
- After calculations, prompts user with "Continue? (y/n)" for next value

Output format:
- Displays approximations for n=1 to 100 in a 10x10 grid
- Each value shown with 6 decimal places
- Final line shows exp(x) from cmath for comparison

Example:
Enter x: [2]
3.000000  5.000000  6.333333  7.000000  7.266667... 7.389056 
exp(2) = 7.389056           //<<-- this is the built in exp(x)

Continue? (y/n) [n]
*/

int main() {
  // variables
  double x, taylor, factorial;
  int count;

  char repeat;

  // repeat loop
  do {
    // initialize vars
    count = 0;

    // user input
    cout << "Enter x: ";
    cin >> x;

    // calculate taylor series expansion
    cout << setprecision(6) << fixed << left;
    for (int i = 1; i <= 100; i++) {
      taylor = 1;
      for (int j = 1; j <= i; j++) {
        factorial = 1;
        // calculate factorial
        for (int k = 1; k <= j; k++) {
          factorial *= k;
        }
        taylor += pow(x, j) / factorial;
      }
      // output current taylor value
      if (count == 10) {
        cout << endl;
        count = 0;
      }
      cout << setw(15) << taylor;
      count++;
    }

    // output exp(x)
    cout << endl << "exp(" << x << ") = " << exp(x);

    cout << endl << endl << "Continue? (y/n): ";
    cin >> repeat;
  } while (repeat == 'Y' || repeat == 'y');

  return 1;
}