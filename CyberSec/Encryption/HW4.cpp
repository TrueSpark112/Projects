//JUAN ALFREDO TORRES MOLINA
#include<fstream>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;



// Transforms a one-dimensional array into a three-dimensional array and returns
int*** inputSHA3(int* v) {
    int*** a = new int**[5];
    for (int i = 0; i < 5; i++) {
        a[i] = new int*[5];
        for (int j = 0; j < 5; j++) {
            a[i][j] = new int[64];
            for (int k = 0; k < 64; k++) {
                a[i][j][k] = v[64 * (5 * j + i) + k];
            }
        }
    }
    return a;
}

// Function to perform theta operation and return the result
int*** theta(int*** ain) {
    int*** aout = new int**[5];
    for (int i = 0; i < 5; i++) {
        aout[i] = new int*[5];
        for (int j = 0; j < 5; j++) {
            aout[i][j] = new int[64];
            for (int k = 0; k < 64; k++) {
              //This part of my code was throwing segmentation faults,
              //So I tried making sure all the indexes were not negative
                int sum1 = ain[(i - 1 + 5) % 5][0][k % 64];
                int sum2 = ain[(i + 1) % 5][0][(k - 1 + 64) % 64];

                for (int l = 1; l < 4; l++) {
                    sum1 ^= ain[(i - 1 + 5) % 5][l][k % 64];
                    sum2 ^= ain[(i + 1 +5) % 5][l][(k - 1 + 64) % 64];
                }
                aout[i][j][k] = ain[i][j][k] ^ sum1 ^ sum2;
            }
        }
    }
    return aout;
}

// Function to transform a three-dimensional array back into a one-dimensional array and return it
int* outputSHA3(int*** a) {
    int* v = new int[1600];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 64; k++) {
                v[64 * (5 * j + i) + k] = a[i][j][k];
            }
        }
    }
    return v;
}


class SHA3(int* input){
public:
  void oneToThree();
  void threeToOne();

private:
  int oneDim[1600];
  int threeDim[5][5][64];
  int threeDimtemp[5][5][64];
  void copy();
}
SHA3::SHA3(int arr[1600]){
  for(int i=0;i<1600;i++){
    oneDim[i]=arr[i];
  }
  oneToThree();
}
void SHA3::oneToThree(){
  for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
          for (int k = 0; k < 64; k++) {
              threedim[i][j][k] = v[64 * (5 * j + i) + k];
          }
      }
  }
}
void SHA3::threeToOne(){
  for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
          for (int k = 0; k < 64; k++) {
              v[64 * (5 * j + i) + k] = a[i][j][k];
          }
      }
  }
  return v;
}


int main() {
    //I had to find this on the internet because I was struggling to read from the file.
    ifstream file("sha3in.txt", ios::binary);
    if (!file) {
        cout << "Error reading input";
        return 1;
    }
    vector<int> inputv;
    char chr;
    while (file.get(chr)) {
        if (chr == '0' || chr == '1') {
            inputv.push_back(chr - '0');
        }
    }

    // Convert vector to one-dimensional array
    int* input = new int[1600];
    for (int i = 0; i < 1600; i++) {
        input[i] = inputv[i];
    }

    // Transform one-dimensional array into three-dimensional array
    int*** input3D = inputSHA3(input);

    // Hope the theta function works
    int*** thetaResult = theta(input3D);
    for(int i=9;i<18;i++){
      cout<<thetaResult[4][3][i];
    }

    // Transform three-dimensional array back into one-dimensional array
    int* output = outputSHA3(thetaResult);




    // I've decided I no longer want to use dynamic arrays after this hw
    //Debugging has been really hard
    delete[] input;
    delete[] output;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            delete[] input3D[i][j];
            delete[] thetaResult[i][j];
        }
        delete[] input3D[i];
        delete[] thetaResult[i];
    }
    delete[] input3D;
    delete[] thetaResult;

    return 0;
}



//Open this comment if you want nightmares about dynamic arrays
//Failed attempts
/*
//INPUT: A one dimensional array with 1s and 0s
//OUTPUT: Nothing but suddenly the 1d array is 3d now
void inputSHA3(int*& v){
  //I Found out while debugging that the price of using 3d arrays is triple pointers
  //I might consider moving to python for the next hw if this causes too many problems
  int *** a= new int**[5];//Creates i row
  for(int i=0;i<5;i++){
    a[i]= new int*[5];//Createsjcolumn
    for(int j=0;j<5;j++){
      a[i][j]=new int[64];//Creates the k lane
      for(int k=0;k<64;k++){
          a[i][j][k]=v[64*(5*j+i)+k];
      }
    }
  }
  //This took me a while to find how to do but to change a 1d array into a 3d array
  //using a function you save the address of the start on the variable
  v=&(a[0][0][0]);
  //My code is buggy so im trying to deallocate the  memory for the arrays
 for(int i = 0; i < 5; i++){
     for(int j = 0; j < 5; j++){
         delete[] a[i][j];
     }
     delete[] a[i];
 }
 delete[] a;
  return;
}

//Im making drastic changes so this is a sefety copy


//Apply the same logic as the 1d to 3d but the other way around
void outputSHA3(int*& a){
  int * v=new int[1600];
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      for(int k=0;k<64;k++){
          v[64*(5*j+i)+k]=a[i][j][k];
      }
    }
  }


  a=&(v[0]);

  delete[] v;

  return;
}
void theta(int*& ain){
  int*** aout= new **int[5];
  for(int i=0;i<5;i++){
    aout[i]= new int*[5];
    for(int j=0;j<5;j++){
      aout[i][j]= new int[64];
      for(int k=0;k<64;k++){
        int sum1=ain[(i-1)%5][0][k%64];
        int sum2=ain[(i+1)%5][0][k-1%64];
        for(int l=1;l<4;l++){
          sum1= sum1^ain[i-1%5][l][k%64];
          sum2= sum2^ain[i+1%5][l][k-1%64];
        }
        aout[i][j][k]= ain[i][j][k]^sum1^sum2;
      }
    }
  }
  //ain=&(aout[0][0][0]);
  for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            delete[] aout[i][j];
        }
        delete[] aout[i];
    }
    delete[] aout;
  return;
}
*/
/*
// Function to transform a one-dimensional array into a three-dimensional array
int* inputSHA3(int v[1600]) {
    int a[5][5][64];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 64; k++) {
                a[i][j][k] = v[64 * (5 * j + i) + k];
            }
        }
    }
    return a;
}

// Function to perform theta function and return the result
int*** theta(int ain[5][5][64]) {
    int aout[5][5][64];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 64; k++) {
                int sum1 = ain[(i - 1 + 5) % 5][0][k % 64];
                int sum2 = ain[(i + 1) % 5][0][(k - 1 + 64) % 64];
                for (int l = 1; l < 4; l++) {
                    sum1 ^= ain[(i - 1 + 5) % 5][l][k % 64];
                    sum2 ^= ain[(i + 1) % 5][l][(k - 1 + 64) % 64];
                }
                aout[i][j][k] = ain[i][j][k] ^ sum1 ^ sum2;
            }
        }
    }
    return aout;
}

// Function to transform a three-dimensional array back into a one-dimensional array and return it
int* outputSHA3(int a[5][5][64]) {
    int v[1600];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 64; k++) {
                v[64 * (5 * j + i) + k] = a[i][j][k];
            }
        }
    }
    return v;
}
*/
/*
int main()
{

//I had to find this on the internet because I was struggling to read from the file.
ifstream file("sha3in.txt", ios::binary); // Open file in binary mode
    if (!file) {
        cout << "Error reading input";
        return 1;
    }

    vector<int> inputv;
    char chr;
    while (file.get(chr)) {
        if (chr == '0' || chr == '1') {
            inputv.push_back(chr - '0'); // Convert character '0' or '1' to integer 0 or 1
        }
    }


    // Turn the binary vector into a binary int array
  int index=0;
  int input[1600];
  in transformedInput[5][5][64];
  int ThetaOut[5][5][64];
  int output[1600]
  for (auto bit : inputv) {
    input[index]=bit;index++;
  }
  for(int i=0;i<1600;i++){
    cout<<input[i];
  }

  transformedInput= inputSHA3(input);
  thetaOut =theta(input);
  output=SHA3(input);

    return 0;



}
*/
