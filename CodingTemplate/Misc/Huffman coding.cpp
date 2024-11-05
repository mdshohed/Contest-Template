#include <bits/stdc++.h>
using namespace std;

map<char,int> mp;
map<char,string> code;
string full_string = "";

struct node {
    char ch;
    int freq;
    node *left, *right;
    node(char c, int f, node* x, node* y) {
        ch = c;
        freq = f;
        left = x;
        right = y;
    }
};

class compare{
public:
    bool operator()(node*a, node* b){
        return a->freq > b->freq;
    }
};

void print_huffman(node* root, string str,map<char,string> &code) {
    if ( root==NULL ) return;
    if ( !root->left&&!root->right ) {
        code[root->ch] = str;
        cout << "  " << root->ch << "   =   " << root->freq
            << "   =   " << str << endl;
    }
    print_huffman(root->left, str+'0', code);
    print_huffman(root->right, str+'1', code);
}

void decode(heap_node* node, int &top_index, string str ){
    if ( node == NULL) return;
    if ( !node->left && !node->right){
        cout << node->ch;
        return;
    }
    top_index++;
    if ( str[top_index]=='0') decode(node->left, top_index, str);
    else decode(node->right, top_index, str);
}

void huffmancoder() {
    freopen( "out1.txt", "w", stdout );

    priority_queue<node*,vector<node*>,compare> pq;
    for(auto it: mp){
        pq.push(new node(it.first, it.second, NULL, NULL));
    }
    while ( pq.size()!=1){
        node* x = pq.top();
        pq.pop();
        node* y = pq.top();
        pq.pop();
        pq.push(new node('*', x->freq+y->freq, x, y));
    }
    cout << "letter | frequency | code" << endl;
    cout << "-------------------------" << endl;
    print_huffman( pq.top(), "", code );
}

void full_code() {
    freopen( "out2.txt", "w", stdout );
    string x = "";
    for (char ch: full_string ){
        x += code[ch];
    }
    cout << x << endl;
}

int main(){
    freopen( "input.txt", "r", stdin );
    string s;
    while(getline(cin,s)) {
        for (int i = 0; i<s.size(); i++ ){
            mp[s[i]]++;
            full_string+=s[i];
        }
    }
    huffmancoder();
    full_code();
    return 0;
}


