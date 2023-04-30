#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
  public:
    TrieNode *children[2];

    TrieNode() {
        children[0] = NULL;
        children[1] = NULL;
    }
};

class Trie {
  public:
    TrieNode *root;

    Trie() { root = new TrieNode(); }

    bool insert( vector<bool> &row) {
        TrieNode *temp = this->root;

        bool flag = false;

        for (int i = 0; i < row.size(); i++) {
            int val = row[i];

            if (temp->children[val] != NULL) {
                temp = temp->children[val];
            } else {
                temp->children[val] = new TrieNode();
                temp = temp->children[val];
                flag = true;
            }
        }

        return flag;
    }
};


int distinctRows(vector<vector<bool>> &matrix) {
    Trie *t = new Trie();

    int count = 0;
    for (int i = 0; i < matrix.size(); i++) {
        if (t->insert(matrix[i])) {
            count++;
        }
    }

    return count;
}

int main() {

    vector<vector<bool>> matrix = {{1, 0, 0}, {0, 1, 0}, {1, 0, 0}, {1, 1, 1}};

    cout << distinctRows(matrix);

    return 0;
}