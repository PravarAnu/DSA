#include<iostream>
using namespace std;

int main(){
    int a[] = {1,2,2};
    int sum;
    int n = sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=i;j<n;j++){
            sum+=a[j];
            cout<<sum<<endl;
        }
    }
    return 0;
}