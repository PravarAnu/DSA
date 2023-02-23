#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    
    Node(){

    }

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


Node *insert(Node *root, int newData){

    if(root == NULL){
        root = new Node();
        root->data = newData;
        root->left = NULL;
        root->right = NULL;
    }
    else if(newData <= root->data){
        root->left = insert(root->left, newData);
    }
    else{
        root->right = insert(root->right, newData);
    }

    return root;
}

Node *iterativeInsertion(Node *root, int newData){
/* 
    curr, prev
*/
    if(root == NULL){
        root = new Node(newData);
    }
    else{

        Node *temp = new Node();
        temp->data = newData;
        temp->left,temp->right = NULL;

        Node *curr = root;
        Node *prev = NULL;

        while(curr!=NULL){
            if(curr->data == newData){
                return root;
            }
            else if(curr->data > newData){
                prev = curr;
                curr = curr->left;
            }
            else{
                prev = curr;
                curr = curr->right;
            }
        }

        if(prev->data > newData){
            prev->left = temp;
        }
        else{
            prev->right = temp;
        }
    }
    
    return root;
}

int main() {

    Node *root = NULL;

    root = insert(root, 20);
    inorder(root);
    cout<<endl;

    root = insert(root, 12);
    inorder(root);
    cout<<endl;

    root = insert(root, 25);
    inorder(root);
    cout<<endl;

    root = insert(root, 10);
    inorder(root);
    cout<<endl;

    root = insert(root, 13);
    inorder(root);
    cout<<endl;

    root = insert(root, 22);
    inorder(root);
    cout<<endl;

    root = insert(root, 27);
    inorder(root);
    cout<<endl;

    root = insert(root, 8);
    inorder(root);
    cout<<endl;

    root = insert(root, 11);
    inorder(root);
    cout<<endl;

    root = insert(root, 15);
    inorder(root);
    cout<<endl;

    root = insert(root, 26);
    inorder(root);
    cout<<endl;

    root = insert(root, 28);
    inorder(root);
    cout<<endl;

    return 0;
}