/**
    problem: ...
    algorithm: Stack
*/

/// Implementation of c language...

#include<bits/stdc++.h>
using namespace std;

#define MAX 100

typedef struct {
    int top;
    int data[MAX];
}stack1;

void push( stack1 *s, int item)
{
    if ( s->top < MAX ) {
        s->data[s->top] = item;
        s->top = s->top+1;
    }
    else {
        cout<<"stack in full"<<endl;
    }
}

int pop(stack1 *s)
{
    int item;
    if ( s->top == 0) {
        cout<<"stack is empty"<<endl;
        return -1;
    }
    else {
        s->top = s->top-1;
        item = s->data[s->top];
    }
    return item;
}

int main(){
    
    stack1 my_stack;
    int item;
    my_stack.top = 0;
    push(&my_stack, 1);
    push(&my_stack, 2);
    push(&my_stack, 3);

    item = pop(&my_stack);
    cout<<item<<endl;

    item = pop(&my_stack);
    cout<<item<<endl;

    item = pop(&my_stack);
    cout<<item<<endl;

    return 0;
}


/// Implementation of c++ language...

#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    while( !st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}

