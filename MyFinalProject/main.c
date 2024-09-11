#include<stdio.h>
#include<string.h>


void startGame(int intRandomNumber);
/*---------------------------------------------------------
Begin of the main function
-----------------------------------------------------------*/
int main()
{
    //variable initialization
    int intRandomNumber = 0;

    printf("            `!`  Welcome to Just Say The Word Game  `!`\n");
    //Give commands to the user to enter a number to guess the word
    printf("Enter a Random Number : ");
    //Scan and Store the user Entered Number in the variable intRandomNumber
    scanf("%d",&intRandomNumber);
   do
    {
        printf("Enter a Random Number  : ");
        scanf("%d",&intRandomNumber);
    }
    while
      ( intRandomNumber >= 15);





    return 0;
}
