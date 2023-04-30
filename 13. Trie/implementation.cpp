#include <iostream>
using namespace std;

class TrieNode {
  public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char d) {
        this->data = d;
        isTerminal = false;

        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
  public:
    TrieNode *root;

    Trie() { root = new TrieNode('\0'); }

    int countChild(TrieNode *root){
        int count = 0;

        for(int i=0; i<26; i++){
            if(root->children[i] != NULL){
                count++;
            }
        }

        return count;
    }

    void insertHelper(TrieNode *root, string word) {
        // base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // fetch current character
        char ch = word[0];

        // fetch index
        int index = ch - 'a';

        // create a child node

        TrieNode *child;

        // There are 2 cases
        // 1 If child is already present
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        // 2 If child is not present
        else {
            child = new TrieNode(ch);
            root->children[index] = child;
        }

        insertHelper(child, word.substr(1));
    }

    void searchHelper(TrieNode *root, string word) {
        //base case
        if (word.length() == 0) {
            if (root->isTerminal == true) {
                cout << "Found" << endl;
            } else {
                cout << "Not Found" << endl;
            }

            return;
        }

        char ch = word[0];
        int index = ch - 'a';
        TrieNode *child;

        if (root->children[index] == NULL) {
            cout << "Not Found" << endl;
            return;
        } else {
            child = root->children[index];
        }

        searchHelper(child, word.substr(1));
    }

    TrieNode *deleteHelper(TrieNode *root, string word){
        
        //base case
        if(word.length() == 0){
            //mark the terminal as false
            root->isTerminal = false;

            //check if there is any child of current node(i.e root)

            //if yes then delete the root and points it to null
            if(!countChild(root)){
                delete root;
                root = NULL;
            }

            return root;
        }


        char ch = word[0];
        int index = ch-'a';

        //recursively call the delete fun for the next node and also store the value returned in the current node
        root->children[index] = deleteHelper(root->children[index], word.substr(1));
        

        //now check if there is any child exists for root and terminal for that node is marked as false 

        //if yes then delete the node and points it to null;
        if(!countChild(root) && root->isTerminal==false){
            delete root;
            root = NULL;
        }
        
        return root;
    }

    void insert(string word) {
        insertHelper(root, word);
        cout << "Inserted Successfully" << endl;
    }
    void search(string word) { searchHelper(root, word); }

    void deleteWord(string word){
      root = deleteHelper(root, word);
    }
};

int main() {

    Trie *t = new Trie();

    t->insert("code");
    t->insert("coder");
    t->search("codemonk");

    t->insert("codemonk");
    t->search("codemonk");
    t->insert("codee");

    t->deleteWord("code");

    t->search("code");
    t->search("codem");


    return 0;
}