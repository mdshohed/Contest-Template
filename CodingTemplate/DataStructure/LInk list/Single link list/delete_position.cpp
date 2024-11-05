#include<bits/stdc++.h>
using namespace std;
typedef struct node Node;
struct node{
    int data;
    Node *next;
};
Node *head;
void insert_node( int x) {
    Node *new_node = new node();
    new_node->data = x;
    new_node->next = NULL;
    if ( head == NULL) head = new_node;
    else {
        Node *temp = head;
        while( temp->next!=NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}
void delete_position(int position) {
    Node *new_node = head;
    if ( position == 1) {
        head = new_node->next;
        free(new_node);
    }
    else {
            Node *t = head;
        for ( int i = 1; i<= position-2 ; i++) {
            t = t->next;
        }
        Node *temp2 = t->next;
        t->next = temp2->next;
        free(t);
    }
}
void print() {
    Node *t = head;
    while ( t!=NULL) {
        cout<<t->data<<" ";
        t = t->next;
    }
    cout<<endl;
}
int main() {
    head = NULL;
    insert_node( 5);
    insert_node( 7);
    insert_node( 9);
    insert_node( 2);
    insert_node( 100);
    print();
    delete_position(2);
    print();
    return 0;
}
