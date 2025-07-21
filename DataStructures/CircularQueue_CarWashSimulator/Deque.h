#ifndef DEQUE_H
#define DEQUE_H
using namespace std;

template <class T>
struct Node{
  Node(T idata, Node<T>* iprev= nullptr, Node<T>* inext=nullptr)
  :data(idata),prev(iprev),next(inext){}
  T data;
  Node * prev;
  Node * next;
};

template <class T>
class deque{
public:
  //CONSTRUCTOR
  deque(int icapacity =100):capacity(icapacity){}
  //RETURNS ELEMENT AT THE START OF THE DEQUE
  T front(){return head->data; }
  //RETURNS ELEMENT AT THE END OF THE DEQUE
  T back(){return tail->data;}
  // RETURNS TRUE IF DEQUE IS EMPTY
  bool empty(){return(!head);}
  // RETURNS TRUE IF DEQUE IS FULL
  bool full(){
    return size==capacity;
  }
  //Adds element at the back if deque is not full
  void push_back(T);
  //Adds element at the front if deque is not full
  void push_front(T);
  //Pops element at back
  void pop_back();
  //Pops element at front
  void pop_front();
  //Empty the queue
  void clear();
  //Copy
  deque& copy(const deque<T>&);
  //COPY CONSTRUCTOR
  deque(const deque<T>&other){
    copy(other);
  }
  //DESTRUCTOR
  ~deque(){
    clear();
  }




private:
  unsigned int size =0;
  unsigned int capacity;
  Node<T>* head;
  Node<T>* tail;

};


#endif
