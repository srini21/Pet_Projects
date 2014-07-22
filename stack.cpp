#include<iostream>
#include<climits>
#include<stack>
#include<utility>
#include<climits>
using namespace std;
class Stack{
  stack <pair<int, int> > s;
public:
  void push(int num){
    s.push(make_pair(num, std::max(num, empty()?num:s.top().second)));
  }
  int pop(){
    if(s.empty()){
      return -1;
    }
    else{
      int res=s.top().first;
      s.pop();
      return res;
    }
  }
  int max(){
    if(s.empty()){
      return INT_MIN;
    }else{
      return s.top().second;
    }
  }
  bool empty(){
    return s.empty();
  }

};
int main(){
  Stack s;
  for(int i=0;i<10;i++){
    s.push(i);
  }
  cout<<s.pop()<<s.pop();
  cout<<s.max();
}
