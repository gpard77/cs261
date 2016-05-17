/* CS261- Assignment 1 - Q.1*/
/* Name: Geoffrey Pard
 * Date: 6/24/15
 * Solution description: Create 10 students using the
 *  struct student framework; assign random test scores;
 *  find min, max, average; print results; free memory
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student{
	int id;
	int score;
};
const int NUMSTUDENTS = 10;

struct student* allocate(){
     /*Allocate memory for ten students*/

     struct student *myStudents = malloc(NUMSTUDENTS * sizeof(struct student));
     /*return the pointer*/
     return myStudents;
}

void generate(struct student* students){
     /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/

     for (int i = 0; i < NUMSTUDENTS; i++)
     {        
        students[i].id = (i+1);   
        students[i].score = rand() % 101;
     } 
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
     for (int i = 0; i < NUMSTUDENTS; i++)
     {
        printf("ID %d:\tScore: %d\n", students[i].id, students[i].score);
     }

}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     int min = students[0].score;
     int max = students[0].score;

     for (int i = 0; i < NUMSTUDENTS; i++)
     {
        if (min > students[i].score)
        {
           min = students[i].score;
        }
        if (max < students[i].score)
        {
           max = students[i].score;
        }
     }

     // Find Average
     int total = 0;
     double average = 0;
     for (int j = 0; j < NUMSTUDENTS; j++)
     {
        total += students[j].score;
     }
     average = (double) total / NUMSTUDENTS;

     // Print Min, Max, Average
     printf("-----------------------\n");
     printf("Min Student Score: %d\n", min);
     printf("Max Student Socre: %d\n", max);
     printf("Average Score: %0.2f\n", average);
     printf("\n");

}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
     if (stud != NULL)
     {
        free(stud);
     }
}

int main(){

    // Declare Pointer to a Struct Student
    struct student * stud = NULL;
    
    /*call allocate*/
    stud = allocate();
    
    /*call generate*/
    generate(stud);
    
    /*call output*/
    output(stud);
    
    /*call summary*/
    summary(stud);
    
    /*call deallocate*/
    deallocate(stud);    

    return 0;
}
