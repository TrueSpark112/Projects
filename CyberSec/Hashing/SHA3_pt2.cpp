//JUAN ALFREDO TORRES MOLINA
#include<fstream>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;



// Function to perform theta operation and return the result


class SHA3{
public:
  //Constructor with input
  SHA3(int arr[1600]);
  //Converts the one dimensional array into a three dimensional array
  void inputSHA3();
  //Converts the three dimensional array into a one dimensional array
  void outputSHA3();
  //Applies theta function
  void theta();
  //Applies rho function
  void rho();
  //Applies pi function
  void pi();
  //Applies chi function
  void chi();

  //Modify this function to test the output.
  void output();
private:

  int _oneDim[1600];
  int threeDim[5][5][64];
  int loafTemp[5][5][64];
  void _copy();
};


SHA3::SHA3(int arr[1600]){
  for(int i=0;i<1600;i++){
    _oneDim[i]=arr[i];
  }
  inputSHA3();
}

void SHA3::_copy(){
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      for(int k=0;k<64;k++){
        threeDim[i][j][k]=loafTemp[i][j][k];
      }
    }
  }
}
void SHA3::inputSHA3(){
  for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
          for (int k = 0; k < 64; k++) {
              loafTemp[i][j][k]= _oneDim[(64 * ((5 * j) + i)) + k];

          }
      }
  }
  _copy();
}

void SHA3::outputSHA3(){
  for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
          for (int k = 0; k < 64; k++) {
              _oneDim[(64 * ((5 * j) + i)) + k] = threeDim[i][j][k];
          }
      }
  }
}
void SHA3::theta() {
  int sum1;
  int sum2;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 64; k++) {

                sum1 = threeDim[(i - 1) % 5][0][k % 64];
                sum2 = threeDim[(i + 1) % 5][0][(k - 1) % 64];

                for (int l = 1; l < 5; l++) {

                    sum1 = sum1^threeDim[(i - 1) % 5][l][k % 64];
                    sum2 = sum2^threeDim[(i + 1) % 5][l][(k - 1) % 64];

                }
                loafTemp[i][j][k] = threeDim[i][j][k] ^ sum1 ^ sum2;

            }
        }
    }
    _copy();
}

void SHA3::output(){
  for(int i=25;i<35;i++){
    cout<<loafTemp[3][1][i];
  }
}
void SHA3::rho(){
  //Gets the values from the rhomatrix and substracts them from k index to shift
  //The lane
  int rhomatrix[5][5]={
    {0,36,3,41,18},
    {1,44,10,45,2},
    {62,6,43,15,61},
    {28,55,25,21,56},
    {27,20,39,8,14}
  };
  for(int i=0 ;i<5;i++){
    for(int j=0; j<5;j++){
      for(int k=0; k<64;k++){
        loafTemp[i][j][k]=threeDim[i][j][k-rhomatrix[i][j]];
      }
    }
  }
  _copy();
}

void SHA3::pi(){
  for(int i=0 ;i<5;i++){
    for(int j=0; j<5;j++){
      for(int k=0; k<64;k++){
        loafTemp[j%5][((2*i)+(3*j))%5][k]=threeDim[i][j][k];
      }
    }
  }
}

void SHA3::chi(){
  for(int i=0 ;i<5;i++){
    for(int j=0; j<5;j++){
      for(int k=0; k<64;k++){
      //This opoeration might be long but it works :D
        loafTemp[i][j][k]=threeDim[i][j][k]^(((1+(threeDim[(i+1)%5][j][k]))%2)*threeDim[(i+2)%5][j][k]);
      }
    }
  }
  _copy();
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
    int input[1600];
    for(int i=0;i<1600;i++){
      input[i]=inputv[i];
    }

    SHA3 hash(input);
    cout<<endl;

    //TO TEST THE FUNCTIONS UNCOMMENT THEM INDIVIDUALLY AND LEAVE HASH OUTPUT AS IS
    //IF YOU WANT TO TEST DIFFERENT PLACES IN THE ARRAY CHANGE OUTPUT()
    //THE ONE DIMENSIONAL ARRAY IS CALLED _oneDim
    //hash.theta();
    //hash.rho();
    //hash.pi();
    hash.chi();
    hash.output();
return 0;

}
