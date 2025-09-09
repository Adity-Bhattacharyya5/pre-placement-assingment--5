#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct {
    Node* top;
} Stack;

void init(Stack* s) {
    s->top = NULL;
}
int isEmpty(Stack* s) {
    return s->top == NULL;
}
void push(Stack* s, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
    printf("%d pushed to stack\n", value);
}
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot pop\n");
        return -1;
    }
    Node* temp = s->top;
    int poppedValue = temp->data;
    s->top = s->top->next;
    free(temp);
    return poppedValue;
}
int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->top->data;
}

int main() {
    Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element is %d\n", peek(&s));

    printf("%d popped from stack\n", pop(&s));
    printf("%d popped from stack\n", pop(&s));

    printf("Top element is %d\n", peek(&s));

    return 0;
}

