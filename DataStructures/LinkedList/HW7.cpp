
//For singly linked list
//#include "node.cpp"
#include<string>
//#include"HW7.h"
#include<iostream>
#include<math.h>
using namespace std;
//For doubly linked list
//#include "LinkedList.cpp"



/*******************************************************************************

For this HW please uncomment Linked node.cpp for number 1, and uncomment
Linked list.cpp for number 2 as the different problems required different node
structures.

********************************************************************************/
//#1
/*
s  int doNothing = 1;
  node<int> *pcurr;
  for(pcurr=head;pcurr->link()!=nullptr;pcurr=pcurr->link()){
    doNothing=1;
  }
  node<int> *temp = new node<int>(data,nullptr);
  pcurr->set_link(temp);
}


node<int> * mergeLists( node<int>* &head1 , node<int>* &head2){
  node<int> *rHead = new node<int>(0,nullptr),*rTail=rHead, *pcurr3=rHead;

  for(node<int> * pcurr1=head1;
  pcurr1!=nullptr;
  pcurr1=pcurr1->link()){
    rTail= new node<int>(pcurr1->data(),nullptr);

    pcurr3->set_link(rTail);
    pcurr3=pcurr3->link();

  }
  cout<<endl;

  pcurr3=rHead;
  pcurr3=pcurr3->link();
  node<int>* pPrevious=rHead;
  node<int>* temp ;
  for(node<int> * pcurr2=head2;
  pcurr2!=nullptr;
  pcurr2=pcurr2->link()){
    if(pcurr2==head2){
      if(pcurr2->data()>pcurr3->data()){
        rHead=rHead->link();
        while(pcurr2->data()>pcurr3->data()&&pcurr3){
            pPrevious=pcurr3;
            pcurr3=pcurr3->link();
        }
        temp = new node<int>(pcurr2->data(),pPrevious->link() );
        pPrevious->set_link(temp);
        pPrevious=pPrevious->link();
      }
      else{
        rHead->set_data(pcurr2->data() );
      }
    }
    else{
      if(pcurr2->data()>pcurr3->data()&&pcurr3 ){
        while(pcurr3->link()&&pcurr2->data()>pcurr3->data()){
            pPrevious=pcurr3;
            pcurr3=pcurr3->link();
        }
        if(pcurr3->link()==nullptr){
          temp = new node<int>(pcurr2->data(),nullptr);
          pPrevious=pcurr3;
          pcurr3->set_link(temp);
          pcurr3=pcurr3->link();


        }
      }
      else if(pcurr2->data()<=pcurr3->data()&&pcurr3){
        temp = new node<int>(pcurr2->data(),pcurr3);
        cout<<"Pprevious data is"<<pPrevious->data()<<endl;
        pPrevious->set_link(temp);
        pPrevious = pPrevious->link();
    }
   }

  }
  return rHead;
}

int main(){
  node<int> *head1= new node<int>(1,nullptr),*head2 = new node<int>(2,nullptr);
  addNode(head1,2);
  addNode(head1,3);
  addNode(head1,4);

  addNode(head1,6);
  addNode(head2,5);

  addNode(head2,8);
  addNode(head2,10);
  addNode(head2,11);

  cout<<"Head 1"<<endl;
  for(node<int>*pcurr=head1;pcurr!=nullptr;pcurr=pcurr->link()){
      cout<<pcurr->data()<<", ";
  }
  cout<<endl;
  cout<<"Head2"<<endl;
  for(node<int>*pcurr=head2;pcurr!=nullptr;pcurr=pcurr->link()){
      cout<<pcurr->data()<<", ";
  }
  cout<<endl;
  node<int> *head3= mergeLists(head1,head2);
  for(node<int>*pcurr=head3;pcurr!=nullptr;pcurr=pcurr->link()){
    cout<<pcurr->data()<<", ";
  }
  cout<< endl;

}
*/
//#2

/*
polynomial::polynomial(int constant){
  push(&head,constant,1);
}
polynomial::polynomial(polynomial& p1){

    for(Node* pcurr= head;pcurr!=nullptr ;pcurr=pcurr->next){
      append(p1.rHead(),pcurr->coef,pcurr->power);

    }
}



polynomial::polynomial(){
  append(&head,0,1);
}
bool polynomial::isIn(Node *head, int power){
  bool temp=false;
  for(Node *pcurr = head; pcurr!=nullptr;pcurr=pcurr->next){
    if(pcurr->power=power){
      temp = true;
    }
  }
  return temp;
}

polynomial::polynomial(int coefficient ,int power){
  push(&head,coefficient,power);
}




polynomial& polynomial::operator =(polynomial& rhs)
{
  polynomial p2;
  if(this->rHead()==rhs.rHead() ) {
    return *this;
  }
  else{

    for(Node* pcurr= head;pcurr!=nullptr ;pcurr=pcurr->next){
      append(p2.rHead(),pcurr->coef,pcurr->power);
    }
    return p2;
   }
}


void polynomial::~polynomial(){
  Node *pcurr *pPrevious;
  while(pcurr!=nullptr){
    pPrevious = pcurr;
    pcurr=pcurr->next;
    delete[] pPrevious;
  }
}

polynomial operator +(polynomial& lhs, polynomial& rhs){
  polynomial p1;

  for(pcurr1=lhs.rHead();pcurr1!=nullptr;pcurr1=pcurr1->next){
    for(pcurr2=rhs.rHead();pcurr2!=nullptr;pcurr2=pcurr2->next){
        if(pcurr2->power==pcurr1->power){
          append(*p1,pcurr1->coef+pcurr2->coef),p1->power;
        }
        else{
          if(p1.!isIn(pcurr1->coef,pcurr1->power)){
            append(*p1.Head(),pcurr1->coef,pcurr1->power)
        }
    }
  }
}
Node * pPrevious=p1.head();
  for(Node *pcurr=lhs.rHead();pcurr1!=nullptr;pcurr1=pcurr1->next){
      if(!IsIn(p1.rHead(),pcurr->power)){
        Node* pcurr2 = p1.Head();
        while(pcurr2->power>pcurr1->power&&pcurr2){
          pPrevious=pcurr2;
          pcurr2=pcurr2->next;
        }
        if(pPrevious==p1.head()){
          push(*p1.head(),pcurr1->coef,pcurr1->power);
        }
        else if(pcurr2==nullptr){
          append(*p1.head(),pcurr1->coef,pcurr1->power);
        }
        else{
          insertAfter(pPrevious,pcurr1->coef,pcurr1->power);
        }
      }
    }

  return p1;
}



polynomial operator -( polynomial& lhs, polynomial& rhs){
  polynomial p1;

  for(pcurr1=lhs.rHead();pcurr1!=nullptr;pcurr1=pcurr1->next){
    for(pcurr2=rhs.rHead();pcurr2!=nullptr;pcurr2=pcurr2->next){
        if(pcurr2->power==pcurr1->power){
          append(*p1,pcurr1->coef+pcurr2->coef),p1->power;
        }
        else{
          if(p1.!isIn(pcurr1->coef,pcurr1->power)){
            append(*p1.Head(),pcurr1->coef,pcurr1->power)
        }
    }
  }
}
Node * pPrevious=p1.head();
  for(Node *pcurr=lhs.rHead();pcurr1!=nullptr;pcurr1=pcurr1->next){
      if(!IsIn(p1.rHead(),pcurr->power)){
        Node* pcurr2 = p1.Head();
        while(pcurr2->power>pcurr1->power&&pcurr2){
          pPrevious=pcurr2;
          pcurr2=pcurr2->next;
        }
        if(pPrevious==p1.head()){
          push(*p1.head(),pcurr1->coef,pcurr1->power);
        }
        else if(pcurr2==nullptr){
          append(*p1.head(),pcurr1->coef,pcurr1->power);
        }
        else{
          insertAfter(pPrevious,pcurr1->coef,pcurr1->power);
        }
      }
    }
  return p1;
}


polynomial operator *( polynomial& lhs,  polynomial&rhs){
polynomial p1,p2;

  for(Node *pcurr1=lhs.rHead();pcurr1!=nullptr;pcurr1=pcurr1->next){
    for(Node *pcurr2=rhs.rHead();pcurr2!=nullptr;pcurr2=pcurr2->next){

      append(*p1.rHead(),pcurr2->coef*pcurr1->coef,pcurr1->power+pcurr2->power);
    }
  }
  node * tmptl=nullptr;
  node* pcurr=p1.rhead();
  while(pcurr){
    node * ptmp= tmptl;
    while(ptmp &&ptmp->power!=pcurr->power()){

    }
  }
  }
}




int polynomial::evaluate(int n){
  double result=0;
for(Node *pcurr = head; pcurr!=nullptr;pcurr=pcurr->next){
  result+=pow(pcurr->coef,pcurr->power)*n;
}
  return result;
}


int main(){
  return 0;

  }
*/
//#3
// A linked list node


struct Node
{
   int data;
   struct Node *next;
};
//insert a new node in an empty list
struct Node *insertInEmpty(struct Node *last, int new_data)
{
   // if last is not null then list is not empty, so return
   if (last != NULL)
   return last;

   // allocate memory for node
   struct Node *temp = new Node;

   // Assign the data.
   temp -> data = new_data;
   last = temp;

   // Create the link.
   last->next = last;

   return last;
}
//insert new node at the beginning of the list
struct Node *insertAtBegin(struct Node *last, int new_data)
{
   //if list is empty then add the node by calling insertInEmpty
   if (last == NULL)
   return insertInEmpty(last, new_data);

   //else create a new node
   struct Node *temp = new Node;

   //set new data to node
   temp -> data = new_data;
   temp -> next = last -> next;
   last -> next = temp;

   return last;
}
//insert new node at the end of the list
struct Node *insertAtEnd(struct Node *last, int new_data)
{
   //if list is empty then add the node by calling insertInEmpty
   if (last == NULL)
   return insertInEmpty(last, new_data);

   //else create a new node
   struct Node *temp = new Node;

   //assign data to new node
   temp -> data = new_data;
   temp -> next = last -> next;
   last -> next = temp;
   last = temp;

   return last;
}

//insert a new node in between the nodes
struct Node *insertAfter(struct Node *last, int new_data, int after_item)
{
   //return null if list is empty
   if (last == NULL)
   return NULL;

   struct Node *temp, *p;
   p = last -> next;
   do
   {
      if (p ->data == after_item)
      {
         temp = new Node;
         temp -> data = new_data;
         temp -> next = p -> next;
         p -> next = temp;

         if (p == last)
         last = temp;
         return last;
       }
   p = p -> next;
 } while(p != last -> next);

   cout << "The node with data "<<after_item << " is not present in the list." << endl;
   return last;

}
//traverse the circular linked list
void traverseList(struct Node *last) {
   struct Node *p;

   // If list is empty, return.
   if (last == NULL) {
      cout << "Circular linked List is empty." << endl;
      return;
      }
p = last -> next; // Point to the first Node in the list.

// Traverse the list starting from first node until first node is visited again

do {
      cout << p -> data << "==>";
      p = p -> next;
      } while(p != last->next);
   if(p == last->next)
   cout<<p->data;
   cout<<"\n\n";
   }

//delete the node from the list
void deleteNode(Node** head, int key){
   // If linked list is empty retun
   if (*head == NULL)
   return;

   // If the list contains only a single node,delete that node; list is empty
   if((*head)->data==key && (*head)->next==*head) {
      delete *head;
      *head=NULL;
      return;
    }

    Node *last=*head,*d;

 // If key is the head
 if((*head)->data==key) {
    while(last->next!=*head) // Find the last node of the list
   last=last->next;

   // point last node to next of head or second node of the list
   last->next=(*head)->next;
   delete *head;
   *head=last->next;
   return;
  }

// end of list is reached or node to be deleted not there in the list
while(last->next!=*head&&last->next->data!=key) {
   last=last->next;
   cout<<"node is not in list";
}
// node to be deleted is found, so free the memory and display the list
if(last->next->data==key) {
      d=last->next;
      last->next=d->next;
      delete d;
      cout<<endl;
      }
   }


int SuitorGame(int n){
  Node *last= nullptr, *pcurr= nullptr;
  last =insertInEmpty(last,1);
  pcurr=last;
  for(int i = 0;i<n-1;i++){
    last =insertAtEnd(last,i+2);
  }

  cout<<"PRE: ";
  traverseList(last);

  while(last->next!=last){
    for(int i =0;i<1;i++){
      pcurr=pcurr->next;
    }
    cout<<endl;
    deleteNode(&pcurr,pcurr->data);
    cout<<"POST: ";
    traverseList(last);
    cout<< "B" << endl;
  }
  std::cout << "A" << endl;
//  int temp2 = last->data;


  //cout<<"Here";
  //return temp2;
  return 1;

}

// main Program
int main()
{
SuitorGame(5);
}
