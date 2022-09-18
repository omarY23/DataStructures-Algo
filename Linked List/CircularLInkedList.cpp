#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;

node(int val){
    data = val;
    next = NULL;
}

};

void insertAtHead(node* &head, int val){

node* n=new node(val);
    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }

    node* temp=head;

    while (temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;    // This is the diff b/w insert at tail and at head

    return;
}

void insertAtTail(node* &head, int val){

    if(head==NULL){
       insertAtHead(head,val);
       return;
    }
    node* n= new node(val);


    node* temp=head;

    while (temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;

    return;
}

void deleteAtHead(node* &head){
node* temp=head;
while(temp->next!=head){
    temp=temp->next;
}
node* todelete= head;
head=head->next;
temp->next=head;

delete todelete;

}

void deletion(node* &head, int pos){
    if(pos==1){
        deleteAtHead(head);
        return;
    }

int count=1;
node* temp=head;

while (count!=pos-1)
{
    temp=temp->next;
    count++;
}

node* todelete= temp->next;
temp->next=temp->next->next;

delete todelete;

}


void display(node* head){

node* temp=head;

do{
    cout<<temp->data<<"->";
    temp=temp->next;
}while(temp!=head);

cout<<endl;
return;

}



int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    display(head);
    insertAtHead(head,6);

    display(head);
    deletion(head, 1);
    display(head);
return 0;

}