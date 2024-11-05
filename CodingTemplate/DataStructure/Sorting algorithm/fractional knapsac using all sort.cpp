#include <bits/stdc++.h>
using namespace std;

struct item {
    double w, p, u;
};

bool compare(item a, item b){
    return a.u > b.u;
}

void bubble_sort(item ara[], int n) {
    for (int i = 0; i<n-1; i++) {
        for (int j = 0; j<n-i-1; j++){
            if ( ara[j].u < ara[j+1].u ) {
                swap( ara[j], ara[j+1] );
            }
        }
    }
}

int insertion_sort(item ara[], int n ) {
    for (int i = 1; i<n; i++) {
        item x = ara[i];
        int j = i-1;
        while ( j >=0 && ara[j].u<x.u ) {
            ara[j+1] = ara[j];
            j = j-1;
        }
        ara[j+1] = x;
    }
}

void Merge(int l,int mid,int h,item ara[]){
    int i = l, j = mid+1, k = 0;
    item temp[100];
    while( i<=mid && j<=h ) {
        if(ara[i].u>ara[j].u) temp[k++] = ara[i++];
        else temp[k++] = ara[j++];
    }
    while( i<=mid ) temp[k++] = ara[i++];
    while( j<=h ) temp[k++] = ara[j++];

    for (k=0, i=l; i<=h; k++, i++) {
        ara[i] = temp[k];
    }
}

void mergesort(int lo, int hi, item ara[]){
    if (lo==hi) return;
    int mid = (lo+hi)/2;
    mergesort(lo,mid,ara);
    mergesort(mid+1,hi,ara);
    Merge(lo, mid, hi, ara);
}

int partitions(item ara[], int p, int r){
    int pivot = ara[r].u;
    int i = p - 1;
    for (int j = p; j<=r-1; j++){
        if ( ara[j].u>pivot ){
            i++;
            swap( ara[i], ara[j]);
        }
    }
    swap( ara[i+1], ara[r]);
    return i+1;
}

int quick_sort(item ara[], int p, int r){
    if ( p<r ) {
        int q = partitions(ara, p, r);
        quick_sort(ara, p , q-1);
        quick_sort(ara, q+1, r);
    }
}

int main() {
    freopen( "input.txt", "r", stdin );

    int w, n;
    cin >> w >> n;

    item ara[100];
    for (int i = 0; i<=n; i++) {
        cin >> ara[i].w >> ara[i].p;
        ara[i].u = ara[i].p/ara[i].w;
    }

    //sort( ara, ara+n, compare );
    //bubble_sort( ara, n );
    //insertion_sort( ara, n );
    //mergesort( 0, n-1, ara );
    //quick_sort(ara, 0, n-1);

    for (int i = 0; i<n; i++) {
        cout << ara[i].p << " " << ara[i].w << " " << ara[i].u << endl;
    }
    cout << endl;

    int maximum = 0;

    for (int i = 0; i<n; i++) {
        if ( w>ara[i].w ){
            maximum +=ara[i].p;
            w-=ara[i].w;
        }
        else {
            maximum += w*ara[i].u;
            w = 0;
        }
    }
    cout << "maximum: " << maximum << endl;
    return 0;
}
