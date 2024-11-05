#include <iostream>
using namespace std;

int main() {

    int ara[6][4] = {{1001, 06, 11, 1999},
                     {1002, 21, 9, 2000},
                     {1003, 17, 01, 2001},
                     {1004, 3, 5, 1999},
                     {1005, 21, 9, 2000},
                     {1006, 12, 01, 2001}};

    // bubble sort...
    for (int i = 0; i<6; i++) {
        for (int j = 0; j<6-i-1; j++) {
            if ( ara[j][3] > ara[j+1][3] ) {

                for (int k =0; k<4; k++) {
                    swap(ara[j][k],ara[j+1][k]);
                }
            }
            if ( ara[j][3] == ara[j+1][3] ) {
                if ( ara[j][2] > ara[j+1][2]) {

                    for (int k =0; k<4; k++) {
                        swap(ara[j][k],ara[j+1][k]);
                    }
                }
            }
            if ( ara[j][2] == ara[j+1][2] ) {
                if ( ara[j][1] > ara[j+1][1]) {

                    for (int k =0; k<4; k++) {
                        swap(ara[j][k],ara[j+1][k]);
                    }
                }
            }
        }
    }

    cout << "Sorted table: " << endl;
    for (int i = 0; i<6; i++) {
        for (int j = 0; j<4; j++) {
            cout << ara[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
