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

const int mx = 1e5+7;

/*int catalon(int n){
    if ( n<=1 ) return 1;
    int ans = 0;
    for (int i = 0; i<n; i++){
        ans  += catalon(i)*catalon(n-i-1);
    }
    return ans;
}*/

/*int catalon(int n){
    int dp[n+1];
    dp[0] = dp[1] = 1;
    for (int i = 2; i<=n; i++){
        dp[i] = 0;
        for (int j = 0; j<i; j++){
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    return dp[n];
}*/

int binomialcofficient(int n, int k) {
    int  ans = 1;
    if ( k > n-k ) {
        k = n-k;
    }
    for (int i=0; i<k; i++){
        ans *= (n-i);
        ans /= (i+1);
    }
    return ans;
}

int catalon(int n ){
    int c = binomialcofficient( 2*n, n );
    return  c/(n+1);
}

int main(){

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i<n; i++){
            cout << catalon(i) << " ";
        }
        cout << endl;
    }
    return 0;
}
