const int n= 1e5+7; 
int sp[n]; 
vector<int> prime; 
void seive(){
	for(int i = 2; i<n; i++) {
		if (!sp[i] ) sp[i] = i, prime.push_back(i); 
		for(int j = 0; j<(int)prime.size()&& i*prime[j] < n && prime[j]<=sp[i]; j++){
			sp[i*prime[j]] = prime[j]; 
		}
	}
	for(int i:prime) cout << i << " ";
	cout << endl;
}

const int mxN = 1e7+7;
vector<ll> p;
bool mark[mxN];
void sieve(){
    p.push_back(2);
    for(ll i = 3; i<=mxN; i+=2){ 
        if(!mark[i]) { 
            p.push_back(i); 
            for(ll j = i*i; j<=mxN; j+=i+i ) {
               mark[j] = 1; 
            }
        }
    }
    for(int i: p) cout << i << " "; 
    cout << endl;
}
