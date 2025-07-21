#ifndef HW4_H
#define HW4_H
#include <string>
#include <iostream>
#include<vector>
using namespace std;
//#2
/*
class Document{
protected:
  string text_;
public:
  Document():text_(""){}
  Document(string itext):text_(itext){}
  string getText()const{return text_;}
  void setText(string itext){text_=itext;}
  Document& operator = (Document& rhs);
};


class Email : public Document{
  string sender_;
  string recipient_;
  string title_;
public:
  Email();
  Email(string itext, string isender, string irecipient, string ititle);
  string getSender(){return sender_;}
  string getRecipient(){return recipient_;}
  string getTitle(){return title_;}
  void setSender(string iSender){sender_= iSender;}
  void setRecipient(string iRecipient){recipient_=iRecipient;}
  void setTitle(string iTitle){title_=iTitle;}
  Email& operator = (Email& rhs);


};
class File: public Document{
string pathName_;
public:
  File();
  File(string itext,string ipathName);
  string getPathName(){return pathName_;}
  void setPathName(string ipathName){pathName_=ipathName;}
  File& operator =(File& rhs);
};
*/
//#3
/*
class Card{
protected:
  int suit_;
  int name_;
  int realValue_;
public:
  Card(){}
  Card(int isuit, int iname);
  int getSuit(){return suit_;}
  int getName(){return name_;}
  int getrealValue(){return realValue_;}
  void setSuit(int isuit){suit_=isuit;}
  void setName(int iName){name_=iName;}
  friend bool operator < (Card& lhs, Card& rhs);
  friend ostream& operator <<(ostream& os, const Card& c1);
  //Card& operator = (Card& rhs);
};

class Deck {
protected:
vector <Card> deck_;
public:
  Deck();
  Card getCard(int i){return deck_[i];};
  void print();
  void Shuffle();
  void addCard(Card c1);
  void removeCard();
  void nameSort();
};

class Hand : public Deck{
  vector <Card> hand_;
  int size;
public:
  Hand();
  void DrawCard();
  int returnSize(){return size;}
  void ReturnCard();
  void printHand();
  Hand(int size);


};
*/
#endif
