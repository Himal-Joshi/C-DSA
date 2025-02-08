#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int returnPrecedence(char c){

    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}



void infixToPostFix(char* exp) {
    int len = strlen(exp);
    char* result = (char*)malloc((len + 1) * sizeof(char)); // Dynamic allocation
    char* stack = (char*)malloc(len * sizeof(char));        // Dynamic allocation
    int top = -1;
    int j = 0;

    if (!result || !stack) {
        printf("Memory allocation failed!\n");
        free(result);
        free(stack);
        return;
    }

    for (int i = 0; i < len; i++) {
        char current = exp[i];
        
        if ((current >= 'a' && current <= 'z') || 
            (current >= 'A' && current <= 'Z')) {
            result[j++] = current;
        }
        else if (current == '(') {
            stack[++top] = current;
        }
        else if (current == ')') {
            while (top != -1 && stack[top] != '(') {
                result[j++] = stack[top--];
            }
            if (top != -1){ 
                top--;
            }
        }
        else {
            while (top != -1 && 
                    returnPrecedence(current) <= returnPrecedence(stack[top])) {
                result[j++] = stack[top--];
            }
            stack[++top] = current;
        }
    }

    while (top != -1) {
        result[j++] = stack[top--];
    }

    result[j] = '\0';
    printf("Postfix Expression: %s\n", result);
    
    free(result);
    free(stack);
}

int main() {
    char exp[50];
    printf("Enter the infix expression: ");
    scanf("%s", exp);
    infixToPostFix(exp);
    return 0;
}