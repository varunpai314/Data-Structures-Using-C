#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


float eval(char op, float num2, float num1){
    switch (op)
    {
    case '+': return num1+num2;
    case '-': return num1-num2;
    case '*': return num1*num2;
    case '/': return num1/num2;
    case '%': return (int)num1% (int)num2;
    case '^': return pow(num1,num2);
    case '$': return pow(num1,num2);    
    default:
        break;
    }
    return INT_MIN;
}


int main(char* argv[]){
    int len = strlen(argv[0]);
    float *st_point = (float*)malloc(len * sizeof(float));
    int top = -1;
    if (st_point == NULL) {
        printf("Memory could not be allocated for the expression.\n");
        exit(0);
    }
    for (int i = 0; i <= len; i++){
        char ch = argv[0][i];
        if(isdigit(ch)){
            st_point[++top] = ch - '0';
        }
        else{
            float result = eval(ch, st_point[top--], st_point[top--]);
            st_point[top] = result;
        }
    }
    float final = st_point[top--];
    if(top == -1){
        printf("%f", final);
    }
    else{
        printf("Invalid Postfix Expression provided!\n");
    }
    return 0;
}