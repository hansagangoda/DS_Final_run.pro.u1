//pro5.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 10
int i,k,strcspn,symbol;

typedef struct {
    int top;
    char items[MAX];
} Stack;


void initStack(Stack* s);
int isEmpty(Stack* s);
int isFull(Stack* s);
void push(Stack* s, char c);
char pop(Stack* s);
char peek(Stack* s);
int precedence(char op);
void infixToPostfix(char* infix, char* postfix);

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);

    
   
    infixToPostfix(infix, postfix);
    
    printf("Postfix expression: %s\n", postfix);

    return 0;
}


void initStack(Stack* s) {
    s->top = -1;
}


int isEmpty(Stack* s) {
    return s->top == -1;
}


int isFull(Stack* s) {
    return s->top == (MAX - 1);
}


void push(Stack* s, char c) {
    if (isFull(s)) {
        printf("Stack is full. Cannot push element %c\n", c);
        return;
    }
    s->items[++(s->top)] = c;
}


char pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop element\n");
        return '\0';  
    }
    return s->items[(s->top)--];
}

char peek(Stack* s) {
    if (isEmpty(s)) {
        return '\0';  
    }
    return s->items[s->top];
}


int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}


void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    initStack(&s);

    i = 0, k = 0;
    
    
    while ((symbol = infix[i++]) != '\0') {
        if (isspace(symbol)) {
            continue; 
        }
        
        if (isalnum(symbol)) {
            postfix[k++] = symbol;  
        } else if (symbol == '(') {
            push(&s, symbol);  
        } else if (symbol == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);  
            }
            pop(&s);  
        } else {  
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(symbol)) {
                postfix[k++] = pop(&s);  
            }
            push(&s, symbol);  
        }
    }
    
    
    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }
    
    postfix[k] = '\0';  
}
