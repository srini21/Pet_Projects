#include<stack>
#include<algorithm>
#include<iostream>
using namespace std;
bool uniq(string s){
  int val=0;
  int len=s.length();
  for(int i=0;i<len;i++){
    int check=(s[i]-'a');
    if(val&(1<<check)){
      cout<<"dup";
      return false;
    }
    val|=(1<<check);
  }
  cout<<"no dup";
  return true;
}
int main(){
  uniq("1q");
}
