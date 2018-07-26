#include <stdio.h>
#include <math.h>
#include "big number.h"

#define max(lhs, rhs) ((lhs) > (rhs)) ? (lhs) : (rhs)

void print_bigNum(bigNum *n);
void initialize_bigNum(bigNum *n);
void zero_justify(bigNum *n);
int compare_bigNum(bigNum *a, bigNum *b);
void digit_shift(bigNum *n, int d);
int int_to_bigNum(int s, bigNum *n);

void add_bigNum(bigNum *a, bigNum *b, bigNum *c);
void subtract_bigNum(bigNum *a, bigNum *b, bigNum *c);
void multiply_bigNum(bigNum *a, bigNum *b, bigNum *c);
void divide_bigNum(bigNum *a, bigNum *b, bigNum *c);

void print_bigNum(bigNum *n) {
	if (n->signBit == MINUS) printf("-");
	for (int i = n->lastDigit; i >= 0; --i)
		printf("%c", '0' + n->digits[i]);
	puts("");
}

void initialize_bigNum(bigNum *n) {
	int i;		/* 카운터 */

	for (i = 0; i < MAXDIGITS; ++i)
		n->digits[i] = 0;

	n->signBit = PLUS;
	n->lastDigit = 0;
}

void zero_justify(bigNum *n) {
	while ((n->lastDigit > 0) && (n->digits[n->lastDigit] == 0))
		--(n->lastDigit);

	if ((n->lastDigit == 0) && (n->digits[0] == 0))
		n->signBit = PLUS;
}

int compare_bigNum(bigNum *a, bigNum *b) {
	int i;		/* 카운터 */

	if ((a->signBit == MINUS) && (b->signBit == PLUS)) return PLUS;
	if ((a->signBit == PLUS) && (b->signBit == MINUS)) return MINUS;

	if (b->lastDigit > a->lastDigit) return PLUS * a->signBit;
	if (a->lastDigit > b->lastDigit) return MINUS * a->signBit;

	for (i = a->signBit; i >= 0; --i) {
		if (a->digits[i] > b->digits[i]) return MINUS * a->signBit;
		if (b->digits[i] > a->digits[i]) return PLUS * a->signBit;
	}
	return 0;
}

void digit_shift(bigNum *n, int d) {	/* n에 10^d를 곱함 */
	int i;		/* 카운터 */

	if ((n->lastDigit == 0) && (n->digits[0] == 0)) return;

	for (i = n->lastDigit; i >= 0; --i)
		n->digits[i + d] = n->digits[i];

	for (i = 0; i < d; ++i) n->digits[i] = 0;

	n->lastDigit = n->lastDigit + d;
}

int int_to_bigNum(int s, bigNum *n) {
	int i;		/* 카운터 */
	int t;		/* 작업용 int 변수 */

	if (s >= 0) n->signBit = PLUS;
	else n->signBit = MINUS;

	for (i = 0; i < MAXDIGITS; ++i) n->digits[i] = (char)0;

	--(n->lastDigit);
	t = abs(s);

	while (t > 0) {
		++(n->lastDigit);
		n->digits[n->lastDigit] = (t % 10);
		t = t / 10;
	}
	if (s == 0) n->lastDigit = 0;
}

void add_bigNum(bigNum *a, bigNum *b, bigNum *c) {
	int carry;	/* 윗자리로 넘길 숫자 */
	int i;		/* 카운터 */

	initialize_bigNum(c);

	if (a->signBit == b->signBit) c->signBit = a->signBit;
	else {
		if (a->signBit == MINUS) {
			a->signBit = PLUS;
			subtract_bigNum(b, a, c);
			a->signBit = MINUS;
		}
		else {
			b->signBit = PLUS;
			subtract_bigNum(a, b, c);
			b->signBit = MINUS;
		}
		return;
	}

	c->lastDigit = max(a->lastDigit, b->lastDigit) + 1;
	carry = 0;

	for (i = 0; i <= (c->lastDigit); ++i) {
		c->digits[i] = (char)(carry + a->digits[i] + b->digits[i]) % 10;
		carry = (carry + a->digits[i] + b->digits[i]) / 10;
	}
	zero_justify(c);
}

void subtract_bigNum(bigNum *a, bigNum *b, bigNum *c) {
	int borrow;	/* 윗자리에서 빌려왔는지 여부 */
	int v;		/* 임시 숫자 */
	int i;		/* 카운터 */

	initialize_bigNum(c);

	if ((a->signBit == MINUS) || (b->signBit == MINUS)) {
		b->signBit = -1 * b->signBit;
		add_bigNum(a, b, c);
		b->signBit = -1 * b->signBit;
		return;
	}

	if (compare_bigNum(a, b) == PLUS) {
		subtract_bigNum(b, a, c);
		c->signBit = MINUS;
		return;
	}

	c->lastDigit = max(a->lastDigit, b->lastDigit);
	borrow = 0;

	for (i = 0; i <= (c->lastDigit); ++i) {
		v = (a->digits[i] - borrow - b->digits[i]);
		if (a->digits[i] > 0) borrow = 0;
		if (v < 0) {
			v += 10;
			borrow = 1;
		}
		c->digits[i] = (char)v % 10;
	}
	zero_justify(c);
}

void multiply_bigNum(bigNum *a, bigNum *b, bigNum *c) {
	bigNum row;		/* 옆으로 밀린 줄 */
	bigNum temp;	/* 임시 숫자 */
	int i, j;		/* 카운터 */

	initialize_bigNum(c);
	row = *a;

	for (i = 0; i <= (b->lastDigit); ++i) {
		for (j = 1; j <= (b->digits[i]); ++j) {
			add_bigNum(c, &row, &temp);
			*c = temp;
		}
		digit_shift(&row, 1);
	}

	c->signBit = a->signBit * b->signBit;
	zero_justify(c);
}

void divide_bigNum(bigNum *a, bigNum *b, bigNum *c) {
	bigNum row;			/* 옆으로 밀린 줄 */
	bigNum temp;		/* 임시 숫자 */
	int aSign, bSign;	/* 임시 부호 */
	int i, j;			/* 카운터 */

	initialize_bigNum(c);

	c->signBit = a->signBit * b->signBit;
	aSign = a->signBit;
	bSign = b->signBit;

	a->signBit = PLUS;
	b->signBit = PLUS;

	initialize_bigNum(&row);
	initialize_bigNum(&temp);

	c->lastDigit = a->lastDigit;

	for (i = a->lastDigit; i >= 0; --i) {
		digit_shift(&row, 1);
		row.digits[0] = a->digits[i];
		c->digits[i] = 0;

		while (compare_bigNum(&row, b) != PLUS) {
			++(c->digits[i]);
			subtract_bigNum(&row, b, &temp);
			row = temp;
		}
	}
	zero_justify(c);

	a->signBit = aSign;
	b->signBit = bSign;
}