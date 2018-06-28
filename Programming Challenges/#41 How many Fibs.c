#include <stdio.h>
#include <math.h>
#include "bignum.h"

//피보나치
void Fibonacci(int n, bign *b) {
	bign fib;		/* 피보나치 숫자 */
	bign lhs, rhs;	/* 초항 */
	int len;		/* 피보나치 숫자의 길이 */
	int i;			/* 카운터 */

	init_num(&lhs);
	init_num(&rhs);
	rhs.digits[rhs.lastbit] = '1';	/* lhs는 0, rhs는 1 */

	for (i = 0; i < n; ++i) {
		init_num(&fib);

		add_num(&lhs, &rhs, &fib);
		copy_num(&lhs, &rhs);
		copy_num(&rhs, &fib);
	}
	copy_num(b, &fib);
}

int main() {
	bign a, b;			/* 입력받은 숫자 */
	bign begin, end;	/* 임시 숫자 */
	int i, j;			/* 카운터 */

	init_num(&a);
	init_num(&b);
	get_num(&a);
	get_num(&b);

	while (!(a.digits[a.lastbit] == '0' && a.lastbit == 0)
		&& !(b.digits[b.lastbit] == '0' && b.lastbit == 0))
	{
		i = 0;

		//시작점 찾기
		do {
			init_num(&begin);
			Fibonacci(++i, &begin);
		} while (isLeftSameOrGreater(&a, &begin));

		j = i;
		//종점 찾기
		do {
			init_num(&end);
			Fibonacci(++j, &end);
		} while (isLeftSameOrGreater(&b, &end));

		//결과 출력
		printf("%d\n", j - i);

		//다음값 입력
		init_num(&a);
		init_num(&b);
		get_num(&a);
		get_num(&b);
	}
	
	return 0;
}

/*
10 100
1234567890 9876543210
0 0
*/