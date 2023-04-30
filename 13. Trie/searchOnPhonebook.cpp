#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
  public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char d) {
        this->data = d;
        this->isTerminal = false;

        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
  public:
    TrieNode *root;

    Trie() { root = new TrieNode('\0'); }

    void insert(string word) {
        TrieNode *temp = root;

        for (auto i : word) {
            int index = i - 'a';

            if (temp->children[index] != NULL) {
                temp = temp->children[index];
            } else {
                temp->children[index] = new TrieNode(i);
                temp = temp->children[index];
            }
        }

        temp->isTerminal = true;
    }

    void getAllNames(TrieNode *temp, string output, vector<string> &tempAns) {

        if (temp->isTerminal) {
            tempAns.push_back(output);
        }

        if(temp == NULL){
            return;
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            TrieNode *next = temp->children[ch - 'a'];

            if (next != NULL) {
                output.push_back(ch);

                getAllNames(next, output, tempAns);

                output.pop_back();
            }
        }
    }

    vector<vector<string>> searchAllNames(string word) {

        TrieNode *prev = root;
        vector<vector<string>> ans;

        string output = "";

        for (auto i : word) {
            char ch = i;
            int index = ch - 'a';

            output.push_back(ch);

            TrieNode *curr = prev->children[index];

            if (curr != NULL) {
                break;
            } else {
                vector<string> tempAns;
                getAllNames(curr, output, tempAns);

                ans.push_back(tempAns);
                prev = curr;
            }
        }
        return ans;
    }
};

vector<vector<string>> searchInContacts(vector<string> name,
                                        string searchName) {
    Trie *t = new Trie();

    for (int i = 0; i < name.size(); i++) {
        t->insert(name[i]);
    }

    return t->searchAllNames(searchName);
}

int main() {

    vector<string> name = {"p", "pr", "pra", "prav", "prava", "pravar"};

    string searchName = "pravar";

    vector<vector<string>> ans = searchInContacts(name, searchName);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
