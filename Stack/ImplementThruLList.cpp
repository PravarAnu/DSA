#include<iostream>
#include<climits>
using namespace std;

class Stack{
public:
    int data;
    Stack* next;
};

Stack* top;

Stack* newnode(int x){
    Stack* temp = new Stack();
    temp->data = x;
    temp->next = NULL;
    return temp;
}

bool isEmpty(){
    return !top;
}

void push(int data){
    Stack* temp = newnode(data);
    
    temp->next = top;
    top = temp;
    cout<<data<<" pushed to stack"<<endl;
}

int pop(){
    if(isEmpty()){
        return INT_MIN;
    }
    Stack* temp = top;
    top = top->next;
    int popped = temp->data;
    
    delete temp;

    return popped;
}

int peek(){
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
        return 0;
    }
    return top->data;
}

void Print(){
    Stack* temp = top;
    while(temp!=NULL){
        cout<<"| "<<temp->data<<" |"<<endl;
        cout<<"------"<<endl;
        temp = temp->next;
    }
}



int main(){
    top = NULL;
    cout<<isEmpty()<<endl;
    push(10);
    Print();
    peek();
    push(20);
    Print();
    peek();
    push(30);
    Print();
    cout<<isEmpty()<<endl;
    cout<<pop()<<endl;
    Print();
    peek();
    cout<<pop();
    cout<<pop();
    Print();
}