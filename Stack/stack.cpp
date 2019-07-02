#include<bits/stdc++.h>
#define STACK_MAX 1000
using namespace std;
typedef struct{
    int top;
    int data[STACK_MAX];

}Stack;

void push(Stack *s, int item)
{
    if(s->top < STACK_MAX)
    {
        s->data[s->top] = item;
        s->top = s->top + 1;
    }else{
        cout << "Stack is full!\n";
    }

}

int pop(Stack *s)
{
    int item = 0;
    if(s->top == 0)
    {
        cout << "Stack is empty\n";
        return -1;
    }else{
        s->top -= 1;
        item = s->data[s->top];
    }
    return item;
}

void print(Stack *s)
{
    while(s->top > 0)
    {
        cout << pop(s) << endl;
    }
}

int main()
{
    Stack my_stack;
    int item;
    my_stack.top = 0;

    push(&my_stack, 1);
    push(&my_stack, 3);
    push(&my_stack, 2);

    //cout << pop(&my_stack) << endl;
    print(&my_stack);
    return 0;
}
