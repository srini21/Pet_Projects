#include<iostream>
using namespace std;
class Stack{
  int top;
  int maxsize;
  int *items;
public:
  Stack(int);
  ~Stack();
  void push(int);
  int pop();
  bool isEmpty();
};
Stack::Stack(int size){
  top=-1;
  maxsize=size;
  items=new int[size];
}
Stack::~Stack(){ delete[] items;}

void Stack::push(int x){
  items[++top]=x;
}
int Stack::pop(){
  return items[top--];
}
bool Stack::isEmpty(){
  return top==-1;
}
int main(){
  Stack s(10);
  int i;
  for(int i=0;i<10;i++){
    s.push(i);
  }
  while(!s.isEmpty()){
    cout<<s.pop();
  }
}
