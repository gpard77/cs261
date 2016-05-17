/********************************************************
 * Geoffrey Pard
 * CS 261 - 400
 *
 * Reverse Polish Calculator
 *******************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynamicArray.h"
#include <assert.h>

/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;

	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	else 
	{
		returnNum = strtod(s, &end);
		/* If there's anythin in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their sum is pushed back onto the stack.
*/
void add (struct DynArr *stack)
{
	/* FIXME: You will write this function */
        double x, y, sum;

        assert(sizeDynArr(stack) >= 2);

        x = topDynArr(stack);
        popDynArr(stack);
        y = topDynArr(stack);
        popDynArr(stack);

        // Sum Top Values Retrieved
        sum = x + y;

        // Add back to stack
        pushDynArr(stack, sum);
      
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
	/* FIXME: You will write this function */
        double x, y, diff;

        assert(sizeDynArr(stack) >= 2);

        x = topDynArr(stack);
        popDynArr(stack);
        y = topDynArr(stack);
        popDynArr(stack);

        // Subtract Top Values Retrieved
        diff = x - y;

        // Push Value back to stack
        pushDynArr(stack, diff);
        
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
	/* FIXME: You will write this function */
        double x, y, div;

        assert(sizeDynArr(stack) >= 2);

        x = topDynArr(stack);
        popDynArr(stack);
        y = topDynArr(stack);

        // Divide Top Values Retrieved
        div = x / y;

        // Push Value back to stack
        pushDynArr(stack, div);
}

void multiply(struct DynArr *stack)
{
   double x, y, multi;

   assert(sizeDynArr(stack) >= 2);

   x = topDynArr(stack);
   popDynArr(stack);
   y = topDynArr(stack);
   popDynArr(stack);

   // Multiply Top Values Retrieved
   multi = x * y;

   // Push Value back to stack
   pushDynArr(stack, multi);
}

void power(struct DynArr *stack)
{
   double x, y, exp;

   assert(sizeDynArr(stack) >= 2);

   x = topDynArr(stack);
   popDynArr(stack);
   y = topDynArr(stack);
   popDynArr(stack);

   // With Top Values Retrieved
   // Raise X to the Y power
   exp = pow(x, y);

   // Push Value Back To Stack
   pushDynArr(stack, exp);
}

void squared(struct DynArr *stack)
{
   double x, square;

   assert(sizeDynArr(stack) >= 1);

   x = topDynArr(stack);
   popDynArr(stack);

   // Square Top Value Retrieved
   square = pow(x, 2);

   // Push value back to stack
   pushDynArr(stack, square);
}

void cubed(struct DynArr *stack)
{
   double x, cube;

   assert(sizeDynArr(stack) >= 1);

   x = topDynArr(stack);
   popDynArr(stack);

   // Cube Top Value Retrieved
   cube = pow(x, 3);

   // Push Value back to stack
   pushDynArr(stack, cube);
}

void absoluteValue(struct DynArr *stack)
{
   double x, absVal;

   assert(sizeDynArr(stack) >= 1);

   x = topDynArr(stack);
   popDynArr(stack);

   // Find Absolute Value of Top Values Retrieved
   absVal = abs(x);

   // Push value back to stack
   pushDynArr(stack, absVal);
}

void squareRoot(struct DynArr *stack)
{
   double x, root;

   assert(sizeDynArr(stack) >= 1);

   x = topDynArr(stack);
   popDynArr(stack);

   // Find the Root of Top Value Retrieved
   root = sqrt(x);

   // Push Value back to stack
   pushDynArr(stack, root);
}

void exponential(struct DynArr *stack)
{
   double x, expVal;

   assert(sizeDynArr(stack) >= 1);

   x = topDynArr(stack);
   popDynArr(stack);

   // Find e^x of Top Value Retrieved
   expVal = exp(x);

   // Push Value back to stack
   pushDynArr(stack, expVal);
}

void natLog(struct DynArr *stack)
{
   double x, natLogVal;

   assert(sizeDynArr(stack) >= 1);

   x = topDynArr(stack);
   popDynArr(stack);

   // Find NatLog of Top Value Retrieved
   natLogVal = log(x);

   // Push value back to stack
   pushDynArr(stack, natLogVal);
}

void logTen(struct DynArr *stack)
{
   double x, logVal;

   assert(sizeDynArr(stack) >= 1);

   x = topDynArr(stack);
   popDynArr(stack);

   // Compute Log of Top Value Retrieved
   logVal = log10(x);

   // Push Value back to stack
   pushDynArr(stack, logVal);
}

double calculate(int numInputTokens, char **inputString)
{
	int i;
	double result = 0.0;
	char *s;
	struct DynArr *stack;
        double *numVal = malloc(sizeof(double));

	//set up the stack
	stack = createDynArr(20);

	// start at 1 to skip the name of the calculator calc
	for(i=1;i < numInputTokens;i++) 
	{
		s = inputString[i];

		// Hint: General algorithm:
		// (1) Check if the string s is in the list of operators.
		//   (1a) If it is, perform corresponding operations.
		//   (1b) Otherwise, check if s is a number.
		//     (1b - I) If s is not a number, produce an error.
		//     (1b - II) If s is a number, push it onto the stack

		if(strcmp(s, "+") == 0)
			add(stack);
		else if(strcmp(s,"-") == 0)
			subtract(stack);
		else if(strcmp(s, "/") == 0)
			divide(stack);
		else if(strcmp(s, "x") == 0)
			/* FIXME: replace printf with your own function */
			multiply(stack);
		else if(strcmp(s, "^") == 0)
			/* FIXME: replace printf with your own function */
			power(stack);
		else if(strcmp(s, "^2") == 0)
			/* FIXME: replace printf with your own function */
		        squared(stack);
		else if(strcmp(s, "^3") == 0)
			/* FIXME: replace printf with your own function */
			cubed(stack);
		else if(strcmp(s, "abs") == 0)
			/* FIXME: replace printf with your own function */
			absoluteValue(stack);
		else if(strcmp(s, "sqrt") == 0)
			/* FIXME: replace printf with your own function */
			squareRoot(stack);
		else if(strcmp(s, "exp") == 0)
			/* FIXME: replace printf with your own function */
			exponential(stack);
		else if(strcmp(s, "ln") == 0)
			/* FIXME: replace printf with your own function */
			natLog(stack);
		else if(strcmp(s, "log") == 0)
			/* FIXME: replace printf with your own function */
			logTen(stack);
		else 
		{
			// FIXME: You need to develop the code here (when s is not an operator)
			// Remember to deal with special values ("pi" and "e")
			if (strcmp(s, "pi") == 0)
                        {
                           pushDynArr(stack, 3.14159265);
                        }
                        else if (strcmp(s, "e") == 0)
                        {
                           pushDynArr(stack, 2.7182818);
                        }
                        else if (isNumber(s, numVal) == 1)
                        {
                           pushDynArr(stack, *numVal);
                        }
                        else
                        {
                           printf("Invalid Operator Entered.  Quiting.\n");
                           return 1;
                        }
		}
	}	//end for 

	/* FIXME: You will write this part of the function (2 steps below) 
	 * (1) Check if everything looks OK and produce an error if needed.
	 * (2) Store the final value in result and print it out.
	 */
     
         result = topDynArr(stack);
         printf("Result: %f\n", result);
	
	return result;
}

int main(int argc , char** argv)
{
	// assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	if (argc == 1)
		return 0;

	calculate(argc,argv);
	return 0;
}
