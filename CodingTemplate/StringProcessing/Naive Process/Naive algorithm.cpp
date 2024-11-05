/*
Algorithm: naive algorithm of string search 
input: 
mdshohed
shohed
mdshohed
asdf
output: 
pattern found 
pattern not found 
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

    string text, pattern;
    cin >> text >> pattern;

    for (int i = 0; i<text.size(); i++) {
        int j = 0;
        for (j = 0; j<pattern.size(); j++) {
            if ( text[i+j] != pattern[j] ) break;
        }
        if ( j == pattern.size()){
            cout << "pattern found " << endl;
           return 0;
        }
    }
    cout << "pattern not found" << endl;
    return 0;
}

