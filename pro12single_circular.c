//program12. singly circular linked list 1.insert,2.delete,3.modify,4.display.
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


void insertAtEnd(Node** head, int value);
void deleteNode(Node** head, int value);
void modifyNode(Node* head, int oldValue, int newValue);
void displayList(Node* head);

int main() {
    Node* head = NULL;
    int choice, value, oldValue, newValue;

    while (1) {
        printf("\nMenu:\n");
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
                insertAtEnd(&head, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 3:
                printf("Enter old value to modify: ");
                scanf("%d", &oldValue);
                printf("Enter new value: ");
                scanf("%d", &newValue);
                modifyNode(head, oldValue, newValue);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                
                if (head != NULL) {
                    Node* current = head;
                    Node* nextNode;
                    do {
                        nextNode = current->next;
                        free(current);
                        current = nextNode;
                    } while (current != head);
                }
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


void insertAtEnd(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    Node* last = *head;

    newNode->data = value;
    newNode->next = newNode; // Point to itself initially

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (last->next != *head) {
        last = last->next;
    }

    last->next = newNode;
    newNode->next = *head;
}


void deleteNode(Node** head, int value) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    
    if (temp->data == value) {
        if (temp->next == *head) {
            free(temp);
            *head = NULL;
            return;
        }

        prev = *head;
        while (prev->next != *head) {
            prev = prev->next;
        }
        prev->next = temp->next;
        *head = temp->next;
        free(temp);
        return;
    }

    
    prev = temp;
    temp = temp->next;
    while (temp != *head && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    
    if (temp == *head) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    prev->next = temp->next;
    free(temp);
}


void modifyNode(Node* head, int oldValue, int newValue) {
    Node* temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    do {
        if (temp->data == oldValue) {
            temp->data = newValue;
            printf("Node value modified.\n");
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Value %d not found in the list.\n", oldValue);
}


void displayList(Node* head) {
    Node* temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Circular Linked List:\n");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}
