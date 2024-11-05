/*
    Time complexity: O(n^2)
*/
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define CLR(x,y) memset( x,y,sizeof(x))
#define FOR(x,n) for(int i = x; i<n; i++)

typedef long long ll;
typedef pair<int,int> pii;
typedef map<int,int> mp;

const int INF = 1e5+7;

int lis(int ara[], int n){
    int dp[n];
    dp[0] =1;
    for (int i = 1; i<n; i++){
        dp[i] = 1;
        for (int j = 0; j<i; j++){
            if ( ara[i]>ara[j] && dp[i]<dp[j]+1){
                dp[i] = dp[j]+1;
            }
        }
    }
    return *max_element(dp, dp+n);
}

int lis_increasin (int ara[], int n) {
    vector<int> v; 
    for (int i = 0; i<n; i++){
        int x = ara[i];
        auto it =  lower_bound(v.begin(), v.end(), x);
        if ( v.end()==it) v.push_back(x);
        else v[ it-v.begin() ] = x;
    }
    return v.size(); 
}

int main(){
    int n;
    cin >> n;
    int ara[100];
    for (int i = 0; i<n; i++) cin >> ara[i];
    cout << lis_increasin( ara, n); 
    return 0;
}
