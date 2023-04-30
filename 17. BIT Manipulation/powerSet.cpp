#include <iostream>
#include <cmath>
using namespace std;

void powerSet(string str){

    for(int i=0; i<pow(2,str.size()); i++){
        int j = 0;
        string s = "";
        int n = i;
        while(n>0){
            if(n&1){
                s += str[j];
            }

            n = n>>1;
            j++;
        }
        if(s == ""){
            cout<<"blank"<<" ";
        }
        else{
            cout<<s<<" ";
        }
    }
}

int main() {

    powerSet("abcd");

    return 0;
}