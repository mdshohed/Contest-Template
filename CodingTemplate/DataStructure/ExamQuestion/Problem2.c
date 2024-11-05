#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

struct node {
    char item; 
    struct node* next;
}; 

struct node* left, *right;
int length = 0; 

void initialize(){
    left = right = 0;
}

int insertBegin(int item){
    struct node * newNode;
    newNode = (struct node*) malloc (sizeof(struct node));
    newNode->item = item;
    newNode->next = left;
    left = newNode;
    length++;
    return SUCCESS_VALUE; 
} 

int insertLast(int item){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->item = item;
    newNode->next = 0; 
    if (right==0) {
        right = newNode; 
        length++;
        return SUCCESS_VALUE; 
    }
    struct node *temp = right;
    while(temp->next!=0){
        temp = temp->next; 
    }
    temp->next = newNode;
    length++; 
    return SUCCESS_VALUE; 
}

bool printAll() {
    struct node* temp = left; 
    struct node* temp2 = right; 

    while (temp2!=0) {
        if (temp->item != temp2->item) {
            return 0; 
        }
        temp = temp->next; 
        temp2 = temp2->next; 
    }
    return 1;   
}

int main() {
    // freopen("in.txt", "r", stdin ); 


    initialize(); 
    
    char s[100]; 
    scanf("%s", s);
    for(int i = 0; i<strlen(s); i++){
        insertBegin(s[i]);
        insertLast(s[i]); 
    }
    int answer = printAll(); 
    if (answer){
        printf("Palindrome\n");
    }
    else {
        printf("Not Palindrome\n");
    }
    return 0;
}
