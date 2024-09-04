//program 8.implement circular queue,1.insert,2.delete,3.modify,4.display.
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
int choice,item,position,newValue,i;  
typedef struct {
    int items[SIZE];
    int front, rear;
} CircularQueue;


void initialize(CircularQueue* cq);
int isEmpty(CircularQueue* cq);
int isFull(CircularQueue* cq);
void insert(CircularQueue* cq, int item);
void delete(CircularQueue* cq);
void modify(CircularQueue* cq, int position, int newValue);
void display(CircularQueue* cq);
void menu();

int main() {
    CircularQueue cq;
    initialize(&cq);

    choice, item, position, newValue;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to insert: ");
                scanf("%d", &item);
                insert(&cq, item);
                break;
            case 2:
                delete(&cq);
                break;
            case 3:
                printf("Enter the position to modify (0-based index): ");
                scanf("%d", &position);
                printf("Enter the new value: ");
                scanf("%d", &newValue);
                modify(&cq, position, newValue);
                break;
            case 4:
                display(&cq);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void initialize(CircularQueue* cq) {
    cq->front = -1;
    cq->rear = -1;
}

int isEmpty(CircularQueue* cq) {
    return cq->front == -1;
}

int isFull(CircularQueue* cq) {
    return (cq->rear + 1) % SIZE == cq->front;
}

void insert(CircularQueue* cq, int item) {
    if (isFull(cq)) {
        printf("Queue is full. Cannot insert.\n");
    } else {
        if (isEmpty(cq)) {
            cq->front = 0;
        }
        cq->rear = (cq->rear + 1) % SIZE;
        cq->items[cq->rear] = item;
        printf("Inserted %d\n", item);
    }
}

void delete(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty. Cannot delete.\n");
    } else {
        int item = cq->items[cq->front];
        if (cq->front == cq->rear) {
            cq->front = cq->rear = -1;
        } else {
            cq->front = (cq->front + 1) % SIZE;
        }
        printf("Deleted %d\n", item);
    }
}

void modify(CircularQueue* cq, int position, int newValue) {
    if (isEmpty(cq)) {
        printf("Queue is empty. Cannot modify.\n");
    } else {
        int index = cq->front;
        for (i = 0; i < SIZE; i++) {
            if (index == cq->rear) {
                break;
            }
            if (i == position) {
                cq->items[index] = newValue;
                printf("Modified position %d to %d\n", position, newValue);
                return;
            }
            index = (index + 1) % SIZE;
        }
        printf("Invalid position. Cannot modify.\n");
    }
}

void display(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty.\n");
    } else {
        int index = cq->front;
        while (1) {
            printf("%d ", cq->items[index]);
            if (index == cq->rear) {
                break;
            }
            index = (index + 1) % SIZE;
        }
        printf("\n");
    }
}

void menu() {
    printf("Circular Queue Menu\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Modify\n");
    printf("4. Display\n");
    printf("5. Exit\n");
}
