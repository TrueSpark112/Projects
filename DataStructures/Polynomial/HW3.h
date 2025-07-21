#ifndef HW3_H
#define HW3_H
#include <string>
#include<iostream>
using namespace std;

//#1
/*
class polynomial
{
public:
  //CONSTRUCTORS
  polynomial(double a[],int Size);

  polynomial(const polynomial& p1);

  polynomial();


  //MUTATOR FUNCTION
  void setCoefficient(int i,double j);

  //ACCESSOR FUCNTIONS
  int rSize() const;

  //OVERLOADED OPERATORS
  double operator [](int pos) const;
  polynomial& operator = (const polynomial& rhs);
  bool operator ==(const polynomial& rhs);

  //MEMBER FUNCTION
  double evaluate(double n);
  //DESTRUCTOR
  void destroy();
private:
  double *coefficient;
  int size;

};
 //NONMEMBER FUNCTIONS

 polynomial operator +(const polynomial&, const double& rhs);
 polynomial operator +(const polynomial&,const polynomial& rhs);

 polynomial operator -(const polynomial&lhs, const double& rhs);
 polynomial operator -(const polynomial& lhs,const polynomial& rhs);

 polynomial operator *(const polynomial& lhs, const double& rhs);
 polynomial operator *(const polynomial& lhs, const polynomial&rhs);
 polynomial operator *(const double& lhs, const polynomial&rhs);
 polynomial operator +(const double& lhs,const polynomial& rhs);
 polynomial operator -(const double& lhs, const polynomial& rhs);
 */
//#2
//#3

class Student{
  string name_;
  int numClasses_;
  string *classList_;
public:
  //CONSTRUCTORS
  Student();
  Student(string iname, int inumClasses, string iclasslist[]);
  //ACCESSORS
  string getName(){return name_;} const
  int getNumCLasses(){return numClasses_;}const

  //MUTATORS
  void setName(string name){name_ = name;}
  void setNumClasses(int numClasses){numClasses_ = numClasses;}
  void setClassList(string classList[]){classList_=classList;}
  //Member FUNCTIONS
  void UserInput();
  void Output();
  void Reset();
  Student& operator =(const Student&rhs);
  //DESTRUCTOR
  ~Student();

};







//10.3
#endif
