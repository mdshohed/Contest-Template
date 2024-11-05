/*
    Reference: https://cp-algorithms.com/sequences/longest_increasing_subsequence.html
    Input: 5 0 9 2 7 3 4
    Output: 0 2 3 4

*/
#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int mx = 1e4+6;
int ara[mx];
int n;

void lis() {

    vector<int> dp(n, 1), parent(n, -1);
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<i; j++ ) {
            if ( ara[j]<ara[i] && dp[i]<dp[j]+1 ) {
                dp[i] = dp[j]+1;
                parent[i] = j;
            }
        }
    }

    int ans = dp[0], pos = 0;
    for (int i = 1; i<n; i++) {
        if ( dp[i]> ans ) {
            pos = i;
            ans = dp[i];
        }
    }

    stack<int> st;
    while ( pos!=-1) {
        st.push( ara[pos]);
        pos =  parent[pos];
    }

    while ( !st.empty() ){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {

    cin >> n;
    for (int i = 0; i<n; i++ ) cin >> ara[i];

    lis() ;
}


// LIs (another) 
#include <bits/stdc++.h>
using namespace std;

#define increasing;

const int mx = 1e5+7;
int ara[mx] , n;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vii;

vi lis() {
    vii best;
    vi dad( n, -1);
    for (int i = 0; i<n; i++ ) {
        #ifdef increasing
            auto item = make_pair( ara[i], 0);
            auto it = lower_bound( best.begin(), best.end(), item);
            item.second = i;
        #elif
            pi item = make_pair( v[i], i);
            auto it = upper_bound( best.begin(), best.end(), item);
        #endif

        if ( it==best.end()) {
            dad[i] = ( best.size()==0?-1:best.back().second);
            best.push_back(item);
        }
        else {
            dad[i] = dad[ it->second];
            *it = item;
        }
    }

    vi ret;
    for (int i = best.back().second; i>=0; i= dad[i]) {
        ret.push_back(ara[i]);
    }
    reverse( ret.begin(), ret.end());
    return ret;

}

int main(){

    cin >> n;
    for (int i = 0; i<n; i++) {
        cin >> ara[i];
    }
    vi x = lis();
    for (int i = 0; i<x.size(); i++ ) {
        cout <<  x[i] << " ";
    }
    cout << endl;
}
