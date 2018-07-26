#pragma once
#ifndef __BIG_NUMBER__
#define __BIG_NUMBER__

#define MAXDIGITS	100		/* 최대 자릿수 */
#define PLUS		1		/* 양수 부호 비트 */
#define MINUS		-1		/* 음수 부호 비트 */

typedef struct {
	char digits[MAXDIGITS];	/* 숫자 부분 */
	int signBit;			/* + 또는 - */
	int lastDigit;			/* 가장 높은 자리의 인덱스 */
} bigNum;

#endif