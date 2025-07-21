#include<iostream>
#include<string>
#include<vector>
#include <cmath>
#include<set>
#include<time.h>
#include<chrono>
#include<stack>
#include"HW6.h"
using namespace std;
using namespace std::chrono;
//#1
/*
void findPrimes(int n){
  vector<int> pList;
  bool isPrime[n-1];
  int size= n-2;
  for(int i=2;i<n;i++){
    pList.push_back(i);
    isPrime[i-2]=true;
  }



  for(int i =0;i<sqrt(size);i++){
    if(isPrime[i]){
      for(int j=i+1;j<size;j++){
        //cout<<pList[j]<<" "<<pList[i]<<endl;
        if(pList[j]%pList[i]==0){
          isPrime[j]=false;
        }
      }
    }
  }

  for(int i=0;i<size;i++){
    if(isPrime[i]){
      cout<<pList[i]<<", ";
    }
  }
}
int main(){
  findPrimes(10);
  cout<<endl<<endl;
  findPrimes(30);
  cout<<endl<<endl;
  findPrimes(100);
  cout<<endl<<endl;
  findPrimes(300);
  cout<<endl<<endl;
}
*/
//#2

// a)

/*
int main(){

  time_t start, end;
  double dif;

  time(&start);
  int n;
  cout<<"Input Number";
  cin>>n;
  vector<int> rVector;
  int size=0;
  srand(time(NULL));
  for(int i=1;i<n;i++){

    int r=rand()%(n-1);

    bool isIn=false;
    for(vector<int>::iterator it = rVector.begin(); it != rVector.end(); ++it){
      if(r==*it){
        isIn=true;
      }
    }
    if(!isIn){
      rVector.push_back(r);
      size++;
    }
  }
  cout<<"added "<<size<<" elements"<<endl;


  time(&end);
  dif = difftime(end,start);
  cout <<"Runtime is "<< (double)(dif/10) <<" seconds"<< endl;
}
*/
// b)
/*
int main(){
  time_t start, end;
  double dif;

  time(&start);

  int n;
  cout<<"Input Number ";
  cin>>n;
  set<int> rSet;
  int size=0;
  srand(time(NULL));
  for(int i=1;i<n;i++){

    int r=rand()%(n-1);
    //cout<<" r is "<< r<<endl;

    if(rSet.find(r)==rSet.end()){

      rSet.insert(r);
      size++;
    }
  }
  cout<<"added "<<size<<" elements"<<endl;
  time(&end);
  dif = difftime(end,start);


  cout <<"Runtime is "<< (double)(dif/10) <<" seconds"<< endl;
}
*/

//#3
template<typename T1,typename T2>
RPNCalc<T1,T2>::RPNCalc(){}

template<typename T1,typename T2>
void RPNCalc<T1,T2>::input(T1 in){
    _data.push(in);

}
template<typename T1, typename T2>
void RPNCalc<T1,T2>::input(T2 in){

  if(in =='/'){
    if(_data.size()>=2){
      T1 temp1=_data.top();
      _data.pop();
      T1 temp2=_data.top();
      _data.pop();
      _data.push(temp2/temp1);
    }
    else{
      cout<<"Error";
    }
  }
  else if(in =='+'){
    if(_data.size()>=2){
      T1 temp1 = _data.top();
      _data.pop();
      T1 temp2 = _data.top();
      _data.pop();
      _data.push(temp1+temp2);
    }
    else{
      cout<<"Error";
    }
  }
  else if(in =='-'){
    if(_data.size()>=2){
      T1 temp1=_data.top();
      _data.pop();
      T1 temp2=_data.top();
      _data.pop();
      _data.push(temp2-temp1);
    }
    else{
      cout<<"Error";
    }
  }
  else if(in =='*'){
    if(_data.size()>=2){
      T1 temp1=_data.top();
      _data.pop();
      T1 temp2=_data.top();
      _data.pop();
      _data.push(temp2*temp1);
    }
    else{
      cout<<"Error";
    }
  }
  else if(in =='q'){
    cout<<"The top of the stack is "<<_data.top();
    exit(1);
  }
}

int main(){
RPNCalc<int,char> c1;
c1.input(10);
c1.input(2);
c1.input(3);
c1.input('+');
c1.input('-');
c1.input(2);
c1.input('*');
c1.input(5);
c1.input('/');
c1.input('q');

}
