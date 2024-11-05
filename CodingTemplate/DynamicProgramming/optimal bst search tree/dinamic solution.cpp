// dynamic programming code for optimal BST problem...
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define EMPTY_VALUE -1
#define CLR(x,y) memset( x,y,sizeof(x))
#define FOR(x,n) for(int i = x; i<n; i++)

typedef long long ll;
typedef pair<int,int> pii;
typedef map<int,int> mp;

const int MOD = 1e9+7;
const int mx = 1e2+7;

int sum(int freq[], int i, int j){
    int s = 0;
    for (int k = i; k<=j; k++) {
        s += freq[k];
    }
    return s;
}

int  optimal_bst (int keys[], int freq[], int n ) {
    int cost[n][n];

    for (int i = 0; i<n; i++){
         cost[i][i] = freq[i];
    }

    for (int l = 2; l<=n; l++) {
        for (int i = 0; i<n-l+1; i++) {
            int j = i+l-1;
            cost[i][j] = INT_MAX;
            for (int r = i; r<=j; r++) {
                int c = ((r>i)?cost[i][r-1]:0) +((r<j)?cost[r+1][j]:0) + sum(freq, i, j);
                if ( c < cost[i][j] ) {
                    cost[i][j] = c;
                }
            }
        }
    }
    return cost[0][n-1];
}

int main() {
    int n;
    cin >> n;
	int keys[] = {10, 12, 20};
	int freq[] = {34, 8, 50};
	cout << "Cost of Optimal BST is " << optimal_bst(keys, freq, n) << endl;
	return 0;
}

