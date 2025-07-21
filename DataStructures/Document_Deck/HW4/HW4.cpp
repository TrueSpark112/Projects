#include "HW4.h"
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


//#1
/*
#include "Question1.cpp"
Administrator::Administrator(){
  SalariedEmployee();
}
Administrator::Administrator(const string& theName, const string& theSsn, double theWeeklySalary,
   string theTitle,string theArea,string theSupervisor)
   :SalariedEmployee(theName,theSsn,theWeeklySalary),
   supervisor_(theSupervisor),area_(theArea),title_(theTitle)
   {
    //Empty on purpose
   }

void Administrator::readData(){
  string tempname,tempssn;
  double tempnetPay,tempsalary;
  cout<<"Input name ";
  cin>>tempname;
  cout<<"Input SSN ";
  cin>>tempssn;

  cout<<"Input salary ";
  cin>> tempsalary;
  SalariedEmployee (tempname, tempssn, tempsalary);
  cout<<"Input title ";
  cin>>title_;
  cout<<"Input Area ";
  cin>>area_;
  cout<<"Input Supervisor ";
  cin>>supervisor_;
}
void Administrator::print(){
  cout<<"Tilte is "<< title_<<endl
  <<"Area is "<<area_<<endl
  <<"Salary is "<< salary;
}

void Administrator::printCheck( ) {
 setNetPay(salary);
  cout << "\n________________________________________________\n";
  cout<< "Administrator of "<<area_<<" Under "<<supervisor_<<" Supervisor";
  cout << "_________________________________________________\n";
  cout << "Pay to the order of "<<title_<< getName( ) << endl;
  cout << "The sum of " << getNetPay( ) << " Dollars\n";
  cout << "_________________________________________________\n";
  cout << "Check Stub NOT NEGOTIABLE \n";
  cout << "Employee Number: " << getSsn( ) << endl;
  cout << "Salaried Employee. Regular Pay: " << salary << endl;
  cout << "_________________________________________________\n";
}




int main(){
  Administrator admin1, admin2;;
  admin1.setSupervisor("Bob Mendez");
  admin1.print();
  cout<<endl;
  admin2.readData();
  admin2.printCheck();
  return 0;
}

*/
//#2 (14.7)
/*
//DOCUMENT
Document& Document::operator=(Document& rhs){

    if(this == &rhs)
    {
      return *this;
    }
    else
    {
      text_ = rhs.getText();
    }

    return *this;
}

//EMAIL
Email::Email(){}
Email::Email(string itext, string isender, string irecipient, string ititle)
:Document(itext),sender_(isender),title_(ititle),recipient_(irecipient)
{
  //Empty on purpose
}
Email& Email::operator =(Email& rhs){

    if(this == &rhs)
    {
      return *this;
    }
    else
    {
      Document::operator =(rhs);
      sender_=rhs.getSender();
      recipient_= rhs.getRecipient();
      title_=rhs.getTitle();
    }

    return *this;
}

//FILE
File::File():Document(){
  //Empty on purpose
}
File::File(string itext,string ipathName):Document(itext),pathName_(ipathName){
  //Empty on purpose
}


File& File::operator =(File& rhs){

    if(this == &rhs)
    {
      return *this;
    }
    else
    {
      Document::operator =(rhs);
      pathName_= rhs.getPathName();
    }

    return *this;
}
//CONTAINST KEYWORD
bool ContainsKeyword(const Document& docObject, string keyword) {
if (docObject.getText().find(keyword) != string::npos)
{
 return true;
}
return false;
}


int main(){
  Document d1,d2("HELLO THERE I AM A TEST"),d3("Extra test for redundancy");
  File f1,f2("I am the third test","This should be a file locations");
  Email e1,e2("Hello Professor Vu this homework was easier than last week's"
 ,"Juan Torres","Professor Vu","Test email");
 if(ContainsKeyword(e2,"Vu")){
   cout<<"Yay";
 }
}
*/
//#3
/*
int suit[]={1,2,3,4};
int name[]={1,2,3,4,5,6,7,8,9,10,11,12,13};
//CARD

Card::Card(int isuit, int iname):suit_(isuit),name_(iname){
  realValue_=name_+(13*(suit_-1));
}
// Trying to overload the assignment operator messed up the sort function so I commented it
*/
/*
Card& Card::operator = (Card& rhs){
 if (this==&rhs){
   return *this;
 }
 else{
  suit_=rhs.suit_;
  name_=rhs.name_;
  realValue_=rhs.realValue_;
  return *this;
 }
}
*/
/*
 bool operator < (Card& lhs, Card& rhs){
   if(lhs.realValue_ >= rhs.realValue_){
     return false;
   }
   return true;
 }

ostream& operator <<(ostream& os, const Card& c1){
  if(c1.name_==1){
    os<<"Ace ";
  }
  else if(c1.name_>1&&c1.name_<11){
    os<<c1.name_<<" ";
  }
  else if(c1.name_==11){
    os<<"Jack ";
  }
  else if(c1.name_==12){
    os<<"Queen ";
  }
  else if(c1.name_==13){
    os<<"King ";
  }
  else{
    os<<"invalid suit";
  }
  os<<"of ";
  if(c1.suit_==1){
    os<<"clubs";
  }
  else if(c1.suit_==2){
    os<<"diamonds";
  }
  else if(c1.suit_==3){
    os<<"diamonds";
  }
  else if(c1.suit_==4){
    os<<"hearts";
  }
  else{
    os<<"Invalid c1.suit_";
  }
  os<<endl;
  return os;
}


//////////////////////////////////////

Deck::Deck(){
  for(int i =0; i<4;i++){
    for(int j=0;j<13;j++){
      deck_.push_back(Card(suit[i],name[j]) );
    }
  }
}


void Deck::print(){
  int j=0;

  for (auto i = deck_.begin(); i != deck_.end(); ++i){

    if(deck_[j].getName()==1){
      cout<<"Ace ";
    }
    else if(deck_[j].getName()>1&&deck_[j].getName()<11){
      cout<<deck_[j].getName()<<" ";
    }
    else if(deck_[j].getName()==11){
      cout<<"Jack ";
    }
    else if(deck_[j].getName()==12){
      cout<<"Queen ";
    }
    else if(deck_[j].getName()==13){
      cout<<"King ";
    }
    else{
      cout<<"invalid suit";
    }
    cout<<"of ";
    if(deck_[j].getSuit()==1){
      cout<<"clubs";
    }
    else if(deck_[j].getSuit()==2){
      cout<<"diamonds";
    }
    else if(deck_[j].getSuit()==3){
      cout<<"diamonds";
    }
    else if(deck_[j].getSuit()==4){
      cout<<"hearts";
    }
    else{
      cout<<"Invalid suit";
    }
    cout<<endl;
    j++;
 }
}

void Deck::Shuffle(){
  random_shuffle(deck_.begin(),deck_.end() );
}

void Deck::addCard(Card c1){
  deck_.push_back(c1);
}
void Deck::removeCard(){
  deck_.erase(deck_.begin());
}
void Deck::nameSort(){
  sort(deck_.begin(),deck_.end());
}

/////////////////////////////////////
//HAND
Hand::Hand(){
}

Hand::Hand(int size):Deck(){
  for(int i =0;i<size;i++){
    hand_.push_back(deck_[0]);
    removeCard();
  }
}



void Hand::printHand(){
  int j=0;
  for (auto i = hand_.begin(); i != hand_.end(); ++i){
    cout<<hand_[j];
    j++;
  }
}

void Hand::DrawCard(){
  hand_.push_back(deck_[0]);
}
void Hand::ReturnCard(){
  addCard(hand_[0]);
}
int main(){
  Card c1;
  c1.setSuit(1);
  c1.setName(13);
  cout<<"///////////////////     Test 1         ////////////////////////////////"<<endl;
  cout<<c1;
  cout<<endl;
  Deck d1;
  cout<<"///////////////////     Test 2         ////////////////////////////////"<<endl;
  d1.print();
  cout<<"///////////////////     Test 3         ////////////////////////////////"<<endl;
  d1.Shuffle();
  d1.print();
  cout<<"//////////////////      Test 4         /////////////////////////////////"<<endl;
  d1.nameSort();
  d1.print();
  cout<<"//////////////////      Test 5         /////////////////////////////////"<<endl;
  Hand h1, h2(3);
  h1.DrawCard();
  h1.printHand();
  cout<<"//////////////////      Test 6         /////////////////////////////////"<<endl;
  h2.printHand();
  cout<<"//////////////////      Test 7         /////////////////////////////////"<<endl;
  cout<<"New Deck"<<endl;
  cout<<endl<<"////////////////////////////////////////////////////////////////"<<endl;
  h2.print();
  for(int i =0; i<h2.returnSize();i++){
    h2.ReturnCard();
  }
  cout<<endl<<"Hand"<<endl;
  h2.printHand();
  cout<<"Reset deck"<<endl<<endl;
  h2.print();



  return 0;
}
*/
