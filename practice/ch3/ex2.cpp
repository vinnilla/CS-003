#include <iostream>

using namespace std;

int main() {
  // initialize variables
  char p1_move, p2_move, repeat;
   
  // repeat loop
  do {
    // user input
    cout << "Player 1: Enter P, R, or S: ";
    cin >> p1_move;
    
    cout << "Player 2: Enter P, R, or S: ";
    cin >> p2_move;
    
    // sanitize user input
    p1_move = toupper(p1_move);
    p2_move = toupper(p2_move);
    
    // output winner
    if (p1_move == p2_move) { // base case
      cout << "Nobody wins";
    } else {
      if (p1_move == 'P') {
        if (p2_move == 'R') {
          cout << "Player 1 wins";
        } else if (p2_move == 'S') {
          cout << "Player 2 wins";
        }
      } else if (p1_move == 'R') {
        if (p2_move == 'S') {
          cout << "Player 1 wins";
        } else if (p2_move == 'P') {
          cout << "Player 2 wins";
        }
      } else if (p1_move == 'S') {
        if (p2_move == 'P') {
          cout << "Player 1 wins";
        } else if (p2_move == 'R') {
          cout << "Player 2 wins";
        }
      }
    }
    
    cout << endl << "Play again? (y/n): ";
    cin >> repeat;
  } while (repeat == 'Y' || repeat == 'y');
   
  return 1;
}