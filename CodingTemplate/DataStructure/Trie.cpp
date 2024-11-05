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
      node->flag = false; 
    }
    node->flag = true; 
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
    string mostFrequentWord = "";
    int maxCount = 0; 
     function<void(TrieNode*, string)> findMostFrequent = [&](TrieNode* currNode, string prefix) {
      if (currNode->flag) {
        if (currNode->cnt > maxCount || (currNode->cnt == maxCount && prefix < mostFrequentWord)) {
          mostFrequentWord = prefix;
          maxCount = currNode->cnt;
        }
      }
      for (int i = 0; i < 26; i++) {
        if (currNode->nxt[i]) {
          findMostFrequent(currNode->nxt[i], prefix + char('a' + i));
        }
      }
    };
    findMostFrequent(node, s);
    cout << mostFrequentWord << " " << maxCount << endl; 
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
    }
    return 0;
}