#include<iostream>
#include<string>
#include<time.h>
#include<stdlib.h>
#include"HW8.h"
using namespace std;

/**************************************************************************
Number guessing game

On this program I realized the player could exploit the computer's strategy
by purposefully playing incorrectly, since the computer's strategy is based
on the player not guessing a number that has already been disqualified.
To correct this I would need to have the Computer check the new maximum and
minimum against the old ones before changing the values.

**************************************************************************/
/*
int HumanPlayer::getGuess(){
  int guess;
  cout<<"Enter your guess"<<endl;
  cin>>guess;
  cout<<endl;
  return guess;
}

int ComputerPlayer::getGuess(){
  int guess= rand()%100;
  while(guess<=min||guess>=max){
    guess=rand()%100;
  }
  cout<<"Computer guesses "<< guess<<endl;
  return guess;
}
void ComputerPlayer::recordGuess(int guess, int answer){
  if(guess>answer){
    max=guess;
    return;
  }
  min=guess;
}


//GUESSING GAME
bool checkForWin(int guess, int answer) {
  if (answer == guess) {
    cout << "You're right! You win!" << endl; return true;
  }
  else if (answer < guess){
    cout << "Your guess is too high." << endl;
  }
  else
    cout << "Your guess is too low." << endl; return false;
  }
void play(Player &player1, Player &player2) {
  int answer = 0, guess = 0;
  answer = rand( ) % 100;
  bool win = false;
  while (!win) {
    cout << "Player 1's turn to guess." << endl;
    guess = player1.getGuess( );
    win = checkForWin(guess, answer);
    player1.recordGuess(guess,answer);
    player2.recordGuess(guess,answer);

    if (win) return;
    cout << "Player 2's turn to guess." << endl;
    guess = player2.getGuess( );
    win = checkForWin(guess, answer);
    player1.recordGuess(guess,answer);
    player2.recordGuess(guess,answer);

   }
}

int main(){
  HumanPlayer h1,h2;
  ComputerPlayer c1,c2;
  srand(time(NULL));

  //Uncomment the following individually for ease of tesing
  //play(h1,h2);
  //play(c1,c2);
  play(h1,c1);

  return 0;
}
*/
/**************************************************************************
Dice Rolling game

DISREGARD THE FOLLOWING PARAGRAPH IT HAS NOTHING TO DO WITH THE CODE:

This program in specific might be useful in the future once I know how to
do more frontend developing so I can play DND with my friends with my own
personalized dice rolling app.(Or just as a feature within another app).


**************************************************************************/
/*
Dice::Dice() {
numSides = 6; srand(time(NULL)); // Seeds random number generator
}
Dice::Dice(int numSides) {
this->numSides = numSides; srand(time(NULL));// Seeds random number generator
}
LoadedDice::LoadedDice(int numSides):Dice(numSides) {
srand(time(NULL));// Seeds random number generator
}
int LoadedDice::rollDice() const{
  int temp;
  temp=(rand()%2)+1;
  if(temp==2){
    return numSides;
  }
  return (rand()%numSides) +1;
}
int Dice::rollDice()const {
return (rand() % numSides) + 1; }
// Take two dice objects, roll them, and return the sum
int rollTwoDice(const Dice& die1, const Dice& die2)
{
   return die1.rollDice() + die2.rollDice();
}

int main(){
  LoadedDice l1(20), l2(6);
  for(int i =0; i<10;i++){
    cout<<rollTwoDice(l1,l2)<<endl;
  }
  return 0;
}
*/
