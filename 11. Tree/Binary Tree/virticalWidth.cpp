#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void horizontalDistance(Node* root, int currHd, int &minHd, int &maxHd, map<int, vector<int>> &m){
    if(root == NULL){
        return;
    }

    m[currHd].push_back(root->data);

    minHd = min(minHd, currHd);
    maxHd = max(maxHd, currHd);
    horizontalDistance(root->left, currHd-1, minHd, maxHd, m);
    horizontalDistance(root->right, currHd+1, minHd, maxHd, m);
}


int virticalWidth(Node *root){
    int minHd = 0;
    int maxHd = 0;

    map<int, vector<int>> m;
    horizontalDistance(root,0,minHd, maxHd, m);


    for(auto i:m){
        // cout<<i.first<<"-> ";

        for(auto j: i.second){
            cout<<j<<" ";
        }
        cout<<endl;
    }


    return abs(minHd) + abs(maxHd) + 1;
}

int main() {

    Node *a = new Node(1);
    Node *b = new Node(2);
    Node *c = new Node(3);
    Node *d = new Node(4);
    Node *e = new Node(5);
    Node *f = new Node(6);
    Node *g = new Node(7);
    Node *h = new Node(8);
    Node *i = new Node(9);


    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->left = f;
    c->right = g;

    f->right = h;

    g->right = i;

    cout<<virticalWidth(a);

    return 0;
}