/**
    Reference: http://www.shafaetsplanet.com/?p=1679
*/
#include <bits/stdc++.h>
using namespace std;

struct node{
    bool endpoint;
    node* next[1000];
    node() {
        endpoint = false;
        for(int i = 0; i<26; i++) {
            next[i] = NULL;
        }
    }
}*root;

void Insert(string s,int n) {
    node *temp = root;
    for (int i = 0; i<n; i++) {
        int x = s[i];
        if ( temp->next[x]==NULL) {
            temp->next[x] = new node();
        }
        temp = temp->next[x];
    }
    temp->endpoint = true;
}

bool Search(string s,int n) {
    node *temp = root;
    for (int i = 0; i<n; i++) {
        int id = s[i];
        if ( temp->next[id]==NULL) {
            return  false;
        }
        temp = temp->next[id];
    }
    return temp->endpoint;
}

void del(node* root) {
    for (int i = 0; i<26; i++) {
        if ( root->next[i]) {
            del(root->next[i]);
        }
    }
    delete(root);
}

int main() {
    root = new node();
    int n;
    cin >> n;

    for (int i = 0; i<n; i++) {
        string s;
        cin >> s;
        Insert(s,s.size());
    }

    int m;
    cin >> m;
    for (int i = 0; i<m; i++ ) {
        string s;
        cin >> s;
        if ( Search( s,s.size()) ) cout << "found" << endl;
        else cout << "NOt found" << endl;
    }
    del(root);
    return 0;
}
