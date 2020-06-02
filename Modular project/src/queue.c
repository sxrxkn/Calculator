#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

// Implementation of functions that will be used for the queue calculator

queue *head = NULL, *tail = NULL;
stack *head_stack = NULL;

void put_queue(char numb){
    queue *tmp = malloc(1 * sizeof(queue));
    tmp->symbols = numb;
    tmp->next = NULL;
    if(tail != NULL){
        tail->next = tmp;
        tail = tmp;
    } else{
        head = tmp;
        tail = tmp;
    }
}
// Get out of the queue
char *get_element(void){
    if(head!=NULL){
        char *symb;
        symb = &head->symbols;
        head = head->next;
        return symb;}
    else
        return NULL;
}

float operation_on_numbers_queue(char op, float num1, float num2)
{
    float result;
    if(op == '!'){ // Operation "!"
        if  (num1>=0){// If the numbers is greater than 0
            result = 1;
            for(int i=1;i<num1+1;i++){
                result=result*i;}
            return result;}
        else printf("Invalid number");} // If the numbers if numbers is less than 0
        else if (op == '^'){
            result = 1;// Operation "^"
            for(int i=0;i<num2;i++) {
                result=result*num1;}
        return result;}
        else{
            switch (op) { // Operations "+-*/"
                case '+':
                    result =  num1 + num2;
                    return result;
                    break;
                case '-':
                    result = num1 - num2;
                    return result;
                    break;
                case '*':
                    result = num1 * num2;
                    return result;
                    break;
                case '/':
                    if(num2 !=0)
                        result = num1 / num2;
                    return result;
                            break;}}
    return num1;
    return num2;
}


// Put in stack
void push_queue(stack **head_stack, float value) {
    stack *tmp = malloc(sizeof(stack));
    tmp->next = *head_stack;
    tmp->value = value;
    *head_stack= tmp;
}


// Get from stack
float pop_queue(stack **head_stack) {
    stack *out;
    float value;
    out = *head_stack;
    *head_stack = (*head_stack)->next;
    value = out->value;
    free(out);
    return value;
}
