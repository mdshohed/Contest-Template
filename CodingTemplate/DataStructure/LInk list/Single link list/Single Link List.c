#include<stdio.h>
#include<stdlib.h>

#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

struct listNode{
    int item ;
    struct listNode *next ;
};

struct listNode *head ;
int length;

void initializeList(){
    head = 0 ;
    length=0;
}

int insertItemBegin(int item){
    struct listNode * newNode;
    newNode = (struct listNode*) malloc (sizeof(struct listNode));
    newNode->item = item;
    newNode->next = head;
    head = newNode;
    length++;
    return SUCCESS_VALUE;
}

struct listNode* searchItem(int item){
    struct listNode *temp ;
    temp = head;
    while (temp != 0){
        if (temp->item == item) return temp;
        temp = temp->next;
    }
    return 0;
}

int GetItem(int position){
    if(position<0 || position>=length) return NULL_VALUE;
    struct listNode *temp;
    int count=0;
    temp=head;
    while(count<position){
        temp=temp->next;
        count++;
    }
    return temp->item;
}

void PrintALL(){
    struct listNode *temp;
    temp = head ;
    while (temp != 0){
        printf("%d ",temp->item);
        temp = temp->next ;
    }
    printf("\n");
}

int deleteFirstOccurrence(int item){
    struct listNode *temp, *prev ;
    temp = head;
    while (temp != 0){
        if (temp->item == item) break;
        prev = temp;
        temp = temp->next;
    } 
    if (temp == 0) return NULL_VALUE;
    if (temp == head) {
        head = head->next;
        free(temp);
    }
    else{
        prev->next = temp->next;
        free(temp);
    }
    length--;
    return SUCCESS_VALUE ;
}

//Assignment
int insertItemLast(int item){
    struct listNode *newNode;
    newNode = (struct listNode*)malloc(sizeof(struct listNode));
    newNode->item = item;
    newNode->next = 0; 
    if (head==0) {
        head = newNode; 
        length++;
        return SUCCESS_VALUE; 
    }
    struct listNode *temp = head;
    while(temp->next!=0){
        temp = temp->next; 
    }
    temp->next = newNode;
    length++; 
    return SUCCESS_VALUE; 
} // Insert item at the last position of the list

int insertItemAT(int position, int item) {
    if (position<0 || position>length ) return NULL_VALUE;
    struct listNode *newNode = (struct listNode*)malloc(sizeof(struct listNode));
    newNode->item = item;
    newNode->next = 0; 
    if (position==0) {          //position first  
        newNode->next = head;
        head = newNode;  
        length++;
        return SUCCESS_VALUE; 
    }
    struct listNode *temp = head;
    if (position==length) {       //position last  
        while(temp->next!=0) {
            temp = temp->next; 
        }
        temp->next = newNode;
        length++; 
        return SUCCESS_VALUE; 
    }
    struct listNode *prev, *next = head;  
    int cnt = 0;
    while(cnt+1<position) {            //position middle  
        temp = temp->next; 
        cnt++; 
    }
    next = temp->next;
    temp->next = newNode; 
    newNode->next = next;
    length++; 
    return SUCCESS_VALUE; 
}

int NumOfItems(int item){
    struct listNode *temp = head;
    int cnt = 0; 
    while(temp->next!=0) {
        temp = temp->next;
        if(temp->item==item) cnt++; 
    }
    return cnt;
}//return the number of the occurrence of the given item

int deleteALLOccurrence(int item){
    struct listNode *temp = head, *prev;
    while(temp->item==item) {
        head = head->next;
        free(temp);
        temp = head; 
        length--; 
    }
    while(temp->next!=0) {
        if (temp->next->item==item) {
            prev = temp->next;
            temp->next = prev->next;
            free(prev);
            length--; 
        }
        else {
            temp = temp->next;  
        }
    }
    return SUCCESS_VALUE; 
}// Delete all the occurrence of the given item in the list with preserving order

int deleteLastOccurrence(int item) {
    struct listNode *prev, *temp = head;
    if (head->next==0) {
        if (head->item==item) {
            head = head->next; 
            free(temp); 
            length--; 
            return SUCCESS_VALUE; 
        }
    }
    else {
        int cnt = 0; 
        if (head->item==item) cnt++; 
        while(temp->next!=0) {
            if (temp->next->item==item) {
                prev = temp;
                cnt++; 
            }
            temp = temp->next; 
        }
        if(cnt==1 && head->item==item) {
            temp = head; 
            head = head->next;
            length--; 
            free(temp);  
        }
        else if(cnt>1) {
            struct listNode *temp2 = prev->next; 
            prev->next = temp2->next;
            length--; 
            free(temp2);
        } 
        return SUCCESS_VALUE;
    }
}// Delete the last occurrence of the given item in the list

int deleteFirstItem(){
    struct listNode *temp = head; 
    head = head->next;
    free(temp); 
    length--; 
    return SUCCESS_VALUE; 
} // delete the first item of the list

int deletelastItem(){
    struct listNode *temp = head;
    if(temp->next==0) {
        head = head->next; 
        free(temp);
        return SUCCESS_VALUE; 
    }
    while(temp->next->next!=0) {
        temp = temp->next; 
    }
    struct listNode *deletelast = temp->next;
    temp->next = 0;
    free(deletelast); 
    length--; 
    return SUCCESS_VALUE;  
}// delete the last item of the list

int main(){

    char inp1, chk;
    int inp2;
    int s;
    initializeList();
    while(1){
        scanf("%c",&inp1);
        switch(inp1){
        case 'I':
            scanf("%d",&inp2);
            s=insertItemBegin(inp2);
            break;
        case 'G':
            scanf("%d",&inp2);
            s=GetItem(inp2);
            printf("%d\n",s);
            break;
        case 'S':
            scanf("%d",&inp2);
            printf("Address: %d\n",searchItem(inp2));
            break;
        case 'R'://delete the item of first occurrence
            scanf("%d",&inp2);
            s=deleteFirstOccurrence(inp2);
            break;
        case 'P':
            PrintALL();
            break;
        case 'L':
            printf("Length: %d\n",length);
            break;

        //Assignment    
        case 'A':
            scanf("%d",&inp2); 
            s = insertItemLast(inp2);
            printf("After insertItemLast the list: ");
            PrintALL();  
            break; 
        case 'B':
            int position; 
            scanf("%d",&position);
            scanf("%d",&inp2);
            s = insertItemAT(position, inp2);
            printf("After insertItemAT the list: ");
            PrintALL(); 
            break;
        case 'C':
            scanf("%d",&inp2);
            printf("Number of item of the given input: %d\n", NumOfItems(inp2));
            break; 
        case 'D': 
            scanf("%d",&inp2); 
            deleteALLOccurrence(inp2);
            printf("after deleteALLOccurrence the list: "); 
            PrintALL(); 
            break;
        case 'E':
            scanf("%d",&inp2); 
            deleteLastOccurrence(inp2); 
            printf("After deleteLastOccurrence the list: ");
            PrintALL(); 
            break; 
        case 'F': 
            deleteFirstItem();
            printf("After deleteFirstItem the list: "); 
            PrintALL();
            break; 
        case 'Z':
            deletelastItem();
            printf("After deletelastItem the list: ");
            PrintALL();
            break; 
        }
        if(s==NULL_VALUE) break; 
    }
    return 0;
}


/*void initializeList()
int insertItemBegin(int item)
struct listNode* searchItem(int item)
int GetItem(int position)
void PrintALL()
int deleteFirstOccurrence(int item)
int insertItemLast(int item)
int insertItemAT(int position, int item)
int NumOfItems(int item)
int deleteALLOccurrence(int item)
int deleteLastOccurrence(int item) 
int deleteFirstItem()
int deletelastItem()*/

/*
input:
A 10
A 20 
A 30 
A 40
A 50 
A 60
A 70
A 70
A 80
A 90
P
A 100
B 1 15
C 70
D 70
E 15
F
Z
D 90
L
0

Output: 
After insertItemLast the list: 10 
After insertItemLast the list: 10 20 
After insertItemLast the list: 10 20 30 
After insertItemLast the list: 10 20 30 40 
After insertItemLast the list: 10 20 30 40 50 
After insertItemLast the list: 10 20 30 40 50 60 
After insertItemLast the list: 10 20 30 40 50 60 70 
After insertItemLast the list: 10 20 30 40 50 60 70 70 
After insertItemLast the list: 10 20 30 40 50 60 70 70 80 
After insertItemLast the list: 10 20 30 40 50 60 70 70 80 90 
10 20 30 40 50 60 70 70 80 90 
After insertItemLast the list: 10 20 30 40 50 60 70 70 80 90 100 
After insertItemAT the list: 10 15 20 30 40 50 60 70 70 80 90 100 
Number of item of the given input: 2
after deleteALLOccurrence the list: 10 15 20 30 40 50 60 80 90 100 
After deleteLastOccurrence the list: 10 15 20 30 40 50 60 80 90 100 
After deleteFirstItem the list: 15 20 30 40 50 60 80 90 100 
After deletelastItem the list: 15 20 30 40 50 60 80 90 
after deleteALLOccurrence the list: 15 20 30 40 50 60 80 
Length: 7*/