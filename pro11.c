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
                
                while (head != NULL) {
                    Node* temp = head;
                    head = head->next;
                    free(temp);
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
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}


void deleteNode(Node** head, int value) {
    Node* temp = *head;
    Node* prev = NULL;

    
    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        return;
    }

    
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    
    prev->next = temp->next;
    free(temp);
}


void modifyNode(Node* head, int oldValue, int newValue) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == oldValue) {
            temp->data = newValue;
            printf("Node value modified.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Value %d not found in the list.\n", oldValue);
}


void displayList(Node* head) {
    Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
