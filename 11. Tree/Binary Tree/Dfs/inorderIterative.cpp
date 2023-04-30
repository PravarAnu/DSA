#include <iostream>
#include <stack>

using namespace std;

struct BtNode{
    char data;
    BtNode *left;
    BtNode *right;
};

void InorderIterative(BtNode *root){
    stack<BtNode *> s;

    BtNode *curr = root;

    while(curr!=NULL || !s.empty()){

        while(curr!=NULL){
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();

        cout<<curr->data<<" ";
        curr = curr->right;
    }
}


BtNode *newNode(char data){
    BtNode *temp = new BtNode;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


int main() {

    BtNode *root = NULL;

    BtNode *first = newNode('I');
    BtNode *second = newNode('O');
    BtNode *third = newNode('H');
    BtNode *fourth = newNode('L');
    BtNode *fifth = newNode('R');
    BtNode *sixth = newNode('T');
    BtNode *seventh = newNode('M');
    BtNode *eight = newNode('A');
    BtNode *ninth = newNode('G');
    BtNode *tenth = newNode('S');

    root = first;

    first->left = second;
    first->right = third;

    second->left = fourth;
    second->right = fifth;

    third->left = sixth;
    third->right = seventh;

    fourth->left = eight;
    fourth->right = ninth;

    seventh->right = tenth;

    InorderIterative(root);

    return 0;
}




