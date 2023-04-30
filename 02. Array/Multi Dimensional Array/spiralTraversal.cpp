#include <iostream>
#include <vector>
using namespace std;

void spiralTraversal(vector<vector<int>> matrix){
    int rowS = 0;
    int rowE = matrix.size()-1;

    int colS = 0;
    int colE = matrix[0].size()-1;


    while(rowS<=rowE && colS<=colE){

        for(int col = colS; col<=colE; col++){
            cout<<matrix[rowS][col]<<" ";
        }
        

        rowS++;

        for(int row=rowS; row<=rowE; row++){
            cout<< matrix[row][colE]<<" ";
        }
        

        colE--;


        if(rowS<=rowE){
            for(int col = colE; col>=colS; col--){
                cout<<matrix[rowE][col]<<" ";
            }
            

            rowE--;
        }

        if(colS <= colE){
            for(int row = rowE; row>=rowS; row--){
                cout<<matrix[row][colS]<<" ";
            }
            

            colS++;
        }

    }
}

int main() {

    vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};

    spiralTraversal(matrix);

    return 0;
}