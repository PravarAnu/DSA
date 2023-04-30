#include <iostream>
#include <string>
using namespace std;

void permutationWithSpace(string s, string output) {
    if (s.length() == 0) {
        cout << output << endl;
        return;
    }

    if(output.length() == 0){
        output.push_back(s[0]);
        s.erase(s.begin() + 0);

        permutationWithSpace(s, output);
    }else{

        string op1 = output;
        string op2 = output;
        op1.push_back(' ');
        op1.push_back(s[0]);
        op2.push_back(s[0]);
        s.erase(s.begin() + 0);

        permutationWithSpace(s, op1);
        permutationWithSpace(s, op2);
    }

}

int main() {

    string s;
    cin>>s;

    string output = "";

    permutationWithSpace(s, output);

    return 0;
}