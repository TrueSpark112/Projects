
#include <string>
#include<iostream>
#include"HW3.h"
#include<math.h>
#include <cstring>
using namespace std;
typedef string* StringPtr;

//#1
/*
polynomial::polynomial(double a[],int Size){
  DoublePtr aPtr;
  aPtr = new double[size];
  for(int i =0;i<size;i++){
    aPtr[i]=a[size];
  }
  this->size = Size;

  coefficient= aPtr;
}
polynomial::polynomial(const polynomial& p1){
  size= p1.rSize();
  DoublePtr aPtr;
  aPtr = new double[size];
  for(int i =0;i<size;i++){
    aPtr[i]=p1[i];
  }
  coefficient= aPtr;
}

polynomial::polynomial(){
  DoublePtr a;
  a = new double[1];
  a[0]= 0.0;
  size = 1;
  coefficient= a;

}

void polynomial::setCoefficient(int i,double j){
  coefficient[i]=j;
}




int polynomial::rSize() const{
  return size;
}
double polynomial::operator [](int pos) const{
  return coefficient[pos];
}


polynomial& polynomial::operator =(const polynomial& rhs)
{
  if(this == &rhs)
  {
    return *this;
  }
  else
  {
    size = rhs.rSize();
    delete [] coefficient;
    coefficient = new double[size];
    for(int i = 0;i<size;i++){
      coefficient[i]=rhs[i];
    }
  }

  return *this;
}

void polynomial::destroy(){
  delete [] coefficient;
}
polynomial operator +(const polynomial& lhs,const polynomial& rhs){
  DoublePtr a;
  int newSize;
  if(rhs.rSize()>lhs.rSize()){
    newSize= rhs.rSize();
  }
  else{
    newSize= lhs.rSize();
  }
  a = new double[newSize];
  for(int i =0;i<newSize;i++){
    a[i]= lhs[i]+rhs[i];
  }
  polynomial p1(a,newSize);
  return p1;
}
polynomial operator +(const polynomial& lhs,const double& rhs){
  DoublePtr a;
  int newSize;
  newSize = lhs.rSize();
  a = new double[newSize];
  a[0]+=rhs;
  for(int i =1;i<newSize;i++){
    a[i]= lhs[i];
  }
  polynomial p1(a,newSize);
  return p1;
}
polynomial operator +(const double& lhs,const polynomial& rhs){
  DoublePtr a;
  int newSize;
  newSize = rhs.rSize();
  a = new double[newSize];
  a[0]+=lhs;
  for(int i =1;i<newSize;i++){
    a[i]= rhs[i];
  }
  polynomial p1(a,newSize);
  return p1;

}
polynomial operator -(const polynomial&lhs, const double& rhs){
  int newSize;
  DoublePtr a;
  newSize= lhs.rSize();
  a = new double[newSize];
  a[0]-=rhs;
  for(int i =1;i<newSize;i++){
    a[i]= lhs[i];
  }

  polynomial p1(a,newSize);
  return p1;
}
polynomial operator -(const polynomial& lhs,const polynomial& rhs){
  DoublePtr a;
  int newSize;
  if(rhs.rSize()>lhs.rSize()){
    newSize= rhs.rSize();
  }
  else{
    newSize= lhs.rSize();
  }
  a = new double[newSize];
  for(int i =0;i<newSize;i++){
    a[i]= lhs[i]-rhs[i];
  }
  polynomial p1(a,newSize);
  return p1;

}
polynomial operator -(const double& lhs, const polynomial& rhs){
  DoublePtr a;
  int newSize;
  newSize = rhs.rSize();
  a = new double[newSize];
  a[0]-=lhs;
  for(int i =1;i<newSize;i++){
    a[i]= rhs[i];
  }
  polynomial p1(a,newSize);
  return p1;

}
polynomial operator *(const polynomial& lhs, const double& rhs){
  DoublePtr a;
  int newSize;
  a = new double[newSize];
  newSize = lhs.rSize();
  for(int i=0;i<newSize;i++){
    a[i]=lhs[i]*rhs;
  }
  polynomial p1(a,newSize);
  return p1;

}
polynomial operator *(const polynomial& lhs, const polynomial&rhs){
  DoublePtr a;
  int newSize;
  if(rhs.rSize()>lhs.rSize()){
    newSize= rhs.rSize();
  }
  else{
    newSize= lhs.rSize();
  }
  a=new double[newSize];

  for(int i =0;i<newSize;i++){
    for(int j=0; i<newSize;i++){
      if(rhs[i]!=0){
        a[j]=lhs[j]*rhs[i];
      }
    }
  }
  polynomial p1(a,newSize);
  return p1;
}

polynomial operator *(const double& lhs, const polynomial&rhs){
  DoublePtr a;
  int newSize;
  a = new double[newSize];
  newSize = rhs.rSize();
  for(int i=0;i<newSize;i++){
    a[i]=rhs[i]*lhs;
  }
  polynomial p1(a,newSize);
  return p1;
}

bool polynomial::operator ==(const polynomial& rhs){
  cout<<"size is: "<<size<<" rhs size is "<<rhs.rSize();
  if(size!= rhs.rSize()){
    return false;
  }
  else
  {
    for(int i =0; i<size;i++)
    {
      if (coefficient[i]!=rhs[i])
      {
        return false;
      }
    }
  }
    return true;
}

double polynomial::evaluate(double n){
  double result=0;
  for(int i = size-1;i>-1;i--){
    result+=pow(n,i)*coefficient[i];
  }
  return result;
}


int main(){
  double arr1[] = {1,2,3,4};
  double arr2[] = {2,2,2,2};
  polynomial test1(arr1,4);
  polynomial test3(arr2,4);
  polynomial b;
  polynomial c(b);

  if((c==b)){
    cout<<"Test 2 succesful";
  }






  return 0;
}
*/


//#2
/*
int main()
{
    string s;
    typedef char* strptr;
    strptr ptr;
    char *head, *tail;


    cout << "Enter a string: ";
    getline(cin, s);

    ptr = new char[s.size() + 1];
    strcpy (ptr, s.c_str());

    head = &ptr[0];
    tail = &ptr[s.size() - 1];

    cout << "Inverted is: ";

    char temp;
for (int i=0;head <= tail;i++)
{
  //Store the value located at the tail
        temp = ptr[i];
  // Make the tail value = the head value
        ptr[i] = *tail;
  //Make the head value the previous tail value
        *tail = temp;
  //Move the pointers
        *tail--;
        *head++;
    }

    cout << ptr << endl;

    exit(1);
    return 0;
}
*/
//#3

typedef string* strPtr;
//CONSTRUCTORS AND DESTRUCTOR
Student::Student() : name_(""), numClasses_(0), classList_(NULL){
}

Student::Student(string iname, int inumClasses, string iclasslist[])
:name_(iname),numClasses_(inumClasses) {
  classList_ = new string[numClasses_];

  for (int i = 0; i < numClasses_; i++)
  {
      classList_[i] = iclasslist[i];
  }
}

Student::~Student(){
  std::cout << "Here" << std::endl;
  std::cout << "=" << this << std::endl;
  numClasses_ = 0;
  Reset();
  name_ = "";
  std::cout << "There" << std::endl;
}


void Student::Reset()
{
        if (classList_) delete [] classList_;
        classList_ = NULL;
        numClasses_ = 0;
}
//INPUT AND OUTPUT
void Student::UserInput()
{
    string VoidLine;
    Reset();
    cout << "Enter student name: "<<endl;
    getline(cin, name_);
    cout << "Enter number of classes: "<<endl;
    cin >> numClasses_;
    StringPtr p;
    p = new string[numClasses_];
    getline(cin,VoidLine);
    for(int i=0;i<numClasses_;i++){
      cout<<"Enter class #"<<i+1<<endl;
      getline(cin,p[i]);
    }
    classList_ = p;
    cout<<endl;
}

void Student::Output()
{
    cout<<"Name is "<<name_<<endl ;
    cout << "Class List: " << endl;
    for (int i = 0; i < numClasses_; i++)
    {
        cout <<"           "<< i + 1 << ". "<< classList_[i] << endl;
    }
}

//;OPERATOR OVERLOAD
Student& Student::operator =(const Student& rhs)
{
    // self-check
    Reset();
    numClasses_ = rhs.numClasses_;
    if (numClasses_ == 0)
    {
      name_ = "";
      classList_ = NULL;

    } else {
    classList_ = new string[numClasses_];

    for (int i = 0; i < numClasses_; i++)
    {
        classList_[i] = rhs.classList_[i];
    }
}
    return *this;
}



int main()
{
    string student2List[3]={"Math","Science","Mystical Defense Against the Dark Arts"};
    Student student1, student2("Bob Thurman",3,student2List), student3;
    std::cout << "S1=" << &student1 << std::endl;
    std::cout << "S2=" << &student2 << std::endl;
    std::cout << "S3=" << &student3 << std::endl;
    cout<<" NumCLasses is "<< student2.getNumCLasses()<<endl;
    student2.Output();

    cout<<"Testing Manual Input for Student 1"<<endl;
    student1.UserInput();

    student1.Output();
    student3= student1;
    student3.Output();
    student3.setNumClasses(5);
    cout<<endl<<student3.getNumCLasses();
    std::cout << "A" << std::endl;

return 0;

}
