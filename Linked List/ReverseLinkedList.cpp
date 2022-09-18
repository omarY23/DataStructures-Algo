#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtHead(node* &head, int val){

    node* n= new node(val);
    n->next = head;
    head=n;
    
}

void insertAtTail(node* &head, int val){
    node* n= new node(val);

 if(head==NULL){
    head=n; // insertAtHead(head, val) <this is not working>
       return;
   }

node* temp=head;
while (temp->next!=NULL)
{
    temp=temp->next;
}

temp->next= n;
}

void display(node* head){
    // if(head== NULL){
    //     return;
    // }
    node* temp=head;
    
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
    }


    void reverseList(node* &head){
        node* previous;
        node* curr; 
        node* upcoming;

        previous= NULL;
        curr=head;
        
        while (curr!=NULL)
        {
            upcoming=curr->next;
            curr->next=previous;
            
            //now incrementing all the pointers

            previous=curr;
            curr=upcoming;
                                                     //previous= previous->next;        This line of code is not doing anything
        }
        head=previous;
        
    }




   int main(){
        node* head = NULL;
        int arr[] = {1, 2, 3, 4, 5};
        for(int i=0; i<5; i++){
        insertAtTail(head,arr[i]);
        }

        display(head);
        reverseList(head);
        display(head);
return 0;
   }