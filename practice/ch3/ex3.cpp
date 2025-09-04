#include <iostream>
#include <string>
#include <iomanip>
#include <cassert>
using namespace std;

/*
🟢
Assignment: Blackjack Hand Scorer
Programming Project 4: 3_P_4_Blackjack. see more on Canvas.

Write a program that scores a blackjack hand. In blackjack, a player receives from two to five cards. 
The cards 2 through 10 are scored as 2 through 10 points each. The face cards—jack, queen, and 
king—are scored as 10 points. The goal is to come as close to a score of 21 as possible without 
going over 21. Hence, any score over 21 is called "busted." The ace can count as either 1 or 11, 
whichever is better for the user.

Input Format:
- First line: Number of cards (2-5)
- Following lines: One card value per line
  Valid inputs: 2-9, T (for 10), J, Q, K, A (case sensitive)
- After each hand: Prompt "Continue? (y/n)"

Output Format:
- Score of the hand as an integer
- "Busted" if score exceeds 21

Example Interaction:

How many cards? [4]
card: [x]
card: [x]
card: [x]
card: [x]

Total Score: XX

continue? (Y/N) [Y]

How many cards? [5]
card: [x]
card: [x]
card: [x]
card: [x]
card: [x]

Busted

continue? (Y/N) [n]

*/

void processCard(char card, int& score, int& ace_count) {
  if (card == 'T' || card == 'J' || card == 'Q' || card == 'K')
    score += 10;
  else if (card == 'A') {
    score += 11;
    ace_count++;
  } else {
    score += card - '0';
  }
}

int main() {
  // variables
  int num_cards, score, ace_count;
  char card_char;
  
  char repeat;

  // repeat loop
  do {
    // initialize variables
    score = 0;
    ace_count = 0;

    // user input
    cout << "Enter number of cards: ";
    cin >> num_cards;
  
    // loop num_cards times
    for (int i = 0; i < num_cards; i++) {
      cout << "Enter card " << i + 1 << ": ";
      cin >> card_char;
  
      processCard(card_char, score, ace_count);
      // cout << card_char << " " << score << " " << ace_count << endl;
    }
  
    // try to resolve score with ace
    if (score > 21 && ace_count > 0) {
      while (ace_count > 0 && score > 21) {
        score -= 10;
        ace_count--;
      }
    }
  
    // output result
    cout << endl;
    if (score > 21)
      cout << "Busted" << endl << endl;
    else
      cout << "Hand total: " << score << endl << endl;

    cout << "Play again? (Y/N): ";
    cin >> repeat;
  } while (repeat == 'Y' || repeat == 'y');

  return 1;
}