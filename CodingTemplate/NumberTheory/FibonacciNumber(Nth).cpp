int Nth_fib(int n) {
	base[0][0] = base[0][1] = base[1][0] =  1; 
	base[1][1] = 0; 
	fib[0][0] = fib[0][1] = fib[1][0] =  1; 
	fib[1][1] = 0; 
	while (n--) {
		int temp[2][2];
		for(int i = 0; i<2; i++){
			for(int j = 0; j<2; j++) {
				int val = 0;
				for(int k = 0; k<2; k++) {
					val = (val+base[i][k]*fib[k][j])%mod;
				}
				temp[i][j] = val;
			}
		}
		for(int i = 0; i<2; i++) {
			for(int j = 0; j<2; j++) {
				fib[i][j] = temp[i][j];
			}
		}
	}
	return fib[1][1]; 
}
