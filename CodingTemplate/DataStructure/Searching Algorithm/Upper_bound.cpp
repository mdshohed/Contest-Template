// not equal but greater value return 
int upper_bound(std::vector<int> a, int x) {
	int l = -1, r = a.size(); 
	while( r>l+1) {
		int mid = ( l + r) >> 1; 
		if ( a[mid] <= x ) l = mid; 
		else r = mid; 
	}
	return l+1;  
}

//built in function
auto it = upper_bound(all(a),x) ; 
int val = distance( a.begin() - it); 
