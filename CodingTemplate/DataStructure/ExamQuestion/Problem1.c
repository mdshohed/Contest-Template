#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define stack_max_size 100
#define null_value -9999
#define success_value 9999

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* head;
struct node* tail;
int top;

void initaializeStack() {
    top = 0;
    head = tail = 0;
}

int push(int item) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = item;
    newNode->next = 0;
    newNode->prev = tail;
    tail = newNode;
    if(newNode->prev==0) {
        head = newNode;
    }
    else {
        newNode->prev->next = newNode;
    }
    top++;
    return success_value;
}


int pop() {
    if(top==0) return null_value;
    struct node* temp = tail;
    int item = tail->data;
    if(tail->prev==0) {
        tail = tail->prev;
        head = tail;
        free(tail);
    }
    else {
        tail = tail->prev;
        tail->next = 0;
        free(temp);
    }
    top--;
    return item;
}


int main() {
    freopen( "in.txt", "r", stdin );

    char s[100];
    gets(s);
    int sign = 1, number = 0, flag = 0, operand; 
    for(int i = 0; i<strlen(s); i++) {
        if (s[i]=='-') {
            sign = -1;
            continue;
        }
        if( s[i]>='0' && s[i]<='9') {
            number = number*10 + s[i] - '0';
            flag = 1; 
            continue;
        }
        if(s[i]==' ' && flag==1) {
            if (sign==-1 ) number*=sign;  
            push(number); 
            number = 0;
            sign = 1; 
            flag = 0; 
            continue;
        }
        if(s[i]=='-' || s[i]=='+' || s[i]=='*' || s[i]=='/') {
            int val2 = pop();
            int val = pop();
            if (s[i]=='+') {
                operand = val + val2;  
                push(operand); 
            }
            else if (s[i]=='-') {
                operand = val - val2; 
                push(operand);  
            }
            else if(s[i]=='*') {
                operand = val * val2;
                push(operand); 
            }
            else if(s[i]=='/') {
                operand = val / val2;
                push(operand);  
            }
            continue; 
        } 
    }
    int answer = pop(); 
    printf("%d\n", answer); 
 
}

/*input:
5 12 * 50 - 20 +

output:
30*/
