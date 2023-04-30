#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> s;
    
    // push function for pushing element inside stack
    s.push(10);                 
    s.push(20);
    s.push(30);
    s.push(40);

    /*
        |    |
        ------
        | 40 |  <---- TOP
        ------
        | 30 |
        ------
        | 20 |
        ------
        | 10 |
        ------
    
    */

   // empty function is used to check whether the stack is empty or not.
    cout<<s.empty()<<endl;

    // top function returns the value which is on the top of stack.
    cout<<s.top()<<endl;

    // pop function removes the value which is on top of the stack.
    s.pop();

    
    cout<<s.top();
}