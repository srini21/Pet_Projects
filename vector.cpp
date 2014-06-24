#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class vec{
public :
  vector<int> v;
  vector<int> push_items( int num){
    vector<int>v;
    if(num==1){
      v.push_back(9);
    return v;
    }
    for(int i=0;i<num;i++){
      v.push_back(i);
    }
    return v;
  }
  void print(vector<int> v){
    for(int i=0;i<v.size();i++){
      cout<<v[i]<<"\t";
    }
    if(v.size()==0){
      cout<<"Empty vector";
    }
  }
  void reverse(vector<int> v,vector<int> * begin, vector<int> * end){
    if(begin!=end){
      end--;
      if(begin!=end){
	while(true){
	  swap(*begin,*end);
	  begin++;
	  if(begin==end){
	    break;
	  }
	  end--;
	  if(begin==end){
	    break;
	  }
	}
      }
    }
    print(v);
  }
  void pascals(int num){
    vector<vector <int> > res;
    vector<int> r;
    r.push_back(1);
    res.push_back(r);
    r.push_back(1);
    res.push_back(r);
    for(int i=2;i<num;i++){
      vector<int> c(i+1,1);
      for(int j=1;j<i;j++){
	c[j]=res[i-1][j]+res[i-1][j-1];
      }
      res.push_back(c);
    }
    for(int i =0;i<res.size();i++){
      print(res[i]);
      cout<<"\n";
    }
 
  }
  
  void addOne(vector<int>&digits){
   vector<int>:: iterator it=digits.end();
        if(digits.size()==1){
            if(*(it-1)==9){
                digits.insert(digits.begin(),1);
		it=digits.end();
		cout<<++*(digits.begin()+1);
		return;
            }
             ++*(it-2);
        }
        else{
            if(*(it-1)==9){
                ++*(it-2);
            }
        }
        
        *(it-1)=(++*(it-1))%10;
        print(digits);
 }
};
  int main(){
    vec v;
    vector<int> ve;
    ve.push_back(1);
    ve.push_back(3);
    ve.push_back(1);
    vector<int> ve2;
    ve2.push_back(1);
    ve2.push_back(3);
    ve2.push_back(1);
    
    std::reverse(ve.begin(),ve.end());
    if(ve2==ve){
      cout<<"Yikes!";
    }
  }
