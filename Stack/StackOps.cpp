#include <iostream>
using namespace std;
#define n 100


class stack{
    int* arr;
    int top;

    public:
    stack(){
        arr= new int[n];
        top=-1;
    }

//Operations

void push(int x){       //To add an element in the stack

    if(top==n-1){
    cout<<"Stack overflow"<<endl;
    return;
    }

    top++;
    arr[top]=x;

}

void pop(){             //Just to remove the top element

    if(top==-1){
        cout<<"No elements in the stack"<<endl;
        return;
    }

    top--;          
}

int Top(){              //To return the topmost element in the stack

    if(top==-1){
     cout<<"No elements in the stack"<<endl;
        return -1;
    }

    return arr[top];

}

bool empty(){            //To check if stack is empty
    return top==-1;
}

};

int main(){

    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout<<st.empty()<<endl;
    cout<<st.Top()<<endl;

    st.pop();
    cout<<st.Top()<<endl;

    return 0;
}