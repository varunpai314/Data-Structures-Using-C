/*This program of converting an infix expression to a postfix expression is an implementation of Stack data structure.*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int stack_precedence(char ch){
    switch (ch)
    {
    case '+':
    case '-': return 2;
    case '*':
    case '%':
    case '/': return 4;
    case '$':
    case '^': return 5;
    case '(': return 0;
    case '#': return -1;    
    default:
        return 8;
    }
}

int input_precedence(char ch){
    switch(ch){
        case '+':
        case '-': return 1;
        case '*':
        case '%':
        case '/': return 3;
        case '$':
        case '^': return 6;
        case '(': return 9;
        case ')': return 0;
        default: return 7;
    }
}

void infixtopostfix(char infix[], char postfix[]){
    int i, j, top;
    char stk[30], symbol;
    top = -1;
    j = 0;
    stk[++top] = '#';
    for(i = 0; i < strlen(infix); i++){
        symbol = infix[i];
        while(stack_precedence(stk[top]) > input_precedence(symbol))
            postfix[j++] = stk[top--];
        if(stack_precedence(stk[top]) != input_precedence(symbol))
            stk[++top] = symbol;
        else
            top--;
    }
    while(stk[top] != '#')
        postfix[j++] = stk[top--];
    postfix[j] = '\0';
    
}

int main(){
    system("cls");//not necessary. Just for clearing the screen.
    char infix_exp[30];
    char postfix_exp[30];
    printf("Enter the infix expression: !!Warning. Do not use any whitespaces!!\n");
    scanf("%s", infix_exp);
    infixtopostfix(infix_exp, postfix_exp);
    printf("\nPostfix form of `%s` is:\n%s\n", infix_exp, postfix_exp);
    return 0;
}