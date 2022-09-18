#include <iostream>                   //Making push operation costly
#include <queue>
using namespace std;

class stack{
    int n;                           //size of stack
    queue<int> q1;
    queue<int> q2;

public:
    stack(){
        n=0;
    }

    
    
    void push(int x){
        q2.push(x);
        n++;
        while (!q1.empty())
        {
            cout<<q1.front()<<endl;
            q2.push(q1.front());
            q1.pop();
        }
        cout<<endl;

        queue<int> temp=q1;
        q1=q2;
        q2=temp;
       
    }

    void pop(){
        q1.pop();
        n--;
    }

    int top(){
        return q1.front();
    }



};

int main(){
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout<<st.top()<<endl;
    st.pop();

    cout<<st.top()<<endl;
    return 0;
}


