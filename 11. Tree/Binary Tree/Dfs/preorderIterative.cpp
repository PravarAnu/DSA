#include <iostream>
#include <stack>

using namespace std;

void PreorderIterative(BtNode *root){
    stack<BtNode *> s;

    s.push(root);

    while(!s.empty()){
        BtNode *curr = s.top();
        s.pop();

        if(curr->right!=NULL){
            s.push(curr->right);
        }

        if(curr->left!=NULL){
            s.push(curr->left);
        }

        cout<<curr->data<<" ";
    }
}

void PreorderIterativeOptimized(BtNode *root){
    stack<BtNode *> s;

    s.push(root);
    BtNode *curr = root;

    while(!s.empty()){
        while(curr!=NULL){
            cout<<curr->data<<" ";

            if(curr->right!=NULL){
                s.push(curr->right);
            }

            curr = curr->left;
        }
        curr = s.top();
        s.pop();
    }
}

struct BtNode{
    char data;
    BtNode *left;
    BtNode *right;
};

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

    PreorderIterative(root);
    cout<<endl;
    PreorderIterativeOptimized(root);

    return 0;
}




