#include <iostream>
#include <vector>
using namespace std;

void snakePattern(vector<vector<int>> matrix){
    int row = matrix.size();
    int col = matrix[0].size();
    
    for(int i=0; i<row; i++){
        if(i % 2 == 0){
            for(int j=0; j<col; j++){
                cout<< matrix[i][j]<<" ";
            }
        }else{
            for(int j = col-1; j>=0; j--){
                cout<<matrix[i][j]<<" ";
            }
        }
    }
}

int main() {

    vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    snakePattern(matrix);

    return 0;
}