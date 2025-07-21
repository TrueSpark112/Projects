#include <iostream>
#include <vector>
#include <stack>
#include <time.h>
#include<stdlib.h>
#include<string>
using namespace std;

int
Partition (vector < int >&A, int start, int &end)
{
  int pivot = A[start];
  int pivot_index = start;
  int i = start + 1;
  int j = end;
  while (i <= j)

    {
      while (i <= end && A[i] < pivot)
	{
	  i++;
	}
      while (j >= start && A[j] > pivot)
	{
	  j--;
	}
      if (i < j)
	{
	  std::swap (A[i], A[j]);
	}
    }
  std::swap (A[j], A[pivot_index]);
  return pivot_index;
}

void
QuickSort (vector < int >&A, int start, int end)
{

  int pivot_index = start + end / 2;
  stack < int >s;
  s.push (0);
  s.push (end);
  while (!s.empty ())
    {
      int size = s.top ();
      s.pop ();
      int i = s.top ();
      s.pop ();
      pivot_index = Partition (A, size, pivot_index);
      if (pivot_index - i > 0)
	{
	  s.push (i);
	  s.push (pivot_index);
	}
      if (end - (i + pivot_index + 1))
	{
	  s.push (i + pivot_index + 1);
	  s.push (size - pivot_index - 1);
	}
    }

}
int main(){
    srand(time(NULL));
    vector<int> v1;
    for(int i =0;i<5;i++){
        v1.push_back(rand()%100);
    }
    QuickSort(v1,0,v1.size());
    for(auto it = v1.begin();it!=v1.end();it++){
        cout<<*it<<",";
    }
    return 0;
}
