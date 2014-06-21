#include<iostream>
#include<queue>
#include<vector>
#include<stdlib.h>
#include<algorithm>
#include<stack>
using namespace std;
struct node{
  int val;
  struct node* left;
  struct node * right;
  node(int data){
    val=data;
    left=NULL;
    right=NULL;
  }
};
struct node* insert(struct node* root, int data){//inserts data into a bst
  if(!root){
    return new node(data);
  }else{
    if(root->val>=data){
      root->left=insert(root->left, data);
    }
    else{
      root->right=insert(root->right,data);
    }
    return root;
  }
}
void inorderPrint(struct node *root){
  if(!root){
    return;
  }
  stack<struct node*> s;
  bool flag=false;
  while(!flag){
    if(root){
      s.push(root);
      root=root->left;
    }
    else{
      if(s.empty()){
	flag=true;
      }
      else{
	root=s.top();
	s.pop();
	cout<<root->val<<"\n";
	root=root->right;
      }
    }
  }
}

void print(struct node * root){//prints the tree
  if(!root){
    cout<<"Empty Tree";
  }
  else{
    inorderPrint(root);
  }
}
void bfs(struct node* root){
  if(!root){
    return;
  }
  queue<struct node*> q;
  q.push(root);
  int curr=1;
  int nxt=0;
  while(!q.empty()){
    struct node * currNode= q.front();
    q.pop();
    curr--;
    if(currNode){
      cout<<currNode->val<<"\t";
      q.push(currNode->left);
      q.push(currNode->right);
      nxt+=2;
    }
    if(curr==0){
      cout<<"\n";
      curr=nxt;
      nxt=0;
    }
  }
}
int size(struct node* root){
  if(!root){
    return 0;
  }
  else{
    return 1+size(root->left)+size(root->right);
  }  
}
int maxDepth(struct node* node){
  if(!node){
    return 0;
  }
  else{
    return max(1+maxDepth(node->left),1+maxDepth(node->right));
  }
}
struct node * build123(){
  struct node * res=NULL;
  res=insert(res,2);
  res=insert(res,1);
  res=insert(res,3);
  return res;
}
struct node* skew(){
  struct node * res=NULL;
  for(int i=0;i<10;i++){
    res=insert(res,i);
  }
  return res;
}
int minValue(struct node* node){
  if(!node->left){
    return node->val;
  }
  else{
    minValue(node->left);
  }
}
int main(){
  struct node * n= build123();
  print(n);
  cout<<minValue(n);
}
