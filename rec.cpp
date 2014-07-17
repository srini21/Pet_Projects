using namespace std;
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
int max=30,min=4;
void print4(int ct, bool flag, string num){
  if(ct < 0 || (ct==0 && !flag)) return;
  if(ct==0 && std::stoi(num) > min && std::stoi(num) < max){
    cout<<num;
    return;
  }
  for(int i=0;i<9;i++){
    if(i==4||i==7){
      flag=1;
    }
    print47(ct-1,flag,strcat(num,(char)i));
  }
}
//
bool isUniq(string s){
  int check=0;
  for(int i=0;i<s.length();i++){
    int val=s[i]-'a';
    if(check&1<<val){
      return false;
    }
    check|=1<<val;
  }
  return true;
}
void rev(char * str){
  char * end= str;
  char tmp;
  if(str){
    while(*end){
      ++end;
    }
    --end;
    while(str <end){
      tmp=*str;
      *str++=*end;
      *end--=tmp;
    }
  }
  cout<<*str;
}
void removeDup(char * s){
  int tail=1,end=1;
  while(*(s+end)){
    if(*(s+end)!=*(s+end-1)){
      *(s+tail)=*(s+end);
      tail++;
    }
    end++;
  }
  *(s+end)='\0';
}
int main(){
  print4(3,0,'');
}
