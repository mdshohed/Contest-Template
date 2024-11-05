//https://www.geeksforgeeks.org/two-dimensional-binary-indexed-tree-or-fenwick-tree/
#include <bits/stdc++.h>
using namespace std;

#define n 4
int tree[100][100];

void  update(int x, int y,int val) {
    while (x<=n) {
        int y1 = y;
        while ( y<=n ) {
            tree[x][y] += val;
            y1 += y1 & (-y1);
        }
        x += x & (-x);
    }
}

int query(int x, int y) {
    int sum = 0;
    while ( x>0) {
        int y1 = y;
        while ( y1>0) {
            sum += tree[x][y1];
            y1 -= y1 & (-y1);
        }
        x -= x & (-x);
    }
    return sum;
}

int query_all(int x1, int y1, int x2, int y2) {
    return query(x2, y2) - query(x2, y1-1) - query( x1-1, y2) + query(x1-1, y1-1);
}

int main() {

    while (1) {
        int x, x1, y1, x2, y2;
        cin >> x;
        if (x) {
            cin >> x1 >> y1 >> x2 >> y2;
            cout << query_all(x1, y1, x2, y2) << endl;
        }
        else {
            cin >> x1 >> y1;
            x1++, y1++;
            int val = 5;
            update(x1, y1, val);
        }
    }
}
