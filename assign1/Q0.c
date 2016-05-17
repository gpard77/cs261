/* CS261- Assignment 1 - Q. 0*/
/* Name: Geoffrey Pard
 * Date: 6/24/15
 * Solution description: Pointer Practice
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
     printf("Value of Pointer iptr: %d\n", *iptr);
     
     /*Print the address pointed to by iptr*/
     printf("Address pointed to by iptr: %p\n", iptr);
     
     /*Print the address of iptr itself*/
     printf("Address of Pointer iptr: %p\n", &iptr);
}

int main(){
    
    /*declare an integer x*/
    int x = 3;
    
    /*print the address of x*/
    int * iptr = &x;
    printf("Address of \'X\': %p\n", iptr);
    
    /*Call fooA() with the address of x*/
    fooA(iptr);
    printf("\n");
    
    /*print the value of x*/
    printf("Value of \'X\': %d\n\n", x);
    
    return 0;
}
