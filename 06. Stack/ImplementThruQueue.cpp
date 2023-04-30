#include <iostream>
#include <queue>

using namespace std;

template<class T>

class Stack{
    queue<T> q1;
    queue<T> q2;

    T curr_size;
public:
    Stack(){
        curr_size = 0;
    }

    // 1.By making the PUSH operation costly in STACK 
    void CostlyPush(T x){
        curr_size ++;

        q2.push(x);

        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();

        }

        queue<T> q = q1;
        q1 = q2;
        q2 = q;
    }

    void CheapPop(){
        if(q1.empty()){
            return;
        }
        q1.pop();
        curr_size--;
    }

    /*
    2.By making the POP operation costly in STACK
    void CheapPush(T x) {
        curr_size++;

        q2.push(x);
    }

    void CostlyPop() {
        if(q2.empty()){
            return;
        }
        while(q2.size()!=1){
            q1.push(q2.front());
            q2.pop();
        }

        q2.pop();
        curr_size--;

        queue<T> q = q1;
        q1 = q2;
        q2 = q;
    }
    */

    T top(){
        if(q1.empty()){
            return -1;
        }
        return q1.front();
    }

    T size(){
        return curr_size;
    }
};


int main(){
    Stack<int> a;
    a.CheapPop();
    a.CostlyPush(10);
    cout<<"PUSH : ";
    cout<<a.top()<<endl;
    a.CostlyPush(20);
    cout<<"PUSH : ";
    cout<<a.top()<<endl;
    a.CheapPop();
    cout<<"POP : ";
    cout<<a.top()<<endl;
    cout<<"SIZE : ";
    cout<<a.size()<<endl;

    cout<<endl;

    // Stack<int> b;
    // b.CostlyPop();
    // b.CheapPush(10);
    // cout<<"PUSH : ";
    // cout<<a.top()<<endl;
    // b.CheapPush(20);
    // cout<<"PUSH : ";
    // cout<<a.top()<<endl;
    // b.CostlyPop();
    // cout<<"POP : ";
    // cout<<a.top()<<endl;
    // cout<<"SIZE : ";
    // cout<<a.size();

    return 0;
}