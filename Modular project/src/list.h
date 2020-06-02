#ifndef LIST_H_
#define LIST_H_
#include<stdio.h>

// Prototypes functions and structures used in the list calculator

typedef struct list{
    char op;
    char type;
    int size;
    float *num1;
    float *num2;
    struct list *next;
}storage;

typedef struct res_list{
    float *res;
    struct res_list *next_res;
}res;

float *operation_on_numbers(char op, float *num1, float *num2);
float  *operation_on_vectors(char op, int size, float *vector1, float *vector2);
float *add_numb(FILE *input, int size);
void add_el_store(storage *current, FILE *input);
void add_el_res(res *current_res, storage *current );

#endif /* LIST_H_ */
