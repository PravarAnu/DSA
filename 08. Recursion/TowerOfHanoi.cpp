#include <iostream>
using namespace std;



void towerOfHanoi2(char s, char d, char e, int n, long long &count){
    if(n<=0){
        return;
    }

    towerOfHanoi2(s,e,d,n-1, count);
    
    // cout<<"Move Disk "<< n <<" from "<< s <<" to "<<d<<endl;
    count++;
    towerOfHanoi2(e,d,s,n-1, count);
}

// void towerOfHanoi1(char source, char destination, char helper, int plates){
//     if(plates == 1){
//         cout<<"Plate No. "<<plates<<" moved from "<<source<<" to "<<destination<<endl;
//         return;
//     }

//     towerOfHanoi1(source, helper, destination, plates-1);

//     cout<<"Plate No. "<<plates<<" moved from "<<source<<" to "<<destination<<endl;

//     towerOfHanoi1(helper, destination, source, plates-1);
// }

int main() {

    // towerOfHanoi1('s','d','h', 10);
    // cout<<endl;
    long long count = 0;
    towerOfHanoi2('s','d','h',32, count);
    cout<<endl;
    cout<<count<<endl;

    return 0;
}