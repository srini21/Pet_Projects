#include<iostream>
#include<climits>
#include<stack>
using namespace std;
struct node{
  int data;
  int order;
  node * next;
  node * jump;
};
node* traverseJump(node * root){
  node * first= root;
  while(root){
    if(root->next){
      if(root->next->next){
	root->jump=root->next->next;
      }else{
	root->jump=first;
      }
    }else{
      root->jump=first->next;
    }
    root=root->next;
  }
  return first;
}
node * createList(int size){
  node * curr= new node();
  node * ret=curr;
  int i=0;
  while(size--){
    node * temp= new node();
    curr->order=-1;
    curr->data=++i;
    curr->next=temp;
    curr->jump=NULL;
    curr=curr->next;
  }
  curr->order=-1;
  return ret;
  
}
void jumpStack(node * n){
  stack<node *>st;
  st.push(n);
  while(!st.empty()){
    node * curr= st.top();
    st.pop();
    if(curr&&curr->order==-1){
      curr->order=1;
      cout<<curr->data;
      st.push(curr->next);
      st.push(curr->jump);
    }
  }
}

void printlist(node * n){
  while(n){
    cout<<n->data;
    if(n->jump)
    cout<<"|"<<n->jump->data<<"-";
    else cout<<n->data<<"!";
    n=n->next;
  }
  cout<<"\n";
}
void jumpList(node * root, int order){
  if(root&&root->order==-1){
    root->order=++order;
    cout<<root->data<<"-";
    jumpList(root->jump,order);
    jumpList(root->next,order);
  }
}
int main(){
  node * root= createList(5);
  root=traverseJump(root);
  printlist(root);
  jumpStack(root);
  
}
