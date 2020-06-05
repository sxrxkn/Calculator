/*
 ============================================================================
 Name        : Modular.c
 Author      : Sxrxkn
 Version     : 1.0
 Copyright   : 
 Description : This is a modular project, which supports the work of the three calculators:
 with lists, queues, and a stack. Calculator with list supports operations such as
 on vectors and float numbers(with operations as
 multiplication'*', division'/', addition'+', subtraction'-',
 exponentiation'^',factorial'!') and vectors (with operation as
 addition'+', subtraction'-', scalar multiplication'*').Other calculators support all the same things,
 except for operations on vectors. If you are working with a stack or queue and want to
 read multiple lines from a file, separate the lines with the n character.
 For example:
2 4 + n
3 ! n
10.5 5.5 / n
2 3 ^
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "queue.h"
#include "stack.h"

// main block
char calc;
int main(void) {
	printf("If you want to work with list calculator print'1' \n");
	printf("If you want to work with queue calculator print '2'\n");
	printf("If you want to work with stack calculator print '3'");
	scanf(" %c", &calc);
	switch(calc){
	case '1':{
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
	}
	break;
	case '2':{
	    FILE *input, *output;
	    stack *head_stack = NULL;
	    int i = 0, counter = 0;
	    char end = 'n', inputfile[100], outputfile[100], tmp, tmp_numb[20], op ='-';
	    float num, num1, num2;
	    while(end == 'n'){ // Repeat the program
	            printf("Enter name of input file:");
	            scanf(" %s", inputfile);
	            printf("Enter name of output file:");
	            scanf(" %s", outputfile);
	            input = fopen(inputfile, "r");
	            while(!feof(input)){ // Read while the file is not finish
	                fscanf(input, "%c", &tmp);
	                if(tmp != '\n'){ // Excluding the line transition character
	                    if(tmp == ' ') // Changing spaces to '_' to separate characters
	                        tmp = '_';
	                    put_queue(tmp);
	                    i += 1;}}
	            fclose(input);
	            output = fopen(outputfile, "w");
	            while(i != 1){ // Works until all characters are used
	                tmp_numb[counter] = *get_element();
	                if (tmp_numb[counter] == '_'){ // Converting a string to a number and putting it on the stack
	                    if (op == '-') {
	                        tmp_numb[counter] = ' ';
	                        num = strtof(tmp_numb, NULL);
	                        push_queue(&head_stack, num);
	                        for(int k = 0; k<(counter+1); k++)
	                            tmp_numb[k] = 0;
	                        i -= 1;
	                        counter = 0;
	                    }
	                    else
	                        i -=1;}
	                else if(tmp_numb[counter] == '!'){ // Perform the operation and write it to the file
	                    num1 = pop_queue(&head_stack);
	                    num2 = 0;
	                    push_queue(&head_stack,operation_on_numbers_queue(tmp_numb[counter], num1 , num2));
	                    fprintf(output, "%f %c = %f -> ", num1, tmp_numb[counter], operation_on_numbers_queue(tmp_numb[counter], num1 , num2));
	                    i -= 1;
	                    counter = 0;
	                    op = '+';}
	                else if(tmp_numb[counter] =='*' || tmp_numb[counter] =='+' || tmp_numb[counter]=='-' || tmp_numb[counter] =='/' || tmp_numb[counter]=='^'){
	                    if(head_stack == NULL) // Perform the operations and write it to the file
	                        break;
	                    num2 = pop_queue(&head_stack);
	                    if(head_stack == NULL)
	                        break;
	                    num1 = pop_queue(&head_stack);
	                    push_queue(&head_stack, operation_on_numbers_queue(tmp_numb[counter], num1, num2));
	                    fprintf(output, "%f %c %f = %f -> ", num1, tmp_numb[counter], num2, operation_on_numbers_queue(tmp_numb[counter], num1 , num2));
	                    op ='+';
	                    i -= 1;
	                    counter=0;}
	                else if(tmp_numb[counter]=='n'){ // Switching to another line
	                 while(head_stack != NULL)
	                     pop_queue(&head_stack);
	                 fprintf(output, "|\n");
	                 counter = 0;
	                 i -=1;
	                 op = '-';
	                }
	                else{  // If we didn't count the whole number
	                    counter += 1;
	                    i -=1;
	                }
	                    }
	            fprintf(output,"|");
	            fclose(output);
	            printf("If you want to continue, press 'n', press any button to turn it off: ");
	            scanf(" %c", &end);}
	}
	break;
	case '3':{
	    char inputfile[100], outputfile[100], end = 'n', temp[100], op = '-';
	    FILE *input, *output;
	    stack1 *head_stack_1 = NULL;
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
	                    push(&head_stack_1, num); // Put it on the stack
	                    for(int k = 0; k<(i+1); k++)
	                        temp[k] = 0;
	                    i = 0;
	                }}
	            else if(temp[i] == '!'){
	                // if operation = !, taking a single number from the stack and performing the operation
	                num1 = pop(&head_stack_1);
	                num2 = 0;
	                push(&head_stack_1,operation_on_numbers_stack(temp[i], num1 , num2));
	                fprintf(output, "%f %c = %f -> ", num1, temp[0], operation_on_numbers_stack(temp[i], num1 , num2)); //writing to a file
	                i = 0;
	                op = '+';}
	            else if(temp[i] =='*' || temp[i] =='+' || temp[i]=='-' || temp[i] =='/' || temp[i]=='^'){
	                // if the operation is equal to one of the above, we get two numbers from the stack and perform the operation
	                if(head_stack_1 == NULL)
	                    break;
	                num2 = pop(&head_stack_1);
	                if(head_stack_1 == NULL)
	                    break;
	                num1 = pop(&head_stack_1);
	                push(&head_stack_1, operation_on_numbers_stack(temp[i], num1, num2));
	                fprintf(output, "%f %c %f = %f -> ", num1, temp[i], num2, operation_on_numbers_stack(temp[i], num1 , num2)); // writing to a file
	                op ='+';}
	            else if(temp[i]=='n'){ // switching to another line
	             while(head_stack_1 != NULL)
	                 pop(&head_stack_1);
	             fprintf(output, "|\n");
	            }
	            else{
	                op ='-';
	                i += 1;}}
	        fprintf(output,"|");
	        fclose(input);
	        fclose(output);
	        printf("If you want to continue, press 'n', press any button to turn it off: ");
	        scanf(" %c", &end);}
	}
	break;
	default:{
	    printf("You entered the wrong number");
	}
	}

    return 0;
}
