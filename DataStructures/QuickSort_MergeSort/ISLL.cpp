#include <vector>
template <class T>
struct Node{
 Node(T idata = NULL, Node * inext = nullptr)
 :data(idata), next(inext){}
 T data;
 Node * next;
};
template<class T>
void LinkPush(const T& data,Node<T>* head ){
  if(head ==nullptr){
    head = new Node(data,nullptr);
    return;
  }
  Node* pcurr=head;
  Node* tmp= new Node(data,nullptr);
  while(pcurr->next!=nullptr){
    pcurr=pcurr->next;
  }
  pcurr->next = tmp;
}

//PRECONDITION: ENTER A VECTOR WITH 1 OR MORE ELEMENTS AND ITS SIZE.
//POSTCONDITION: TRANSFORMS THE VECTOR INTO A lINKED LIST, RETURNS POINTER TO THE HEAD.
template <class T>
Node* VecToLink(const vector<T>& v,const unsigned int& s){
  Node* tmp;
  for(auto it = v.begin();it!=v.end();it++ ){
    LinkPush(*it,tmp);
  }
  return tmp;
}

//PRECONDITION: ENTER A LINKED LIST WITH 1 OR MORE ELEMENTS.
//POSTCONDITION: TRANSFORMS THE lINKED LIST INTO A VECTOR, RETURNS THE VECTOR
template <class T>
vector<T> LinkToVec(Node* head ){
  Node* pcurr= head;
  vector<T> tmp;

  while(pcurr){
    tmp.push_back()
    pcurr=pcurr->next;
  }
}

template<class T>
void insertionSort(vector<T> A, int start, int finish){
  for(int i = start +1, i<= finish, i++){
    key = A[i];
    int j = i-1;
    while (j>=start && key < A[j]){
      A[j+1] = A[i];
      j--;
      a[j+1]=key;
    }
  }
}
template <class T>
void insertionSort(Node& * head){
  vector<T> temp= LinkToVec(head);
  insertionSort(temp,0,temp.size() );
  head = VecToLink(temp,temp.size() );

}
