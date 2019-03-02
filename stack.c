//
// Created by Osaid K on 9/29/18.
//

#include <stack_arr.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



void makeStack(Stack312 *s){
   s->top=-1;             //Initiating the Stack!
}

bool isFull(Stack312 s){
   if (s.top >= 79) {
       return true; }   // checking for overflow
   else return false;
}

bool isEmpty(Stack312 s){
    if(s.top==-1) { return true;}   // Check if stack is empty
    else return false;
}

void push(StackEntry e,Stack312 *s){
    s->top++;
    s->elements[s->top]=e;
}

StackEntry pop(Stack312 *s){
    StackEntry element;
    element= s->elements[s->top];
    s->top--;
    return element;
}