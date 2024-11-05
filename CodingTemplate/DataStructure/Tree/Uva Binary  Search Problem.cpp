#include <bits/stdc++.h>

using namespace std;

typedef struct node Node;

struct node {
    int data;
    Node *left;
    Node *right;
};

Node *root = nullptr;

Node *create(int x ) {
    Node *val = new node;
    if ( val==nullptr) {
        exit(1);
    }
    val->data = x;
    val->left = nullptr;
    val->right = nullptr;
    return val;
}

Node *insertnode(Node *temp, int x ) {
    if ( temp==nullptr ) {
        temp = create( x);
    }
    if ( x< temp->data ) {
        temp->left = insertnode(temp->left, x);
    }
    else if ( x>temp->data) {
        temp->right = insertnode(temp->right,x);
    }
    return temp;
}

void post_order (Node *temp) {
    if( temp==NULL) return;

    post_order( temp->left );
    post_order( temp->right );
    cout << temp->data << endl ;
}

int main() {
    //freopen ( "in.txt", "r", stdin );

    int n;
    while (cin >> n ) {
        root = insertnode ( root, n);
    }
    post_order (root );
}
