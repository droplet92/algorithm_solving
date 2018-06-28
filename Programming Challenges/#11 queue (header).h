#pragma once
#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#define QUEUESIZE 3650

typedef struct {
	int q[QUEUESIZE + 1];
	int first;
	int last;
	int count;
} queue;

void init_queue(queue *q) {
	q->first = 0;
	q->last = QUEUESIZE - 1;
	q->count = 0;
}

void enqueue(queue *q, int data) {
	if (q->count >= QUEUESIZE)
		printf("Warning: queue overflow enqueue data=%d\n", data);
	else {
		q->last = (q->last + 1) % QUEUESIZE;
		q->q[q->last] = data;
		q->count = q->count + 1;
	}
}

int dequeue(queue *q) {
	int x = 0;

	if (q->count <= 0)
		puts("Warning: empty queue dequeue.");
	else {
		x = q->q[q->first];
		q->first = (q->first + 1) % QUEUESIZE;
		q->count = q->count - 1;
	}
	return x;
}

int empty(queue *q) {
	return (q->count <= 0);
}

#endif