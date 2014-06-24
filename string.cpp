#include<stack>
#include<algorithm>
#include<iostream>
using namespace std;

                if(st.top()=='('){
                    st.pop();
                    length+=2;
                }
                else{
                    continue;
                }
            }
        }
        return length;
    }
int main(){
  
  cout<<longestValidParentheses(")");
}
