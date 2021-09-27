#include<iostream>

using namespace std;

class Node{
public:
    int data;
    Node* next;
};

Node* head;

void Reverse();
void Print();

int main(){
    head = NULL;

    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();
    Node* fifth = new Node();

    head = first;

    first->data = 10;
    first->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = fifth;

    fifth->data = 50;
    fifth->next = NULL;

    Print();

    Reverse();

    Print();
}

void Reverse(){
    Node* current = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void Print(){
    Node* temp = head;
    cout<<"List is: ";
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}