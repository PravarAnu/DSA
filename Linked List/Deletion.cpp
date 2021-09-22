#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

Node* head;

void Print();
void Delete(int n);


int main(){
    head = NULL;
    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();

    head = first;

    first->data = 30;
    first->next = second;

    second->data = 20;
    second->next = third;

    third->data = 50;
    third->next = fourth;

    fourth->data = 70;
    fourth->next = NULL;
    Print();

    Delete(1);
    Print();
    return 0;
}

void Print(){
    Node* temp = head;
    cout<<"List is: ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void Delete(int n){
    Node* temp = head;

    if(n==1){
        head = temp->next;
        delete temp;
        return;
    }
    for(int i=0;i<n-2;i++){
        temp = temp->next;
    }
    Node* temp2 = temp->next;
    temp->next = temp2->next;
    delete temp2;
}