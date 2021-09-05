#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

void printList(Node* n){
    while(n != NULL){
        cout<< n->data <<" ";
        n = n->next;
    }
}


// Given a reference (pointer to pointer) to the head of a list and an int, inserts a new node on the front of the list.

void insertAtFirst(Node** head_ref, int new_data){
    Node* new_node = new Node();        // Allocate new node
    new_node->data = new_data;          // Put in the data
    new_node->next = *head_ref;         // Make next of new node as head
    (*head_ref) = new_node;             // Move the head to point to the new node
}


// Given a node prev_node, insert a new node after the given prev_node

void insertAtMiddle(Node* prev_node, int new_data){
    // Check if the given prev_node is NULL
    if(prev_node == NULL){
        cout<<"The given previous node can't be null";
        return ;
    }

    Node* new_node = new Node();        // Allocate new node
    new_node->data = new_data;          // Put in the data
    new_node->next = prev_node->next;   // Make next of new node as next of previos node
    prev_node->next = new_node;         // move the next of prev_node as new_node
}


void  insertAtLast(Node** head_ref, int new_data){
    Node* new_node = new Node();        //Allocate new node
    Node* last = *head_ref;             //Storing 
    new_node->data = new_data;
    new_node->next = NULL;

    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }

    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
    return;
}

int main(){
    Node* head = NULL;

    insertAtLast(&head, 6);
    insertAtFirst(&head, 7);
    insertAtFirst(&head, 1);
    insertAtLast(&head, 4);
    insertAtMiddle(head->next, 8);

    printList(head);

    return 0;
}