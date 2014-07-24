#include<iostream> 
using namespace std;
class CirQ{
  int *q;
  int start;
  int end;
  int size;
public: 
  CirQ(int Qsize){
    q = new int[Qsize];
    start=0;
    end=0;
    size=Qsize;
  }
  void enQ(int num){
      q[(end++)%size]=num;
  }
  int deQ(){
      return q[start++];
  }
  bool empty(){
    return end==start;
  }
  bool full(){
    return (end+1)%size==start;
  }
};

int main(){
  CirQ q(5);int i=0;
  while(!q.full()){
    cout<<i;
    q.enQ(i++);
  }
  while(!q.empty()){
    cout<<q.deQ()<<"-";
  }
}
