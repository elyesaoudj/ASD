#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>//for strcmp fonction 
const char *choices[] = {"rock", "paper", "scissors"};

int main() {
    char user_choice[10];
    int computer_choice;
    char play_again;
    srand(time(0));
    printf("--welcome to rock paper scissors game--\n ");
    do
    {
        //user choice
        printf("  -->  enter your choice :\trock\tpaper\tscissors\n");
        scanf("%s",user_choice);

        //random choice for the computer
        computer_choice=rand()%3;//0,1 or 2
        printf("computer choice: %s\n",choices[computer_choice]);

        //compare choices
        if (strcmp(user_choice,choices[computer_choice] )== 0)
        {
            printf(" ------------------\n");
            printf(" |  It's a drwa!  |\n");
            printf(" ------------------\n");
        }
        else if (   (strcmp(user_choice,"paper") == 0 && strcmp(choices[computer_choice],"rock") ==0) ||
                    (strcmp(user_choice,"rock") == 0 && strcmp(choices[computer_choice],"scissors") ==0) ||                                                                          
                    (strcmp(user_choice,"scissors") == 0 && strcmp(choices[computer_choice],"paper") ==0) 
                 )
        {
            printf(" --------------\n");
            printf(" |  you Win!  |\n");
            printf(" --------------\n");
        }
        else{
            printf(" --------------\n");
            printf(" |  you lose!  |\n");
            printf(" --------------\n");
        }

        //ask if the user wants to play again?
        printf("do you want to play again? (y/n):");
        scanf(" %c", &play_again);

    } while (play_again == 'y' || play_again == 'Y');
    printf("Thanks for playing :)\n");
    return 0;
}
