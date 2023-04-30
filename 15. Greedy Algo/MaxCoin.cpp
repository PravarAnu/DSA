#include<iostream>
using namespace std;

int main(){
    int m;
    m = 2;
    int count=0;

    while(m!=0){
        if(m>=10){
            m = m-10;
            count++;
        }
        else if(m>=5){
            m = m-5;
            count++;
        }
        else if(m>=1){
            m = m-1;
            count++;
        }
    }
    cout<<count;
    return 0;
}