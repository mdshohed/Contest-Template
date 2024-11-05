queue i/o c++ code...

#include<bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> q;
    int n,x;
    cin>>n;
    for(int i = 0; i<n; i++) {
     cin>>x;
     q.push(x);
    }
    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}

queue sum function....

#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int> q;
    int sum(0);
    int n;
    cin>>n;
    for( int i = 1; i<=n; i++) q.push(i);
    while(!q.empty()) {
        sum +=q.front();
        q.pop();
    }
    cout<<sum<<endl;
    return 0;
}


/// priority_queue in c++ function....
#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int> q;
    int sum(0);
    int n;
    cin>>n;
    for( int i = 1; i<=n; i++) q.push(i);
    while(!q.empty()) {
        sum +=q.front();
        q.pop();
    }
    cout<<sum<<endl;
    return 0;
}

