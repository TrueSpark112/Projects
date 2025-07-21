#ifndef CARWASH_SIMULATION
#define CARWASH_SIMULATION
#include <string>
#include <iostream>
using namespace std;


class Road{
public:
  Road(double lp, double hp):lowProb(lp),highProb(hp){}
  string makeCar();

private:
  double lowProb;
  double highProb;


};
class washer{
private:
  unsigned int time;
public:
  washer():time(0){};
  void start(string s);
  void run(){
    time--;
  }
  bool isBusy(){
    return time>0;
  }

};




#endif
