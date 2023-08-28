/*This program of converting an infix expression to a postfix expression is an implementation of Stack data structure.*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int stack_precedence(char ch){
    if(ch == '+' || ch == '-')
        return 2;
    else if (ch == '*' || ch == '/')
        return 4;
    else if(ch == '$' || ch == '^')
        return 5;
    else if(isalnum(ch))
        return 8;
    else if(ch == '(')
        return 0;
    else if(ch == '#')
        return -1;
    else return INT_MIN;
}

int input_precedence(char ch){
    if(ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 3;
    else if(ch == '$' || ch == '^')
        return 6;
    else if(isalnum(ch))
        return 7;
    else if(ch == '(')
        return 9;
    else if(ch == ')')
        return 0;
    else return INT_MIN;
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
    printf("\nPostfix form of %s is:\n%s\n", infix, postfix);
}

int main(){
    system("cls");
    char infix_exp[30];
    char postfix_exp[30];
    printf("Enter the infix expression: !!Warning. Do not use any whitespaces!!\n");
    scanf("%s", infix_exp);
    infixtopostfix(infix_exp, postfix_exp);
    return 0;
}