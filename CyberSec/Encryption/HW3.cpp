using namespace std;
#include <iostream>
#include <vector>
#include<cmath>
#include<algorithm>
//This function will convert the Decimal numbers into Binary numbers

vector<int> DecimalToBinary(int number, int n)
{
  vector<int> result;
  if(number>pow(2,n)){
    cout<<number<<" "<<n;
    cout<<"Error, the number can't be represented in "<<n<<"Bits";
  }
  //Ensures we have the right number of digits
  int ctr=0;
  int num= number;
  //I use binary operators to extract the binary representation of the number
  while(num){
    if(num & 1)
    {
      result.push_back(1);
    }
    else// 0
    {
      result.push_back(0);
    }
    num>>=1; // Right Shift by 1
    ctr++;
  }
  //Append any zeroes at the end
  for(int i=ctr;i<n;i++){
    result.push_back(0);
  }
  //At this point I realize the vector is backwards
  reverse(result.begin(),result.end());
  return result;
}

//The function below will convert Bit vectors into an array of ints
vector<int> ConvertBitArraytoInt(vector<int> k, int n){
  int powerCounter=0;
  int tempResult =0;
  vector<int> result;
  //I found this way to iterate through a vector in reverse on the internet
  for (vector<int>::reverse_iterator riter = k.rbegin(); riter != k.rend(); ++riter)
  {
    //Get the binary value and multiply it by the corresponding power of 2
    int bNum= *riter;
    tempResult+= (bNum)*pow(2,powerCounter);
    powerCounter++;
    //
    if(powerCounter>=n||riter==k.rend()-1){
        result.push_back(tempResult);
        tempResult=0;
        powerCounter=0;
    }
  }
  //Once Again my result is backwards (But correct)
  reverse(result.begin(),result.end());

  return result;
}
//This is the stream generating function
vector<int> generateStream(int n, int l, vector<int> key){
  vector<int> s,t,result,resultBinary,keyDecimal;

  keyDecimal=ConvertBitArraytoInt(key,n);

  //Populates the s and t vectors so we can alter them
  for (int i=0;i<pow(2,n);i++){
    s.push_back(0);
    t.push_back(0);
  }
  for(int i=0;i<pow(2,n);i++){
    s[i]=i;
    t[i]=keyDecimal[i%keyDecimal.size()];
  }

  int i=0,j=0,ks,store,t2;
  for(int k=0;k<l;k++){
    i=(i+1)%((int)pow(2,n));
    j=(j+s[i])%((int)pow(2,n));

    store=s[i];
    s[i]=s[j];
    s[j]=store;
    t2=(s[i]+s[j])%((int)pow(2,n));

    ks=s[t2];

    result.push_back(ks);
  }


  reverse(result.begin(),result.end());
  //Converts the array of decimal numbers into a single array of 1s and 0s
  for(vector<int>::iterator it=result.begin();it!=result.end();it++){

    vector<int> binaryTemp=DecimalToBinary(*it,n);

    for(vector<int>::iterator it2=binaryTemp.begin();it2!=binaryTemp.end();it2++){
      resultBinary.push_back(*it2);
    }
  }
  reverse(resultBinary.begin(),resultBinary.end());
  return resultBinary;
}

int exor(int a, int b){
  if(a==0&b==0){
    return 0;
  }
  if(a==0&b==1){
    return 1;
  }
  if(a==1&b==0){
    return 1;
  }
  if(a==1&b==1){
    return 0;
  }
  return 0;
}

int main(){
  /*
  //Test to see my Decimal To Binary Function is working
    vector<int> test1 = DecimalToBinary(3,4);
    cout<<"["
    for (int i: test1){
    cout << i << ',';
    cout<<"]"
  }
  */
  //Test to see my ConvertBitArraytoInt Function is working
  /*
  vector<int> sample1={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
  vector<int> test2 = ConvertBitArraytoInt(sample1,4);
  cout<<"[";
  for (int i: test2){
    cout << i << ',';
  }
  cout<<"]";
*/
//HACEDAB VALUES {1,1,1,0,0,0,0,1,0,1,0,0,0,1,1,0,0,0,0,0,1}
/*
//B)
vector<int> key1= {0,1,0,1,0,1,1,1,1,0,0,1};
vector<int> key1c= ConvertBitArraytoInt(key1,3);



int n=3;
vector<int> questionb= generateStream(n,7,key1);
cout<<"[";
for (int i: questionb){
  cout << i << ',';
}
cout<<"]";
*/
int n = 8, l = 61;

vector<int>key={1, 0, 1, 1, 1, 0, 0, 1 , 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1};
vector<int>ciphertext= {1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1};

vector<int> questionc= generateStream(n,l,key);
vector<int> plaintext;

for(int i=0;i<ciphertext.size();i++){

  int temp =ciphertext[i]^questionc[i];
  plaintext.push_back(temp);
}

reverse(plaintext.begin(),plaintext.end());
plaintext=ConvertBitArraytoInt(plaintext,8);

for (int i=0;i<plaintext.size();i++){
  cout << char(plaintext[i])<<",";
}




return 0;
}
