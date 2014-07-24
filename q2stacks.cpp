#include<iostream>
#include<stack>
using namespace std;
class Qstack{
  stack<int> a;
  stack<int> b;
public:
  void enq(int num){
    a.push(num);
  }
  int deq(){
    if(b.empty()){
      while(!a.empty()){
	b.push(a.top());
	a.pop();
      }
    }
    if(!b.empty()){
      int ret=b.top();
      b.pop();
      return ret;
    }
  }
};
int main(){
  Qstack q;
  int i=5;
  while(i--){
    q.enq(i);
  }
  i=5;
  while(i--){
    cout<<q.deq();
  }
}
