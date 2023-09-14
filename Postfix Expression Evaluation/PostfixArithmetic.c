//a program to evaluate the value of a postfix expression. eg: 23*54*+9- = 17

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

int eval(char ch, int n1, int n2){
	switch(ch){
		case '+': return n1 + n2;
		case '-': return n1 - n2;
		case '*': return n1 * n2;
		case '/': return n1 / n2;
		case '%': return fmod(n1, n2);
		case '$':
		case '^': return pow(n1, n2);
	}
	return ch - '0';
}

int main(){
	char postfix[30];
	int top, i, n1, n2, n3, stk[30];
	top = -1;
	printf("Enter a postfix expression: ");
	scanf("%s", postfix);
	for(i = 0; i < strlen(postfix); i++){
		if(isdigit(postfix[i]))
			stk[++top] = postfix[i] - '0';
		else{
			n2 = stk[top--];
			n1 = stk[top--];
			n3 = eval(postfix[i], n1, n2);
			stk[++top] = n3;
		}
	}
	printf("The value of the postfix expression is: %d\n", stk[top]);
	
	

	return 0;
}