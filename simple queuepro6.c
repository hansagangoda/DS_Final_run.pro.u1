//pro6.
#include <stdio.h>
#include <stdlib.h>

#define MAX 5  
int i,found,value,choice,oldValue,newValue;
typedef struct {
    int front, rear, size;
    int queue[MAX];
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = -1;
    q->size = 0;
}

int isFull(Queue* q) {
    return q->size == MAX;
}

int isEmpty(Queue* q) {
    return q->size == 0;
}

void insert(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot insert element.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX;
    }
    q->queue[q->rear] = value;
    q->size++;
    printf("Inserted %d\n", value);
}

void delete(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot delete element.\n");
        return;
    }
    printf("Deleted %d\n", q->queue[q->front]);
    q->front = (q->front + 1) % MAX;
    q->size--;
    if (isEmpty(q)) {
        q->front = q->rear = -1;
    }
}

void modify(Queue* q, int oldValue, int newValue) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot modify element.\n");
        return;
    }
    i = q->front;
    found = 0;
    do {
        if (q->queue[i] == oldValue) {
            q->queue[i] = newValue;
            found = 1;
            break;
        }
        i = (i + 1) % MAX;
    } while (i != (q->rear + 1) % MAX);

    if (found) {
        printf("Modified %d to %d\n", oldValue, newValue);
    } else {
        printf("Element %d not found.\n", oldValue);
    }
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    i = q->front;
    do {
        printf("%d ", q->queue[i]);
        i = (i + 1) % MAX;
    } while (i != (q->rear + 1) % MAX);
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);
    
    choice, value, oldValue, newValue;
    
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Modify\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&q, value);
                break;
            case 2:
                delete(&q);
                break;
            case 3:
                printf("Enter old value: ");
                scanf("%d", &oldValue);
                printf("Enter new value: ");
                scanf("%d", &newValue);
                modify(&q, oldValue, newValue);
                break;
            case 4:
                display(&q);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    
    return 0;
}
