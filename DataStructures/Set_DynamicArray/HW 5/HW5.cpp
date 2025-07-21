#include "HW5.H"
 #include <iostream>

 using namespace std;
 //#1

 const int ARRAY_SIZE = 10;
 template<typename T1,typename T2>
 // T1 can be any type that has the ==, <, and > operator defined
 // T2 has to be a number to determine the range
 void search(const T1 a[ ], T2 first, T2 last, T1 key, bool& found, T2& location);
 //Precondition: a[first] through a[last] are sorted in increasing //order.
 //Postcondition: if key is not one of the values a[first] through
 //a[last], then found == false; otherwise, a[location] == key
 //and found == true. 12 int main( ) 13 { 14 15
int main(){


  //Case for INTs
  //int a[ARRAY_SIZE]={1,2,3,4,5,6,7,8,9,10};
  //const int finalIndex = ARRAY_SIZE - 1;

  char a[ARRAY_SIZE]={'a','b','c','d','e','f','g','h','i','j'};
  const int finalIndex = ARRAY_SIZE - 1;
  char key;
  int location;
  bool found;
  cout << "Enter character to be located: ";
  cin >> key;

  search(a, 0, finalIndex, key, found, location);
  if (found){
    cout << key << " is in index location " <<
     location << endl;
  }
  else{
   cout << key << " is not in the array." << endl;
    return 0;
  }
}


template <typename T1, typename T2>
void search(const T1 a[ ], T2 first, T2 last,
  T1 key, bool& found, T2& location)
{
  T1  mid;
  if (first > last) {
    found = false;
  }
  else {
    mid = (first + last)/2;
    if (key == a[mid]) {
      found = true; location = mid;
    }
    else if (key < a[mid]) {
      search(a, first, mid - 1, key, found, location);
    }
    else if (key > a[mid]) {
      search(a, mid + 1, last, key, found, location);
     }
   }
}
*/
//#2

template<typename T>
Set<T>::Set(int size,T *a):size_(size),set_(a){}

template<typename T>
void Set<T>::add(const T& newThing){
  size_++;
  T *temp;
  temp = new T[size_];
  for(int i =0; i<size_-1;i++){
    temp[i]==set_[i];
  }
  temp[size_-1]=newThing;
  delete [] set_;
  set_=temp;


}

//The output operator "<<" must be defined for T
template <typename T>
ostream& operator<<(ostream& os, Set<T>& rhs){
  for(int i =0; i< rhs.getsize_(); i++){
    os<<rhs.rData(i)<<",";
  }
  os<<endl;
  return os;
}

int main(){
string *a;
a= new string[0];
Set s1(0,a);
string t1= "TEST1", t2="TEST 2";
s1.add(t1);
s1.add(t2);
//cout<< s1;
for(int i =0; i<s1.getsize_();i++){
  cout<<s1.rData(i)<<", ";
  cout<<"size is ";
}

return 0;
}


//#3
template<typename T>
DynamicArray<T>::DynamicArray(DynamicArray& other){
  size = other.rSize();
  data_ = new T[size];
  for(int i=0;i<size;i++){
    data_[i]=other.getEntry(i);
  }

}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator = (DynamicArray<T>& rhs){
  if(&this==&rhs){
    return *this;
  }
  size = rhs.rSize();
  delete [] data_;
  data_ = new T[size];
  for(int i=0;i<size;i++){
    data_[i]=rhs.getEntry(i);
  }
  return *this;
}

template<typename T>
void DynamicArray<T>::addEntry(){
  T *temp;
  temp = new T[size+1];
  for(int i=0;i<size;i++){
    temp[i]=data_[i];
  }
  delete[] data_;
  data_=temp;
  size++;
}
template<typename T>
bool DynamicArray<T>::deleteEntry(T key){
  bool Found=false;
  T *temp;
  temp = new T[size-1];
  int j=0;
  for(int i=0;i<size;i++){
    if(key!=data_[i]&&Found!=true){
      temp[j]=data_[i];
      j++;
    }
    else{
      Found= true;
    }
  }
  if(Found){
    delete[] data_;
    data = temp;
    return true;
  }
  else{
    delete[] temp;
    return false;
  }
}
template<typename T>
T DynamicArray<T>::getEntry(int i){
  if(i<size){
    return data_[i];
  }
  else{
    return NULL;
  }
}

int main(){
  int a[10]={1,2,3,4,5,6,7,8,9,10};
  DynamicArray d1,d2(a,10);
  d2.addEntry(11);
  d1=d2;
  for(int i =0;i<size;i++){
    cout<<d1.getEntry(i)<<endl;
  }


  return 0;
}
