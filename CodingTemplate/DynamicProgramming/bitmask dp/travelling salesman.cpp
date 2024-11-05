#include <bits/stdc++.h>
using namespace std;

int n = 4;
int dp[16][4];

int dis[10][10] = {
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}
};

int visited_all = (1<<n)-1;

int tsp( int mask, int pos ){
    if ( mask==visited_all ) return dis[pos][0];

    int ans = INT_MAX;
    if ( dp[mask][pos] != -1 ) {
        return dp[mask][pos];
    }

    for (int i = 0; i<n; i++){
        if ( (mask & (1<<i))==0) {
            int newans = dis[pos][i] + tsp( mask|(1<<i), i);
            ans = min(ans, newans);
        }
    }
    //return ans;
    return dp[mask][pos] = ans ;
}

int main (){
    for (int i = 0; i<(1<<n); i++){
        for (int j = 0; j<n; j++) {
            dp[i][j] = -1;
        }
    }

    cout << tsp(1, 0) << endl;
    return 0;
}
