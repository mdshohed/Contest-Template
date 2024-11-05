#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define getbit(x,i) (((x)&(1ll<<(i))) != 0)
#define pii pair<int,int>
#define ll long long

const int mx = 1e6;
deque<int> dq;
bool flag = true; 
ll sum = 0; 
int a[mx<<1]; 

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif 
  string s;
  while(cin >> s) {
    ll n; 
    if( s == "PUSH") {
      cin >> n; 
      if(flag){
        dq.emplace_back(n); 
      }
      else {
        dq.emplace_front(n); 
      }
      sum += n;
      if(dq.size() > mx ){
        if(flag){
          sum -= dq.back(); 
          dq.pop_back(); 
        }
        else {
          sum -= dq.front(); 
          dq.pop_front(); 
        }
      }
    }
    else if( s == "POP"){
      if(!dq.size()) continue;
      if(flag){
        sum -= dq.back(); 
        dq.pop_back(); 
      }
      else {
        sum -= dq.front(); 
        dq.pop_front(); 
      }
    }
    else if( s== "PRINT"){
      if(dq.empty()){
        puts("-");  
        continue; 
      }
      if(flag){
        ll val = dq.back(); 
        printf("%d\n",val); 
        // cout << dq.back() << endl; 
      }
      else {
        ll val = dq.front(); 
        printf("%d\n",val);         
      }
    }
    else if( s == "SIZE"){
      ll val = (int)dq.size(); 
      printf("%d\n",val);       
    }
    else if( s == "SUM"){
      printf("%lld\n",sum); 
    }
    else if( s== "REPEAT"){
      int k; cin >> k;  
      n = dq.size(); 
      if( !n ) continue;
      if( n + n > mx ){
        int need = mx - n; 
        int cnt = 0 ;
        // vector<ll> a( mx<<1);
        while ( cnt < need ){
          if(flag) a[cnt] = dq[cnt]; 
          else a[cnt] = dq[ n - 1 - cnt];
          cnt++;
        }
        while ( k-- && dq.size() < mx){
          for(int i = 0 ; i < cnt && dq.size() < mx; i++){
            int x = a[i];
            sum += x;
            if(flag) dq.emplace_back(x);
            else dq.emplace_front(x); 
          }
        }
      }
      else{
        int cnt = 0 ;
        while ( cnt < dq.size()){
          if(flag) a[cnt] = dq[cnt]; 
          else a[cnt] = dq[ n - 1 - cnt];
          cnt++;
        }
        while ( k-- && dq.size() < mx){
          for(int i = 0 ; i<cnt && dq.size()<mx; i++){
            int x = a[i];
            sum += x;
            if(flag) dq.emplace_back(x);
            else dq.emplace_front(x); 
          }
        }
      }
    }
    else if( s== "REVERSE"){
      flag ^= 1; 
    }
  }
  return 0;
}