#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

struct Node
{
Node (int idata = 0, Node * inext = nullptr):data (idata), next (inext)
  {
  }
  int data;
  Node * next;
};

class Queue
{
public:
  Queue ()
  {
  }
  //ADD ELEMENT TO QUEUE
  void enqueue (int);
  //REMOVE ELEMENT FROM QUEUE
  //BECAUSE OF A BUG WITH THE FRONT FUNCTION
  //IT ALSO RETURNS THE DATA IN FRONT OF THE QUEUE
  int dequeue ();
  //RETURN ELEMENT IN FRONT OF QUEUE

  // For some reason the program crashes whenever it has to use the front function
  int Front ();
  //RETURN TRUE IF QUEUE IS EMPTY
  bool empty ();
  //RETURN SIZE OF THE QUEUE
  int size ();
  //Clear function for DESTRUCTOR
  void clear();

  ~Queue ()
  {
  clear();
  }

private:

  Node * tail;

};













#endif
