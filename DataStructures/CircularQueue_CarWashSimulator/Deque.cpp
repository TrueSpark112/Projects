#include <iostream>
#include <string>
#include "Deque.h"
#include <stdlib.h>
#include <time.h>
using namespace std;
template<class T>
void deque<T>::push_back(T in){
  if(!full()){
    if(size==0){
      Node<T> * temp = new Node<T>(in,nullptr,nullptr);
      tail = temp;
      head = temp;
      size++;
      return;
    }
    Node<T> * temp = new Node<T>(in,tail,nullptr);
    tail->next=temp;
    tail = temp;
    size++;
  }
}

template<class T>
void deque<T>::push_front(T in){
  if(!full()){
    if(size==0){
      Node<T> * temp = new Node<T>(in,nullptr,nullptr);
      tail = temp;
      head = temp;
      size++;
      return;
    }
    Node<T> * temp = new Node<T>(in,nullptr,head);
    head->prev=temp;
    head=temp;
    size++;
  }
  }

template<class T>
void deque<T>::pop_back(){
  if (tail){
    Node<T>* newtail= tail->prev;
    delete tail;
    tail=newtail;
    size--;
  }
}

template<class T>
void deque<T>::pop_front(){
  Node<T> * newhead= head->next;
  delete head;
  head = newhead;
}
template<class T>
void deque<T>::clear(){
  Node<T> * temp = head;
  while(head){
    temp = head;
    head=head->next;
    delete temp;
  }
}
template <class T>
deque& deque::copy(const deque<T>& other){
  if(this!=&other){
    size= other.size;
    capacity= other.capacity;
    for(Node<T>* pcurr =other.head;pcurr!=other.tail)
    {
      push_front(pcurr->data);
    }
  }
  return *this;


}

int main(){
  srand(time(NULL));
  deque<int> d1;
  for(int i =0;i<5;i++){
    d1.push_back(i);
  }
  for(int i =20 ; i< 35; i++){
    d1.push_front(i);
  }
  while(!d1.empty()){
    cout<<d1.front()<<",";
    d1.pop_front();
  }



  return 0;
}
