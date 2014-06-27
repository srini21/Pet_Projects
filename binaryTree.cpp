#include<iostream>
#include<queue>
#include<vector>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<limits.h>
#include<utility>
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
  while(true){
    if(root){
      s.push(root);
      root=root->left;
    }
    else{
      if(s.empty())
	break;
      else{
	root=s.top();
	s.pop();
	cout<<root->val<<"\t";
	root=root->right;
      }
    }
  }
}
void postorderPrint(struct node * root){
  if(!root){
    return;
  }
  stack<struct node*> s;
  s.push(root);
  struct node * prev=NULL;
  while(!s.empty()){
    struct node* curr=s.top();
    if(!prev||prev->left==curr||prev->right==curr){//moving down
      if(curr->left){
	s.push(curr->left);
      }
      else if(curr->right){
	s.push(curr->right);
      }
    }
    else if(curr->left==prev){
      if(curr->right){
	s.push(curr->right);
      }
    }
    else{
      cout<<curr->val<<"\t";
      s.pop();
    }
    prev=curr;
  }
}
bool hasPathSum(struct node * root, int sum){
  if(!root){
    return sum==0;
  }
  else{
    int subSum=sum-root->val;
    return hasPathSum(root->left,subSum) || hasPathSum(root->right,subSum);
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
struct node *randomTree(){
  struct node * res=NULL;
  res=insert(res,10);
  res=insert(res,7);
  res=insert(res,9);
  res=insert(res,8);
  res=insert(res,5);
  res=insert(res,6);
  res=insert(res,12);
  res=insert(res,11);
  res=insert(res,15);
  res=insert(res,14);
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
void printvector(vector<int>&v){
  for(vector<int>::iterator it=v.begin();it!=v.end();it++){
    cout<<*it<<"\t";
  }
  cout<<"\n";
}
void printPath(struct node * root,vector<int>r, vector<vector<int> > res){
  vector<vector<int> > res2;
  if(!root){
    return;
  }
  if(!root->left&&!root->right){
    r.push_back(root->val);
    res2.push_back(r);
    for(int i=0;i<res2.size();i++){
      printvector(res2[i]);
    }
  }
  else{
    r.push_back(root->val);
    printPath(root->left,r,res2);
    printPath(root->right,r,res2);
  }
}
void printPathDrive(struct node * root){
  vector<int> r;
  vector<vector< int> > res;
  printPath(root, r, res);
}
void mirror(struct node * root){
  if(!root)return;
  else{
    struct node* temp=root->left;
    root->left=root->right;
    root->right=temp;
    mirror(root->left);
    mirror(root->right);
  }
}
void morrisTraversal(struct node* root){
  while(root){
    if(root->left){
      struct node * pre=root->left;
      while(pre->right&&pre->right!=root){
	pre=pre->right;
      }
      if(pre->right){
	pre->right=NULL;
	root=root->right;
      }else{
	cout<<root->val<<"--";	
	pre->right=root;
	root=root->left;
      }
    }else{
      cout<<root->val<<"-";
      root=root->right;
    }
  }
}
void doubleTree(struct node * root){
  if(!root){
    return;
  }
  else{
    struct node* oldNode;
    doubleTree(root->left);
    doubleTree(root->right);
    oldNode=root->left;
    root->left=new node(root->val);
    root->left->left=oldNode;
  }
}
bool sameTree(struct node* a, struct node * b){
  if(!a&&!b){
    return true;
  }
  else if(a&&!b|| !a&&b || a->val!=b->val){
    return false;
  }
  else{
    return sameTree(a->left,b->left)&&sameTree(a->right,b->right);
  }
}
long long int numTrees(int n){
  if(n<=1)
    return 1;
  else{
    int left,right,root;
    long long int sum=0;
    for(root=1;root<=n;root++){
      left=numTrees(root-1);
      right=numTrees(n-root);
      sum+=left*right;
    }
    return sum;
  }
}
bool minmax(struct node * root, int max, int min){
  if(!root){
    return true;
  }
  else{
    if(root->val>=max||root->val<min){
      return false;
    }
    else{
      return minmax(root->left,root->val,min)&&minmax(root->right,max,root->val);
    }
  }
}
bool isBST(struct node * root){
  if(!root)
    return true;
  else{
    return minmax(root,INT_MAX,INT_MIN);
  }
}
pair<struct node *, int> firstKBal(struct node * root,int k){
  if(!root){
    return pair<struct node*, int>(NULL,0);
  }
  pair<struct node* ,int> l=firstKBal(root->left,k);
  if(l.first){
    return l;
  }
  pair<struct node *, int> r=firstKBal(root->right,k);
  if(r.first){
    return r;
  }
  int nodes=l.second+r.second+1;
  if(abs(l.second-r.second)>k){
    return make_pair(root,nodes);
  }
  return pair<struct node*, int>(NULL,nodes);
}
int main(){
  struct node * n= randomTree();
  struct node * n1=skew();
  vector<int>r;
  vector<vector <int> >res;
  // morrisTraversal(n);
  // cout<<endl;
  // postorderPrint(n);
  // bfs(n);
  pair<struct node*,int> p=firstKBal(n1,0);
  if(!p.first){
    cout<<p.second;
  }else{
    bfs(p.first);
  }  
}
