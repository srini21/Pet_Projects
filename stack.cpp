#include<iostream>
using namespace std;
class Stack{
  int size;
  int* items;
  int top;
public:
  Stack(int);
  ~Stack();
  void push(int);
  int pop();
  bool isEmpty();
};
Stack::Stack(int size){
  items= new int[size];
  top=-1;
}
Stack::~Stack(){
  delete[] items;
}
void Stack::push(int num){
  items[++top]=num;
}
int Stack::pop(){
  return items[top--];
}
bool Stack::isEmpty(){
  return (top==-1);
}
int main(){
  Stack s(20);
  int c;
  while((c=cin.get())!='\n'){
      s.push(c-'0');
  }
  while(!s.isEmpty()){
    cout<<"\t"<<s.pop();
  }
}
