/* Copyright 2019 camrockz https://github.com/camrockz/ */

/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <errno.h>

int get_int()
{
    char buffer[10];
    char *endp;
    errno = 0;
    fgets(buffer , sizeof(buffer) , stdin);
    int ret_int = strtol(buffer , &endp , 10);
    
    if (*endp != '\n')
    {
        fprintf(stderr , "Invalid input\n");
        exit(EXIT_FAILURE);
    }
    
    if (errno != 0 && ret_int == 0)
    {
        perror("strtol");
        exit(EXIT_FAILURE);
    }
    if (endp == (char*)&buffer)
    {
        fprintf(stderr , "There were no numbers found");
        exit(EXIT_FAILURE);
    }
    return ret_int;
}

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
    int maxChars;
    double base = 10;
    int maxValue;
    int guess;
    
    printf("Choose the max number of digits in the secret number: ");
    maxChars = get_int();
    maxValue = pow(base , maxChars - 1);
    int magicNum = genNumber(&maxValue);
    // For testing printf("%d\n" , magicNum);
    while (guess != magicNum)
    {   
        printf("Guess a number between 0 and %i: " , maxValue);
        guess = get_int();
        //printf("%d" , iguess);
        if (guess < magicNum)
        {
            printf("That's too low! Try again! ");
        }
        if (guess > magicNum)
        {
            printf("That's too high! Try again! ");
        }
        if (guess == magicNum)
        {
            printf("You guessed the correct number!");
        }
    }
    return 0;
}
