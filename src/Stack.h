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
int StackPush(Stack *S, int num);

// Тихое уничтожение стека S
void StackFree(Stack *const);

// Возврат 1, если стек пустой
int StackIsNotEmpty(Stack const *const);

// Извлечение вершины стека S в num
int StackPull(Stack *const);

// Удаление вершины стека
void StackDelTop(Stack *S);

// Создание пустого стека
Stack StackInit(void);

// Неисключающее чтение вершины стека S
int StackReadTop(Stack const *const);

#endif