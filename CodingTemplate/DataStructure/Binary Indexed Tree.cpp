/**
  Algorithm: binary index tree 
  Resource: http://www.shafaetsplanet.com/?p=1961 & https://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
  Time complexity: O(log MaxIdx)
  problem: 
  http://lightoj.com/volume_showproblem.php?problem=1080
  https://www.spoj.com/problems/NICEDAY/
  http://lightoj.com/volume_showproblem.php?problem=1112
*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+7;
int ara[mx];
int tree[mx];

int query(int n) {
    int sum = 0;
    while (  n>0) {
        sum += tree[n];
        n -= n & (-n);
    }
    return sum;
}

void update(int i, int x, int n) {
    while (i<=n) {
        tree[i] += x;
        i += i&(-i);
    }
}

int main() {

    int n;
    cin >> n;
    for (int i = 1; i<=n; i++) {
        cin >> ara[i];
        update( i,ara[i],n);
    }
    for (int i = 1; i<=n; i++) {
        cout << tree[i] << " ";
    }
    cout << endl;
    cout<< query(n) << endl;
    
    // summation from a to b
    int a, b;
    cin >> a >> b;
    int sum1 = query(a-1);
    int sum2 = query(b);
    cout << sum2-sum1 << endl;
    
    // For update..
    cin >> a >> b;
    update(a,b,n);
    cout << query(n) << endl;
    return 0;
}
