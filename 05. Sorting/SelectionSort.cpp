#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int> &v);
void printArr(vector<int> &v);

int main(){
    int n;
    vector<int> v;
    cout<<"Enter the number of elements: ";
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    selectionSort(v);
    printArr(v);
}

void selectionSort(vector<int> &v){
    for(int i=0; i<v.size(); i++){
        int min = i;
        for(int j=i+1; j<v.size(); j++){
            if(v[j]<v[min]){
                min = j;
            }
        }
        if(i!=min){
            int temp = v[min];
            v[min] = v[i];
            v[i] = temp;
        }   
    }
}

void printArr(vector<int> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}