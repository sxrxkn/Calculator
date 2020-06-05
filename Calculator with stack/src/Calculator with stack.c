/*
 ============================================================================
 Name        : Calculator with stack
 Author      : sxrxkn
 Version     : 1.0
 Copyright   :
 Description : This is a calculator with stack implemented in Polish notation.
 It supports operations on real numbers (with operations as
 multiplication'*', division'/', addition'+', subtraction'-',
 exponentiation'^',factorial'!'). To read multiple lines from a file,
 put the n character at the end of the line.
 For example :
2 4 + n
3 ! n
10.5 5.5 /
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef  struct Queue{
    char symbols;
    struct Queue *next;
}queue;

typedef struct numbers {
    float value;
    struct numbers *next;
} stack;



void put_queue(char numb);
char *getElement(void);
void push(stack **head_stack, float value);
float operation_on_numbers(char op, float num1, float num2);
float pop(stack **head_stack);




queue *head = NULL, *tail = NULL;
stack *head_stack = NULL;

int main(int argc,char *argv[]) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    FILE *input, *output;
    int i = 0, counter = 0;
    char end = 'n', inputfile[100], outputfile[100], tmp, tmp_numb[20], op ='-';
    float num, num1, num2;
    while(end == 'n'){
            printf("Enter name of input file:");
            scanf(" %s", inputfile);
            printf("Enter name of output file:");
            scanf(" %s", outputfile);
            input = fopen(inputfile, "r");
            while(!feof(input)){
                fscanf(input, "%c", &tmp);
                if(tmp != '\n'){
                    if(tmp == ' ')
                        tmp = '_';
                    put_queue(tmp);
                    i += 1;}}
            fclose(input);
            output = fopen(outputfile, "w");
            while(i != 1){
                tmp_numb[counter] = *getElement();
                if (tmp_numb[counter] == '_'){
                    if (op == '-') {
                        tmp_numb[counter] = ' ';
                        num = strtof(tmp_numb, NULL);
                        push(&head_stack, num);
                        for(int k = 0; k<(counter+1); k++)
                            tmp_numb[k] = 0;
                        i -= 1;
                        counter = 0;
                    }
                    else
                        i -=1;}
                else if(tmp_numb[counter] == '!'){
                    num1 = pop(&head_stack);
                    num2 = 0;
                    push(&head_stack,operation_on_numbers(tmp_numb[counter], num1 , num2));
                    fprintf(output, "%f %c = %f -> ", num1, tmp_numb[counter], operation_on_numbers(tmp_numb[counter], num1 , num2));
                    i -= 1;
                    counter = 0;
                    op = '+';}
                else if(tmp_numb[counter] =='*' || tmp_numb[counter] =='+' || tmp_numb[counter]=='-' || tmp_numb[counter] =='/' || tmp_numb[counter]=='^'){
                    if(head_stack == NULL)
                        break;
                    num2 = pop(&head_stack);
                    if(head_stack == NULL)
                        break;
                    num1 = pop(&head_stack);
                    push(&head_stack, operation_on_numbers(tmp_numb[counter], num1, num2));
                    fprintf(output, "%f %c %f = %f -> ", num1, tmp_numb[counter], num2, operation_on_numbers(tmp_numb[counter], num1 , num2));
                    op ='+';
                    i -= 1;
                    counter=0;}
                else if(tmp_numb[counter]=='n'){
                 while(head_stack != NULL)
                     pop(&head_stack);
                 fprintf(output, "|\n");
                 counter = 0;
                 i -=1;
                 op = '-';
                }
                else{
                    counter += 1;
                    i -=1;
                }
                    }
            fprintf(output,"|");
            fclose(output);
            printf("If you want to continue, press 'n', press any button to turn it off:");
            scanf(" %c", &end);}
    return 0;}


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

char *getElement(void){
    if(head!=NULL){
        char *symb;
        symb = &head->symbols;
        head = head->next;
        return symb;}
    else
        return NULL;
}

float operation_on_numbers(char op, float num1, float num2)
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



void push(stack **head_stack, float value) {
    stack *tmp = malloc(sizeof(stack));
    tmp->next = *head_stack;
    tmp->value = value;
    *head_stack= tmp;
}



float pop(stack **head_stack) {
    stack *out;
    float value;
    out = *head_stack;
    *head_stack = (*head_stack)->next;
    value = out->value;
    free(out);
    return value;
}
