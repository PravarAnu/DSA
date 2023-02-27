#include <iostream>
using namespace std;


void permutationWithLetterCase(string str, string output){
    if(str.length() == 0){
        cout<<output<<endl;
        return;
    }

    string op1 = output;
    op1.push_back(str[0]);

    if(isalpha(str[0])){
        string op2 = output;
        op2.push_back(str[0]^' ');

        str.erase(str.begin() + 0);

        permutationWithLetterCase(str, op1);
        permutationWithLetterCase(str, op2);
    }else{
        str.erase(str.begin() + 0);
        permutationWithLetterCase(str, op1);
    }
    
}

int main() {
    string str = "a1B2";
    string output = "";

    permutationWithLetterCase(str, output);

    return 0;
}