#include<stdio.h>
#include<stdlib.h>

struct node{
    int data; 
    struct node *prev; 
    struct node *next;
};

int length;
struct node *head, *tail; 

void initializeList() {
    head = 0;
    tail = 0;
    length = 0;
}

void insertBegin(int item) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node)); 
    newNode->data = item ;
    newNode->next = head;
    head = newNode;
    newNode->prev = 0; //no previous node as this is the first item
    if ( newNode->next==0 )
        tail = newNode; //this is the first node in the list
    else{
        newNode->next->prev = newNode;
    }
    length++;
} 

void insertLast(int item){
    struct node *newNode = (struct node*)malloc(sizeof(struct node)); 
    newNode->data = item;
    newNode->prev = tail;
    newNode->next = 0;
    tail = newNode;
    if (newNode->prev==0) {
        head = newNode; 
    }
    else {
        newNode->prev->next = newNode; 
    }
}

void printAll(){
    struct node *temp = head;
    while(temp!=0) {
        printf("%d ",temp->data);
        temp = temp->next; 
    }
    printf("\n");  
}

void deleteFirstOccurrence(int item) {
    struct node *temp = head;
    if (length==1) {
        if(head->data==item) {
            head = head->next; 
            free(temp);
            length--;
            return;  
        }
    }
    else {
        struct node *pos = head;
        while(temp!=0) {
            if (temp->data==item) break;
            pos = temp;
            temp = temp->next; 
        }
        if(head->data==item) {
            head = head->next; 
            head->prev = 0;
            free(pos);
            length--;  
            return; 
        }
        else {
            struct node *current = pos->next;
            if (current->next==0) {
                pos->next = 0;
                tail = pos;
            }
            else {
                pos->next = current->next;
                current->next->prev = current->prev;
            }
            free(current);
            return;   
        } 
    }
}

void deleteLastOccurrence(int item) {
    struct node *temp = tail;
    if (length==1) {
        if (temp->data==item) {
            tail = tail->prev;
            free(temp);
            return;
        }
    }
    else {
        struct node *pos = tail;
        while( temp!=0 ) {
            if (temp->data==item ) break; 
            pos = temp; 
            temp = temp->prev; 
        }
        if ( tail->data==item ) {
            tail = tail->prev;
            tail->next = 0;
            free(pos); 
            length--;
            return; 
        }
        else {
            struct node *current = pos->prev;
            if(current->prev==0) {
                pos->prev = 0;
                head = pos; 
            }
            else {
                pos->prev = current->prev;
                current->prev->next = current->next; 
            }
            free(current);
            return;  
        }
    }
}

void deleteFirstItem() {
    struct node *temp = head;
    if (head==0) return;
    else {
        head = head->next;
        head->prev = 0; 
        free(temp);  
    }
    length--; 
}

void deleteLastItem(){
    struct node *temp = tail;
    if(tail==0) return;
    else {
        tail = tail->prev;
        tail->next = 0; 
        free(temp); 
    }
    length--; 
}

int main() {
    freopen("in.txt", "r", stdin ); 

    char a;
    int b; 
    while(1) {
        scanf("%c",&a); 
        switch(a) {
            case 'A':
                int b; 
                scanf("%d",&b);  
                insertBegin(b);
                break; 
            case 'B':
                scanf("%d",&b); 
                insertLast(b);
                break; 
            case 'C': 
                printAll();
                break; 
            case 'D': 
                deleteFirstItem(); 
                break;
            case 'E':
                deleteLastItem();
                break; 
            case 'F': 
                scanf("%d",&b); 
                deleteFirstOccurrence(b);
                break;  
            case 'G':
                scanf("%d",&b); 
                deleteLastOccurrence(b);
                break;
        }
        if(a=='0') break; 
    }
    return 0; 
}

/*void initializeList()
void insertBegin(int item)
void insertLast(int item)
void printAll()
void deleteFirstOccurrence(int item)
void deleteLastOccurrence(int item)
void deleteFirstItem() 
void deleteLastItem()*/