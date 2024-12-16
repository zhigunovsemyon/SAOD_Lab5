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
	CROSS_LOOP
} CheckResult;

typedef struct {
	int m, n;
} Pair;

static CheckResult CheckPairs(Pair const pairs[], int const count)
{
	for (int i = 0; i < count; ++i) {
		Pair const *const p = pairs + i; //Первая сравниваемая пара
		
		/*Проверка на правильную очередность*/
		if (p->m >= p->n)
			return BAD_PAIR;

		for (int j = i + 1; j < count; ++j) {
			/*Пара, с которой будет сравнение*/
			Pair const *const n = pairs + j;

			/*Если конец первой пары находится до конца второй,
			но до начала первой, циклы пересекаются*/
			if (p->n < n->n && p->n > n->m )
				return CROSS_LOOP;
		}
	}
	return CORRECT;
}

int main() {
	Pair const pairs[] = {{1, 5}, {2, 3}, {4, 9}};
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
	}

	return EXIT_SUCCESS;
}
