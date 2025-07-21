#ifndef QUESTION1_H
#define QUESTION1_H
#include <string>
using namespace std;

class Employee {
public:
Employee( );
Employee(const string& theName, const string& theSsn);
string getName( ) const;
string getSsn( ) const;
double getNetPay( ) const;
void setName(const string& newName);
void setSsn(const string& newSsn);
void setNetPay(double newNetPay);
void printCheck( ) const;
private:
string name;
string ssn;
double netPay;
};





class SalariedEmployee : public Employee {
public:
SalariedEmployee( );
SalariedEmployee (const string& theName, const string& theSsn, double theWeeklySalary);
double getSalary( ) const;
void setSalary(double newSalary); void printCheck( );
protected:
   double salary;//weekly
};

class Administrator : public SalariedEmployee{
string title_;
string area_;
string supervisor_;
public:
  Administrator();
  Administrator(const string& theName, const string& theSsn, double theWeeklySalary,
     string theTitle,string theArea,string theSupervisor);
  void readData();
  void setSupervisor(string isupervisor){supervisor_=isupervisor;}
  void print();
  void printCheck();



};
#endif
