using namespace std;
#include<iostream>
#include<malloc.h>
 struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };
void printlist(RandomListNode * head);
RandomListNode*  copy_list(RandomListNode **head){
  RandomListNode * headCop=*head;
  while((*head)!=NULL){
	    RandomListNode* temp=(RandomListNode *)malloc(sizeof(RandomListNode));
            temp->label=(*head)->label;
            temp->next=(*head)->next;
	    (*head)->next=temp;
	    temp->random=(*head)->random;
            *head=(*head)->next->next;
        }
  return headCop;
    }
void printlist(RandomListNode * head){//printing the list
  if(head==NULL){cout<<"Empty List\n";}
  while(head!=NULL){
    cout<<head->label<<"*";
    /*  if(head->random==NULL){
      cout<<"#-";
    }
    else{
      cout<<head->random->label<<"-";
      }*/
    head=head->next;
  }
  cout<<"\n";
}

RandomListNode *copyRandomList(RandomListNode **head) {
  if(!head){
    return NULL;
  }
  map<RandomListNode*, RandomListNode*> mp;
  mp.clear();
  RandomListNode *res=new RandomListNode(0);
  RandomListNode *p=head;
  RandomListNode *q=res;
  while(p){
    RandomListNode* temp=new RandomListNode(p->label);
    q->next=temp;
    mp[p]=tmp;
    p=p->next;
    q=q->next;
  }
  p=head;
  q=res->next;
  while(p){
    if(p->random==NULL){q->random=NULL;}
    q->random=mp[p->random];
    p=p->next;
    q=q->next;
  }
  return res->next;
}
int main(){
  RandomListNode * head =new RandomListNode(-1);
  head->random=NULL;
  RandomListNode * next;//= new RandomListNode(5);
  // next->label=5;
  // next->random=head;
  //  head->next=next;
  printlist(head);
  next=copyRandomList(&head);
  printlist(next);
}
