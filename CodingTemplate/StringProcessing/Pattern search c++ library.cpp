#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;
    while (t--) {
            
        string txt, pat;
        cin >> txt >> pat;

        int found = txt.find(pat);
        while( found!=string::npos){
            cout << "pattern found at index: " << found << endl;
            found = txt.find(pat,found+1);
        }
    }
    return 0;
}
