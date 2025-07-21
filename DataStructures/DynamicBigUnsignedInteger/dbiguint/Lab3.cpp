//Juan Torres & Jenning Xuan
#define BIGUINT_H
#include"biguint.h"
#include<iostream>
#include<string>
using namespace std;


//Member functions
biguint::biguint()
{
  for(int i= 0;i<CAPACITY;i++)
  {
    data_[i]=0;
  }
}
biguint::biguint(const string& s)
{
  for(int i= 0;i<CAPACITY;i++)
  {
    if(i<s.length())
    {
        data_[i]= s[s.length()-1-i]-'0';
    }
    else
    {
      data_[i]=0;
    }
  }
}
/*
unsigned short biguint::operator [](std::size_t pos) const
{
  return data_[pos];
}
int biguint::returnSize(){
  return CAPACITY;
}
void biguint::operator += (const biguint & b){
  for(int i =0; i<CAPACITY;i++){
    if (data_[i]+b[i]>10){
      data_[i]+=b[i]-10;
      data_[i+1]+=1;
    }
    else{
      data_[i]+=b[i];
    }
  }
}
// nonmember functions

biguint operator + (const biguint &, const biguint &);
biguint operator - (const biguint &, const biguint &);

bool operator < (const biguint &, const biguint &);
bool operator <= (const biguint &, const biguint &);
bool operator != (const biguint &, const biguint &);
bool operator == (const biguint &, const biguint &);
bool operator >= (const biguint &, const biguint &);
bool operator > (const biguint &, const biguint &);

ostream& operator <<(ostream& outputStream, const biguint& number)
{
  for(int i =19;i>-1;i--)
  {
    cout<<number[i];
  }
return outputStream;
}

int main()
{
  biguint decimals("123456789"), decimals2("123456789");
  cout<< decimals<<endl;
  decimals+=decimals2;
  cout<<decimals;




return 0;
}
*/
