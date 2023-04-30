#include <bits/stdc++.h>
using namespace std;

string subArrayWithGivenSumNaive(vector<int> &arr, int sum){
    for (int i = 0; i < arr.size(); i++){
        int currSum = 0;
        for (int j = i; j < arr.size(); j++){
            currSum += arr[j];

            if (currSum == sum){
                //cout<<"Found Between Index "<<i<<" to "<<j<<endl;
                return "Found";
            }
        }
    }

    return "Not Found";
}

string subArrayWithGivenSumFast(vector<int> &arr, int sum){
    unordered_set<int> u;
    int total = 0;
    for (auto i : arr){
        
        total += i;
        if(total == sum){
            return "Found";
        }
        if (u.find(total - sum) != u.end()){
            return "Found";
        }

        u.insert(total);
    }

    return "Not Found";
}


// For Testing Purpose

void testTheMethods(){
    srand(time(0));

    for (int t = 0; t < 1000; t++){
        cout<<t+1<<". ";
        int sizeOfArray = rand() % 100;

        vector<int> v(sizeOfArray);

        for (int i = 0; i < sizeOfArray; i++){
            v[i] = rand() % 100 - 30;
        }

        int givenSum = rand() % 80 - 20;

        // cout<<"Array is: ";
        // for(auto i:v){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        
        // cout<<"Required Sum: "<<givenSum<<endl;

        string naive = subArrayWithGivenSumNaive(v, givenSum);
        string fast = subArrayWithGivenSumFast(v, givenSum);

        // cout<<naive<<" "<<fast<<endl;

        if(naive == fast){
            cout<<"Matched"<<endl;
        }
        else{
            cout<<"Not Matched"<<endl;
        }
        //cout<<endl;
    }

}

int main(){

    int sizeOfArray,givenSum;
    cin>>sizeOfArray>>givenSum;

    vector<int> v(sizeOfArray);

    for(int i=0; i<sizeOfArray; i++){
        cin>>v[i];
    }

    cout<<subArrayWithGivenSumFast(v, givenSum);


    /* For Testing Purpose
        testTheMethods(); 
    */


    return 0;
}