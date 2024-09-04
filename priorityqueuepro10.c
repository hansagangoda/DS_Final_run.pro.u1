//pro10.write program to implement priority queue.
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
int i,choice,data,priority; 

typedef struct {
    int data;
    int priority;
} Element;

typedef struct {
    Element elements[SIZE];
    int size;
} PriorityQueue;


void initialize(PriorityQueue* pq);
int isEmpty(PriorityQueue* pq);
int isFull(PriorityQueue* pq);
void insert(PriorityQueue* pq, int data, int priority);
void removeHighestPriority(PriorityQueue* pq);
void display(PriorityQueue* pq);
void menu();

int main() {
    PriorityQueue pq;
    initialize(&pq);

    choice, data, priority;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter priority: ");
                scanf("%d", &priority);
                insert(&pq, data, priority);
                break;
            case 2:
                removeHighestPriority(&pq);
                break;
            case 3:
                display(&pq);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void initialize(PriorityQueue* pq) {
    pq->size = 0;
}

int isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

int isFull(PriorityQueue* pq) {
    return pq->size == SIZE;
}

void insert(PriorityQueue* pq, int data, int priority) {
    if (isFull(pq)) {
        printf("Priority queue is full. Cannot insert.\n");
    } else {
        int i = pq->size - 1;
        while (i >= 0 && pq->elements[i].priority < priority) {
            pq->elements[i + 1] = pq->elements[i];
            i--;
        }
        pq->elements[i + 1].data = data;
        pq->elements[i + 1].priority = priority;
        pq->size++;
        printf("Inserted data %d with priority %d\n", data, priority);
    }
}

void removeHighestPriority(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority queue is empty. Cannot remove.\n");
    } else {
        Element e = pq->elements[0];
        for (i = 0; i < pq->size - 1; i++) {
            pq->elements[i] = pq->elements[i + 1];
        }
        pq->size--;
        printf("Removed data %d with priority %d\n", e.data, e.priority);
    }
}

void display(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority queue is empty.\n");
    } else {
        printf("Priority Queue:\n");
        for (i = 0; i < pq->size; i++) {
            printf("Data: %d, Priority: %d\n", pq->elements[i].data, pq->elements[i].priority);
        }
    }
}

void menu() {
    printf("\nPriority Queue Menu\n");
    printf("1. Insert\n");
    printf("2. Remove Highest Priority\n");
    printf("3. Display\n");
    printf("4. Exit\n");
}
