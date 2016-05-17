/* CS261- Assignment 1 - Q.3*/
/* Name: Geoffrey Pard
 * Date: 6/25/15
 * Solution description: Dynamically Allocate memory for an
 *   array of ints; pass the array and size into a sort function;
 *   print before and after.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sort(int* number, int n){
     /*Sort the given array number , of length n*/
     int start, minIndex, minVal;

     for (start = 0; start < (n-1); start++)
     {
        minIndex = start;
        minVal = number[start];

        for (int i = start + 1; i < n; i++)
        {
           if (number[i] < minVal)
           {
              minVal = number[i];
              minIndex = i;
           }
        }
        number[minIndex] = number[start];
        number[start] = minVal;
      }          
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;

    /*Allocate memory for an array of n integers using malloc.*/
    int *array;
    array = (int *)malloc(n * sizeof(int));

    /*Fill this array with random numbers, using rand().*/
    for (int i = 0; i < n; i++)
    {
       array[i] = rand() % 100;
    }

    /*Print the contents of the array.*/
    for (int i = 0; i < n; i++)
    {
       printf("%d ", array[i]);
    }
    printf("\n");
  
    /*Pass this array along with n to the sort() function of part a.*/
    sort(array, n);    

    /*Print the contents of the array.*/    
    for (int i = 0; i < n; i++)
    {
       printf("%d ", array[i]);
    }
    printf("\n");
  

    return 0;
}
