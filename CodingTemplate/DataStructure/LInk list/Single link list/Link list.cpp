#include <bits/stdc++.h>
using namespace std;

#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

typedef struct node Node;

struct node{
    int data;
    Node* next;
};

Node* head;
int length;

void initialize() {
    head = 0;
    length = 0;
}

int insertbegin(int x) {
    Node* newnode = new node();
    newnode->data = x;
    newnode->next = head;
    head = newnode;
    length++;
    return SUCCESS_VALUE;
}

int insertlast(int x) {
    Node* newnode = new node();
    newnode->data = x;
    newnode->next = 0;
    if ( head==0) {
        head = newnode;
    }
    else {
        Node* t = head;
        while ( t->next!=0 ) {
            t = t->next;
        }
        t->next = newnode;
    }
}

int insetitem( int position, int x ) {

    Node* newnode = new node();
    newnode->data = x;
    newnode->next = NULL;
    if ( position<1) return NULL_VALUE;
    if ( position==1 ) {
        newnode->next = head;
        head = newnode;
    }
    else {
        Node* temp = head;
        for (int i = 1; i<position-1; i++) {
            if ( temp!=0 ) {
                temp = temp->next;
            }
        }

        if ( temp!=NULL ) {
            newnode->next = temp->next;
            temp->next = newnode;
        }
        else return NULL_VALUE;
    }
    return SUCCESS_VALUE;
}

int numofitem(int x) {
    int cnt = 0;
    Node* temp = head;
    while ( temp!=0) {
        int value = temp->data ;
        if ( value==x) {
            cnt++;
        }
        temp = temp->next;
    }
    return cnt;
}

void deletealloccurrence(int x) {
    Node* temp = head;
    while ( head->data==x ) {
         head = head->next;
    }
    while ( temp->next!=NULL ) {
        if (temp->next->data==x ) {
            temp->next = temp->next->next;
        }
        else {
            temp = temp->next;
        }
    }
}

int deletelastoccurrence(int data) {
    Node* x = NULL;
    Node* temp = head;
    while ( temp!=0 ) {
        if ( temp->data==data ) {
            x = temp;
        }
        temp = temp->next;
    }
    if ( x!=NULL && x->next==NULL) {
        temp = head;
        while ( temp->next!=x) {
            temp = temp->next;
        }
        temp->next = NULL;
    }
    if ( x!=NULL && x->next!=NULL) {
        x->data = x->next->data;
        temp = x->next;
        x->next = x->next->next;
        free(temp);
    }
}

void deletefirstitem() {
    head = head->next;
}

void deletelastitem() {
    Node* temp = head;
    if ( temp->next==0 ) {
        free(head);
    }
    else {
        while ( temp->next->next!=0) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = 0;
    }
}

void print() {
    Node* temp = head;
    while ( temp!=0) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
//    insertbegin(x);
//    insertlast(x);
//    insetitem(position,item);
//    numofitem(x);
//    deletealloccurrence(x);
//    deletelastoccurrence(x)
//    deletefirstitem();
//    deletelastitem();
//    print();

    initialize();

    int n;
    cin >> n;

    for (int i =0; i<n; i++) {
        int x;
        cin >> x;
        insertlast(x);
    }
    print();


    int item;
    cin >> item;
    deletealloccurrence(item);
    print();

    cin >> item;
    deletelastoccurrence(item);
    print();

    //deletefirstitem();
    //deletelastitem();

    print();

    int position;
    cin >> position >> item;
    insetitem(position,item);

    print();

    return 0;
}
