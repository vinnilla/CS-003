#include <iostream>

using namespace std;

/*
🟢
Rock Paper Scessors
Practice Programs #2: 3.E2 Rock Paper Scissors. See Canvas for more

Write a program to score the paper-rock-scissor game. Each of two users types 
in either P, R, or S. The program then announces the winner as well as the basis
for determining the winner: Paper covers rock,Rock breaks scissors,Scissors cut 
paper,or Nobody wins. Be sure to allow the users to use lowercase as well as 
uppercase letters. Your program should include a loop that lets the user play 
again until the user says she or he is done.
use these prompts: 

Player 1: Enter P, R, or S: 
Player 2: Enter P, R, or S:

announce who won by this output:
Player 1 wins
or 
Player 2 wins

Example Interactions:

Player1: [p]
Player2: [R]
Player 2 wins

Play again? (y/n): [Y]

Player1: [R]
Player2: [r]
Nobody wins

Play again? (y/n): [y]

Player1: [s]
Player2: [P]
Player 1 wins

Play again? (y/n): [n]



*/

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