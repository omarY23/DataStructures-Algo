#include <iostream>
#include <math.h>
#include <stack>
using namespace std;


int prefixEvaluation(string s){

    stack<int> st;
    for(int i=s.length()-1; i>=0; i--){

        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');                      //By doing this we store as integer in the stack
        }

        else{
            int operand1=st.top();
            st.pop();
            int operand2=st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
            st.push(operand1+operand2);
                break;
            
            case '-':
            st.push(operand1-operand2);
                break;

            case '*':
            st.push(operand1*operand2);
                break;

            case '/':
            st.push(operand1/operand2);
                break;

            default:
                break;
            }
        }
    }

    return st.top();
}


int main(){
    cout<<prefixEvaluation("-+7*45+20");
    return 0;
}