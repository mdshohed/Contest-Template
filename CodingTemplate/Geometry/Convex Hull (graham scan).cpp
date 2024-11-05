#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pairs;

struct point{
    int x, y;
}ara[1000], ans[1000];

stack<point> s;

int dist(point p, point q) {
    return (p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y);
}

int orientation(point p, point q, point r) {
    int val = (q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
    if (val==0 ) return 0;
    return (val>0)? 1:2;
}

bool cmp(point x, point y) {
    int val = orientation(ara[0],x,y);
    if ( val==0) {
        return dist(ara[0],x) < dist(ara[0],y);
    }
    else if (val==2) return true;
    else return false;
}

point nexttop() {
    point val = s.top();
    s.pop();
    point val2 = s.top();
    s.push(val);
    return val2;
}

void convexhull(int n) {
    int ymin = ara[0].y , index = 0;
    for (int i = 1; i<n; i++) {
        if ( (ara[i].y<ymin) || (ara[i].y==ymin&&ara[i].x<ara[index].x)) {
            ymin = ara[i].y;
            index = i;
        }
    }
    swap(ara[0], ara[index]);
    sort(&ara[1],&ara[n],cmp);

    s.push(ara[0]);
    for(int i=1;i<n;i++){
        while(s.size()>1&&orientation(nexttop(),s.top(),ara[i])!=2) s.pop();
        s.push(ara[i]);
    }
    set<pairs> st;
    while(!s.empty()) {
        pairs p = s.top();
        set.insert(p);
        s.pop();
    }
    for (auto &i: st) {
        cout << i.first << " " << i.second << endl;
    }
}

int main() {

    freopen( "in.txt", "r", stdin );
    int n;
    while (cin >> n && n!=0) {
        for (int i = 0; i<n; i++) {
            int x, y;
            cin >> x >> y;
            point a = (x,y);
            ara[i] = {x,y};
        }
        convexhull(n);
    }
    return 0;
}
