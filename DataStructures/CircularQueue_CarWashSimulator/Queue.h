class Queue1{
public:
  Queue1()
  void enqueue(int d){
    Node*pcurr=head;
    while(pcurr->next()!=nullptr){
      pcurr->setNext(pcurr->next());
    }
    Node* temp= new Node(d,nullptr);
    pcurr->setNext(temp);

  }
  void dequeue(){
    head= head->next();
  }
  int Front(){
    return head->data();
  }
  bool empty(){
    if (head== nullptr){
      return true;
    }
  }
  int size(){
    int size=0;
    Node* pcurr;
    while(pcurr){
      pcurr=pcurr->next();
      size++;
    }
    return size;
  }

private:
  class Node(){
    public:
      Node(int data=0, Node* next= nullptr):data_(data),next_(next_){}
      Node * next(){return next_;}
      int data(){return data_;}
      setNext(Node* to){next_=to;}
      sData(int d){data_=d;}
    private:
      int data_;
      Node * next_;
  };
  Node* head;

};


class Queue2{
  public:
    Queue2(int icount=0,int icapacity=4):
    count(icount),front(icount),back(icount),capacity(icapacity){
      data= new int[capacity];}
    ~Queue(){
      delete[] data;
    }
    Queue(const Queue& other){
      copy(other);
    }

    Queue& operator =(const Queue& other){
         if(this==&other){
           return *this;
         }
          if(data){
            delete [] data;
          }


          copy(other);
          return *this;

    }
    void copy(const Queue& other){
      count = other.count;
      front= other.front;
      back= other.back;
      capacity= other.capacity;
      data = new int[other.capacity];
      for(int i =0;i<other.capacity;i++){
        data[i]=other.data[i];
      }
    }

    void enqueue(int d){
      if(count<=capacity){
        data[back]=d;
        back=nextIndex(back);
        count++;
      }
      else{
        increaseCapacity();
        enqueue(d);
      }
    }

    void dequeue(){
      front= nextIndex(front);
      count--;
    }
    int Front(){
      assert(!empty());
      return data[front];
    }
    bool empty(){
      return size()==0;
    }
    int size(){
      return count;
    }

  private:
    int *data;
    unsigned int capacity;
    unsigned int count, front, back;
    unsigned int nextIndex(unsigned int i){
      return(i+1)%capacity;
    }
    void increaseCapacity(){
      int *tmp =new int[2*capacity];
      int tmp_index=0;
      for(unsigned int i=1;i<=count;i++){
        tmp[tmp_index]=data[front];
        front = nextIndex(front);
        tmp_index ++;
      }
      delete[] data;
      data=tmp;
      back=count-1;
      front=0;
      capacity*=2;
    }
};
