/*
 ============================================================================
 Name        : project_01.c
 Author      : Sxrxkn
 Version     : 3.0
 Copyright   :
 Description : A calculator that can work with files and the console
               with float numbers (with operations as
               multiplication'*', division'/', addition'+', subtraction'-',
               exponentiation'^',factorial'!') and vectors (with operation as
               addition'+', subtraction'-', scalar multiplication'*').
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int d,v,size;
float a,b,res,factorial,resu,summ,*e,*l,*resul;
char c,r,m,numb,op,t,br1,br2, inputfile[100], outputfile[100];
FILE *input,*output;
int main(int argc,char *argv[]) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    r='y';
    while(r=='y'){// Cycle to repeat the program
    printf("if you want to work with files, enter (f), if you want to work with the console , enter (c) ");
    scanf(" %c", &c);
    switch (c) {
    case 'f': //If we work with files
        printf("Enter name of input file:");
        scanf(" %s", inputfile);
        printf("Enter name of output file:");
        scanf(" %s", outputfile);
        input = fopen(inputfile,"r");
        output = fopen(outputfile, "w");
   fscanf(input," %c",&op);//Reading the operation from the file
   fscanf(input," %c",&t);//Reading the type from the file
    if(t == 's'){ //If we work with console
        do { // Cycle for correct operation input
            if(op=='+'|| op=='-'||op=='*'||op=='^'||op=='/'||op=='!') r='d';
            else printf("Incorrect operation, \n");}
        while (r!='d');
        if(op == '!'){ // Operation "!"
            fscanf(input," %f",&a);
            if  (a>=0){ // If the numbers is greater than 0
                resu=1;
                for(int i=1;i<a+1;i++){
                    resu=resu*i;}
                fprintf(output,"%.3f! = %.3f",a, resu);}
            else   printf("Invalid number");} // If the numbers if numbers is less than 0
        else if (op == '^'){ // Operation "^"
                   fscanf(input," %f",&a);
            fscanf(input," %i",&d);
            res = 1;
            for(int i=0;i<d;i++) {
                res=res*a;}
            fprintf(output,"%.3f ^ %i = %.3f",a, d, res);}
        else{
            fscanf(input," %f",&a);
            fscanf(input," %f",&b);
            switch (op) { // Operations "+-*/"
               case '+':
                    fprintf(output,"%.3f + %.3f = %.3f", a, b, a+b);
                    break;
                case '-':
                    fprintf(output,"%.3f - %.3f = %.3f", a, b, a-b);
                    break;
                case '*':
                    fprintf(output,"%.3f * %.3f = %.3f", a, b, a*b);
                    break;
                case '/':
                    if(b !=0)
                        fprintf(output,"%.3f / %.3f = %.3f", a, b, a/b);
                    else fprintf(output,"No solution");// If divide by 0
                    break; }} }
    else if(t=='v'){// If we work with vectors
        e=malloc(size*sizeof(int));
        l=malloc(size*sizeof(int));
        resul=malloc(size*sizeof(int));
        if (op == '+'){ // Operation +
            fscanf(input," %i",&size);
            br1='(';
            br2=')';
            fprintf(output,"%c",br1);
            for(int i=0;i<size;i++){ // Cycle for entering the first vector
                fscanf(input," %f",&e[i]);
                fprintf(output," %f ",e[i]);}
            fprintf(output,"%c",br2);
            fprintf(output," %c ",op);
            fprintf(output,"%c ",br1);
            for(int i=0;i<size;i++){ // Cycle for entering the second vector
                fscanf(input," %f",&l[i]);
                fprintf(output,"%f ",l[i]);}
            fprintf(output,"%c",br2);
            op = '=';
            fprintf(output," %c ",op);
            fprintf(output,"%c ",br1);
            for(int i=0;i<size;i++)
                fprintf(output,"%f ",e[i]+l[i]);
            fprintf(output,"%c ",br2);
            fprintf(output,"\n");}
        else if (op == '-'){ // Operation -
            fscanf(input," %i",&size);
            br1='(';
            br2=')';
            fprintf(output,"%c",br1);
            for(int i=0;i<size;i++){ // Cycle for entering the first vector
                fscanf(input," %f",&e[i]);
                fprintf(output," %f ",e[i]);}
            fprintf(output,"%c",br2);
            fprintf(output," %c ",op);
            fprintf(output,"%c ",br1);
            for(int i=0;i<size;i++){ // Cycle for entering the second vector
                fscanf(input," %f",&l[i]);
                fprintf(output,"%f ",l[i]);}
           fprintf(output,"%c",br2);
            op = '=';
            fprintf(output," %c ",op);
            fprintf(output,"%c ",br1);
            for(int i=0;i<size;i++)
                fprintf(output,"%f ",e[i]-l[i]);
            fprintf(output,"%c ",br2);
            fprintf(output,"\n");}
        else if (op == '*'){ //Operation *
            br1='(';
            br2=')';
            fprintf(output,"%c",br1);
            fscanf(input," %i",&size);
            for(int i=0;i<size;i++){
                fscanf(input," %f",&e[i]);
            fprintf(output,"%f ",e[i]);}
            fprintf(output,"%c",br2);
            fprintf(output," %c ",op);
            fprintf(output,"%c",br1);
            for(int i=0;i<size;i++){
                fscanf(input," %f",&l[i]);
                fprintf(output,"%f ",l[i]);}
            fprintf(output,"%c",br2);
            for(int i=0;i<size;i++) // Cycle for for performing the operation *
                summ=summ + e[i]*l[i];
            fprintf(output," = %.3f",summ);}
        else if (op!='*'|| op!="+" || op!="-") // If entered invalid operation
            fprintf(output,"Invalid operation entered");
        free(e);
        free(l);
        free(resul);}
    fclose(input);
    fclose(output);
    break;
    case 'c': //If we work with console
        printf("For operations on vectors, enter (v), for operations on numbers , enter(n): ");
        scanf(" %c",&c);
        if(c == 'n'){
            do { // Cycle for correct operation input
                puts("Enter the correct operation(-+/^!*): \n");
                scanf(" %c",&c);
                if(c=='+'|| c=='-'||c=='*'||c=='^'||c=='/'||c=='!') r='d';
                else printf("Incorrect operation, \n");}
            while (r!='d');
            if(c=='!'){ // Operation "!"
                puts("Enter number: \n");
                scanf(" %f",&factorial);
                if  (factorial>=0){ // If the numbers is greater than 0
                    resu=1;
                    for(int i=1;i<factorial+1;i++){
                        resu=resu*i;}
                    printf("Result %2f (operation %c)",resu,factorial);}
                else   printf("Invalid number");} // If the numbers if numbers is less than 0
            else if (c == '^'){ // Operation "^"
                puts("Enter the first number: \n");
                scanf(" %f",&a);
                puts("Enter the second number: \n");
                scanf(" %i",&d);
                res = 1;
                for(int i=0;i<d;i++) {
                    res=res*a;}
                printf("Result %f (operation %c)",res,d);}
            else{ puts("Enter the first number: \n");
                scanf(" %f",&a);
                puts("Enter the second number: \n");
                scanf(" %f",&b);
                switch (c) { // Operations "+-
                    case '+':
                        printf("Result %f (operation %c)",a+b,c);
                        break;
                    case '-':
                        printf("Result %f (operation %c)",a-b,c);
                        break;
                    case '*':
                        printf("Result %f (operation %c)",a*b,c);
                        break;
                    case '/':
                        if(b !=0)
                            printf("Result %f (operation %c)",a/b,c);
                        else printf("No solution");// If divide by 0
                        break; }} }
        else if(c=='v'){ // If we work with vectors
            printf("Enter an operation on vectors(+-*): ");
            scanf(" %c",&c);
            e=malloc(size*sizeof(int));
            l=malloc(size*sizeof(int));
            resul=malloc(size*sizeof(int));
            if (c == '+'){ // Operation +
                printf("Enter vector's size: ");
                scanf(" %i",&size);
                printf("Enter first vector: ");
                for(int i=0;i<size;i++) // Cycle for entering the first vector
                    scanf(" %f",&e[i]);
                printf("Enter second vector: ");
                for(int i=0;i<size;i++) // Cycle for entering the second vector
                    scanf(" %f",&l[i]);
                printf("Result vectors addition: ");// Cycle for for performing the operation +
                for(int i=0;i<size;i++)
                    printf("%f ",e[i]+l[i]);
                printf("\n");}
            else if (c == '-'){
                printf("Enter vector's size: ");
                scanf(" %i",&size);
                printf("Enter first vector: ");
                for(int i=0;i<size;i++)
                    scanf(" %f",&e[i]);
                printf("Enter second vector: ");
                for(int i=0;i<size;i++)
                    scanf(" %f",&l[i]);
                printf("Result vectors subtraction : ");
                for(int i=0;i<size;i++)// Cycle for for performing the operation -
                    printf("%f ",e[i]-l[i]);
                printf("\n");}
            else if (c == '*'){
                printf("Enter vector's size: ");
                scanf(" %i",&size);
                printf("Enter first vector: ");
                for(int i=0;i<size;i++)
                    scanf(" %f",&e[i]);
                printf("Enter second vector: ");
                for(int i=0;i<size;i++)
                    scanf(" %f",&l[i]);
                printf("Result vectors multiplication: ");
                for(int i=0;i<size;i++) // Cycle for for performing the operation *
                    summ=summ + e[i]*l[i];
                printf("%f",summ);}
            else if (c!='*'|| c!="+" || c!="-") // If entered invalid operation
                printf("Invalid operation entered");
            free(e);
            free(l);
            free(resul);}
        break;}
    printf("Continue? (y/n)");// Ability to repeat the program
    scanf(" %c",&r);}
    return 0;}
