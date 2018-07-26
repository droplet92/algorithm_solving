#pragma once
#ifndef __BIG_NUMBER__
#define __BIG_NUMBER__

#define MAXDIGITS	100		/* �ִ� �ڸ��� */
#define PLUS		1		/* ��� ��ȣ ��Ʈ */
#define MINUS		-1		/* ���� ��ȣ ��Ʈ */

typedef struct {
	char digits[MAXDIGITS];	/* ���� �κ� */
	int signBit;			/* + �Ǵ� - */
	int lastDigit;			/* ���� ���� �ڸ��� �ε��� */
} bigNum;

#endif