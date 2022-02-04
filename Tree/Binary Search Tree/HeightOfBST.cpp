#include <iostream>

using namespace std;

int height(BstNode *root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(height(root->left), height(root>right));
}

int main() {
    
return 0;
}