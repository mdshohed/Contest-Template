#include <bits/stdc++.h>
using namespace std;
typedef struct node Node;
struct node {
    int data;
    Node *left, *right;
};
Node *root;
void insert_node( int x) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = x;
    new_node->left = NULL;
    new_node->right = NULL;
    if ( root == NULL) root = new_node;
    else {
        Node *temp = root;
        while(1) {
            if ( x<=temp->data){
                if ( temp->left == NULL) {
                    temp->left =new_node;
                    break;
                }
                else{
                    temp = temp->left;
                }
            }
            else {
                if (temp->right == NULL) {
                    temp->right = new_node;
                    break;
                }
                else {
                    temp = temp->right;
                }
            }
        }
    }
}

void in_order( Node *node) {

    if ( node==NULL) return ;
    in_order(node->left);
    cout<<node->data<< " ";
    in_order(node->right);
}

int main() {
    root = NULL;
    insert_node(55);
    insert_node(44);
    insert_node(34);
    insert_node(28);
    insert_node(38);
    insert_node(80);
    insert_node(60);
    insert_node(90);
    pre_order(root);
    cout<<endl;
    in_order(root);
    cout<<endl;
    post_order(root);
    return 0;
}

// Another way...
#include <bits/stdc++.h>
using namespace std;

typedef struct node Node;

struct node {
    int data;
    Node *left;
    Node *right;
};

Node *root = NULL;

Node *create_node (int x) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if ( new_node==NULL) {
        exit(1);
    }
    new_node->data = x;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node *insert_node (Node *temp , int x) {
    if( temp==NULL) {
        temp = create_node(x);
    }
    if ( x < temp->data) temp->left = insert_node( temp->left,x);
    else if ( x > temp->data ) temp->right = insert_node( temp->right,x);
    return temp;
}

Node *getSuccessor(Node *node) {
    if(node == NULL){
        return NULL;
    }
    Node *temp = node->right;
    while (temp->left != NULL){
        temp = temp->left;
    }

    return temp;
}

Node *Delete(int data, Node *node){
    if(node == NULL){
        return NULL;
    }
    if(data < node->data){
        node->left = Delete(data, node->left);
    }else if(data > node->data){
        node->right = Delete(data, node->right);
    }else{
        if(node->left == NULL && node->right == NULL){
            return NULL;
        }else if(node->left == NULL || node->right == NULL){
            Node *temp = NULL;
            temp = node->left==NULL?node->right:node->left;
            return temp;
        }else{
            Node *successor = getSuccessor(node);
            node->data = successor->data;
            node->right = Delete(successor->data,node->right);
            return node;
        }
    }
    return node;
}

void inOrder (Node *temp) {
    if( temp==NULL) return;

    inOrder(temp->left);
    cout << temp->data << " ";
    inOrder(temp->right);
}

void preOrder (Node *temp) {

    if( temp==NULL) return;

    cout << temp->data << " ";
    preOrder(temp->left);
    preOrder(temp->right);
}

void post_order (Node *temp) {
    if( temp==NULL) return;

    post_order( temp->left );
    post_order( temp->right );
    cout << temp->data << " ";
}

int main() {
#ifdef _test
    freopen( "in.txt", "r", stdin);
#endif

    int n, x;
    cin >> n;
    for (int i = 0; i<n; i++) {
        cin >> x;
        root = insert_node( root, x);
    }

    inOrder(root);
    cout << '\n';

    preOrder(root);
    cout << '\n';

    post_order(root);
    cout << '\n';
    return 0;
}
