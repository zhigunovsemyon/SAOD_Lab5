#include "Stack.h"

#include <malloc.h>
#include <stdio.h>

int IsStackEmpty(Stack *S) { // Если указатель на верхний элемент не NULL,
				 // будет возврщён 1,
	// в противном случае -- 0
	return (S->top) ? 1 : 0;
}

Stack InitStack(void) {
	Stack ret = {NULL};
	return ret;
}

int PushInStack(Stack *S, int num) { // Создание нового блока, проверка
	struct int_Stack *newEl;
	if (!(newEl = (struct int_Stack *)malloc(sizeof(struct int_Stack))))
		return ERR_MALLOC;

	// Перезапись указателя на верхний элемент
	newEl->next = S->top;
	newEl->num = num;
	S->top = newEl;

	return ERR_NO;
}

int ReadTopFromStack(Stack *S) { // Чтение вершины
	return S->top->num;
}

void DelTopFromStack(Stack *S) { // Сохранение прошлого верхнего элемента
	struct int_Stack *prevTop = S->top;
	// Перезапись нового верхнего элемента
	S->top = S->top->next;
	// Освобождение старого элемента
	free(prevTop);
}

int PullFromStack(Stack *S) { // Возврат числа из вершины стека
	int num = ReadTopFromStack(S);
	// Удаление верхнего элемента
	DelTopFromStack(S);
	return num;
}

void SilentFreeStack(Stack *S) { // Очистка, пока не будет удалён последний
				 // элемент и top будет указывать в NULL
	while (S->top)
		DelTopFromStack(S);
}