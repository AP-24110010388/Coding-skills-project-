#include <stdio.h>
#include <string.h>

#define MAX 10
#define ITEM_LEN 50

typedef struct {
    char items[MAX][ITEM_LEN];
    int top;
} Stack;


void push(Stack *s, char item[]);
void pop(Stack *s);
void display(Stack *s);

int main() {
    Stack s;
    s.top = -1;

    int choice;
    char item[ITEM_LEN];

    do {
        printf("\n----- SHOPPING LIST (Using Stack) -----\n");
        printf("1. Add Item (Push)\n");
        printf("2. Remove Last Item (Pop)\n");
        printf("3. Display Shopping List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch(choice) {
            case 1:
                printf("Enter item name: ");
                fgets(item, ITEM_LEN, stdin);
                item[strcspn(item, "\n")] = '\0'; 
                push(&s, item);
                break;

            case 2:
                pop(&s);
                break;

            case 3:
                display(&s);
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 4);

    return 0;
}

void push(Stack *s, char item[]) {
    if (s->top == MAX - 1) {
        printf("Stack is full! Cannot add more items.\n");
        return;
    }
    s->top++;
    strcpy(s->items[s->top], item);
    printf("Added: %s\n", item);
}
void pop(Stack *s) {
    if (s->top == -1) {
        printf("Shopping list is empty! Nothing to remove.\n");
        return;
    }
    printf("Removed: %s\n", s->items[s->top]);
    s->top--;
}

void display(Stack *s) {
    if (s->top == -1) {
        printf("Shopping list is empty.\n");
        return;
    }

    printf("\nCurrent Shopping List (Top to Bottom):\n");
    for (int i = s->top; i >= 0; i--) {
        printf("- %s\n", s->items[i]);
    }
}