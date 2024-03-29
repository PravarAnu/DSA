#include <iostream>
#include <queue>

using namespace std;

struct BtNode
{
    char data;
    BtNode *left;
    BtNode *right;
};

BtNode *newNode(char data)
{
    BtNode *temp = new BtNode;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void levelOrder(BtNode *root);

int main()
{

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

    levelOrder(root);

    return 0;
}

void levelOrder(BtNode *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BtNode *> q;

    q.push(root);

    while (!q.empty())
    {
        BtNode *temp = q.front();

        if (temp->left != NULL)
        {
            q.push(temp->left);
        }

        if (temp->right != NULL)
        {
            q.push(temp->right);
        }

        cout << temp->data << " ";
        q.pop();
    }
}

// Levelorder traversal and storing the values by levelorder way.

vector<vector<int>> levelOrder(TreeNode *root){
    vector<vector<int>> output;

    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);

    vector<int> v;
    while (!q.empty())
    {
        TreeNode *front = q.front();
        q.pop();

        if (front != NULL)
        {
            v.push_back(front->val);
            if (front->left != NULL)
            {
                q.push(front->left);
            }

            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
        else
        {
            if (!q.empty())
            {
                q.push(NULL);
            }
            output.push_back(v);
            v.clear();
        }
    }

    return output;
}