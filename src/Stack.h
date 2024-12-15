#ifndef STACK_H_
#define STACK_H_

enum Errors {
	ERR_NO,	   // Отсутствие ошибок
	ERR_MALLOC // Ошибка malloc
};

struct int_Stack; // Определён в с файле

// Стек чисел
typedef struct {
	struct int_Stack *top; // Верхний элемент стека
} Stack;

/*Вталкивание элемента num в стек S.
Возврат 0 при успехе, либо ERR_MALLOC*/
int PushInStack(Stack *S, int num);

// Тихое уничтожение стека S
void SilentFreeStack(Stack *const);

// Возврат 0, если стек пустой
int IsStackEmpty(Stack const *const);

// Извлечение вершины стека S в num
int PullFromStack(Stack *const);

// Удаление вершины стека
void DelTopFromStack(Stack *S);

// Создание пустого стека
Stack InitStack(void);

// Неисключающее чтение вершины стека S
int ReadTopFromStack(Stack const *const);

#endif