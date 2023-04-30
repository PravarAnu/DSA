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

/* FIRST APPROACH (ITERATIVE) */

int findKthNodeFromLast(int k){

    Node *slow = head;
    Node *fast = head;

    while(k--){
        fast = fast->next;
    }

    while(fast!=NULL){
        slow = slow->next;
        fast = fast->next;
    }

    return slow->data;
}

/* SECOND APPROACH (RECURSIVE) */

int findKthfromLast(Node *head, int k){
    if(head == NULL){
        return 0;
    }

    int count = findKthfromLast(head->next,k)+1;

    if(count == k){
        cout<<head->data;
    }
    return count;
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


    cout<<findKthNodeFromLast(3)<<endl;
    findKthfromLast(head, 3);

    return 0;
}