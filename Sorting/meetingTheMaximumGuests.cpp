#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int meetMaxGuest(vector<int> arrival, vector<int> departure){
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int maxMeet = 0;

    int a=0;
    int d=0;

    int count = 0;
    while(a<arrival.size() && d<departure.size()){
        if(arrival[a] < departure[d]){
            count ++;
            maxMeet = max(maxMeet, count);

            a++;
        }else if(arrival[a] > departure[d]){
            count --;
            d++;
        }else{
            a++;
            d++;
        }
    }

    return maxMeet;
}

int main() {

    vector<int> arrival = {900, 940, 950, 1100, 1500, 1800};
    vector<int> departure = {910, 1200, 1120, 1130, 1900, 2000};

    cout<<meetMaxGuest(arrival, departure);

    return 0;
}