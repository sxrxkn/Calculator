#include "list.h"
#include <stdlib.h>
#include <stdio.h>
// Implementation of functions that will be used for the list calculator
storage *head_list, *current;
res *head_result, *current_result;

float *operation_on_numbers(char op, float *num1, float *num2)
{
    float *result;
    result = malloc(1 * sizeof(float));
    if(op == '!'){ // Operation "!"
        if  (num1[0]>=0){// If the numbers is greater than 0
            result[0] = 1;
            for(int i=1;i<num1[0]+1;i++){
                result[0]=result[0]*i;}
            return result;}
        else printf("Invalid number");} // If the numbers if numbers is less than 0
        else if (op == '^'){
            result[0] = 1;// Operation "^"
            for(int i=0;i<num2[0];i++) {
                result[0]=result[0]*num1[0];}
        return result;}
        else{
            switch (op) { // Operations "+-*/"
                case '+':
                    result[0] =  num1[0] + num2[0];
                    return result;
                    break;
                case '-':
                    result[0] = num1[0] - num2[0];
                    return result;
                    break;
                case '*':
                    result[0] = num1[0] * num2[0];
                    return result;
                    break;
                case '/':
                    if(num2 !=0)
                        result[0] = num1[0] / num2[0];
                    return result;
                            break;}}
    return num1;
    return num2;
    free(num1);
    free(num2);
    free(result);
}

float  *operation_on_vectors(char op, int size, float *vector1, float *vector2){
    float *result;
    if (op != '*'){
        result = malloc(size * sizeof(float));
        switch(op) {
            case '+':
                for(int i=0;i<size;i++)
                    result[i] = vector1[i]+vector2[i];
                return result;
            case '-':
                for(int i=0;i<size;i++)
                    result[i] = vector1[i]-vector2[i];
                return result;}}
    else{
        result = malloc(1 * sizeof(float));
        result[0] = 0;
        for (int i = 0; i < size; i++)
            result[0] = result[0] + (vector1[i] * vector2[i]);
        return result;}
    return vector1;
    return vector2;
    free(vector1);
    free(vector2);
    free(result);
}
// Function for adding num1 and num2 elements
float *add_numb(FILE *input, int size){
    float *number;
    number = malloc(size * sizeof(float));
    for(int i = 0;i < size;i++)
    {
        fscanf(input,"%f", &number[i]);
    }
    return number;
}

// Function for adding elements in list
void add_el_store(storage *current, FILE *input){
    storage *tmp = malloc(1 * sizeof(storage));
       fscanf(input, " %c %c",  &tmp->op, &tmp->type);
       if(tmp->type == 'v')
           fscanf(input, " %i", &tmp->size);
       else
           tmp->size = 1;
       if(tmp->op == '!'){
           tmp->num1 = add_numb(input, tmp->size);
           tmp->num2 = NULL;}
       else{
           tmp->num1 = add_numb(input, tmp->size);
           tmp->num2 = add_numb(input, tmp->size);}
       tmp->next = NULL;
       current->next = tmp;
}

// Function for adding elements in result list
void add_el_res(res *current_res, storage *current ){
    res *tmp_res = malloc(1 * sizeof(res));
        if(current->type == 'v'){
            tmp_res->res = operation_on_vectors(current->op, current->size, current->num1, current->num2);
        }
        else {
            tmp_res->res = operation_on_numbers(current->op, current->num1, current->num2);}
        tmp_res->next_res = NULL;
        current_res->next_res = tmp_res;
}
