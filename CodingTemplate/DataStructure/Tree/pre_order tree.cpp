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
void pre_order( Node *node) {
    if ( node == NULL) return;
    cout<<node->data<<" ";
    pre_order(node->left);
    pre_order(node->right);
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
    return 0;
}
