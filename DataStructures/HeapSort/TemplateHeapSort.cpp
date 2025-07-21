
template <class T>
void heapsort(T data[], size_t n)
{
size_t unsorted;
make_heap(data, n);
unsorted = n;
while (unsorted > 1)
{
--unsorted;
swap(data[0], data[unsorted]);
reheapify_down(data, unsorted);
}
}

template<class T>
void make_heap(T data[],size_t n){
  for (i = 1; i < n; ++i)
{
k = i; // The index of the new entry

while(data[k]!=0&&data[k]>data[parent(k)]){
  swap(data[k],data[parent(k)]);
  k = parent(k);
}
}
}

size_t parent(size_t k)
{
return (k-1)/2;
}

size_t Lchild(size_t i){
  return 2*i+1;
}

template<class T>
void reheapify_down(T data[],size_t n){
  // Reheapification downward (for a heap where the root is out of place)
  size_t current; // Index of the node that’s moving down
  size_t big_child_index; // Index of current’s larger child
  bool heap_ok; // Will become true when heap is correct
  current = 0;
  heap_ok = false;
  while ((!heap_ok) && (Lchild(current)<=n))
  {
  if (data[Lchild(current)]!=n&&data[Lchild]<data[Lchild(current)+1]){
    big_child_index=Lchild(current)+1;
  }
  else{
    big_child_index=Lchild(current);
  }
  if (data[current] < data[big_child_index])
  {
  swap(data[current],data[big_child_index]);
  current =big_child_index;
  }
  else
  heap_ok = true;
  }
}

int main(){
int d[9]={9,8,7,6,5,4,3,2,1}
heapsort(d,9);
for(int i=0;i<9;i++){
  cout<<d[i];
}
}
