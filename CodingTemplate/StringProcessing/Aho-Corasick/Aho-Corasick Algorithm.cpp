/*
resource: https://www.geeksforgeeks.org/aho-corasick-algorithm-pattern-searching/
algorithm: Aho-Corasick algorithm
*/

#include <bits/stdc++.h>
using namespace std;

#define db(x) cout << #x << " -> " << x << endl;
const int mxstate = 500;
const int mxch = 26;
int out[mxstate], f[mxstate], g[mxstate][mxch];

int buildtree(string ara[],int n) {
    memset( out, 0, sizeof out);
    memset( f, -1, sizeof f );
    memset( g, -1, sizeof g );

    int state = 1;
    for(int i = 0; i<n; i++) {
        string word = ara[i];
        cout << word.size() << " ";
        int current = 0;

        for (int j = 0; j<word.size(); j++) {
            int ch = word[j] - 'a';
            if ( g[current][ch]==-1) {
                g[current][ch] = state++;
            }
            current = g[current][ch];
        }
        out[current] |= ( 1<< i );
    }
    for (int i = 0; i<mxch; i++) {
        if ( g[0][i] == -1 ) g[0][i] = 0;
    }

    queue<int> q;
    for (int i = 0; i<mxch; i++) {
        if ( g[0][i]!=0 ) {
            f[g[0][i]] = 0;

            q.push(g[0][i]);
        }
    }

    while (q.size()) {

        int state = q.front();
        q.pop();
        
        //db(state);
        
        for (int i = 0; i<=mxch; i++) {
            if ( g[state][i]!=-1 ) {
                int failure = f[state];
                while ( g[failure][i]==-1) {
                    failure = f[failure];
                }
                failure = g[failure][i];
                f[g[state][i]] = failure;
                out[g[state][i]] |= out[failure];
                q.push( g[state][i] );
            }

        }
    }
}

int nextstate(int ans , char c) {
    int ch = c - 'a';
    while( g[ans][ch] == -1) {
        ans = f[ans];
    }
    return g[ans][ch];
}

int wordfind(string ara[], int n, string txt) {
    buildtree(ara, n);

    int current = 0;
    for (int i = 0; i< txt.size(); i++) {
        current = nextstate( current,txt[i]);
        if( out[current]==0) continue;
        for (int j = 0; j<n; j++) {
            if ( out[current] & (1<<j) ) {
                cout << ara[j] << " " << i - ara[j].size()+1 << " to " << i << endl;
            }
        }
    }
}

int main() {
    string ara[] = {"he", "she", "hers", "his"};
	string txt = "ahishers";
	int k = sizeof(ara)/sizeof(ara[0]);
	wordfind(ara, k, txt);
	return 0;
}
