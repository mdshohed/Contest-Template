#include <bits/stdc++.h>
using namespace std;

vector<int> v, aux;

void merge_sort(int left, int right) {
    if (left == right) {
        return;
    }
    int middle = (left + right) / 2;
    merge_sort(left, middle);
    merge_sort(middle + 1, right);
    aux.clear();
    int i = left, j = middle + 1;
    while (i <= middle || j <= right) {
        if (j > right || (i <= middle && v[i] < v[j])) {
            aux.push_back(v[i]);
            i += 1;
        } else {
            aux.push_back(v[j]);
            j += 1;
        }
    }
    for (int i = left; i <= right; i += 1) {
        v[i] = aux[i - left];
    }
}

int main() {
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i<n; i++ ) cin >> v[i];

    merge_sort(0,n-1);

    for (int i = 0; i<n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
