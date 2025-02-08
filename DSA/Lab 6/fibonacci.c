#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;  
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);  
    }
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Fibonacci is not defined for negative numbers.\n");
    } else {
        printf("Fibonacci number at position %d is %d\n", num, fibonacci(num));
    }

    return 0;
}
