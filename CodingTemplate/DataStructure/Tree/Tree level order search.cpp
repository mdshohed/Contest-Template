#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left_child;
    node *right_child;
};

node* newNode(int n)
{
    node *new_node = new node();
    new_node->data = n;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    return new_node;
}

void level_order_traversal(node *n)
{
    queue<node*> q;
    q.push(n);
    while( !q.empty()) {
        node *temp  = q.front();
        q.pop();
        if ( temp->left_child != NULL ) {
            q.push(temp->left_child);
        }
        if ( temp->right_child != NULL ){
            q.push( temp->right_child );
        }
        cout << temp->data << " ";
    }
    cout << endl;
}

int main()
{
    node *root = newNode(2);
    root->left_child = newNode(7);
    root->right_child = newNode(5);
    root->left_child->left_child = newNode(2);
    root->left_child->right_child = newNode(6);
    root->left_child->right_child->left_child = newNode(5);
    root->left_child->right_child->right_child = newNode(11);
    root->right_child->right_child = newNode(9);
    root->right_child->right_child->left_child = newNode(4);


    cout << "Level order traversal: ";
    level_order_traversal(root);

    return 0;
}
