#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define maximum size of the deque
int i,actualPosition,count,choice,value,position,newValue;
typedef struct {
    int front, rear, size;
    int deque[MAX];
} Deque;

void initDeque(Deque* dq) {
    dq->front = dq->rear = -1;
    dq->size = 0;
}

int isFull(Deque* dq) {
    return dq->size == MAX;
}

int isEmpty(Deque* dq) {
    return dq->size == 0;
}

void insertFront(Deque* dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full. Cannot insert element at the front.\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX) % MAX;
    }
    dq->deque[dq->front] = value;
    dq->size++;
    printf("Inserted %d at the front\n", value);
}

void insertRear(Deque* dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full. Cannot insert element at the rear.\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX;
    }
    dq->deque[dq->rear] = value;
    dq->size++;
    printf("Inserted %d at the rear\n", value);
}

void deleteFront(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty. Cannot delete element from the front.\n");
        return;
    }
    printf("Deleted %d from the front\n", dq->deque[dq->front]);
    dq->front = (dq->front + 1) % MAX;
    dq->size--;
    if (isEmpty(dq)) {
        dq->front = dq->rear = -1;
    }
}

void deleteRear(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty. Cannot delete element from the rear.\n");
        return;
    }
    printf("Deleted %d from the rear\n", dq->deque[dq->rear]);
    dq->rear = (dq->rear - 1 + MAX) % MAX;
    dq->size--;
    if (isEmpty(dq)) {
        dq->front = dq->rear = -1;
    }
}

void modify(Deque* dq, int position, int newValue) {
    if (isEmpty(dq) || position < 0 || position >= dq->size) {
        printf("Invalid position or deque is empty.\n");
        return;
    }
    actualPosition = (dq->front + position) % MAX;
    printf("Modified value at position %d from %d to %d\n", position, dq->deque[actualPosition], newValue);
    dq->deque[actualPosition] = newValue;
}

void display(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque elements: ");
    i = dq->front;
    for (count = 0; count < dq->size; count++) {
        printf("%d ", dq->deque[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Deque dq;
    initDeque(&dq);
    
    choice, value, position, newValue;
    
    while (1) {
        printf("\nDeque Operations:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Modify at Position\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert at the front: ");
                scanf("%d", &value);
                insertFront(&dq, value);
                break;
            case 2:
                printf("Enter value to insert at the rear: ");
                scanf("%d", &value);
                insertRear(&dq, value);
                break;
            case 3:
                deleteFront(&dq);
                break;
            case 4:
                deleteRear(&dq);
                break;
            case 5:
                printf("Enter position to modify (0-based index): ");
                scanf("%d", &position);
                printf("Enter new value: ");
                scanf("%d", &newValue);
                modify(&dq, position, newValue);
                break;
            case 6:
                display(&dq);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    
    return 0;
}
