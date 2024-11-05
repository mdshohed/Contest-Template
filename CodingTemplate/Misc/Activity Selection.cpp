#include <bits/stdc++.h>
using namespace std;

struct activity{
    int start, finish;
};

bool compare(activity a, activity b) {
    return a.finish < b.finish;
}

int main() {

    freopen( "input.txt", "r", stdin );
    int n;
    cin >> n;
    activity ara[100];
    for (int i = 0; i<n; i++) {
        cin >> ara[i].start >> ara[i].finish;
    }
    sort( ara, ara+n, compare );
    int i = 0;
    cout << ara[i].start << " " << ara[i].finish << endl;
    for (int j = 1; j<n; j++) {
        if ( ara[j].start>= ara[i].finish) {
            cout << ara[j].start << " " << ara[j].finish << endl;
            i = j;
        }
    }
    return 0;
}
