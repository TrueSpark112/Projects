#ifndef HW6_H
#define HW6_H
#include<iostream>
#include<string>
#include<stack>
using namespace std;
template<typename T1,typename T2>
class RPNCalc{
  stack<T1> _data;

public:
  RPNCalc();
  void input(T1 in);
  void input(T2 in);
};



#endif
