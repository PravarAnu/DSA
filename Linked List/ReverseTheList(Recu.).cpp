#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

Node* head;
void Print(Node* n);
void RevList(Node*p);

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

    Print(head);
    RevList(head);
    Print(head);
}


void Print(Node* n){
    if(n==NULL){
        return;
    }
    cout<<n->data;
    Print(n->next);
}

void RevList(Node* p){
    if(p->next==NULL){
        head = p;
        return;
    }
    RevList(p->next);
    Node* q = p->next;
    q->next = p;
    p->next = NULL;
}