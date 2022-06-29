#include <iostream>
#include <climits>
using namespace std;

struct BstNode{
    int data;
    BstNode *left;
    BstNode *right;
};

BstNode *newNode(int value){
    BstNode *temp = NULL;
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

/* Approach 1 : WORST APPROACH */
bool isSubtreeLesser(BstNode *root, int data);
bool isSubtreeGreater(BstNode *root, int data);

bool checkBst(BstNode *root){
    if(root == NULL){
        return true;
    }
    if(isSubtreeLesser(root->left, root->data)&&isSubtreeGreater(root->right, root->data)&&checkBst(root->left) 
    && checkBst(root->right)){
            return true;
        }
    return false;
}

bool isSubtreeLesser(BstNode *root, int data){
    if(root == NULL){
        return true;
    }

    if(root->data <= data && isSubtreeLesser(root->left, data) && isSubtreeLesser(root->right, data)) 
        return true;

    return false;
}

bool isSubtreeGreater(BstNode *root, int data){
    if(root == NULL){
        return true;
    }

    if(root->data <= data && isSubtreeGreater(root->left, data) && isSubtreeGreater(root->right, data)) 
        return true;

    return false;
}

/* End of Approach 1 */


/* Approach 2 : GOOD APPROACH*/
    bool isUtil(BstNode *root, int min, int max);
    
    bool checkBST(BstNode *root){
        return isUtil(root, INT_MIN, INT_MAX);
    }

    bool isUtil(BstNode *root, int min, int max){
        if(root == NULL){
            return true;
        }

        if(root->data > min && root->data < max 
        && isUtil(root->left, min, root->data) 
        && isUtil(root->right, root->data, max)){
            return true;
        }

        return false;
    }
/* End of Approach 2 */


/* Approach 3 : BEST APPROACH */



/* End of Approach 3 */

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

    cout<<checkBST(root);

    return 0;
}