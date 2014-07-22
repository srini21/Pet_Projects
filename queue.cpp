#include<iostream>
using namespace std;
struct node{
  int data;
  node* next;
};
class Queue{
  int size;
  int max;
  node* head;
  node* tail;
public:
  Queue(int);
  void enqueue(int);
  int dequeue();
  void print();
};
Queue::Queue(int qsize){
  max=qsize;
  size=0;
  head=NULL;
  tail=NULL;
}
void Queue::enqueue(int num){
  if(size==max){
    cout<<"\n Queue full";
    return;
  }
  node * temp= new node();
  temp->data=num;
  if(head==NULL){
    head=temp;
    tail=temp;
  }else{
    tail->next=temp;
    tail=tail->next;
  }
  size++;
}
int Queue::dequeue(){
  if(!head){
    return -1;
  }else{
    int res=head->data;
    head=head->next;
    size--;
    return res;
  }
}
void Queue::print(){
  while(size){
    cout<<"\n"<<dequeue();
  }
}
int main(){
  Queue q(5);
  for(int i=5;i<11;i++){
    q.enqueue(i);
  }
  q.print();
}
