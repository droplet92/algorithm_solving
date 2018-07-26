#include <stdio.h>
/* ���� ť, �������� ���� ���� ��Ȱ�� ���� */
#define QUEUESIZE 10

typedef struct {
	int q[QUEUESIZE + 1];	//ť ����, ���� ����Ʈ�� �ۼ��ϴ°� ����
	int first;				//�Ӹ�
	int last;				//����
	int count;				//ť ���� ����
} queue;

void init_queue(queue *q) {
	q->first = 0;
	q->last = QUEUESIZE - 1;
	q->count = 0;
}

void enqueue(queue *q, int x) {
	if (q->count >= QUEUESIZE)
		printf("Warning: queue overflow enqueue x=%d\n", x);
	else {
		q->last = (q->last + 1) % QUEUESIZE;
		q->q[q->last] = x;
		q->count = q->count + 1;
	}
}

int dequeue(queue *q) {
	int x;
	
	if (q->count <= 0) printf("Warning: empty queue dequeue.\n");
	else {
		x = q->q[q->first];
		q->first = (q->first + 1) % QUEUESIZE;
		q->count = q->count - 1;
	}
	return x;
}

bool empty(queue *q) {
	if (q->count <= 0) return true;
	else return false;
}

int main() {

	return 0;
}