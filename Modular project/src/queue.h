#ifndef QUEUE_H_
#define QUEUE_H_
#include<stdio.h>

// Functions, queue, and stack that will be used in this program

typedef  struct Queue{
    char symbols;
    struct Queue *next;
}queue;

//It is stack
typedef struct numbers {
    float value;
    struct numbers *next;
} stack;


// Functions prototypes
void put_queue(char numb);
char *get_element(void);
void push_queue(stack **head_stack, float value);
float operation_on_numbers_queue(char op, float num1, float num2);
float pop_queue(stack **head_stack);



#endif /* QUEUE_H_ */
