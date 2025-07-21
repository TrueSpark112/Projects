#ifndef HW7_H
#define HW7_H
#include "LinkedList.cpp"
using namespace std;
class polynomial
{
public:
  //CONSTRUCTORS
  polynomial(int);

  polynomial(int coefficient,int power);

  polynomial( polynomial& p1);

  polynomial();

  ~polynomial();


  //MUTATOR FUNCTION



  //ACCESSOR FUCNTIONS
  Node **rHead() {return &head;}
  

  //OVERLOADED OPERATORS

  polynomial& operator = (polynomial& rhs);

  //MEMBER FUNCTION
  int evaluate(int n);

  //DESTRUCTOR
  void destroy();
private:
  Node *head;
  bool isIn(Node*, int);


};
 //NONMEMBER FUNCTIONS


 polynomial operator +(polynomial&,const polynomial& rhs);
 polynomial operator -(polynomial& lhs,const polynomial& rhs);

 polynomial operator *(polynomial& lhs, const polynomial&rhs);














#endif
