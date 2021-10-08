#include<iostream>
#include<stack>
using namespace std;

bool checkParenthesis(string s);

int main(){
    string s;
    s = "])";
    if(checkParenthesis(s)){
        cout<<"Balanced Parenthesis";
    }
    else{
        cout<<"Not balanced";
    }

    return 0;
}

bool checkParenthesis(string s){
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
            continue;
        }
        else if(st.empty()){
            return false;
        }
        else{
            switch(s[i]){
                case ')':
                    if(st.top() == '('){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                    break;
                case '}':
                    if(st.top() == '{'){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                    break;
                case ']':
                    if(st.top() == '['){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                    break;
            }
        }
    }

    return st.empty();
}