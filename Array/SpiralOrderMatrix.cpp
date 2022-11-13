#include<iostream>
using namespace std;

int main(){
    int a[4][3]={
        {  1,  2,  3},
        { 10, 11,  4},
        {  9, 12,  5},
        {  8,  7,  6}
    };
    int n = sizeof(a)/sizeof(a[0]);
    int m = sizeof(a)/sizeof(a[0][0]) / n;

    int RowS=0;
    int RowE=n-1;
    int ColS=0;
    int ColE=m-1;

    while(RowS<=RowE && ColS<=ColE){
        for(int col=ColS; col<=ColE; col++){
            cout<<a[RowS][col]<<" ";
        }
        RowS++;
        
        for(int row=RowS; row<=RowE; row++){
            cout<<a[row][ColE]<<" ";
        }
        ColE--;

        for(int col=ColE; col>=ColS; col--){
            cout<<a[RowE][col]<<" ";
        }
        RowE--;

        for(int row=RowE; row>=RowS; row--){
            cout<<a[row][ColS]<<" ";
        }
        ColS++;
    }
}