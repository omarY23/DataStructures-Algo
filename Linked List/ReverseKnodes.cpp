/*Reverse K nodes at a time.
for ex k=2; 
1->2->3->4->5
2->1->4->3->6->5
*/

#include<iostream>
using namespace std;

class node{
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }

};

void insertAtTail(node* &head,int val){
node* n= new node(val);

if(head==NULL){
head=n;
return;
}

node* temp=head;

while(temp->next!=NULL){
    temp=temp->next;
}
temp->next=n;

}

node* reverseK(node* &head, int k){

    node* prevptr=NULL;
    node* currptr= head;
    node* nextptr;

     int count=0;
     while(currptr!=NULL && count<k){
    
        nextptr= currptr->next;
        currptr->next= prevptr;

        prevptr= currptr;
        currptr= nextptr;
        count++;

     }
head->next= reverseK()
}


int main(){

        node* head = NULL;
        int arr[] = {1, 2, 3, 4, 5};
        for(int i=0; i<5; i++){
        insertAtTail(head,arr[i]);
        }
       
        display(head);



}







