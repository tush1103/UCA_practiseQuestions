#include<stdio.h>
#include<stdlib.h>
#define SIZE 10000
typedef struct{
    char arr[SIZE];
    int top;
} Stack;

void initialize(Stack *st){
    st->top=-1;
}
void push(Stack *st,int elem){
    if(st->top==SIZE-1){
        printf("Stack overflow");
        return;
    }
    st->arr[++st->top]=elem;
}
char pop(Stack *st){
    if(st->top==-1){
        printf("Stack underflow");
        return -1;
    }
    return st->arr[st->top--];
}
char peek(Stack *st){
    if(st->top==-1){
        return -1;
    }
    return st->arr[st->top];
}
int isEmpty(Stack *st){
    if(st->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
bool isValid(char* s){
    Stack st;
    initialize(&st);
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            push(&st,s[i]);
        }
        else if(isEmpty(&st)==1){
            return false;
        }
        else if(s[i]==')' && peek(&st)=='('){
            pop(&st);
        }
        else if(s[i]=='}' && peek(&st)=='{'){
            pop(&st);
        }
        else if(s[i]==']' && peek(&st)=='['){
            pop(&st);
        }
        else{
            return false;
        }
    }
    return isEmpty(&st);
}
