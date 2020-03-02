/*
 ============================================================================
 Name        : project_01.c
 Author      : Sxrxkn
 Version     : 1.0
 Copyright   :
 Description : A calculator that can work with float numbers with operations as
               multiplication'*', division'/', addition'+', subtraction'-',
               exponentiation'^',factorial'!'.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int d,v;
float a,b,res,factorial,resu;
char c,r,m;
int main(int argc,char *argv[]) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    r='y';
    while(r=='y'){ // Cycle to repeat the program
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
                    break; }}
        printf("Continue? (y/n)");// Ability to repeat the program
        scanf(" %c",&r);}
    return 0;}
