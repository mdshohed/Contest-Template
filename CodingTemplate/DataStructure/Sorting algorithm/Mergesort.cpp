/*
Time Complexity: O(nlogn) 
Algorithm: merge sort; 
*/
#include <bits/stdc++.h>
using namespace std;

int build_merge(int ara[], int low , int mid , int high){
    int i = low, j = mid +1, temp[100], k = 1;
    while(i<=mid && j<=high){
        if (ara[i] < ara[j]) {
            temp[k++] = ara[i++];
        }
        else temp[k++] = ara[j++];
    }
    while(i<=mid) temp[k++] = ara[i++];
    while (j<=high ) temp[k++] = ara[j++];

    for(k=1, i= low; i<=high; i++, k++){
        ara[i] = temp[k];
    }
}

void merge_sort(int ara[], int low, int high){

    if ( low==high) return;
    int mid = (low + high)/2;
    merge_sort(ara, low , mid);
    merge_sort( ara, mid + 1, high);
    build_merge(ara, low, mid, high);
}

int main(){

    int n;
    cin >> n;
    int ara[100];
    for (int i = 0; i<n; i++){
        cin >> ara[i];
    }

    merge_sort(ara,0, n-1);

    for (int i = 0; i<n; i++){
        cout << ara[i] << " ";
    }
    cout << endl;
    return 0;
}
