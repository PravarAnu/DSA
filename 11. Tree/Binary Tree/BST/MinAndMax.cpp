#include <iostream>

using namespace std;


struct BstNode{
    int data;
    BstNode *left;
    BstNode *right;
};

BstNode *newNode(int data){
    BstNode *temp = new BstNode;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

int min(BstNode *root){
    if(root == NULL){
        return -1;
    }

    if(root->left == NULL){
        return root->data;
    }
    return min(root->left);
}

int max(BstNode *root){
    if(root == NULL){
        return -1;
    }

    if(root->right == NULL){
        return root->data;
    }
    return max(root->right);
}


int main() {

    BstNode *root = NULL;

    BstNode *first = newNode(20);
    BstNode *second = newNode(15);
    BstNode *third = newNode(22);
    BstNode *fourth = newNode(12);
    BstNode *fifth = newNode(18);
    BstNode *sixth = newNode(21);
    BstNode *seventh = newNode(25);
    BstNode *eight = newNode(10);
    BstNode *ninth = newNode(13);
    BstNode *tenth = newNode(30);

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

    cout<<min(root);
    cout<<endl;
    cout<<max(root);


return 0;
}