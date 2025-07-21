#include<string>
#include <iostream>
#include "CircularQueue.h"
using namespace std;



void
Queue::enqueue (int d)
{
  if (!empty ())
    {
      Node *temp = new Node (d, tail->next);
      tail->next = temp;
      tail = temp;
    }
  else if(tail==nullptr)
    {

      tail = new Node (d, nullptr);
      tail->next=tail;
    }

}

int
Queue::dequeue ()
{
  Node *temp = tail->next;
  int result = temp->data;
  tail->next = (temp->next);
  delete temp;
  return result;
}


int
Queue::Front ()
{
    //The program likes to send a segmentation error at this point and I'm not sure why
    // If you instead return the value at the tail it works, however the rest of the
    //class works.
     return (tail->next->data);

}

bool
Queue::empty ()
{
  if (tail == nullptr)
    {
      return true;
    }
  return false;
}

int
Queue::size ()
{
    if(!tail){
        return 0;
    }
  int size = 1;
  Node *pcurr = tail->next;
  while (pcurr != tail)
    {
      pcurr = pcurr->next;
      size++;
    }
  return size;
}

void Queue::clear(){
  if (size() == 0) {
            return;
        }
        else if (size() == 1) {
            delete tail;
            return;
        }
        else {
            Node* pcurr = tail;
            pcurr = pcurr->next;
            while (tail != pcurr) {
                Node* tmp = tail;
                tail = tail->next;
                delete tmp;
            }
            delete pcurr;
            return;
        }
}



int
main ()
{

  Queue q1;

  q1.enqueue (27);
  q1.enqueue (28);
  //int i1 = q1.Front();
  q1.dequeue();
  cout<< q1.dequeue();


}
