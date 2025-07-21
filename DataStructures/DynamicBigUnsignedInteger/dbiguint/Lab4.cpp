
//#include "dbiguint.h"
#include "dbiguint.cpp"
#include "Lab3.cpp"
using namespace std;
typedef unsigned short* shortPtr;



int main()
{
    dbiguint biguint = dbiguint();
    dbiguint i1124 = dbiguint("1124");
    dbiguint i1111 = dbiguint("1111");
    string s= "";

    cout << "0: " << biguint << endl << "1124: " << i1124 << endl;
    cout << "Second digit in 1124: " << i1124[2] << endl;
    cout << "Size of 1124: " << i1124.size() << endl;

    biguint.reserve(4);
    cout << "Size of 0000: " << biguint.size() << endl;

    i1111 += i1124;
    cout << "1111 + 1124: " << i1111 << endl;

    return 0;
}
