
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
//    if ( b == 0 ) return a;
//    else return gcd(b, a%b);

    return b==0? a:gcd(b,a%b);
}

int lcm( int a, int b) {
    return ( a/__gcd(a,b))*b;
}

int main() {
    //filein;
    int a, b;
    cin>>a >>b;
    int y = gcd ( a , b);
    cout<<y<<endl;
    int x = lcm( a, b);
    cout<<x<<endl;
    return 0;
}
