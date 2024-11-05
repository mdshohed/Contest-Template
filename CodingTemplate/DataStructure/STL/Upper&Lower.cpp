#include <bits/stdc++.h>
using namespace std; 

int main() {
	freopen( "in.txt", "r", stdin); 
	int n; 
	cin >> n;
	std::vector<int> a(n);
	for(int &i:a) cin >> i;  
	cout << (binary_search(a.begin(), a.end(), 4)==1? "Yes": "No") << endl; 

	auto it = lower_bound( a.begin(),a.end(), 5);    
	if (it==a.end()) {
		cout << "lower value not found" << endl; 
	}
	else {
		cout << (*it) << endl;
		cout << "Position: " << it - a.begin() << endl; 
	} 
	it = upper_bound( a.begin(), a.end(), 5); 
	if (it==a.end()) cout << "Upper value not found" << endl;  
	else {
		cout << (*it) << endl;
		cout << "Position: " << it - a.begin() << endl; 
	}

	cin >> n;
	int ara[n]; 
	for(int i = 0; i<n; i++) cin >> ara[i]; 
	cout << (binary_search(ara,ara+n, 3)? "yes": "no") << endl;
	int *it1 = lower_bound(ara, ara+n, 7); 
	if (it1 == ara+n) cout << "lower value not found" << endl; 
	else {
		cout << (*it1) << endl; 
		cout << (it1 - ara) << endl; 
	} 
	it1 = upper_bound(ara, ara+n, 25); 
	if (it1==ara+n) cout << "Upper value not found" << endl; 
	else {
		cout << (*it1) << endl; 
		cout << (it1 - ara) << endl; 
	}
	
	// set
	set<int> s; 
	cin >> n; 
	for(int i = 0; i<(int)1e3; i++) {
		s.insert(rand());
	}
	for(int i = 0; i<(int)1e5; i++) {
		auto it = s.lower_bound(rand());
		if (it==s.end()) cout << "No" << " "; 
		else cout << "Yes" << " ";  
	} 
	cout << endl; 
	return 0;
}
