#include <iostream>
using namespace std;

int countSetBitsNaive(int n){
    int count = 0;
    while(n>0){
        if(n & 1){
            count++;
        }

        n = n>>1;
    }

    return count;
}


int countSetBitsByBrianKeriningam(int n){
    int count = 0;

    while(n>0){
        n = n&(n-1);

        count++;
    }

    return count;
}

int lookUp[256];

void setLookUp(){
    lookUp[0] = 0;

    for(int i=1; i<256; i++){
        lookUp[i] = (i&1) + lookUp[i/2];
    }
}


int countSetBitsUsingLookupTable(int n){
    setLookUp();

    int count = 0;
    for(int i=0; i<4; i++){
        count += lookUp[n & 0xff];
        n = n>>8;
    }

    return count;
}

int main() {

    int n = 7;

    cout<<countSetBitsNaive(n)<<endl;
    cout<<countSetBitsByBrianKeriningam(n)<<endl;
    cout<<countSetBitsUsingLookupTable(n)<<endl;


    return 0;
}