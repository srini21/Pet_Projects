#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int size;
class arrays{
  
  int A[100];
 public:
  int size;
  int * push_random(int size){
    int j=0,it=size;
    while(it--){
      A[j++]=rand()%size;
    }
    print(A,size);
    return A;
  }
  void print(int * A,int size){
    int j=0;
    while(j<size){
      cout<<A[j++]<<"\t";
    }
    cout<<"\n";
  }
  void insertion_sort(int * A,int size){
    if(size<1){
      cout<<"Empty array";
    }
    int i=0,j=0,key;
    for(i=1;i<size;i++){
      j=i-1;key=A[i];
      while(j>=0&&A[j]>key){
	A[j+1]=A[j--];
      }
      A[j+1]=key;
    }
    print(A,size);
  }
  int binary_search(int * A, int size, int target){
    int low=0,mid,high=size-1;
    while(low<=high){
      mid=(high+low)/2;
      if(A[mid]==target){
	return mid;
      }
      else if(A[mid]>target){
	high=mid-1;
      }
      else{
	low=mid+1;
      }
     }
    return -1;
 
  }
};
int main(){
  arrays a;
  int * A;int size,num; 
  cout<<"enter size\n";
  cin>> size;
  a.size=size;
  A=a.push_random(size);
  a.insertion_sort(A,size);
  cout<<"search for?:\n";
  cin>>num;
  cout<<a.binary_search(A,size,num);
}
