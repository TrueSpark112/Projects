#include <queue>
#include "CarWashSimulation.h"
#include <string>
#include <iostream>
#include <time.h>
#include<stdlib.h>
using namespace std;
string Road::makeCar(){
  double p=(rand()%100)/100.00;
  cout<<p<<endl;

  if(p<=highProb&&p>=lowProb){
    if( (rand()&100)/100 ){
      return"Short";
    }
    return "Long";
  }
  return "No Car";
}

void washer::start(string s){
  if(s =="No Car"){time = 0;}
  else if(s=="Long"){time =3;}
  else if(s=="Short"){time =2;}
}

void simulateCarWash(){
  Road s(0.08,0.30);
  washer w;
  queue<string> q;
  int customers =0;
  for(int time=0;time<60;time++){
      q.push(s.makeCar());
      if(!q.empty()){
        if(!w.isBusy()){
          w.start(q.front());
          if(q.front()!="No Car"){
            customers++;
          }
          q.pop();
        }
        else{
          w.run();
        }
      }
      else{
        if(w.isBusy()){
          w.run();
        }
      }
  }
  int time = 60;
  while(!q.empty()){
      if(!w.isBusy()){
        w.start(q.front());
        if(q.front()!="No Car"){
          customers++;
        }
        q.pop();

      }
      else{
        w.run();
        time++;
      }
  }
  cout<<"Probability of a customer arriving in one minute"<<" 22%"<<endl;
  cout<<"Total time operating: "<<time<<" minutes"<<endl;
  cout<<"Customers served: "<<customers<<endl;
  cout<<"Average waiting time: "<<time/customers;

}

int main(){


simulateCarWash();
  return 0;
}
