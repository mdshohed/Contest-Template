#include <bits/stdc++.h>
using namespace std;
 
//const int N = 1414220;
const int N = 2 * 1e6;
vector <int> p;
bool mark[N+1];
 
void sieve(){
  p.push_back(2);
  int lim = sqrt(N);
  for (long long i = 3;i <= N;i+=2){
    if (!mark[i]){
      p.push_back(i);
      //if (i > lim)continue;
      for (long long j = i*i; j <= N;j+=i+i){
        mark[j] = true;
      }
    }
  }
}
 
vector <long long> pd;
 
void find_pd(long long n){
  for (int i = 0;i < p.size();i++){
    long long d = p[i];
    if (d*d > n)break;
    if (n%d==0){
      while (n%d==0)n /= d;
      pd.push_back(d);
    }
  }
  if (n > 1)pd.push_back(n);
}
 
long long f(long long n){
  int len = pd.size();
  //cout << n << '\n';
  len = (1<<len);
  long long cut = 0;
  for (int i = 1;i < len;i++){
    int cnt = 0;
    long long dd = 1;
    for (int j = 0;j < pd.size();j++){
      if ( (i & (1<<j)) > 0){
        dd *= pd[j];
        cnt++;
      }
    }
    if (cnt%2){
      cut += n/dd;
    }else {
      cut -= n/dd;
    }
  }
  return n - cut;
}
 
void solve(int ca){
  long long a, b, m;
  cin >> a >> b >> m;
  if (a==b){
    cout << "Case " << ca << ": " << 0 << '\n';
    return;
  }
  if (a > b)swap(a, b);
  find_pd(b-a);
  long long ff = a-1;
  long long ss = a+m;
  ff = f(ff);
  ss = f(ss);
  cout << "Case " << ca << ": " << ss-ff << '\n';
  pd.clear();
}
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T = 1, ca = 0;
  cin >> T;
  sieve();
  while (T--){
    solve(++ca);
  }
  return 0;
}