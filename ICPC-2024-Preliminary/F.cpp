#include <bits/stdc++.h>
using namespace std;
void solve()
{
  long long x, y, z, a, b;
  cin >> x >> y >> z;
  long long p = (x + y + z);
  a = p * (p * p * p - 2 * p * p * z - 2 * p * p * y - 2 * p * p * x + 4 * x * y * p + 4 * y * z * p + 4 * x * z * p - 8 * x * y * z);
  b = 4 * p * p;
  long long mx = __gcd(a, b);
  a /= mx;
  b /= mx;
  cout << a << "/" << b << endl;
}
int32_t main()
{
  ios_base::sync_with_stdio(false), cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--)
  {
    solve();
  }
}