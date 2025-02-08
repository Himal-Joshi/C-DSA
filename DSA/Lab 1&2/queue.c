//queue

#include <stdio.h>

#define MAXSIZE 10
int queue[MAXSIZE];
int front = -1;
int rear = -1;

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return (rear == MAXSIZE - 1);
}

void enqueue(int num) {
    if (isFull()) {
        printf("Queue Overflow! Could not insert %d\n", num);
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = num;
        printf("%d enqueued to queue.\n", num);
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Could not retrieve element.\n");
        return -1;
    } else {
        int num = queue[front];
        front++;
        if (front > rear) {
            front = rear = -1;
        }
        return num;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue to the queue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                value = dequeue();
                if (value != -1) {
                    printf("Dequeued element: %d\n", value);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
