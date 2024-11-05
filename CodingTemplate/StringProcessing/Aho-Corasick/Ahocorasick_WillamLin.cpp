struct {
    int next[mxM][26],d[mxM][26], sl[mxM],ol[mxM], de[mxM], m = 1;

    void ins(string s) {
        int u = 0;
        for (char a: s) {
            if(!next[u][a-'a']) {
                next[u][a-'a'] = m++;
            }
            u = next[u][a-'a'];
        }
        ol[u] = u;
    }
    void ac() {
        queue<int> qu;
        qu.push(0);
        while (!qu.empty()) {
            int u = qu.front();
            qu.pop();
            for(int i=0; i<26; i++) {
                int v = next[u][i];
                if (v) {
                    de[v] = de[u]+1;
                    sl[v] = d[sl[u]][i];
                    if (!ol[v]) {
                        ol[v] = ol[sl[v]];
                    }
                    d[u][i] = v;
                    qu.push(v);
                }
                else {
                    d[u][i] = d[sl[u]][i];
                }
            }
        }
    }
}ac;
