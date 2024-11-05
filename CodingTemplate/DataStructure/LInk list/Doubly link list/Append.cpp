
#include <bits/stdc++.h>
using namespace std;

typedef struct node Node;

struct node
{
    int data;
    Node *next, *prev;
};

Node *head, *tail;

void insert_node(int x)
{
    Node *new_node = new node();
    new_node->data = x;
    if (head == NULL)
    {
        new_node->next = NULL;
        new_node->prev = NULL;
        head = new_node;
        tail = head;
    }
    else
    {
        new_node->prev = tail;
        tail->next = new_node;
        new_node->next = NULL;
        tail = new_node;
    }
}

void print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        insert_node(x);
    }
    print();
    return 0;
}
