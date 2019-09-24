#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int genNumber(int *v)
{
    time_t t;
    srand((unsigned) time(&t));
    int g;
    g = rand() % *v;
    return g;
}

/* Not needed, but useful for future projects
void clearbuff()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
*/

int main()
{
    char cMaxChars[5];
    int maxChars;
    double base = 10;
    int maxValue;
    char guess [10];
    int iguess;
    
    printf("Choose the max number of digits in the secret number: ");
    fgets(cMaxChars , sizeof(cMaxChars) , stdin);
    //clearbuff();
    maxChars = atoi(cMaxChars);
    maxValue = pow(base , maxChars - 1);
    int magicNum = genNumber(&maxValue);
    // For testing printf("%d\n" , magicNum);
    while (iguess != magicNum)
    {   
        printf("Guess a number between 0 and %i: " , maxValue);
        fgets(guess , sizeof(guess) , stdin);
        iguess = atoi(guess);
        //printf("%d" , iguess);
        if (iguess < magicNum)
        {
            printf("That's too low! Try again! ");
        }
        if (iguess > magicNum)
        {
            printf("That's too high! Try again! ");
        }
        if (iguess == magicNum)
        {
            printf("You guessed the correct number!");
        }
        
    }
    
    
    
    return 0;
}
