#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

Node * newNode(int data){
    Node *temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void inorder(Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node *findMin(Node *root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

Node * Delete(Node *root, int data){
    if(root == NULL){
        return root;
    }
    else if(data < root->data){
        root->left = Delete(root->left, data);
    }
    else if(data > root->data){
        root->right = Delete(root->right, data);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        else if(root->left == NULL){
            Node * temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL){
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        else{
            Node * temp = findMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

int main() {

    Node *root = NULL;

    Node *first = newNode(20);
    Node *second = newNode(12);
    Node *third = newNode(25);
    Node *fourth = newNode(10);
    Node *fifth = newNode(13);
    Node *sixth = newNode(22);
    Node *seventh = newNode(27);
    Node *eighth = newNode(8);
    Node *ninth = newNode(11);
    Node *tenth = newNode(15);
    Node *eleventh = newNode(26);
    Node *twelveth = newNode(28);

    root = first;

    first->left = second;
    first->right = third;

    second->left = fourth;
    second->right = fifth;

    third->left = sixth;
    third->right = seventh;

    fourth->left = eighth;
    fourth->right = ninth;

    fifth->right = tenth;

    seventh->left = eleventh;
    seventh->right = twelveth;

    inorder(root);
    cout<<endl;

    root = Delete(root, 28);

    inorder(root);
    cout<<endl;

    return 0;
}