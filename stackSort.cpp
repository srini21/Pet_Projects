#include<iostream>
#include<stack>
using namespace std;
void insert(stack<int> &st, int e){
  if(st.empty()||st.top()<=e){
    st.push(e);
  }else{
    int f=st.top();
    st.pop();
    insert(st,e);
    st.push(f);
  }
}
void sort(stack<int> &st){
  if(!st.empty()){
    int e=st.top();
    st.pop();
    sort(st);
    insert(st,e);
  }
}
int main(){
  stack<int> s;
  for(int i=0;i<10;i++){
    s.push((i+1)%2);
  }
  sort(s);
  while(!s.empty()){
    cout<<s.top()<<"-";
    s.pop();
  }
}
