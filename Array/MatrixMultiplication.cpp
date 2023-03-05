#include <iostream>
using namespace std;

int main() {
// int r1,r2,c1,c2;
#define r1 3
#define c1 4
#define r2 4
#define c2 3

    // cin>>r1>>c1>>r2>>c2;
    int a[r1][c1] = {{2, 4, 1, 2}, {8, 4, 3, 6}, {1, 7, 9, 5}};
    int b[r2][c2] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {4, 5, 6}};
    int c[r1][c2] = {0};
    if (c1 == r2) {

        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                for (int k = 0; k < c1; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}