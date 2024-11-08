#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T> using ordered_set =  tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
int main() {
 
    int n;
    ordered_set<array<int,2>> s;
    cin >> n;
    for(int i = 0; i<n; i++) {
        int x;
        cin >> x;
        s.insert( {i,x});
    }
    for(int i = 0; i<n; i++) {
        int p;
        cin >> p;
        p--;
        auto it = s.find_by_order(p);
        cout  << (*it)[1] << " ";
        s.erase(it);
    }
}
// https://cses.fi/problemset/task/1749