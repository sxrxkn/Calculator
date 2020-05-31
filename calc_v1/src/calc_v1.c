/*
 ============================================================================
 Name        : Calculator with list
 Author      : sxrxkn
 Version     : 1
 Copyright   :
 Description : This is a calculator with lists. It supports operations
 on vectors and float numbers. Data from the file is read to the list.
 After that, operations are performed and written to the resulting list.
 Finally, the results are written to a file.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

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

// Function prototype
float *operation_on_numbers(char op, float *num1, float *num2);
float  *operation_on_vectors(char op, int size, float *vector1, float *vector2);
float *add_numb(FILE *input, int size);
void add_el_store(storage *current, FILE *input);
void add_el_res(res *current_res, storage *current );


int main(int argc,char *argv[]){
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    char inputfile[100], outputfile[100], end = 'n';
    FILE *input, *output;
    storage *head_list, *current;
    res *head_result, *current_result;
    while(end == 'n'){
        printf("Enter name of input file:");
        scanf(" %s", inputfile);
        printf("Enter name of output file:");
        scanf(" %s", outputfile);
        input = fopen(inputfile, "r");
            if(!feof(input)){
                // Reading the file to the end
                head_list = malloc(1 * sizeof(storage));
                fscanf(input," %c %c", &head_list->op, &head_list->type);
                if(head_list->type == 'v')
                    fscanf(input, " %i", &head_list->size);
                else
                    head_list->size = 1;
                if(head_list->op == '!'){
                    head_list->num1 = add_numb(input, head_list->size);
                    head_list->num2 = NULL;}
                else{
                    head_list->num1 = add_numb(input, head_list->size);
                    head_list->num2 = add_numb(input, head_list->size);}
                current = head_list;
                // If there is one example in the file, move current->next to NULL
                if (feof(input))
                    current->next = NULL;
                // Reading elements to the end of the file
                while (!feof(input)){
                    add_el_store(current, input);
                    current = current->next;}
                head_result = malloc(sizeof(res));
                current = head_list;
                // Ahead is a block of code for calculating operations
                if(current->type == 'v')
                    head_result->res = operation_on_vectors(current->op, current->size, current->num1, current->num2);
                else
                    head_result->res = operation_on_numbers(current->op, current->num1, current->num2);
                head_result->next_res = NULL;
                current = current->next;
                current_result = head_result;
                // Adding results to the result list
                while (current != NULL){
                    add_el_res(current_result, current);
                    current = current->next;
                    current_result = current_result->next_res;}
                current = head_list;
                current_result = head_result;
                fclose(input);
                output = fopen(outputfile, "w");
                // Writing to a file
                while (current != NULL) {
                    if (current->type == 'v') {
                        fprintf(output, "(");
                        for (int i = 0; i < current->size; i++){
                            fprintf(output, " %.2f ", current->num1[i]);}
                        fprintf(output, ") %c (", current->op);
                        for (int i = 0; i < current->size; i++){
                            fprintf(output, " %.2f ", current->num2[i]);}
                        fprintf(output, ") = ");
                        if (current->op != '*') {
                            fprintf(output, "(");
                            for (int i = 0; i < current->size; i++)
                                fprintf(output, " %.2f ", current_result->res[i]);
                            fprintf(output, ")\n");}
                        else
                            fprintf(output, " %.2f\n", current_result->res[0]);
                    } else if (current->type == 's'){
                        if(current->op != '!')
                            fprintf(output, "%.2f %c %.2f = %.2f\n",current->num1[0],current->op, current->num2[0], current_result->res[0]);
                        else
                            fprintf(output, "%.2f %c = %.2f\n",current->num1[0],current->op, current_result->res[0]);;
                    }
                    current = current->next;
                    current_result = current_result->next_res;
                }
                fclose(output);}
            printf("If you want to continue, press 'n', press any button to turn it off: ");
            scanf(" %c", &end);}
    return 0; }

//Block with functions

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
