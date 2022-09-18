#include<iostream>              
#include<stack>
#include<math.h>
using namespace std;


bool isBalanced(string s){

    int n=s.size();
    stack<char> st;

    bool validity= true;
    for(int i=0; i<n; i++){

        if(s[i]== '{' || s[i]== '[' || s[i]== '(')
        st.push(s[i]);

        else if(!st.empty() && s[i]=='}'){

            if(st.top()!='{')
            validity=false;
            else
            st.pop();
        }

        else if(!st.empty() && s[i]==']'){
            
            if(st.top()!='[')
            validity=false;

            else
            st.pop();
        }

        else if(!st.empty() && s[i]==')'){

            if(st.top()!='(')
            validity=false;

            else
            st.pop();
        }


    }
    if(!st.empty()){
        validity=false;
    }
    
    return validity;

}

int main(){
    string s= "{[()]}";

    if(isBalanced(s))
    cout<<"Balanced Paranthesis";

    else
    cout<<"Not Balanced Paranthesis";

return 0;
}