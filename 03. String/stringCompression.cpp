#include <iostream>
using namespace std;

void compressedString(string s, int n){

    int count = 1;
    string ans="";

    for(int i=1; i<s.size(); i++){
        if(s[i] == s[i-1]){
            count++;
        }else{
            if(count >= n){
                cout<<s[i-1]<<count;
            }

            count = 1;
        }
    }

    if(s[s.size()-1] == s[s.size()-2]){
        cout<<s[s.size()-1]<<count;
    }else{
        cout<<s[s.size()-1]<<1;
    }

}

int main() {

    string s = "aaaabbbccb";
    // cin>>s;
    int n = 1;
    // cin>>n;

    compressedString(s, n);

    return 0;
}