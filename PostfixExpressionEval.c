#include <stdio.h>
#include <string.h>
#include<ctype.h>
#include <math.h>
#include <stdlib.h>
#include<stdbool.h>

typedef struct{
    int top;
    int arr[100];
} Stack;

void initialize(Stack *st){
    st->top=-1;
}
void push(Stack *st,int elem){
    if(st->top==99){
        // printf("Stack overflow");
        return;
    }
    st->arr[++st->top]=elem;
}
int pop(Stack *st){
    if(st->top==-1){
        // printf("Stack underflow ");
        return -1;
    }
    return st->arr[st->top--];
}
int peek(Stack *st){
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

int postfixEvaluation(char* s){
    Stack st;
    initialize(&st);
    for(int i=1;i<strlen(s)-1;i++){
        if(s[i]==' ' || s[i]=='?'){
            continue;
        }
        else if(isdigit(s[i])){
            int num=0;
            while(isdigit(s[i])){
                num=num*10+(int)(s[i]-'0');
                i++;
            }
            i--;
            push(&st,num);
        }
        else{
            int op2=pop(&st);
            int op1=pop(&st);
            
            switch(s[i]){
                case '+':
                    push(&st,op1+op2);
                    break;
                case '-':
                    push(&st,op1-op2);
                    break;
                case '*':
                    push(&st,op1*op2);
                    break;
                case '/':
                    push(&st,op1/op2);
                    break;
            }
        }
    }
    return pop(&st);
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    scanf("%d",&n);
    while(n--){
        char str[10000]="";
        scanf("%c",&str[0]);
        int i=0;
        while(str[i]!='?'){
            i++;
            scanf("%c",&str[i]);
        }
        printf("%d\n",postfixEvaluation(str));
    }
    return 0;
}
