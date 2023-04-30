#include<iostream>
using namespace std;
#define MAX 100

class Stack{
    int top;
public:
    int arr[MAX];
    Stack(){
        top = -1;
    }
    void push(int x){
        if(top == MAX-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        arr[++top] = x;
        cout<<"Pushed "<<x<<" in stack"<<endl;
    }

    int pop(){
        if(top < 0){
            cout<<"Stack Undeflow"<<endl;
            return 0;
        }
        cout<<"Popped element: "<<arr[top];
        return arr[top--];
    }

    int peek(){
        if(top<0){
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        cout<<"Top element: "<<arr[top]<<endl;
        return 0;
    }

    bool isEmpty(){
        if(top == MAX-1){
            cout<<"Stack is full"<<endl;
            return false;
        }
        cout<<"Space is available"<<endl;
        return true;
    }
};

int main(){
    Stack s;
    s.push(10);
    s.peek();
    s.push(20);
    s.push(30);
    s.pop();

    return 0;
}