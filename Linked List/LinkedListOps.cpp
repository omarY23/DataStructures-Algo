#include <iostream>
using namespace std;

class node
{
    int data;
    node* next;
    
public:
node(int val){
    data = val;
    next = NULL;
}

};


void insertAtTail(node* &head, int val){
    
   node* n = new node(val);
    if(head==NULL){
    head=n; // insertAtHead(head, val) <this is not working>
       return;
   }


    node* temp=head;
    while (temp->next!=NULL)
   {
    temp=temp->next;
    }
   temp->next=n;

   }

    void deleteAtHead(node* &head){

        node* todelete= head;
        head=head->next;

        delete todelete;
    }


    void deleteNode(node* &head, int key){      //delete function in linked list

        if(head== NULL){
            return;
        }

        if(head->next==NULL){
            deleteAtHead(head);
        }

        node* temp=head;
        while(temp->next->data!=key){
            temp=temp->next;
        }
        node* todelete= temp->next;
        temp->next=temp->next->next;

        delete todelete;

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

   void insertAtHead(node* &head, int val){
        node* n = new node(val);

        n->next = head;
        head = n;
    }
   
   
   int main(){
        node* head = NULL;
        int arr[] = {1, 2, 3, 4, 5};
        for(int i=0; i<5; i++){
        insertAtTail(head,arr[i]);
        }
       
        display(head);
        
        return 0;
   }