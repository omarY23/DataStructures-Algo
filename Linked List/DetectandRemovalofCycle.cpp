#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next= NULL;
    }
};

void insertAtTail(node* &head, int val){

node* n= new node(val);

if(head== NULL){
    head=n;
    return;
}

node* temp=head;

while(temp->next!=NULL){
    temp=temp->next;
}
temp->next=n;

}

void makeCycle(node* &head, int pos){

    node* temp=head;
    node* startnode;

    int count=1;
    while(temp->next!=NULL){
        
        if(pos==count){
            startnode=temp;
        }
        temp=temp->next;
        count++;

    }
    temp->next=startnode;

}

bool detectCycle(node* &head){          //hare and tortoise algorithm

node* slow=head;
node* fast=head;

while(fast!=NULL && fast->next!=NULL){


fast=fast->next->next;
slow=slow->next;

if(fast==slow){
    return true;
}

}
return false;
}

void removeCycle(node* &head){

node* slow=head;
node* fast=head;

do{
    slow=slow->next;
    fast=fast->next->next;

}while(slow!=fast);

fast=head;
while(fast->next !=slow->next){
    fast=fast->next;
    slow=slow->next;
}
slow->next=NULL;

return;
}

void display(node* head){
    node* temp = head;

    if(head==NULL)
    return;

    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
    
}


int main(){
    node* head= NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    
    makeCycle(head,3);
    removeCycle(head);
    cout<<detectCycle(head)<<endl;
        display(head);

}