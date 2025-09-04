#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
using namespace std;

/*
🟢
Assignment: Fibonacci Sequence Generator

Description:
Read an integer n (>0) from the user and print the first n Fibonacci numbers.
The Fibonacci numbers are defined as:
- F0 = 1
- F1 = 1
- Fi+2 = Fi + Fi+1 for i ≥ 0

Input Format:
- A positive integer n
- After output, prompt "Continue? (y/n)"
- Repeat if user enters 'y', end if 'n'

Output Format:
- The first n Fibonacci numbers, space-separated
- Each sequence on a new line

Sample Interaction:

Enter n: [xx]
fib(): 1 1 2 3 5 8 13 21 34 55 89 144 ...

Continue? (y/n) [n]
*/

int main() {
  // variables
  int n, new_val, f_2, f_1;
  string fib;

  char repeat;

  // repeat loop
  do {
    // user input
    cout << "Enter n: ";
    cin >> n;

    // construct fib string
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        fib = "1";
        f_1 = 1;
      }
      else if (i == 1) {
        fib += " 1";
        f_2 = f_1;
        f_1 = 1;
      } else {
        new_val = f_1 + f_2;
        fib += " " + to_string(new_val);
        f_2 = f_1;
        f_1 = new_val;
      }
    }

    // output result
    cout << "fib(): " << fib << endl << endl;

    cout << "Continue? (y/n): ";
    cin >> repeat;
  } while (repeat == 'Y' || repeat == 'y');

  return 1;
}