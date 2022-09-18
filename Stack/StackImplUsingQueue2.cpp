#include<iostream>
#include<queue>
using namespace std;

class stack{
    queue<int> q1;
    queue<int> q2;
    int n=0;

    public:
    stack(){
        n=0;
    }

    void push(int x){
        q1.push(x);
    }

    int pop(){

        if(q1.empty()){
            return -1;
        }
        
        while (q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }

            int ans=q1.front();
            q2.push(ans);           //now we got our required ans.. now pe put that also in q2 so it becomes 
                                    //exactly like q1. Now we just need to exchange.
        
            queue<int> temp=q1;
            q1=q2;
            q2=temp;
            
        return ans;
    } 


};



int main(){

    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout<<st.pop()<<endl;

    return 0;



}