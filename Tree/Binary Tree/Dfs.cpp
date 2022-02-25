#include <iostream>

using namespace std;

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

void Inorder(BtNode *root);
void Preorder(BtNode *root);
void Postorder(BtNode *root);

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

    Inorder(root);
    cout<<endl;
    Preorder(root);
    cout<<endl;
    Postorder(root);

    return 0;
}




void Inorder(BtNode *root){
    if(root == NULL){
        return;
    }

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}


void Preorder(BtNode *root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}


void Postorder(BtNode *root){
    if(root == NULL){
        return;
    }

    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}