//
// Created by Osaid K on 9/29/18.
//



#include<stdio.h>
#include<stdbool.h>
#include <string.h>
#include <stack_arr.h>
#include <stdlib.h>


//int argc, char *argv[]
int main () {
    Stack312 equation;
    int flag=0;
    int index = 0;
    int len;
    StackEntry item;
  // char fName[strlen(argv[1])];
  // strcpy(fName, argv[1]);
    char buf[BUFSIZ];       // A buffer to extract file data then dump it in the grid.
    FILE *fileptr;
    fileptr = fopen("fake_picture.txt", "r");
    if (fileptr == NULL) {
        printf("Cannot open file!\n");
        exit(0);
    }

    while (fscanf(fileptr, "%s", buf) != EOF) {

        len = strlen(buf);
        makeStack(&equation);
        for (int i = 0; i < len; i++) {
            char e = buf[i];
            if (isFull(equation)) {
                printf("\n");
                printf("Error, Stack is full.");
                return 0;
            }
            push(e, &equation);
        }
        push('\0', &equation);
        equation.top--;
        printf("\n");

        int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0;
        int top = equation.top;


         while (!isEmpty(equation)) {
              item = pop(&equation);

                if (item == '[') { count1++; }  // counting delimiters
                if (item == ']') { count2++; }
                if (item == '(') { count3++; }
                if (item == ')') { count4++; }
                if (item == '<') { count5++; }
                if (item == '>') { count6++; }
             if ((item == ']' && count1>0)  || (item== ')' && count3>0)|| (item=='>' && count5>0))  { flag=1;}
            }

             // checking when an expression is invalid

             if (flag==1) {printf("%s === invalid expression", equation.elements); }
             else if (count1 > count2) {
                printf("%s === missing %c", equation.elements, ']');
            } else if (count1 < count2) {
                printf("%s === missing %c", equation.elements, '[');
            } else if (count3 > count4) {
                printf("%s === missing %c", equation.elements, ')');
            } else if (count3 < count4) {
                printf("%s === missing %c", equation.elements, '(');
            } else if (count5 > count6) {
                printf("%s === missing %c", equation.elements, '>');
            } else if (count5 < count6) {
                printf("%s === missing %c", equation.elements, '<');
            } else if (count1 == 0 && count2 == 0 && count3 == 0 && count4 == 0 && count5 == 0 && count6 == 0) {
                printf("%s === There is nothing to be checked!", equation.elements);
            } else printf("%s === valid expression", equation.elements);

   flag=0;
        }

    }



