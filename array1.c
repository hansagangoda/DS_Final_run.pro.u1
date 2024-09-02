#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void addElement(int arr[], int *n, int value) {
    if (*n >= MAX) {
        printf("Array is full. Cannot add more elements.\n");
        return;
    }
    arr[*n] = value;
    (*n)++;
}

void deleteElement(int arr[], int *n, int index) {
    if (index < 0 || index >= *n) {
        printf("Invalid index.\n");
        return;
    }
    for (int i = index; i < (*n) - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void modifyElement(int arr[], int n, int index, int newValue) {
    if (index < 0 || index >= n) {
        printf("Invalid index.\n");
        return;
    }
    arr[index] = newValue;
}

void sortArray(int arr[], int n) 
{
    int temp;
    for (int i = 0; i < n - 1; i++) 
	{
        for (int j = i + 1; j < n; j++) 
		{
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void simpleSearch(int arr[], int n, int key) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element %d found at index %d.\n", key, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element %d not found in the array.\n", key);
    }
}

void binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1, mid;
    int found = 0;
    
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            printf("Element %d found at index %d.\n", key, mid);
            found = 1;
            break;
        }
        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (!found) {
        printf("Element %d not found in the array.\n", key);
    }
}

void displayArray(int arr[], int n) {
    printf("Array elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX];
    int n = 0;
    int choice, value, index;
    
    do {
        printf("\nMenu:\n");
        printf("1. Add Element\n");
        printf("2. Delete Element\n");
        printf("3. Modify Element\n");
        printf("4. Sort Array\n");
        printf("5. Simple Search\n");
        printf("6. Binary Search\n");
        printf("7. Display Array\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to add: ");
                scanf("%d", &value);
                addElement(arr, &n, value);
                break;
            case 2:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                deleteElement(arr, &n, index);
                break;
            case 3:
                printf("Enter index to modify: ");
                scanf("%d", &index);
                printf("Enter new value: ");
                scanf("%d", &value);
                modifyElement(arr, n, index, value);
                break;
            case 4:
                sortArray(arr, n);
                printf("Array sorted.\n");
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                simpleSearch(arr, n, value);
                break;
            case 6:
                sortArray(arr, n);  // Ensure array is sorted for binary search
                printf("Enter value to search: ");
                scanf("%d", &value);
                binarySearch(arr, n, value);
                break;
            case 7:
                displayArray(arr, n);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}
