#include <iostream>     // In c++, if we call a function inside another func., then the called function
using namespace std;    // must be written above the calling function. For ex insertAtHead must be written above
                        // insertAtTail

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
    node* n= new node(val);

    if(head==NULL){
        head=n;
        return;
    }

    node* temp=head;
    head=n;
    n->next=temp->next;

    return;

}
void insertAtTail(node* &head, int val){
    if(head== NULL){
        insertAtHead(head, val);
        return;
    }
    node* n=new node(val);

    node* temp=head;

    while (temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=n;
    return;
    
}

void evenAfterodd(node* &head){
    node* odd=head;
    node* even=head->next;

    node* evenstart= even;

    while (odd->next!=NULL && even->next!=NULL)
    {
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    

    odd->next=evenstart;
    return;
    
}

    void display(node* head){
    node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
    }

    
   int main(){
        node* head = NULL;
        insertAtTail(head,1);
        insertAtTail(head,2);
        insertAtTail(head,3);
       insertAtTail(head,4);
        insertAtTail(head,5);
        insertAtTail(head,6);
              
        display(head);

        evenAfterodd(head);
        display(head);
        // insertAtHead(head,19);
        // display(head);
        
        return 0;
   }