#include<iostream>              //Some error in this code
#include<stack>
#include<math.h>
using namespace std;

int precedence(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }

    else if(c=='+' || c=='-'){
        return 1;
    }

    else{
        return -1;
    }

}

string infixToPostfix(string s){

    string res;
    stack<char> st;
    for(int i=0; i<s.length(); i++){

        if(s[i]>='a' && s[i]<='b' || s[i]>='A'&& s[i]<='Z'){             //beacuse the operands are variable
            res=res+s[i];
            }

        else if(s[i]=='('){
            st.push(s[i]);
        }

        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                res=res+st.top();
                st.pop();
            }
            if(!st.empty()){
            st.pop();   
            }             //beacuse at this position we will have the opening braces which we will just pop
        }

        else{
            while (!st.empty() && precedence(st.top())>precedence(s[i]))
            {
                res=res+st.top();
                st.pop();
            }
            st.push(s[i]);
            
        }

        
    }


        while (!st.empty())
        {
            res=res+st.top();
            st.pop();
        }

        return res;
}


int main(){

    cout<<infixToPostfix("(a-b/c)*(a/k-l)")<<endl;

    return 0;
}