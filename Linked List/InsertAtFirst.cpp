#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

Node *head;

void InsertAtFirst(int x);
void Print();

int main(){
    head = NULL;

    InsertAtFirst(30);
    Print();
    
    InsertAtFirst(10);
    Print();
    
    InsertAtFirst(40);
    Print();
    
    InsertAtFirst(60);
    Print();

    InsertAtFirst(20);
    Print();

    return 0;
}

void InsertAtFirst(int x){
    Node* temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
}

void Print(){
    Node* temp = head;
    cout<<"List is: ";
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}