#include <iostream>
#include <vector>
using namespace std;

void transpose(vector<vector<int>> &matrix){
    int row = matrix.size();
    int col = matrix[0].size();


    for(int i=0; i<row; i++){
        for(int j=i+1; j<col; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void print(vector<vector<int>> matrix){
    int row = matrix.size();
    int col = matrix[0].size();



    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {

    vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    print(matrix);

    transpose(matrix);
    print(matrix);
    return 0;
}