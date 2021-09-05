#include<iostream>
using namespace std;

int main(){
    int n;
    // cout<<"Size of square matrix: ";
    // cin>>n;

    int a[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    n = sizeof(a)/sizeof(a[0]);

    //For taking input from user
    // for(int i=0;i<n;i++){
    //     cout<<"Insert for row: "<<i<<endl;
    //     for(int j=0;j<n;j++){
    //         cin>>a[i][j];
    //     }
    // }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }


    //For printing array
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
}