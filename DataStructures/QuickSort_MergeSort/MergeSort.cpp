#include <iostream>
#include <string>
using namespace std;


void Merge (int A[], int start, int middle, int end,int temp[] ){
  size_t copied = 0; // Number of elements copied from data to temp
  size_t copied1 = 0; // Number copied from the first half of data
  size_t copied2 = 0; // Number copied from the second half of data
  int i= (end - start); // Array index to copy from temp back into data
  // Merge elements, copying from two halves of data to the temporary array.
  while ((copied1 < n1) && (copied2 < n2))
  {
      if (A[copied1] < (data + n1)[copied2])
          temp[copied++] = data[copied1++]; // Copy from first half
      else
          temp[copied++] = (data + n1)[copied2++]; // Copy from second half
  }
  // Copy any remaining entries in the left and right subarrays.
  while (copied1 < n1)
      temp[copied++] = data[copied1++];
  while (copied2 < n2)
      temp[copied++] = (data + n1)[copied2++];
  // Copy from temp back to the data array
  for (i = 0; i < n1 + n2; ++i)
      data[i] = temp[i];
}
}

void mergesort(
int data[ ],
size_t start,
size_t end,
int temp[ ]
)
{
  if(start==end){return;}

  mergesort(data,start,middle,temp);
  mergesort(data,middle+1,end,temp);
  for(int i =0;i<10;i++){
    cout<<data[i]<<",";
  }
  cout<<endl;
  int middle=(start+end)/2;
  Merge(data,start,middle,end,temp);
}


int main(){
  int a[10]={10,9,8,7,6,5,4,3,2,1};
  int b[10];
  mergesort(a,0,9,b);
  for(int i =0;i<10;i++){
    cout<<a[i]<<",";
  }

}


// Precondition: data[first_index] through
// data[last_index] are array elements in no
// particular order. The temp array has
// locations temp[first_index] through
// temp[last_index].
// Postcondition: The elements
// data[first_index] through data[last_index]
// have been rearranged so that they are
// ordered from smallest to largest. The array
// elements temp[first_index] through
// temp[last_index] have been used as
// temporary storage and now contain a
// copy of data[first_index] through
// data[last_index]
