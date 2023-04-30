#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
};
Node *head;

void Print(Node* n){
    if(n==NULL){
        return;
    }
    cout<<n->data<<" ";
    Print(n->next);
}

Node *reverseInKnodes(Node *head, int k){
    if(head == NULL){
        return NULL;
    }

    Node *curr = head;
    Node *next = NULL;
    Node *prev = NULL;
    int count = 0;
    while(curr!=NULL && count<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if(next!=NULL){
        Node *rem = reverseInKnodes(next, k);

        head->next = rem;
    }

    return prev;

}

int main() {

    head = NULL;

    Node *first = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;
    Node *fifth = new Node;
    Node *sixth = new Node;
    Node *seventh = new Node;

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
    fifth->next = sixth;

    sixth->data = 60;
    sixth->next = seventh;

    seventh->data = 70;
    seventh->next = NULL;

    Print(head);
    cout<<endl;
    Node *rev = reverseInKnodes(head, 3);
    Print(rev);

    return 0;
}