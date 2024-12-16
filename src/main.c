/*
В некотором языке программирования операторы располагаются в разных строках.
Строки программы нумеруются. Программист указал множество пар (m, n),
где m – номер начальной строки цикла, а n – номер конечной строки. Выяснить:
	а) пропустит ли такой вариант транслятор?
	б) правильно ли организовано вложение циклов?
*/
#include <stdio.h>  /*printf()*/
#include <stdlib.h> /*EXIT_SUCCESS*/

typedef enum {
	CORRECT,
	BAD_PAIR,
	CROSS_LOOP,
	ALLOC_ERR
} CheckResult;

typedef struct {
	int m, n;
} Pair;

static CheckResult CheckPairs(Pair const pairs[], int const count)
{
	for (int i = 0; i < count; ++i) {
	
	}
}

int main() {
	Pair const pairs[] = {{1, 5}, {2, 3}, {6, 9}};
	int const count = (int)(sizeof(pairs) / sizeof(*pairs));

	switch (CheckPairs(pairs, count)) {
	case CORRECT:
		puts("Пары корректны\n");
		break;
	case BAD_PAIR: 
		puts("Неправильные пары\n");
		break;
	case CROSS_LOOP:
		puts("Циклы пересекаются\n");
		break;
	case ALLOC_ERR:
		perror("");
		break;
	}
	printf("Hello World!\n");
	return EXIT_SUCCESS;
}
