#include<iostream>
using namespace std;

int main(){
    int a[] = {2,3,4,5,1,2};
    int n = sizeof(a)/sizeof(a[0]);
    int max_count = 0;
    int curr_count = 2;
    int pd = a[0]-a[1];

    for(int i=1;i<n-1;i++){
        if(pd == (a[i]-a[i+1])){
            curr_count++;
            max_count = curr_count;
        }
        if(max_count<curr_count) max_count = curr_count;
        if(pd != (a[i]-a[i+1])){
            pd = a[i] - a[i+1];
            curr_count = 2;
        }
    }
    cout<<max_count;

    return 0;
}