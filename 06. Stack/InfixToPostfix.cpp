#include <iostream>
#include <stack>
#include <string>

using namespace std;

string InfixToPostfix(string expression);
bool isOperand(char a);
bool isOperator(char a);
bool checkPrecedence(char a,char b);
int precedence(char a);

int main() {
    string a = "A+B*C-D*E";
    cout<<InfixToPostfix(a);

    return 0;
}

string InfixToPostfix(string expression) {
    stack<char> s;
    string postfix = "";

    for(int i=0; i<expression.size(); i++) {
        
        if(isOperand(expression[i])){
            postfix.push_back(expression[i]);
        }
        else if(isOperator(expression[i])){
            if(s.empty()){
                s.push(expression[i]);
            }
            else if(checkPrecedence(s.top(), expression[i])){
                postfix.push_back(s.top());
                s.pop();
                s.push(expression[i]);
            }
            else{
                s.push(expression[i]);
            }
        }
    }
    while(!s.empty()){
        postfix.push_back(s.top());
        s.pop();
    }
    return postfix;
}

bool checkPrecedence(char a,char b){
    int A = precedence(a);
    int B = precedence(b);

    if(A>=B){
        return true;
    }
    return false;
}

int precedence(char a){
    int weight = -1;
    switch(a){
        case '+':
        case '-':
            weight = 1;
            break;
        case '*':
        case '/':
            weight = 2;
            break;
        case '^':
            weight = 3;
    }
    return weight;
}

bool isOperand(char a) {
    if((a>='0' && a<='9') || (a>='A' && a<='Z') || (a>='a' && a<='z')){
        return true;
    }
    return false;
}

bool isOperator(char C){
	if(C == '+' || C == '-' || C == '*' || C == '/' || C== '$')
		return true;

	return false;
}