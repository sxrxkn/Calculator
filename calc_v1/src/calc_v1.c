/*
 ============================================================================
 Name        : project_01.c
 Author      : Sxrxkn
 Version     : 2.0
 Copyright   :
 Description : A calculator that can work with float numbers with operations as
               multiplication'*', division'/', addition'+', subtraction'-',
               exponentiation'^',factorial'!' and vectors with operation as
               addition'+', subtraction'-', scalar multiplication(*).
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int d,v,size;
float a,b,res,factorial,resu,summ,*e,*l,*resul;
char c,r,m;
int main(int argc,char *argv[]) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    r='y';
    while(r=='y'){ // Cycle to repeat the program
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
            switch (c) { // Operations "+-*/"
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
        printf("Continue? (y/n)");// Ability to repeat the program
        scanf(" %c",&r);}
    return 0;}
