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
    if(a->data>=b->data){
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
void rec_rev(struct node ** headRef){//recursive linked list reversal
  if(*headRef==NULL||(*headRef)->next==NULL){
    return;
  }
  struct node *temp;
  struct node * rev=NULL;
  struct node * current=*headRef;
  while(current!=NULL){
    temp=current->next;
    current->next=rev;
    rev=current;
    current=temp;
  }
  *headRef=rev;
  printlist(*headRef);
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
void mergeSort(struct node ** headRef){//mergeSort
  struct node* head=*headRef;
  struct node *aRef=NULL, *bRef=NULL;
  if(head==NULL||head->next==NULL){
    return;
  }
  else{
    fbsplit(head, &aRef, &bRef);
    mergeSort(&aRef);
    mergeSort(&bRef);
    *headRef=sortedMerge(aRef,bRef);
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
int main(){
  struct node* head=NULL;struct node * head2=NULL;
  int i;
  struct node *front=NULL,* middle=NULL;
  for(i=10;i>0;i--){
    push(&head, i);
  
  }
  push(&head2, 11);
  push(&head, 11);
  push(&head2, 12);
  push(&head2,13);
  struct node * result=NULL;
  printlist(head2);
  
  rev_end(head2);
  printlist(head2);
 
}
