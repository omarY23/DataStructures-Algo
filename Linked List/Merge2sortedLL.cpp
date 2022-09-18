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

void insertAtTail(node* &head, int val){
    node* n= new node(val);

    if(head==NULL){
        head=n;
        return;
    }

    node* temp=head;

    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;

    return;
}

int length(node* &head){
    if(head==NULL){
        return 0;
    }
    node* temp=head;
    int l=0;

    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}

node* merge(node* &head1, node* &head2){

node* p1=head1;
node* p2=head2;

node* dummy=new node(-1);

node* p3=dummy;
while (p1!=NULL && p2!=NULL)
{
    if(p1->data<p2->data){
        p3->next=p1;
        p1=p1->next;
    }
    else{
        p3->next=p2;
        p2=p2->next;
    }
    p3=p3->next;

}

while (p1!=NULL)
{
    p3->next=p1;
    p1=p1->next;
    p3=p3->next;
}


while (p2!=NULL)
{
    p3->next=p2;
    p2=p2->next;
    p3=p3->next;
}

return dummy->next;
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

int main(){

    node* head1= NULL;
    node* head2= NULL;

    insertAtTail(head1,1);
    insertAtTail(head1,4);
    insertAtTail(head1,6);
    insertAtTail(head1,7);

    insertAtTail(head2,2);
    insertAtTail(head2,3);
    insertAtTail(head2,5);

    display(head1);
    display(head2);
    // cout<<length(head1);

    node* a=merge(head1,head2);
    display(a);
    return 0;

}