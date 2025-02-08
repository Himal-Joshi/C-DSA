#include <stdio.h>

int moveCount = 0; 

void toh(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        moveCount++;
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    toh(n - 1, source, destination, auxiliary);  
    moveCount++;
    printf("Move disk %d from %c to %c\n", n, source, destination);  
    toh(n - 1, auxiliary, source, destination);  
}

int main() {
    int num;

    printf("Enter the number of disks: ");
    scanf("%d", &num);

    toh(num, 'A', 'B', 'C'); 
    printf("Total moves required: %d\n", moveCount);
    return 0;
}
