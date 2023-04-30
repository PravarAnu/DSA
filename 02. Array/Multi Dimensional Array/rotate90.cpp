#include <iostream>
#include <vector>
using namespace std;

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

void rotate90Naive(vector<vector<int>> matrix){
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> rotated(row, vector<int>(col));

    for(int i=0; i<row; i++){
        
        for(int j=0; j<col; j++){
            rotated[col-j-1][i] = matrix[i][j];
        }
    }

    print(rotated);
}

void transpose(vector<vector<int>> &matrix){
    int row = matrix.size();
    int col = matrix[0].size();


    for(int i=0; i<row; i++){
        for(int j=i+1; j<col; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void rotate90Efficient(vector<vector<int>> matrix){
    int row = matrix.size();
    int col = matrix[0].size();
    //vector<vector<int>> rotated(row, vector<int>(col));

    transpose(matrix);

    for(int i=0; i<row/2; i++){
        swap(matrix[i], matrix[row-i-1]);
    }

    print(matrix);
}

int main() {

    vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    rotate90Naive(matrix);
    cout<<endl;
    rotate90Efficient(matrix);
    

    return 0;
}