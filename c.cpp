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
  int n, k; 
  cin >> n >> k; 
  vector<int> a(n);
  for (int &i: a ) cin >> i;
  vector<int> ans;
  priority_queue<int> maxHeap;
  priority_queue<int,vector<int>, greater<int>> minHeap;
  for(int i = 0; i<n; i++){
    minHeap.push(a[i]);
    int val = minHeap.top();
    minHeap.pop();
    maxHeap.push(val);
    if( minHeap.size() < maxHeap.size() ){
      minHeap.push( maxHeap.top()); 
      maxHeap.pop(); 
    }
    if(minHeap.size()+maxHeap.size() == k ){
      if( k&1 ){
        ans.push_back( minHeap.top()); 
      }
      else {
        int val1 = minHeap.top();
        int val2 = maxHeap.top();
        ans.push_back( min( val1, val2 ));
      }
      int lastValue = a[ i - k + 1 ];
      if( lastValue >= minHeap.top() ) {
       vector<int> temp;
        while(!minHeap.empty()){
          temp.push_back( minHeap.top() );
          minHeap.pop(); 
        }
        int flag = 0; 
        for(int i: temp ){
          if(!flag&& lastValue == i) flag = 1;
          else minHeap.push( i ); 
        } 
      }
      else{
        vector<int> temp;
        while(!maxHeap.empty()){
          temp.push_back( maxHeap.top() );
          maxHeap.pop(); 
        }
        int flag = 0; 
        for(int i: temp ){
          if( !flag&& lastValue == i) flag = 1;
          else maxHeap.push( i ); 
        }
      }
    }
  }  
  for(int i: ans ) cout << i << " ";
  cout << endl; 
  
  return 0;
}