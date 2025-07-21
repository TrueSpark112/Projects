#ifndef HW8_H
#define HW8_H
//Number Guessing Game
/*
class Player{

public:
  int virtual getGuess()=0;
  void virtual recordGuess(int guess, int answer)=0;
};

class HumanPlayer: public Player{

public:
  int getGuess();
  void recordGuess(int guess, int answer){};
};
class ComputerPlayer: public Player{
int min=-1;
int max=101;
public:
  int getGuess();
  void recordGuess(int guess, int answer);
};
*/

//Dice Rolling Game
/*
class Dice {
public:
  Dice();
  Dice(int numSides);
  virtual int rollDice()const;
protected:
  int numSides;
};

class LoadedDice: public Dice{

public:
  LoadedDice(int numsides =6);
  int rollDice()const;
};
*/

#endif
