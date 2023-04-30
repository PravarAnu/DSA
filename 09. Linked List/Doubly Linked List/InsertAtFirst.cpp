#include<iostream>
using namespace std;

class Node{
public:
    Node* prev;
    int data;
    Node* next;
};

Node* head;

void InsertAtFirst(int x);
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

    Print();
    cout<<endl;

    InsertAtFirst(40);
    Print();
    cout<<endl;
    RevPrint();
    cout<<endl;
    InsertAtFirst(50);
    InsertAtFirst(5);

    Print();
    cout<<endl;
    RevPrint();
}

void InsertAtFirst(int x){
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;

    if(head == NULL){
        head = temp;
        return;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;
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