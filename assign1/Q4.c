/* CS261- Assignment 1 - Q.4*/
/* Name: Geoffrey Pard
 * Date: 6/25/15
 * Solution description: Dynamically Allocate memory
 *  for a number of struct elements; assign ids and
 *  test scores; sort by test score, print.
 */
 
#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
 
     /*Sort the n students based on their score*/     
    
      int i, j;
  
      for (i = 1; i < n; i++)
      {
         for (j = 0; j < n-i; j++)
         {
            if (students[j].score > students[j+1].score)
            {
               struct student temp = students[j];
               students[j] = students[j+1];
               students[j+1] = temp;
            }
          }
        }  
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 10; 

    /*Allocate memory for n students using malloc.*/
    struct student *class = malloc(n * sizeof(struct student));

    /*Generate random IDs and scores for the n students, using rand().*/
    for (int i = 0; i < n; i++)
    {
       class[i].id = (i+1);
       class[i].score = rand() % 100 + 1;
    }

    /*Print the contents of the array of n students.*/
    for (int i = 0; i < n; i++)
    {
        printf("ID %2d:\tScore: %3d\n", class[i].id, class[i].score);
    }
    printf("\n");

    /*Pass this array along with n to the sort() function*/
    sort(class, n);    

    /*Print the contents of the array of n students.*/
    printf("Sorted by Score: \n");
    for (int i = 0; i < n; i++)
    {
        printf("ID %2d:\tScore: %3d\n", class[i].id, class[i].score);
    }
    printf("\n");

    return 0;
}
