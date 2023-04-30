#include<iostream>
#include<climits>
using namespace std;

int minWaitingTime(int t[], int n);

int main(){
    int t[]={2,4,15,16,18,18,19,19,20};
    int n = sizeof(t)/sizeof(t[0]);

    cout<<minWaitingTime(t,n);
    return 0;
}

int minWaitingTime(int t[], int n){
    int waitingTime = 0;
    int treated[9] = {0};
    
    for(int i=1;i<n;i++){
        int tmin = INT_MAX;
        int minIndex = 0;
        for(int j=1;j<n;j++){
            if(treated[j]==0 && t[j]<tmin){
                tmin = t[j];
                minIndex = j;
            }
        }
        waitingTime = waitingTime + (n-i)* tmin;
        treated[minIndex] = 1;
    }
    return waitingTime;
}