#include "dbiguint.h"
#include <iostream>
#include <string>
using namespace std;
typedef short unsigned int* shortPtr;
dbiguint::dbiguint()
{

    shortPtr  p;
    p = new unsigned short[1];
    p[0]=0;
    this->data_=p;
    this->capacity_=1;
    delete [] p;
}
dbiguint::dbiguint(const string& s)
{
  shortPtr p;
  int LENGTH= s.length();
  //cout<<"s length is "<<s.length()<<endl;
  p = new unsigned short[LENGTH];
  for(int i= 0;i<LENGTH;i++)
  {
      p[i]= s[s.length()-1-i]-'0';

  }
  data_=p;
  capacity_=LENGTH;
  //cout<<"capacity is: "<<capacity_<<endl;
  //delete [] p;

}

size_t dbiguint::size() const{
  return this->capacity_;
}

unsigned short dbiguint::operator [](std::size_t pos) const
{
  return data_[pos];
}
ostream& operator <<(ostream& outputStream, const dbiguint& number)
{
  for(int i =number.capacity_-1;i>-1;i--)
  {
    outputStream<<number[i];
  }
return outputStream;
}

//reserve
void dbiguint::reserve(std::size_t newcapacity){
  shortPtr p;
  delete [] p;
  p= new short unsigned int[newcapacity];
  if(newcapacity>capacity_){
    for (int i =0; i<newcapacity;i++){
      if(data_[i]!=0){
        p[i]=data_[i];
      }
      else{
        p[i]=0;
      }
    }
      delete[] data_;
      data_ = p;
    }
  else{
    delete [] p;
  }
//+= OPERATOR
void dbiguint::operator += (const dbiguint & b){
  for(int i =0; i<capacity_;i++){
    if (data_[i]+b[i]>10){
      data_[i]+=b[i]-10;
      data_[i+1]+=1;
    }
    else{
      data_[i]+=b[i];
    }
  }
}



}
