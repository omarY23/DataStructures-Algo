#include<iostream>          //Using two stacks
#include<stack>
using namespace std;

class Queue{
    stack<int> s1;
    stack<int> s2;

    public:

    void push(int x){                                       //Enqueue
        s1.push(x);
    }

    int pop(){                                              //Dequeue
        if(s1.empty() && s2.empty()){
            cout<<"no elements to pop"<<endl;
            return -1;
        }
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        int topval= s2.top();
        s2.pop();
        
        return topval;        

    }

    bool empty(){
        if(s1.empty() && s2.empty()){
            return true;
        }
        else
        return false;
    }
};

int main(){

    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<q.pop()<<endl;
    return 0;



}