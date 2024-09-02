//pro3 
#define MAX 10
int i;
int stackNumber;

typedef struct {
    int arr[MAX];
    int top1;
    int top2;
} DoubleStack;


void initialize(DoubleStack *stack);
int isFull(DoubleStack *stack);
int isEmpty1(DoubleStack *stack);
int isEmpty2(DoubleStack *stack);
void push1(DoubleStack *stack, int value);
void push2(DoubleStack *stack, int value);
int pop1(DoubleStack *stack);
int pop2(DoubleStack *stack);
int peep1(DoubleStack *stack);
int peep2(DoubleStack *stack);
void modify(DoubleStack *stack, int stackNumber, int index, int value);
void display(DoubleStack *stack);

int main() {
    DoubleStack stack;
    int choice, value, index;

    initialize(&stack);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push to Stack 1\n");
        printf("2. Push to Stack 2\n");
        printf("3. Pop from Stack 1\n");
        printf("4. Pop from Stack 2\n");
        printf("5. Peep Stack 1\n");
        printf("6. Peep Stack 2\n");
        printf("7. Modify an Element\n");
        printf("8. Display Stacks\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push to Stack 1: ");
                scanf("%d", &value);
                push1(&stack, value);
                break;
            case 2:
                printf("Enter value to push to Stack 2: ");
                scanf("%d", &value);
                push2(&stack, value);
                break;
            case 3:
                value = pop1(&stack);
                if (value != -1) {
                    printf("Popped from Stack 1: %d\n", value);
                }
                break;
            case 4:
                value = pop2(&stack);
                if (value != -1) {
                    printf("Popped from Stack 2: %d\n", value);
                }
                break;
            case 5:
                value = peep1(&stack);
                if (value != -1) {
                    printf("Top of Stack 1: %d\n", value);
                }
                break;
            case 6:
                value = peep2(&stack);
                if (value != -1) {
                    printf("Top of Stack 2: %d\n", value);
                }
                break;
            case 7:
                printf("Enter stack number (1 or 2): ");
               
                scanf("%d", &stackNumber);
                printf("Enter index (relative to stack start): ");
                scanf("%d", &index);
                printf("Enter new value: ");
                scanf("%d", &value);
                modify(&stack, stackNumber, index, value);
                break;
            case 8:
                display(&stack);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


void initialize(DoubleStack *stack) {
    stack->top1 = -1;
    stack->top2 = MAX;
}


int isFull(DoubleStack *stack) {
    return stack->top1 + 1 == stack->top2;
}

// Check if Stack 1 is empty
int isEmpty1(DoubleStack *stack) {
    return stack->top1 == -1;
}


int isEmpty2(DoubleStack *stack) {
    return stack->top2 == MAX;
}


void push1(DoubleStack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top1] = value;
}


void push2(DoubleStack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[--stack->top2] = value;
}


int pop1(DoubleStack *stack) {
    if (isEmpty1(stack)) {
        printf("Stack 1 Underflow\n");
        return -1;
    }
    return stack->arr[stack->top1--];
}


int pop2(DoubleStack *stack) {
    if (isEmpty2(stack)) {
        printf("Stack 2 Underflow\n");
        return -1;
    }
    return stack->arr[stack->top2++];
}


int peep1(DoubleStack *stack) {
    if (isEmpty1(stack)) {
        printf("Stack 1 is Empty\n");
        return -1;
    }
    return stack->arr[stack->top1];
}


int peep2(DoubleStack *stack) {
    if (isEmpty2(stack)) {
        printf("Stack 2 is Empty\n");
        return -1;
    }
    return stack->arr[stack->top2];
}


void modify(DoubleStack *stack, int stackNumber, int index, int value) {
    if (stackNumber == 1) {
        if (index < 0 || index > stack->top1) {
            printf("Invalid index for Stack 1\n");
            return;
        }
        stack->arr[index] = value;
    } else if (stackNumber == 2) {
        if (index < 0 || index > MAX - 1 - stack->top2) {
            printf("Invalid index for Stack 2\n");
            return;
        }
        stack->arr[stack->top2 + index] = value;
    } else {
        printf("Invalid stack number\n");
    }
}

void display(DoubleStack *stack) {
    printf("Stack 1: ");
    if (isEmpty1(stack)) {
        printf("Empty\n");
    } else {
        for (i = 0; i <= stack->top1; i++) {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }

    printf("Stack 2: ");
    if (isEmpty2(stack)) {
        printf("Empty\n");
    } else {
        for (i = MAX - 1; i >= stack->top2; i--) {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}