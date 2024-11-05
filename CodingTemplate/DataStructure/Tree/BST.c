#include <bits/stdc++.h>
using namespace std;

struct treeNode{
    int item; 
    struct treeNode* left;
    struct treeNode* right;
}; 

struct treeNode* root;

void initializeTree() {
    root = 0; 
}

bool insert(int item) {
    struct treeNode* newNode;
    newNode = (struct treeNode*)malloc(sizeof(struct treeNode));
    newNode->item = item; 
    newNode->left = 0; 
    newNode->right = 0; 
    root = newNode; 
    return true;
}

bool insertItem(struct treeNode* node, int item) {
    if( node->item==item ) return false; 
    if (item < node->item && node->left==0 ){
        struct treeNode* newNode;
        newNode = (struct treeNode*)malloc(sizeof(struct treeNode)); 
        newNode->item = item;
        newNode->left = 0; 
        newNode->right = 0;
        node->left = newNode;
        return true; 
    }
    if (item > node->item && node->right==0){
        struct treeNode* newNode;
        newNode = (struct treeNode*)malloc(sizeof(struct treeNode)); 
        newNode->item = item;
        newNode->left = 0; 
        newNode->right = 0;
        node->right = newNode;
        return true; 
    }
    int status; 
    if( item < node->item ) {
        status = insertItem(node->left, item); 
    }
    else {
        status = insertItem(node->right, item);
    }
    return status; 
}

void printInorder(struct treeNode* node) {
    if(node==0) return;
    printInorder(node->left);
    printf("%d ", node->item); 
    printInorder(node->right); 
}

void printPreorder(struct treeNode* node) {
    if(node==0) return; 
    printf("%d ", node->item); 
    printPreorder(node->left); 
    printPreorder(node->right); 
}

void printPostOrder(struct treeNode* node) {
    if(node==0) return;  
    printPreorder(node->left); 
    printPreorder(node->right); 
    printf("%d ", node->item);
}


int main() {
    // freopen("in.txt", "r", stdin ); 

    int n; 
    cin >> n; 
    for(int i = 0; i<n; i++) {
        int x; scanf("%d", &x); 
        if( root==0 ) {
            insert(x);
        } 
        else {
            insertItem(root, x);
        }
    }
    printPostOrder(root); 
    return 0;  
}
