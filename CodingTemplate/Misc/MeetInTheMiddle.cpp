#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define getbit(x,i) (((x)&(1ll<<(i))) != 0)
#define pii pair<int,int>
#define ll long long

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif 
    int n, x;
    cin >> n >> x;
    vector<ll> a(n); 

    auto generateSubSetSum = [&](vector<ll>& arr, vector<ll>& s) {
      int n = arr.size();
      int totalSubset = 1 << n;
      for (int mask = 0; mask < totalSubset; mask++) {
        ll sum = 0;
        for (int i = 0; i < n; i++) {
          if (mask & (1 << i)) {
            sum += arr[i];
          }
        }
        s.push_back(sum);
      }
    };

    auto countWay = [&](vector<ll>& a, int x) {
      int n = a.size();
      int m = n / 2;
      vector<ll> left(a.begin(), a.begin() + m);
      vector<ll> right(a.begin() + m, a.end());
      vector<ll> leftSum, rightSum;
      generateSubSetSum(left, leftSum);
      generateSubSetSum(right, rightSum); 
      sort(all(rightSum)); 
      ll cnt = 0;
      for(ll sum: leftSum ){
        ll target = x - sum;
        cnt += upper_bound(rightSum.begin(), rightSum.end(), target) -
                 lower_bound(rightSum.begin(), rightSum.end(), target);
      }
      cout << cnt << endl; 
    };
    for(ll &i: a ) cin >> i; 
    countWay(a, x); 
    return 0;
}
// https://cses.fi/problemset/task/1628