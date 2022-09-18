#include <iostream>
using namespace std;


class node{
    public:
    int data;
    node* prev;
    node* next;

    node(int val){

        data= val;
        next=prev=NULL;
    }


};

void insertAtTail(node* &head, int val){

    node* n= new node(val);
    if(head== NULL){
        head=n;
        return;
    }

    node* temp= head;

    while(temp->next!= NULL){
        temp= temp->next;
    }

    temp->next=n;
    n->prev=temp;

    return;

}

void display(node* head){

    node* temp= head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    
    cout<<"NULL"<<endl;

}

void deleteNode(node* &head, int pos){
    node* temp= head;
    int count=1;
    while (temp->next!=NULL && count!=pos)
    {
        temp=temp->next;
        count++;
    }
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }

    if(temp->prev!=NULL){
        temp->prev->next=temp->next;
    }

    delete temp;
}

int main(){

    return 0;
}