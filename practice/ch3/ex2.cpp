#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
using namespace std;

/*
🟢
Assignment: Roman Numeral Year Converter
Programming Projects 3: 3.P3_Arabic_to_Roman. See Canvas for more.

Convert a year between 1000-3000 from Arabic numerals to Roman numerals.
Input: Four-digit year (1000-3000)
Output: Year in Roman numerals
Rules: 
- The Roman Numeral MUST BE ENCLOSED BY VERTICAL BARS: |MDCXXII|
- Use standard Roman numeral notation (I=1, V=5, X=10, L=50, C=100, D=500, M=1000)
- Handle subtractive notation (IV=4, IX=9, XL=40, XC=90, CD=400, CM=900)
- Program loops until user chooses to exit



Example Interaction:

Enter a year (1000-3000): [1622]
Roman numeral: |MDCXXII|

Continue? (y/n): [Y]

Enter a year (1000-3000): [4622]
Year must be between 1000 and 3000.

Continue? (y/n): [y]

Enter a year (1000-3000): [2000]
Roman numeral: |MM|

Continue? (y/n): [n]

*/

int main() {
  // variables
  int input_year;
  int year;
  string roman_numeral_year = "|";
  char repeat;

  // repeat loop
  do {
    // output instruction
    cout << "Enter a year (1000-3000): ";
    cin >> input_year;
    year = input_year;
    roman_numeral_year = "|";
  
    // error handling
    if (year < 1000 || year > 3000) 
      cout << "Year must be between 1000 and 3000.";
    else { // construct roman numeral string
      while (year > 0) {
        // check largest denom first
        if (year % 1000 != year) {
          year = year - 1000;
          roman_numeral_year += "M";
        } else if (year % 900 != year) {
          year = year - 900;
          roman_numeral_year += "CM";
        } else if (year % 500 != year) {
          year = year - 500;
          roman_numeral_year += "D";
        } else if (year % 400 != year) {
          year = year - 400;
          roman_numeral_year += "CD";
        } else if (year % 100 != year) {
          year = year - 100;
          roman_numeral_year += "C";
        } else if (year % 90 != year) {
          year = year - 90;
          roman_numeral_year += "XC";
        } else if (year % 50 != year) {
          year = year - 50;
          roman_numeral_year += "L";
        } else if (year % 40 != year) {
          year = year - 40;
          roman_numeral_year += "XL";
        } else if (year % 10 != year) {
          year = year - 10;
          roman_numeral_year += "X";
        } else if (year % 9 != year) {
          year = year - 9;
          roman_numeral_year += "IX";
        } else if (year % 5 != year) {
          year = year - 5;
          roman_numeral_year += "V";
        } else if (year % 4 != year) {
          year = year - 4;
          roman_numeral_year += "IV";
        } else if (year - 1 >= 0) {
          year -= 1;
          roman_numeral_year += "I";
        }
      }
    }

    // output result
    cout << "The year " << input_year << " in Roman numerals is " << roman_numeral_year << "|" << endl << endl;

    cout << "Continue? (y/n): ";
    cin >> repeat;
  } while (repeat == 'Y' || repeat == 'y');

  cout << "Goodbye!" << endl;

  return 1;
}