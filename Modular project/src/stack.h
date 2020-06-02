#ifndef STACK_H_
#define STACK_H_
#include <stdio.h>

// Stack and function prototypes that will be used in the stack calculator

typedef struct number {
    float value;
    struct number *next;
} stack1;

//// Function prototype
void push(stack1 **head_stack_1, float value);
float operation_on_numbers_stack(char op, float num1, float num2);
float pop(stack1 **head_stack_1);

#endif /* STACK_H_ */
