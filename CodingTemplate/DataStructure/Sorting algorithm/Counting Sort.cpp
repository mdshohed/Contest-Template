#include <bits/stdc++.h>
using namespace std; 
 
void countingSort(int ara[], int n, int mn, int mx){
    int size = mx - mn + 1; 
    std::vector<int> cnt(size,0);
    for(int i = 0; i<n; i++) {
        cnt[ara[i] - mn]++; 
    }
    int j = 0; 
    for(int i = mn; i<=mx; i++) {
        while (cnt[i-mn]-->0) {
            ara[j++] = i; 
        }
    }
    for(int i = 0; i<n; i++) {
        cout << ara[i] << " "; 
    }
    cout << endl; 
}

int main(){
    // freopen("in.txt", "r", stdin ); 
    int ara[] = {5, 9, 11, 10, 15, 12, 2, 8 ,10};
    int n = 9; 
    int mx = *max_element( ara, ara+n);
    int mn = *min_element( ara, ara+n );
    countingSort(ara, n, mn, mx );
    return 0;
}
