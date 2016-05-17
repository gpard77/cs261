/* CS261- Assignment 1 - Q.5*/
/* Name: Geoffrey Pard
 * Date: 6/25/15
 * Solution description: Use a function to invoke Sticky
 *  Caps behavior.  Each letter in a string will alternate
 *  between upper and lowercase.
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){
     /*Convert to sticky caps*/
     int i;
     int length = 0;

     // Find length of User Word
     for (i = 0; word[i] != '\0'; i++)
     {
         length++;
     }

     // Incorporate Sticky Procedure
     for (i = 0; i < length; i ++)
     {
        if (i % 2 == 0)
        {
           if (word[i] >= 'a' && word[i] <= 'z')
           {
              word[i] = toUpperCase(word[i]);
           }
         }
         else
         {
            if (word[i] >= 'A' && word[i] <= 'Z')
            {
               word[i] = toLowerCase(word[i]);
            }
          }
       } 

}

int main(){
    /*Read word from the keyboard using scanf*/
    char word[50];
    char * userWord;
    userWord = word;

    printf("Enter a word: ");
    scanf("%s", userWord);
    
    /*Call sticky*/
    sticky(userWord);
    
    /*Print the new word*/
    printf("%s\n", userWord);

    return 0;
}
