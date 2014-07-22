#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;
class Stackset{
  vector<stack<int> > vec;
public:
  int pop(int);
  void push(int);
};
int Stackset::pop(int i){
  if(vec.empty()){
    return INT_MAX;
  }else{
    while(!vec[i].empty()){
      int res=vec[i].top();
      vec[i].pop();
      cout<<res;
    }
    return -1;

  }
}
void Stackset::push(int num){
  if(vec.empty()||vec[vec.size()-1].size()==5){
    cout<<"New Stack"<<"\n";
    stack<int> s;
    s.push(num);
    vec.push_back(s);
  }else{
    vec[vec.size()-1].push(num);
  }
}

int main(){
  Stackset s;
  for(int i=0;i<20;i++){
    s.push(i);
  }
    cout<<s.pop(4);
}
