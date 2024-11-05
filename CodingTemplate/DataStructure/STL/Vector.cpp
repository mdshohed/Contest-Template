#include <bits/stdc++.h>
using namespace std; 

int main() {
	freopen("in.txt", "r", stdin ); 
	int n, m; 
	cin >> n;  
	// 1D vector 
	std::vector<int> a;
	for(int i = 0; i<n; i++) {
		int x; cin >> x; 
		// a.push_back(x); 
		a.emplace_back(x); 
	} 
	for(int i: a ) cout << i << " "; 
	cout << endl; 
	for(auto it = a.begin(); it!=a.end(); it++) {
		cout << (*it) << " "; 
	}
	cout << endl; 

	// 2D vector 
	cin >> n >> m; 
	vector<vector<int>> v2(n,vector<int>(m));
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<m; j++) {
			cin >> v2[i][j];  
		}
	}
	for(int i = 0; i<n; i++) {
		for(int j: v2[i]) {
			cout << j << " "; 
		}
		cout << endl; 
	}
	cout << endl; 

	// pair vector
	cin >> n; 
	vector<pair<int,int>> v(n);
	for(int i = 0; i<n; i++) {
		cin >> v[i].first;
		v[i].second = i;
	}
	sort( v.begin(),v.end(),[&](auto x,auto y){
		if (x.first==y.first ) return x.second > y.second; 
		else x.first < y.first; 
	}); 
	for(auto i:v) {
		cout << i.first << " " << i.second << endl;
	}
	cout << endl; 
	return 0; 
}