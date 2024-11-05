/*
algorithm: dot product & cross product
input:
// two vector array
output:
dot product:
-4
cross product:
-49 -7 28
*/
#include <bits/stdc++.h>
using namespace std;

//function to find dot product form two vector array
int dot_product(int a[], int b[]) {
    int product = 0;
    for (int i = 0; i<3; i++) {
        product += a[i]*b[i];
    }
    return product;
}
//function to find cross product form two vector array
int cross_product(int a[], int b[]) {
    int product[3];
    product[0] =  a[1]*b[2] - a[2]*b[1];
    product[1] =  a[2]*b[0] - a[0]*b[2];
    product[2] =  a[0]*b[1] - a[1]*b[0];
    for (int i = 0; i<3; i++) {
        cout << product[i] << " ";
    }
    cout << endl;
}

int main() {

    int a[3] = { 3, -5, 4 };
    int b[3] = { 2, 6, 5 };

    cout << "dot product: " << endl;
    cout << dot_product(a,b) << endl;

    cout << "cross product: " << endl;
    cross_product(a, b);
    return 0;
}
