#include <bits/stdc++.h>
using namespace std;

class lis {
public:
    int lis_increasing(vector<int> v) {
        int n = v.size();
        const int inf = 1e9;
        vector<int> dp( n+1, inf);
        dp[0] = -inf;

        for (int i = 0; i<n; i++) {
            int j = upper_bound( dp.begin(), dp.end(), v[i]) - dp.begin();
            if ( dp[j-1]<v[i] && v[i]<dp[j] ) {
                dp[j] = v[i];
            }
        }
        int ans = 0;
        for (int i = 0; i<=n; i++ ) {
            if ( dp[i]< inf) {
                ans = i;
            }
        }
        return ans;
    }
};

int main() {

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i<n; i++ ) cin >> v[i];

    lis a;
    cout << a.lis_increasing(v) << endl;

}

