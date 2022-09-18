//DOUBT

#include<iostream>          //Using only one stack
#include<stack>
using namespace std;

class Queue{
    stack<int> s;

    public:
    void push(int x){
        s.push(x);
    }

    int Pop(){
        if(s.empty){
            cout<<"no elements"<<endl;
            return -1;
        }
        int y=s.top();
        s.pop()
        if(s.empty()){
            return x;
        }

        int item=
        s.push(y);

    }
}

