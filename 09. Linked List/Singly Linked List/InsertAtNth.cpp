#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

Node* head;

void InsertAtN(int data, int location);
void Print();

int main(){
    head = NULL;

    InsertAtN(30,1);
    Print();
    InsertAtN(40,2);
    Print();
    InsertAtN(50,3);
    Print();
    InsertAtN(20,3);
    Print();

}

void InsertAtN(int data, int location){
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;

    if (location == 1){
        temp1->next = head;
        head = temp1;
        return;
    }
    Node* temp2 = head;
    for(int i=0; i<location-2; i++){
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
    
}

void Print(){
    Node* temp = head;
    cout<<"List: ";
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}