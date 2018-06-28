#include "queue.h"

int main() {
	//t: test cases, n: number of days, p: parties
	queue q[100];
	int h[100];
	int t, n, p, count, temp;
	scanf("%d", &t);

	//t개의 테스트
	for (int i = 0; i < t; ++i) {
		count = 0;
		scanf("%d", &n);	//7 <= n <= 3650
		scanf("%d", &p);	//1 <= p <= 100

		//p에 대한 h 입력
		for (int j = 0; j < p; ++j) {
			scanf("%d", &h[j]);
		}
		//휴업일 초기화
		for (int j = 0; j < p; ++j) {
			init_queue(&q[j]);

			for (int k = 0; k < n; ++k) {
				enqueue(&q[j], ((k + 1) % h[j] == 0));
			}
		}
		//첫날은 일요일부터, 금/토요일은 휴업 안함
		for (int j = 0; j < n; ++j) {
			temp = 0;

			for (int k = 0; k < p; ++k) {
				if (dequeue(&q[k])) {
					++temp;
				}
			}
			if ((j + 1) % 7 == 6 || (j + 1) % 7 == 0) continue;	//6은 금, 0은 토
			if (temp) ++count;
		}
		printf("%d\n", count);
	}
	return 0;
}