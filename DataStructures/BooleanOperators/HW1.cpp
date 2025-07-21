#include <iostream>

#include<stack>
using namespace std;
//7.7
/*
#include <cctype>
#include <cstdlib>
#include <cstring>

bool read_and_evaluate(istream& ins);
void evaluate_stack_tops(
  stack<double>& numbers, stack<string>& operations, stack<bool>& bools);
template <class T>
void releaseSpace(stack<T>& s1);
//PRECONDITION: Enter an stl stack class;
//POSTCONDITION: All of the contents of the stack will be popped

int main(){
  cout<<"Input a boolean operation, space all operations and numbers to run correctly";
  cout<<endl;
  string input;
  cout<<read_and_evaluate(cin);


  return 0;

}

bool read_and_evaluate(istream& ins){
  const char DECIMAL = '.';
  const char RIGHT_PARENTHESIS = ')';
  stack<double> numbers;
  stack<string> operations;
  stack<bool> bools;
  double number;
  string symbol;
  while(ins&&ins.peek()!='\n'){
    if(isdigit(ins.peek()) || ins.peek( )== DECIMAL){
      ins>>number;

      numbers.push(number);
    }
    else if (strchr("<>!=&|",ins.peek()) != NULL){
      ins>>symbol;

      operations.push(symbol);
    }
    else if(ins.peek() == RIGHT_PARENTHESIS){
      ins.ignore();
      evaluate_stack_tops(numbers,operations,bools);
    }
    else{
      ins.ignore();
    }
  }
  return bools.top();
}


void evaluate_stack_tops(
  stack<double>& numbers, stack<string>& operations, stack<bool>& bools){
  double operand1,operand2;
  bool boperand1,boperand2;
  //STEP 1: Check if the top of the stack is an operation with numbers or with booleans.
  //STEP 2: If its an operation with numbers pop  the top two elements
   of the stack into double variables, do the same with boolean operations
   but using bool variables.
  //STEP 3: Evaluate the operands using the top of operations.
  //STEP 4: 

  if(operations.top()=="=="){
    operand1=numbers.top();
    numbers.pop();
    operand2=numbers.top();
    numbers.pop();

    bools.push(operand1==operand2);
  }
  else if(operations.top()=="<="){
    operand1=numbers.top();
    numbers.pop();
    operand2=numbers.top();
    numbers.pop();

    bools.push(operand1>=operand2);
  }
  else if(operations.top()==">="){
    operand1=numbers.top();
    numbers.pop();
    operand2=numbers.top();
    numbers.pop();

    bools.push(operand1<=operand2);
  }
  else if(operations.top()=="!="){
    operand1=numbers.top();
    numbers.pop();
    operand2=numbers.top();
    bools.push(operand1!=operand2);
  }
  else if(operations.top()==">"){
    operand1=numbers.top();
    numbers.pop();
    operand2=numbers.top();
    numbers.pop();

    bools.push(operand1<operand2);
  }
  else if(operations.top()=="<"){
    operand1=numbers.top();
    numbers.pop();
    operand2=numbers.top();
    numbers.pop();

    bools.push(operand1>operand2);
  }


  else if(operations.top()=="!"){
    boperand1=bools.top();
    bools.pop();
    bools.push(!boperand1);

  }

  else if(operations.top()=="&&"){
    boperand1=bools.top();
    bools.pop();
    boperand2=bools.top();
    bools.pop();
    bools.push(boperand1&&boperand2);

  }
  else if(operations.top()=="||"){
    boperand1=bools.top();
    bools.pop();
    boperand2=bools.top();
    bools.pop();
    bools.push(boperand1||boperand2);


  }
  operations.pop();
}

// I thought I would eventually need this function but I eventaully realized I didn't,
//but I still kept it for future use.
template <class T>
void releaseSpace(stack<T>& s1){
  while(!s1.empty()){
    s1.pop();
  }
}
*/
//7.8
/*
template <class T>
bool compareStacks(stack<T> lhs, stack<T> rhs){
  while(!lhs.empty()){
    if(lhs.top()==rhs.top()){
      lhs.pop();
      rhs.pop();
    }
    else{
      return false;
    }
  }
  return (lhs.empty() && rhs.empty());
}

int main(){
  stack<int> s1, s2;
  s1.push(1);
  s1.push(2);
  s2.push(1);
  s2.push(3);
  cout<<compareStacks(s1,s2);
}
*/

//7.9

// On this one I'll admit that I didn't use my own full implementation of the stack
//because my code was bugged and my compiler wasn't detecting any errors.
//For some reason applying this method to my class breaks something and makes
//all the elements on the stack 0.

/*
#include<string>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;




template<class T>
class myStack: public stack<T>{
public:
  myStack():stack<T>(){}
  void flip();
  myStack(const myStack& other):stack<T>(other){}
  myStack& operator = (myStack&);
};

template<class T>
void myStack<T>::flip(){
  myStack<T> s1;
  while(!stack<T>::empty()){
    s1.push(stack<T>::top()); stack<T>::pop();
  }
  *this = s1;
}
template <class T>
myStack<T>& myStack<T>::operator = (myStack<T>& other){
  if(this!= &other){
    stack<T>::operator=(other);
  }
  return *this;
}

int main(){

 myStack<int> s1;
 for(int i =0; i< 5; i++){
     s1.push(i);
 }
 s1.flip();
 for(int i =0; i<5; i++){
     cout<< s1.top();
     s1.pop();
 }



return 0;
}
*/
