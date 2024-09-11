#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int id;
    char name[100];
    struct Student *next;
    struct Student *prev;
} Student;

Student* createStudent(int id, const char* name) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    newStudent->id = id;
    strcpy(newStudent->name, name);
    newStudent->next = newStudent;
    newStudent->prev = newStudent;
    return newStudent;
}


void insertStudent(Student** head, int id, const char* name) {
    Student* newStudent = createStudent(id, name);
    if (*head == NULL) {
        *head = newStudent;
    } else {
        Student* last = (*head)->prev;
        last->next = newStudent;
        newStudent->prev = last;
        newStudent->next = *head;
        (*head)->prev = newStudent;
    }
}

void deleteStudent(Student** head, int id) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    Student* current = *head;
    do {
        if (current->id == id) {
            if (current->next == current) {
                free(current);
                *head = NULL;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                if (*head == current) *head = current->next;
                free(current);
            }
            printf("Student with ID %d deleted.\n", id);
            return;
        }
        current = current->next;
    } while (current != *head);
    
    printf("Student with ID %d not found.\n", id);
}

void modifyStudent(Student* head, int id, const char* newName) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    Student* current = head;
    do {
        if (current->id == id) {
            strcpy(current->name, newName);
            printf("Student with ID %d modified.\n", id);
            return;
        }
        current = current->next;
    } while (current != head);
    
    printf("Student with ID %d not found.\n", id);
}

void displayStudents(Student* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    Student* current = head;
    do {
        printf("ID: %d, Name: %s\n", current->id, current->name);
        current = current->next;
    } while (current != head);
}

int main() {
    Student* head = NULL;
    int choice, id;
    char name[100];
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Student\n");
        printf("2. Delete Student\n");
        printf("3. Modify Student\n");
        printf("4. Display Students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  
        
        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                getchar(); 
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; 
                insertStudent(&head, id, name);
                break;
            case 2:
                printf("Enter ID of student to delete: ");
                scanf("%d", &id);
                deleteStudent(&head, id);
                break;
            case 3:
                printf("Enter ID of student to modify: ");
                scanf("%d", &id);
                getchar();  
                printf("Enter new Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; 
                modifyStudent(head, id, name);
                break;
            case 4:
                displayStudents(head);
                break;
            case 5:
                
                while (head != NULL) {
                    deleteStudent(&head, head->id);
                }
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
