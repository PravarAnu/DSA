/*
            -------      --------       --------       --------       -------- 
        |-->|  5  |----->|  10  |------>|  15  |------>|  20  |------>|  25  |-----
        |   -------      --------       --------       --------       --------    |
        |                                                                         |
        |_________________________________________________________________________|

*/

#include <iostream>
using namespace std;


class CLLNode {
public:
    int data;
    CLLNode *next;

    CLLNode(int data){
        this->data = data;
        this->next = NULL;
    }
};

CLLNode *head,*tail;

void printCLL(){
    CLLNode *temp = head;
    
    do{
        cout<< temp->data<<" ";
        temp = temp->next;
    }
    while(temp != head);
}

void insertAtHead(int data){
    CLLNode *newNode = new CLLNode(data);
    //cout<<"NEW NODE POINTER : "<<newNode<<endl;
    newNode->next = head;
    tail->next = newNode;
    head = newNode;
}

void insertAtTail(int data){
    CLLNode *newNode = new CLLNode(data);
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
}

int main() {

    head = NULL;
    tail = NULL;

    CLLNode *first = new CLLNode(5);
    CLLNode *second = new CLLNode(10);
    CLLNode *third = new CLLNode(15);
    CLLNode *fourth = new CLLNode(20);
    CLLNode *fifth = new CLLNode(25);

    head = first;
    tail = fifth;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = first;

    printCLL();
    cout<<endl;
    cout<<"Head: "<<head<<" Tail: "<<tail<<endl;

    insertAtHead(1);
    printCLL();
    cout<<endl;
    cout<<"Head: "<<head<<" Tail: "<<tail<<endl;

    insertAtTail(30);
    printCLL();
    cout<<endl;
    cout<<"Head: "<<head<<" Tail: "<<tail<<endl;


    return 0;
}