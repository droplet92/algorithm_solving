#pragma once
#ifndef __BIGNUM_H__
#define __BIGNUM_H__

#include <stdio.h>

#define max(lhs, rhs)	(lhs) > (rhs) ? (lhs) : (rhs)
#define MAXSIZE	100
typedef enum { False, True } Bool;

//기본 함수
int atoi(char c) {
	int i;

	for (i = 0; i < 10; ++i) {
		if (c == '0' + i) return i;
	}
	return -1;
}

char itoa(int n) {
	int i;

	for (i = 0; i < 10; ++i) {
		if (n == i) return '0' + i;
	}
	return '-1';
}

void swap_char(char *lhs, char *rhs) {
	char temp;
	temp = *lhs;
	*lhs = *rhs;
	*rhs = temp;
}

//큰 숫자
typedef struct {
	char digits[MAXSIZE];
	int lastbit;
} bign;

void init_num(bign *n) {
	int i;		/* 카운터 */

	for (i = 0; i < MAXSIZE; ++i) n->digits[i] = '0';
	n->lastbit = 0;
}

void get_num(bign *n) {
	char ch;	/* 임시 문자 */
	int num;	/* 임시 숫자 */
	int i;		/* 카운터 */

	while (ch = getchar()) {
		if (ch == '\n') break;
		if (ch == ' ') break;
		n->digits[n->lastbit++] = ch;
	}
	n->lastbit -= 1;

	for (i = 0; i < (n->lastbit / 2) + (n->lastbit % 2); ++i) {
		swap_char(&(n->digits[i]), &(n->digits[n->lastbit - i]));
	}
}

void add_num(bign *a, bign *b, bign *c) {
	int maxlen;		/* 최대 자릿수 */
	int carry;		/* 올림 숫자 */
	int i;			/* 카운터 */

	init_num(c);
	maxlen = max(a->lastbit, b->lastbit);
	carry = 0;

	for (i = 0; i <= (maxlen + carry); ++i) {
		c->digits[c->lastbit++] =
			itoa((atoi(a->digits[i]) + atoi(b->digits[i]) + carry) % 10);
		if (atoi(a->digits[i]) + atoi(b->digits[i]) + carry >= 10) carry = 1;
		else carry = 0;
	}
	c->lastbit -= 1;
}

void copy_num(bign *target, bign *source) {
	int i;					/* 카운터 */
	init_num(target);

	for (i = 0; i <= (source->lastbit); ++i) {
		target->digits[i] = source->digits[i];
	}
	target->lastbit = source->lastbit;
}

void swap_num(bign *a, bign *b) {
	bign temp;		/* 임시 숫자 */

	copy_num(&temp, a);
	copy_num(a, b);
	copy_num(b, &temp);
}

Bool isLeftSameOrGreater(bign *lhs, bign *rhs) {
	int i;

	if (lhs->lastbit > rhs->lastbit) return True;
	if (lhs->lastbit < rhs->lastbit) return False;

	for (i = (lhs->lastbit); i >= 0; --i) {
		if (lhs->digits[i] > rhs->digits[i]) return True;
		if (lhs->digits[i] < rhs->digits[i]) return False;
	}
	return True;
}

void print(bign *n) {
	for (int i = (n->lastbit); i >=0; --i) {
		printf("%c", n->digits[i]);
	}
	puts("");
}

#endif