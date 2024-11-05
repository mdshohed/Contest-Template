#include<bits/stdc++.h>
using namespace std;

struct node{
    int year, month, day, total;
};

void Merge(int l,int mid,int h,node ara[])
{
    int i = l, j = mid+1, k = 0;
    node temp[100];
    while(i<=mid && j<=h ) {
        if(ara[i].total<ara[j].total) temp[k++] = ara[i++];
        else temp[k++] = ara[j++];
    }
    while( i<=mid ) temp[k++] = ara[i++];
    while( j<=h ) temp[k++] = ara[j++];

    for (k=0, i=l; i<=h; k++, i++) {
        ara[i] = temp[k];
    }
}

void mergesort(int lo, int hi, node ara[])
{
    if (lo==hi) return;
    int mid = (lo+hi)/2;
    mergesort(lo,mid,ara);
    mergesort(mid+1,hi,ara);

    Merge(lo, mid, hi, ara);
}

int main()
{
    //freopen( "input(1).txt", "r", stdin);
    int n;
    cin >> n;
    node ara[100];
    for (int i=0; i<n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        ara[i].year = x;
        ara[i].month = y;
        ara[i].day = z;
        int sum = x*360+y*30+z;
        ara[i].total = sum;
    }
    mergesort(0, n-1, ara);
    for (int i=0; i<n; i++) {
        cout<<ara[i].year<<" "<<ara[i].month<<" "<<ara[i].day<<endl;
    }
    return 0;
}
