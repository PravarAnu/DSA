#include <iostream>

using namespace std;

int size(BstNode *root){
    if(root == NULL){
        return 0;
    }

    return 1 + size(root->left) + size(root->right);
}

int main() {
    
return 0;
}