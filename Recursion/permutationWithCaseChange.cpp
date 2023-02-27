#include <iostream>
using namespace std;


void permutationWithCaseChange(string s, string output){
    if(s.length() == 0){
        cout<<output<<endl;
        return;
    }

    string op1 = output;
    string op2 = output;

    op1.push_back(s[0]);
    op2.push_back(toupper(s[0]));

    s.erase(s.begin()+0);
    permutationWithCaseChange(s, op1);
    permutationWithCaseChange(s, op2);
    
}

int main() {

    string s = "ab";
    // cin>>s;

    string output = "";

    permutationWithCaseChange(s, output);

    return 0;
}