#include<iostream>
using namespace std;

class Node{
public:
    Node* prev;
    int data;
    Node* next;
};

Node* head;
void Print();
void RevPrint();

int main(){
    head = NULL;

    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();
    Node* fifth = new Node();

    head = first;

    first->prev = NULL;
    first->data = 10;
    first->next = second;

    second->prev = first;
    second->data = 20;
    second->next = third;

    third->prev = second;
    third->data = 30;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 40;
    fourth->next = fifth;

    fifth->prev = fourth;
    fifth->data = 50;
    fifth->next = NULL;

    Print();
    cout<<endl;
    RevPrint();
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
    cout<<"Reverse List is: ";
    while(temp->next!=NULL){
        temp = temp->next;
    }
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
}