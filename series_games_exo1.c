#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main (){
    int guess_number,user_guess,count=0;
    srand(time(0));
    guess_number=rand()%100+1;
    printf("welcome to Number Guessing Game\n");
    printf("you can guess a number from 1 to 100, can guess what it is?\n");
    do
    {
        printf("enter your guess:");
        scanf("%d",&user_guess);
        count++;
        if (user_guess > guess_number)
        {
            printf("your guess is too high\n");
        }
        else if (user_guess < guess_number)
        {
            printf("your guess is too low\n");
        }
        else{
            printf("Congratulations!you guessed the number %d correctly!\n",guess_number);
        }
        
    } while (user_guess != guess_number);
    printf("you found the number in %d times\n ",count);
    return 0;
}