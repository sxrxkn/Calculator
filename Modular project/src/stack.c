#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

// Implementation of functions that will be used for the stack calculator

    stack1 *head_stack_1 = NULL;

float operation_on_numbers_stack(char op, float num1, float num2)
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
}


// Adding to the stack
void push(stack1 **head_stack_1, float value) {
    stack1 *tmp = malloc(sizeof(stack1));
    tmp->next = *head_stack_1;
    tmp->value = value;
    *head_stack_1 = tmp;
}


// Taking elements from the stack
float pop(stack1 **head_stack_1) {
    stack1 *out;
    float value;
    out = *head_stack_1;
    *head_stack_1 = (*head_stack_1)->next;
    value = out->value;
    free(out);
    return value;
}
