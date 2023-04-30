#include <iostream>
#include <vector>
using namespace std;

void boundryTraversal(vector<vector<int>> matrix){
    int row = matrix.size();
    int col = matrix[0].size();

    for(int j=0; j<col; j++){
        cout<<matrix[0][j]<<" ";
    }

    for(int i=1; i<row; i++){
        cout<<matrix[i][col-1]<<" ";
    }

    for(int j = col-2; j>=0; j--){
        cout<<matrix[row-1][j]<<" ";
    }

    for(int i = row-2; i>0; i--){
        cout<<matrix[i][0]<<" ";
    }

}

int main() {

    vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    boundryTraversal(matrix);

    return 0;
}