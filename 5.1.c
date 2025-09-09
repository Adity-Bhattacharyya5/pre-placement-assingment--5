#include <stdio.h>

int MAX = 100;
typedef struct {
    int arr[100];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow! Cannot push %d\n", value);
        return;
    }
    s->arr[++(s->top)] = value;
    printf("%d pushed to stack\n", value);
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot pop\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->arr[s->top];
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

