#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data= val;
        next= NULL;
    }
};

void insertAtTail(node* &head, int val){
    node *n= new node(val);

    if(head==NULL){
        head=n;
        return;
    }

    node* temp= head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    
}

void display(node* head){
if(head== NULL){
    return;
    }
    node* temp= head;

    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }

    cout<<"NULL"<<endl;
    
}

node* appendK(node* &head, int k){
    
    node* newTail;
    node* newHead;
    node* temp= head;

    int pos=1;
    while(temp->next!=NULL){

        if(pos==k){
            newTail=temp;
            newHead= temp->next;
        }
        temp=temp->next;
        pos++;

    }
    newTail->next=NULL;
    temp->next=head;

    return newHead;
}


int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);

    display(head);
    
    node* a=appendK(head,3);

    display(a);

    return 0;

}