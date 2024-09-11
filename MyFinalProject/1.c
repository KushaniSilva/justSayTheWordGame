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
    printf("  Enter a Random Number : ");
    //Scan and Store the user Entered Number in the variable intRandomNumber
    scanf("%d",&intRandomNumber);



    startGame(intRandomNumber);
    return 0;
}
/*---------------------------------------------------------
End of the main function
-----------------------------------------------------------*/
/*---------------------------------------------------------
Precondition  : intRandomNumber- integer
Postcondition : None
Description   : Starting function of the game
-----------------------------------------------------------*/

void startGame(int intRandomNumber)
{
    char strUserWord[20];
    int intHintProgress = 0;
    int intWrongLetters = 0;
    int intWordLength = 0;
    int intFirstScore = 40;
    int intUserWordLength = 0;


    //One dimensional array to store the words to guess by the user
    char strWords[15][25] = {"apple","orange","sigiriya","colombo","bts","madoldoova","sinharaja","squidgame"
                             ,"netball","parakramabahu","cricket","sunil perera","blackpink","harrypotter","jupiter",
                            };

    //One dimensional array to store First three hints shown to the user
    char strFirstHints[45][50] = {"Mainly in red colour","Round shape","Tasty fruit","Mainly in Orange colour","Round shape",
                                  "Tasty fruit","Ancient rock in Sri Lanka","Located in nothern matale district","Worldwide popular historical place",
                                  "Capital city of Sri Lanka","Previously it was Jayewhardanapura Kotte","Located in western province","Boy band group",
                                  "Originated in South Korea","Worldwide famous musical group","Famous book in Sri Lanka","Written by Mr.Martin Wikramasinghe"
                                  ,"Genre - Children's Literature","Popular forest reserve","Bio diversity hotspot in Sri lanka",
                                  "Located in Sabaragamuwa & Southern province","Popular television series streaming on Netflix","Genre - Action,traveller,Survival",
                                  "Consist of 9 episodes","A sport played by two teams","Only played by female players","A team has 7 players",
                                  "A king of the kingdom in Polonnaruwa","Constructed extensive irrigation systems","The creator of ParakramaSamudraya",
                                  "A sport in between two teams","One team has 11 players","This is a bat and ball game","Popular singer in Sri Lanka",
                                  "Vocalist and guitarist","Song Writer and composer","World famous girl group","Formed by YG entertainment","Consist of 4 members",
                                  "Series of seven fantasy novels","Author - J.K.Rowling","Genre - Fantasy","Fifth planet of the solar system","Largest planet",
                                  "surrounded by dozen of moons"
                                 };

    //One dimensional array to store Three Extra hints shown to the user after entering wrong guesses for the first three chances
    char strExtraHints[45][65] = {"Originated in Central Asia","Species M.Domestica","Genus - Malas","Has various citrus species",
                                  "Has both sweet and bitter taste","Consist of vitamin C","Built for 1st Kashyapa","Located in central province",
                                  "Now it is UNESCO listed world Heritage Site","By population it is the largest city","Has population of 5.6 million",
                                  "Financial centre of the island","7 singers with dancers","First song was released at 2013","The first song name was No more dreams",
                                  "Published in 1947","This novel translated to many languages","Film also produced for the same story",
                                  "Recognized as world heritage site by UNESCO","Has a area of 88.64 square kilo meters","Established in 1978",
                                  "Written by Hwang Dong Hyuk","Country of origin is South Korea","Trending in 90 countries in Netflix","Indoor game",
                                  "First played in England United States","Famous netball player: ","He reformed buddhist practices","Born on 1153",
                                  "The successor is Vijayabahu 1","This is a bat and ball game","Both male and female play this game",
                                  "Famous player Kumar Sangakkar","Lead vocalist of the band Gypsies","Died in 2021","Associated with Sri Lanka Baila genre",
                                  "Popular song - How you like that","2 members - Jisoo,Jennie","2 members - Lisa, Rose","First published in 1997",
                                  "Story based on a young wizard and his friends in a magic school","The film series was also popular in many countries",
                                  "Has several rings","Environment not supportive to living beings","radius - 43440.7 miles"
                                 };



    intWordLength = strlen(strWords[intRandomNumber-1]);  //assigning No. of letters of the correct word which user has to guess to the variable intWordLength
    intHintProgress = (intRandomNumber-1)*3; //assigning the array index of the starting hint with respect to user entered intRandomNumber

//Check the random number is less than 15 as in the strWords array
if ((intRandomNumber-1)<15){

    //Give output to the user No. of letters in the word which the user has to guess
    printf("$$$     The word contains %d letters     $$$ \n\n",intWordLength);

     /*---Start giving hints for the user by for loop---
    Here count is the no. times which the loop goes.
    IntHintProgress is the index of the starting hint.*/
    for ( int count = intHintProgress; count<intHintProgress+3; count++)
    {

        printf("\n    (^)(^)(^)  %s  (^)(^)(^)    \n",strFirstHints[count]); //Show the hint for the user.Here the array index is count.
        printf("        Guess the correct word : ");//Give commands to the user to Enter the correct word
        scanf("%s",strUserWord);//Scan and store the user entered word in the variable strUserWord

        intWrongLetters = 0; //Count of no. of letters entered wrong by the user
        intUserWordLength = strlen(strUserWord); // Assigning number of the length of the user entered word to the variable intUserWordLength


        //Checking whether the word guessed by the user is correct or not
        if(strcmp(strWords[intRandomNumber-1], strUserWord)==0)
        {
            //If the word entered by the user is correct goes inside the loop
            printf("You Guessed the Correct word\n");//Show output that the user entered the correct word
            printf("Your Score is %d",intFirstScore);//Show the score of the user
            break;
        }

        else if(intUserWordLength>intWordLength)//Checking whether the User entered more letters than the expected No. of letters
        {
            //If the condition satisfied goes inside of the loop
            printf("You have Entered more letters than the expected No. of letters\n");//Show output that user entered more than the expected no.of letters
            printf("TRY AGAIN\n");
        }
        else if(intUserWordLength<intWordLength)//Checking whether the user entered less than the expected No. of letters
        {
            //If the condition satisfied goes inside of the loop
            printf("You have Entered less than the expected No. of letters\n");//Show output that user entered less than the expected no. of letters
            printf("TRY AGAIN\n");
        }
        else
        {
            //If all the other above conditions does not satisfied then goes inside this loop
            printf("You Guessed it wrong\n");

            //This loop is to check no.of wrong letters in the guessed word by the user
            //In here variable check is no. of occurrences loop goes through
            //It is set to length of the user entered word
            for (int check = 0; check<strlen(strWords[intRandomNumber-1]); check++)
            {
                //here if the letter in the strUserWord is not same as strWord then goes inside this block
                if (strUserWord[check]!=strWords[intRandomNumber-1][check])
                {
                    //Here the intWrongLetters is count of the wrong Letters entered by the user
                    intWrongLetters=intWrongLetters+1;
                }

            }
            //Give output to the user No. of letters wrong in the guessed word
            printf("***There are %d letters wrong in your guessed word*** \n",intWrongLetters);
            printf("TRY AGAIN\n");
        }

        //if the user failed to guess the correct word by first 3 chances then goes inside this loop for extra hints
        if (count == intHintProgress+2 && strcmp(strWords[intRandomNumber-1],strUserWord) !=0)
        {
            //If the user failed to enter the correct word in the first three attempts goes inside this loop

            //The user informed that his score will be deducted for every extra hint
            printf("\n+-+-  Now For Every Extra Hint, 10 Marks will be deducted  -+-+\n");

            //Here counter is the no.of occurrences that the loop increment
            //Variable counter will starting from intHintProgress same as the previous loop

            for (int counter = intHintProgress; counter<intHintProgress+3; counter++)
            {
                //Here the intFirstScore is score of the user
                intFirstScore = intFirstScore - 10; //The score will be deducted by 10 marks for each extra hint
                printf("\n (^)(^)(^)  %s  (^)(^)(^)\n",strExtraHints[counter]);//Show the extra hint to the user
                printf("Guess the correct word : ");//Give commands to enter the correct word to the user
                scanf("%s",strUserWord);//Scan and store the user entered word in the variable strUserWord

                intUserWordLength = strlen(strUserWord); //count of no. of letters entered by the user for the word

                //checking whether the word guessed by the user is correct or not
                if(strcmp(strWords[intRandomNumber-1], strUserWord)==0)
                {
                    //If the all letters entered by the user are correct it goes inside this block
                    printf("You Guessed the Correct word\n"); //Output that the user entered the correct word
                    printf("Your Score is %d",intFirstScore);//The score of the user will be shown here
                    break; //If the correct word guessed by the user then the loop must be break
                }

                else if(intUserWordLength>intWordLength) //Checking whether the User entered more letters than the expected No. of letters
                {
                    //If the condition satisfied then goes inside of the loop
                    printf("You have Entered more letters than the expected No. of letters");//Show output that user entered more than the expected no.of letters
                    printf("\nTRY AGAIN");
                }
                else if(intUserWordLength<intWordLength)//Checking whether the user entered less than the expected No. of letters
                {
                    //If the condition satisfied then goes inside of the loop
                    printf("You have Entered less than the expected No. of letters");//Show output that user entered less than the expected no.of letters
                    printf("\nTRY AGAIN\n");
                }
                else
                {
                    //If all the other above conditions does not satisfied then goes inside this block
                    printf("You Guessed it wrong try again\n");
                    intWrongLetters = 0; //This variable assign to zero because in the previous block it may contain some value assigned

                    //This loop is to check no.of wrong letters in the guessed word by the user
                    //In here variable check is no. of occurrences loop goes through
                    //It is set to length of the user entered word

                    for (int check = 0; check<strlen(strWords[intRandomNumber-1]); check++)
                    {

                        //here if the letter in the strUserWord is not same as strWords then goes inside this block
                        if (strUserWord[check]!=strWords[intRandomNumber-1][check])
                        {
                            //Here the intWrongLetters is count of the wrong Letters entered by the user
                            intWrongLetters=intWrongLetters+1;
                        }

                    }
                    //Give output to the user No. of letters wrong in the guessed word
                    printf("***There are %d letters wrong in your guessed word*** ",intWrongLetters);
                    printf("\nTRY AGAIN\n");
                }

            }
            //Finally check whether the guessed word is not similar to the correct word
            if (strcmp(strWords[intRandomNumber-1],strUserWord) !=0)
            {
                //If the guessed word is not similar then goes inside of this block
                printf(" \n\n***/###/       Your Score is 00       /###/***\n\n");
                printf("***/###/  Your All guesses are wrong  /###/***\n \n");
                printf("***/###/   The Correct Word is %s    /###/*** \n\n",strWords[intRandomNumber-1]);//Shows the correct word from strWords array

            }

        }
    }
}

else //If the randomNumber is greater than the no. of words in the strWords array
{
     printf("  ???  Please Enter a number less than 15  ???  ");
}
}
/*---------------------------------------------------------
End of the startGame function
-----------------------------------------------------------*/
















