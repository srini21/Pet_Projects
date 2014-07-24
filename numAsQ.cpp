#include<iostream>
#include<queue>
#include<tgmath.h>
class Queue{
  unsigned val, size;
public:
  Queue() : val(0), size(0){}
  void enqueue(const unsigned &x){
    val=val*10+x;
    ++size;
    cout<<val;
  }
  unsigned dequeue(){
    if(size){
      unsigned ret=0,d=floor(log10(val));
      if(d+1==size){
	ret=val/pow(10,d);
	val-=pow(10,d)*ret;
      }
      --size;
      return ret;
    }
  }
};
int main(){
  Queue q();
  int i=3;
  while(i--){
    q.enqueue(i);
  }
}
