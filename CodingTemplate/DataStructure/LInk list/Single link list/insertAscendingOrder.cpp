#include <bits/stdc++.h>
using namespace std; 

struct node{
    int data; 
    struct node *next;  
}; 

struct node *head;

void insert_node( int x) {
    struct node *temp = new node();
    temp->data = x;
    if ( head == NULL || (temp->data<head->data)) {
        temp->next = head;
        head = temp;
    }
    else {

        struct node *current_node = head->next;
        struct node *previous_node = head;

        while( current_node != NULL && temp->data > current_node->data ) {
            previous_node = current_node;
            current_node = current_node->next;
        }

        previous_node->next = temp;
        temp->next = current_node;
    }
}

void print(){
    struct node *temp = head;
    while(temp!=0) {
        cout << temp->data << " "; 
        temp = temp->next; 
    }
    cout << endl; 
}

int main() {
    
    char a; 
    int b; 
    while(1) {
        cin >> a; 
        int b;
        cin >> b; 
        insert_node(b);
        print(); 
        if (a=='0') break; 
    }

}