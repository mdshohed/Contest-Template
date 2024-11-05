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

int cnt = 0;
bool done[1000];
bool value[1000];

int rod_cut(int price[], int n ){
    cnt++;
    if ( n<=0 ) return 0;
    int  max_value = INT_MIN;
    for (int i= 0; i<n; i++){
        int temp;
        if (done[n-i-1]) temp = value[n-i-1];
        else {
            temp = rod_cut( price, n-i-1 );
            done[n-i-1] = true;
            value[n-i-1] = temp;
        }
        max_value = max( max_value, price[i]+temp);
    }
    return max_value;
}

int road_cut (int ara[],int n ){
    if( n<= 0) return 0;
    int max_val = INT_MAX;
    for (int i = 0; i<n; i++){
        max_val = max( max_val, ara[i]+road_cut(ara, n-i-1));
    }
}

int rod_cuting (int ara[], int n ){
    int val[n+1];
    val[0] = 0;
    for (int i = 1; i<=n; i++){
        int max_val = INT_MAX;
        for (int j = 0; j<i; j++){
            max_val = max( max_val , ara[j]+val[i-j-1]);
        }
        val[i] = max_val;
    }
    return val[n];
}

int main(){
    int n;
    cin >> n;
    int ara[100];
    for (int i = 0; i<n; i++){
        cin >> ara[i];
    }
    cout << rod_cut(ara, n) << endl;
    cout << cnt << endl;
    return 0;
}
