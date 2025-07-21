#ifndef HW5_H
#define HW5_H
#include <iostream>
#include <string>

using namespace std;
template<typename T>

class Set{
  int size_;
  T *set_;
public:

Set(int size=0,T *a=nullptr);
void add(const T& newThing);
int  getsize_(){return size_;}
T* returnPointer(){return set_;}
T rData(int i){return set_[i];}


};


//#3
template<typename T>
class DynamicArray{
 T *data_;
 int size;
public:
  DynamicArray(T idata=nullptr,int isize=0):data_(idata),size(isize){}
  DynamicArray(DynamicArray<T>& other);
  ~DynamicArray(){
    delete[] data_;
  }
  int rSize(){return size;}
  void addEntry();
  bool deleteEntry(T key);
  T getEntry(int i);
  DynamicArray<T>& operator = (DynamicArray<T>& rhs);
};









#endif
