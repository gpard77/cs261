/* CS261- Assignment 1 - Q.2*/
/* Name: Geoffrey Pard
 * Date: 6/25/15
 * Solution description: Declare three ints; pass two
 * by reference; notice the results.
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a *= 2;
    /*Set b to half its original value*/
    *b /= 2;
    /*Assign a+b to c*/
    c = *a + *b;
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5;
    int y = 6;
    int z = 7;

    /*Print the values of x, y and z*/
    printf("x = %d\n", x); 
    printf("y = %d\n", y); 
    printf("z = %d\n", z); 

    /*Call foo() appropriately, passing x,y,z as parameters*/
    int value = 0;  
    value = foo(&x, &y, z);
 
    /*Print the value returned by foo*/
    printf("Value = %d\n", value);

    /*Print the values of x, y and z again*/
    printf("x = %d\n", x); 
    printf("y = %d\n", y); 
    printf("z = %d\n", z); 


    /*Is the return value different than the value of z?  Why?*/

    /*************************************************************************
     * C is a pass by value language, so unless variables are
     * passed by reference the functions will not alter
     * the variable values assigned in main.  In this example, only x & y
     * are passed by reference.  "Z" is passed by value so its
     * inital value in main remains unchanged.  The function 
     * calculates appropriately and returns the value to main, but
     * "Z" stays 7.
     ************************************************************************/
    return 0;
}
    
    
