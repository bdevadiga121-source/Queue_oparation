
#include <stdio.h>
#define MAX 5

struct Queue {
    int items[MAX];
    int front;
    int rear;
};

void enqueue(struct Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }

    q->items[++q->rear] = value;
    printf("%d inserted\n", value);
}

void dequeue(struct Queue *q) {
    if (q->front > q->rear) {
        printf("Queue Underflow!\n");
        return;
    }

    printf("Removed: %d\n", q->items[q->front++]);
}

void display(const struct Queue *q) {
    int i;

    if (q->front > q->rear) {
        printf("Queue is empty\n");
        return;
    }

    for (i = q->front; i <= q->rear; i++)
        printf("%d ", q->items[i]);

    printf("\n");
}

int main(void) {
    struct Queue q = {{0}, 0, -1};

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);
    dequeue(&q);
    display(&q);

    return 0;
}
