#include "Question1.h"
#include <iostream>
#include <string>
using namespace std;
Employee::Employee(){}

Employee::Employee(const string& theName, const string& theNumber) : name(theName), ssn(theNumber), netPay(0)
{
}
string Employee::getName( ) const {
return name; }
string Employee::getSsn( ) const {
return ssn; }
double Employee::getNetPay( ) const {
return netPay; }
void Employee::setName(const string& newName) {
name = newName; } void Employee::setSsn(const string& newSsn)
{ssn = newSsn; }
void Employee::setNetPay (double newNetPay) {
netPay = newNetPay; }
void Employee::printCheck( ) const {
cout << "\nERROR: printCheck FUNCTION CALLED FOR AN \n" <<
"UNDIFFERENTIATED EMPLOYEE. Aborting the program.\n" <<
"Check with the author of the program about this bug.\n";
exit(1); }


SalariedEmployee::SalariedEmployee(const string& theName,
const string& theNumber, double theWeeklyPay)
: Employee(theName, theNumber), salary(theWeeklyPay) {
   //deliberately empty
  }
double SalariedEmployee::getSalary( ) const {
return salary; }
void SalariedEmployee::setSalary(double newSalary) {
salary = newSalary; }
void SalariedEmployee::printCheck( ) {
 setNetPay(salary);
  cout << "\n________________________________________________\n";
  cout << "Pay to the order of " << getName( ) << endl;
  cout << "The sum of " << getNetPay( ) << " Dollars\n";
  cout << "_________________________________________________\n";
  cout << "Check Stub NOT NEGOTIABLE \n";
  cout << "Employee Number: " << getSsn( ) << endl;
  cout << "Salaried Employee. Regular Pay: " << salary << endl;
  cout << "_________________________________________________\n";
}

SalariedEmployee::SalariedEmployee( ) : Employee( ), salary(0){}
