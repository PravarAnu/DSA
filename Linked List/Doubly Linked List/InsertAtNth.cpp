#include<iostream>
using namespace std;

class Node{
public:
    Node* prev;
    int data;
    Node* next;
};

Node* head;

void InsertAtNth(int x,int location);
void RevPrint();
void Print();


int main(){
    head = NULL;

    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head = first;

    first->prev = NULL;
    first->data = 10;   
    first->next = second;

    second->prev = first;
    second->data = 20;  
    second->next = third;

    third->prev = second;
    third->data = 30;   
    third->next = NULL;

    Print();            //10 20 30
    cout<<endl;

    InsertAtNth(40,2);  
    Print();            //10 40 20 30
    cout<<endl;
    RevPrint();         //30 20 40 10
    cout<<endl;
    InsertAtNth(50,1);  
    InsertAtNth(5,3);   

    Print();            //50 10 5 40 20 30
    cout<<endl;
    RevPrint();         //30 20 40 5 10 50
}

void InsertAtNth(int x,int location){
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;

    if(location==1){
       head->prev = temp;
       temp->next = head;
       head = temp;
       return;
    }
    Node* temp2 = head;

    for(int i=0;i<location-2;i++){
        temp2 = temp2->next;
    }

    temp->next = temp2->next;
    temp->prev = temp2;
    temp2->next = temp;
    temp = temp->next;
    temp->prev = temp2->next;
}

void Print(){
    Node* temp = head;
    cout<<"List is: ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void RevPrint(){
    Node* temp = head;

    while(temp->next!=NULL){
        temp = temp->next;
    }

    cout<<"Reversed list is: ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
}