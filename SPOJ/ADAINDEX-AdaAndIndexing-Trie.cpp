#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define getbit(x,i) (((x)&(1ll<<(i))) != 0)
#define pii pair<int,int>
#define ll long long

struct TRIE{
  struct TrieNode{
    TrieNode* nxt[26];
    int cnt = 0; 
    TrieNode(){
      memset(nxt, 0, sizeof nxt); 
      cnt = 0;
    }
  }*root;
  TRIE(){
    root = new TrieNode();
  }
  void inset(string s){
    TrieNode* node = root;
    for(char ch: s ){
      if(!node->nxt[ch - 'a']){
        node->nxt[ch-'a'] = new TrieNode();
      }
      node = node->nxt[ ch-'a']; 
      node->cnt++; 
    }
  }
  int query(string s){
    int ans = 0; 
    TrieNode* node = root; 
    for( char ch: s){
      if( !node->nxt[ch-'a'] ){
        return 0;
      }
      node = node->nxt[ch-'a'];
    }
    return node->cnt;
  }
  void printTrie(TrieNode *node,  std::string prefix) { 
    if (!node) return;
    std::cout << prefix << " -> Count: " << node->cnt << std::endl;
    for (int i = 0; i < 26; ++i) {
      if (node->nxt[i]) {
        char nextChar = 'a' + i;
        printTrie(node->nxt[i], prefix + nextChar);
      }
    }
  }
}trie; 

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif 
    int n, q; 
    cin >> n >> q; 
    // vector<string> a(n);
    for(int i = 0; i<n; i++) {
      string s; 
      cin >> s;  
      trie.inset(s); 
    } 
    while ( q-- ){
      string s;
      cin >> s; 
      cout << trie.query(s) << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define getbit(x,i) (((x)&(1ll<<(i))) != 0)
#define pii pair<int,int>
#define ll long long

struct TRIE{
  struct TrieNode{
    TrieNode* nxt[26];
    int cnt = 0; 
    bool flag = false; 
    TrieNode(){
      memset(nxt, 0, sizeof nxt); 
      cnt = 0;
      flag = false; 
    }
  }*root;
  TRIE(){
    root = new TrieNode();
  }
  void inset(string s){
    TrieNode* node = root;
    for(char ch: s ){
      if(!node->nxt[ch - 'a']){
        node->nxt[ch-'a'] = new TrieNode();
      }
      node = node->nxt[ ch-'a']; 
      node->cnt++; 
    }
    node->flag = true; 
  }
  pair<string,int> queryList(TrieNode* node, string s,pair<string,int> &list){
    if(node->flag && list.second<=node->cnt){
      // cout << s << " " << node->cnt << " " << node->flag << endl; 
      list = {s, node->cnt}; 
    }
    for(int i = 0; i<26; i++){
      if (node->nxt[i]){
        char ch = 'a' + i;
        queryList(node->nxt[i], s + ch, list); 
      }
    }
    return list;
  }
  void query(string s){
    TrieNode* node = root; 
    string ans = s;
    for( char ch: s){
      if( !node->nxt[ch-'a'] ){
        cout << -1 << endl;
        return;
      }
      node = node->nxt[ch-'a'];
    }
    pair<string,int> list; 
    list = queryList(node, s, list);  
    cout << list.first << " " << list.second << endl; 
  }
  void printTrie(TrieNode *node,  std::string prefix) { 
    if (!node) return;
    if(node->flag) std::cout << prefix << " -> Count: " << node->cnt << std::endl;
    for (int i = 0; i < 26; ++i) {
      if (node->nxt[i]) {
        char nextChar = 'a' + i;
        printTrie(node->nxt[i], prefix + nextChar);
      }
    }
  }
}trie; 

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
#endif 
    int n, q; 
    cin >> n; 
    // vector<string> a(n);
    for(int i = 0; i<n; i++) {
      string s; 
      cin >> s;  
      trie.inset(s); 
    } 
    cin >> q; 
    while ( q-- ){
      string s;
      cin >> s; 
      trie.query(s);
      // cout << ans.first  << endl;
    }
    return 0;
}
// https://www.spoj.com/problems/ADAINDEX/