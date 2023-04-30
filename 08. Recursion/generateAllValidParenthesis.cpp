#include <iostream>
using namespace std;

void generateAllValidParenthesis(int ob, int cb, string output) {
    if (ob == 0 && cb == 0) {
        cout << output << endl;
    }

    if (ob != 0) {
        string op1 = output;
        op1.push_back('(');
        generateAllValidParenthesis(ob - 1, cb, op1);
    }

    if (cb > ob) {
        string op2 = output;
        op2.push_back(')');
        generateAllValidParenthesis(ob, cb - 1, op2);
    }
}

int main() {

    int n = 3;

    string output = "";

    generateAllValidParenthesis(3, 3, output);

    return 0;
}