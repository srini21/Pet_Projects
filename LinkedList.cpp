using namespace std;
#include<iostream>
#include<malloc.h>
struct node{
  int data;
  struct node * next;
};
int count(struct node* head,int number){//Number of occurrences of 'number'
  int count=0;
  while(head!=NULL){
    if(head->data==number){
      count++;
    }
    head=head->next;
  }
  return count;
}
int len(struct node*head){//Length of the linked list
  int length=0;
  while(head!=NULL){
    length++;
    head=head->next;
  }
  return length;
}
void printlist(struct node * head){//printing the list
  if(head==NULL){cout<<"Empty List\n";}
  while(head!=NULL){cout<<head->data<<"-";head=head->next;}
  cout<<"\n";
}
int getnth(struct node* head,int nth){//get the nth number of the list if it exists
  int i;
  for(i=0;i<nth-1;i++){
    if(head->next==NULL){return 0;}
    head=head->next;
  }
  return head->data;
}
void push(struct node** headRef, int number){//push a number to the front by creating a node given the number
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->data=number;
  temp->next=*headRef;
  *headRef=temp;
}
int pop(struct node * head){//pop the head from the list
  if(head==NULL){return -1;}
  int res=head->data;
  struct node * temp= head->next;
  free(head);
  head=temp;
  return res;
}
void del_list(struct node ** ref){//delete the whole list
  if((*ref)==NULL){
    cout<<"End\n";
    return;
  }
  else{
    del_list(&((*ref)->next));
    cout<<(*ref)->data;
    cout<<"\n";
    free((*ref));
    cout<<"Deleted";

  }
}
void sortedInsert(struct node ** headRef,struct node* newNode){//given a sorted list and a newNode, insert the newNode in its correct position
  if(*headRef==NULL|| (*headRef)->data >= newNode->data){
    newNode->next=*headRef;
    *headRef=newNode;
  }
  else{
  struct node* current=*headRef;
  while(current->next!=NULL&&current->next->data < newNode->data ){
    current=current->next;
  }
  newNode->next=current->next;
  current->next=newNode;
  }
}
void insert(struct node **headRef, int index, int val){//insert a given number in the given index
  struct node* current=*headRef;
  struct node* nex= (*headRef)->next;
  if(index==0){push(headRef,val);
    return;}
  int i=0;
  for(i=0;i<index-1;i++){
    if(current==NULL){
      return;
    }
    current=current->next;
    nex=nex->next;
  }
  push(&nex, val);
  current->next=nex;
}
void insertSort(struct node ** headRef){//given a list, rearrange the nodes so that they are in increasing order, using SortedInsert
  struct node *result=NULL;
  struct node * current= *headRef;
  struct node * next;
  while(current!=NULL){
    next=current->next;
    sortedInsert(&result,current);
    current=next;
  }
  *headRef=result;
}
void append(struct node** aref, struct node** bref){//append list b to list a
  struct node* result=*aref;
  if(*aref==NULL){
    *aref=*bref;
    *bref=NULL;
    return;
  }
  if(*bref==NULL){
    return;
  }
  while((*aref)->next!=NULL){
    *aref=(*aref)->next;
  }
  (*aref)->next=*bref;
  *bref=NULL;
  *aref=result;
}
void fbsplit(struct node * head, struct node** front, struct node** middle){//split the list into two halves
  struct node* source=head;
  int length=len(head);
  int i=0;
  if(length<2){
    *front= source;
    *middle=NULL;
    return;
  }
  if(length%2!=0){length+=1;}
  for(i=0;i<(length/2)-1;i++){
    source=source->next;
  }
  *front=head;
  *middle=source->next;
  
  source->next=NULL;
  return;
}
void removeDuplicates(struct node * head){//remove all duplicates in a sorted list
  if(head==NULL || head->next== NULL){return;}
  struct node * current=head; 
  struct node* next= head->next;

  while(next!=NULL){
    if(current->data==next->data){
      next=next->next;
      free(current->next);
      current->next=next;
    }
    else{
      current=current->next;
      next=next->next;
    }
  }
}
void moveNode(struct node** destRef, struct node** sourceRef){//move the front node of list2 and push it to the list1
  struct node * temp= *sourceRef; 
  *sourceRef=temp->next;
  temp->next=*destRef;
  *destRef=temp;
}

struct node * swapPairs(struct node * head){
  if(head==NULL||head->next==NULL){return head;}
  struct node * left=head->next, * right=left->next;struct node * dummy=head;
  while(dummy!=NULL&&dummy->next!=NULL&&dummy->next->next!=NULL){
    left=dummy->next;
    right=left->next;
    cout<<left->data<<"\t"<<right->data<<"\n";
    dummy->next=right;
    left->next=right->next;
    right->next=left;
    dummy=left;
    printlist(head->next);
  }
  return head;
}
void it_reverse(struct node ** headRef){//iterative reverse of a linked list
  struct node* head=*headRef;
  struct node* rev=NULL;
  struct node* temp= NULL;
  while(head!=NULL){
    temp=head->next;
    head->next=rev;
    rev=head;
    head=temp;
   }
  *headRef=rev;
}
struct node* it_rev(struct node * head, int k){//reverse in k pairs
  struct node *current= head;
  struct node * next;
  struct node * rev=NULL;
  int i=0;
  struct node * checker=current;
    while(checker!=NULL&&i<k-1){
   checker=checker->next;
    i++;
   }
  if(checker==NULL){
    return current;
    }
  i=0;
  while(current!=NULL&&i<k){
    next=current->next;
    current->next=rev;
    rev=current;
    current=next;
    i++;
  }
  if(current!=NULL){
    head->next=it_rev(current,k);
  }
  return rev;
}
struct node* rotateRight(struct node* head, int k){
  if(!head||!(head->next)||k==0){return head;}
  int length=len(head);
  cout<<length;
  int i=1;
  struct node* fullprev;
  bool flag=false;
  struct node *slow=head,*full=head;
  while(i<length){
    if(i<(length-k)){
      slow=slow->next;
    }
    full=full->next;
    i++;
  }
  fullprev=slow->next;
  slow->next=NULL;
  full->next=head;
  
  return fullprev;
}
void altSplit(struct node* source, struct node ** aRef, struct node ** bRef){//alternating split, divide a list into two lists of alternating elements
  if(source==NULL){
    cout<<"empty source list";
    return;
  }
  bool flag=true; 
  while(source!=NULL){
  if(flag){
    moveNode(aRef,&source);
    flag=!flag;
   }
   else{
     flag=!flag;
     moveNode(bRef,&source);
    }
  }
}
struct node* shuffleMerge(struct node* a, struct node * b){//merge two lists taking one node alternately between lists
  struct node *result=NULL;
  bool flag=true;
  while(!(a==NULL && b==NULL)){
    if(flag){
      moveNode(&result,&a);
    }
    else{
      moveNode(&result,&b);
    }
    flag=!flag;
  }
  return result;
}
struct node *insertionSortList(struct node *head) {//insertion sort //TODO
        struct node* temp=head;
        struct node* comp=temp->next;
        while(temp!=NULL){
            while(comp!=NULL && comp->data>temp->data){
                comp=comp->next;
            }
            temp->data=temp->data^comp->data;
            comp->data=temp->data^comp->data;
            temp->data=temp->data^comp->data;
            temp=temp->next;
        }
        return head;
        
    }
struct node* sortedMerge(struct node * a, struct node * b){//merge sorted lists
  cout<<"SortedMergeFunction started\n";
  printlist(a);
  printlist(b);
  struct node * result=NULL;
  struct node ** ref=&result;
  while(1){
    if(a==NULL){
      cout<<"A null";
      *ref=b;
      break;
    }
    else if(b==NULL){
      cout<<"B null";
      *ref=a;
      break;
    }
    if(a->data<b->data){
      moveNode(ref,&a);
    }
    else{
      moveNode(ref,&b);
    }
    ref=&((*ref)->next);
  }
  cout<<"SortedMerge Ended\n";
  return result;
}
struct node * partition(struct node * head, int x){
  struct node * less=head,*temp;
       struct node *lessRef=less;
       if(head==NULL){
           return NULL;
       }
       while(head!=NULL){
           if(head->data<x){
               temp=head->next;
               less->next=head;
               head=temp;
               break;
           }
           head=head->next;
       }
       return lessRef;
}
void rec_rev(struct node ** headRef){//recursive linked list reversal
  if(*headRef==NULL){return;}
  struct node * first= *headRef; 
  struct node * rest= first->next;
  if(rest==NULL){return;}
  rec_rev(&rest);
  first->next->next=first;
  first->next=NULL;
  *headRef=rest;
  
}
void rev_end(struct node* headRef){//leetcode problem Reorder list
  if(headRef==NULL||headRef->next==NULL){
    return;
  }  
  struct node* head= headRef,*dummy=headRef;
  struct node*fast=head,*slow=head;
  struct node* temp,*temp1;
  while(fast!=NULL&&fast->next!=NULL){
    fast=fast->next->next;
    temp=slow;
    slow=slow->next;
  }
  rec_rev(&slow);
  temp->next=NULL;
  while(head!=NULL && slow!=NULL){
    temp=head->next;
    temp1=slow->next;
    head->next=slow;
    if(temp!=NULL){
      slow->next=temp;}
    slow=temp1;
    head=temp;
  }  
  headRef=dummy;
}
void mergeSort(struct node *head){//mergeSort
  struct node *aRef=NULL, *bRef=NULL;
  if(head==NULL||head->next==NULL){
    return;
  }
  else{
    fbsplit(head, &aRef, &bRef);
    mergeSort(aRef);
    mergeSort(bRef);
    head=sortedMerge(aRef,bRef);
  }
}
struct node* sortedIntersect(struct node * a, struct node * b){//find the intersection between two sorted lists
  struct node *head=NULL;
  if(a==NULL||b==NULL){
    return NULL;
  }
  int count=0;
  while(a!=NULL && b!=NULL){
    count++;
    if(a->data>b->data){
      a=a->next;
    }
    else if(a->data<b->data){
      b=b->next;
    }
    else if(a->data==b->data){
      push(&head,a->data);
      a=a->next;
      b=b->next;
    }
  }
  cout<<count<<"\n";
  return head;
}
void copy_list(struct node* head){
 
 while(head!=NULL){
   struct node* temp=(struct node*)malloc(sizeof(struct node));
   temp->data=(head)->data;
    temp->next=(head)->next;
    (head)->next=temp;
    head=head->next->next;
  }
}
struct node *removeNthFromEnd(struct node *head, int n) {
  // if(head==NULL)return head;
  struct node * fast=head, *slow=head;
  if(n==0){return head;}
  while(--n){
    fast=fast->next;
    cout<<"Fast-"<<fast->data<<"\n";
  }
  fast=fast->next;
  if(fast==NULL){return head->next;}
  while(fast->next!=NULL){
    cout<<"Fast-"<<fast->data<<"\t"<<"Slow-"<<slow->data<<"\n";
    fast=fast->next;
    slow=slow->next;
  }
  if(slow->next!=NULL)
  slow->next=slow->next->next;
  return head;
}
struct node * mypartition (struct node * head, int n){
  if(head==NULL) return head;
  struct node * low=NULL, * high =NULL;
  push(&low,0);push(&high,0);
  struct node * highend=high, * lowend=low,*temp;
  printlist(lowend);printlist(highend);
  while(head!=NULL){
    temp=head->next;
    if(head->data < n){
      low->next=head;
      low=low->next;
      low->next=NULL; //add to low
    }
    else{
      high->next=head;
      high=high->next;
      high->next=NULL;
     //add to high
    }
    head=temp;
   }
  //mix low and high
  low->next=highend->next;
  return lowend->next;
}
int main(){
  struct node* head=NULL;struct node * head2=NULL;
  int i;
  struct node *front=NULL,* middle=NULL;
  for(i=0;i<3;i++){
    push(&head,i);
  }
  printlist(head);
  head= it_rev(head,2);
  printlist(head);
}
