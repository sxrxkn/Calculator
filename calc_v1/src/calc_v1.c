/*
 ============================================================================
 Name        : Calculator with stack
 Author      : Sxrxkn
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

// It is stack
typedef struct numbers {
    float value;
    struct numbers *next;
} stack;

//// Function prototype
void push(stack **head, float value);
float operation_on_numbers_stack(char op, float num1, float num2);
float pop(stack **head);


// Main block
int main(int argc,char *argv[]){
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    char inputfile[100], outputfile[100], end = 'n', temp[100], op = '-';
    FILE *input, *output;
    stack *head_stack = NULL;
    int i = 0;
    float num, num1, num2;
    while(end == 'n'){
        // Repeat the program
        printf("Enter name of input file:");
        scanf(" %s", inputfile);
        printf("Enter name of output file:");
        scanf(" %s", outputfile);
        input = fopen(inputfile, "r");
        output = fopen(outputfile, "w");
        while(!feof(input)){
       // This works until the file runs out
            fscanf(input, "%c", &temp[i]);
            if (temp[i] == ' '){
                if (op == '-') {
                    num = strtof(temp, NULL); // Converting the string format to float
                    push(&head_stack, num); // Put it on the stack
                    for(int k = 0; k<(i+1); k++)
                        temp[k] = 0;
                    i = 0;
                }}
            else if(temp[i] == '!'){
                // if operation = !, taking a single number from the stack and performing the operation
                num1 = pop(&head_stack);
                num2 = 0;
                push(&head_stack,operation_on_numbers_stack(temp[i], num1 , num2));
                fprintf(output, "%f %c = %f -> ", num1, temp[0], operation_on_numbers_stack(temp[i], num1 , num2)); //writing to a file
                i = 0;
                op = '+';}
            else if(temp[i] =='*' || temp[i] =='+' || temp[i]=='-' || temp[i] =='/' || temp[i]=='^'){
                // if the operation is equal to one of the above, we get two numbers from the stack and perform the operation
                if(head_stack == NULL)
                    break;
                num2 = pop(&head_stack);
                if(head_stack == NULL)
                    break;
                num1 = pop(&head_stack);
                push(&head_stack, operation_on_numbers_stack(temp[i], num1, num2));
                fprintf(output, "%f %c %f = %f -> ", num1, temp[i], num2, operation_on_numbers_stack(temp[i], num1 , num2)); // writing to a file
                op ='+';}
            else if(temp[i]=='n'){ // switching to another line
             while(head_stack != NULL)
                 pop(&head_stack);
             fprintf(output, "|\n");
            }
            else{
                op ='-';
                i += 1;}}
        fprintf(output,"|");
        fclose(input);
        fclose(output);
        printf("Do you want to continue? Print n for close or any button for continue");
        scanf(" %c", &end);}
    return 0;}



// block with functions
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
    return num2;
}


// Adding to the stack
void push(stack **head, float value) {
    stack *tmp = malloc(sizeof(stack));
    tmp->next = *head;
    tmp->value = value;
    *head = tmp;
}


// Taking elements from the stack
float pop(stack **head) {
    stack *out;
    float value;
    out = *head;
    *head = (*head)->next;
    value = out->value;
    free(out);
    return value;
}

