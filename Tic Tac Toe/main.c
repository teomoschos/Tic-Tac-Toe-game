#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define STRING_SIZE 30
#include <string.h>


typedef struct // struct of the player
{
    char name[50];
    char wins;
    char loses;
    char draws;
} player;


int wincondition(char  *table,int n)  //This function checks if someone wins and returns 1 if there is a winner, 0 if the players drew or -1.
{
    if (table[1] == table[2] && table[2] == table[3])
        return 1;

    else if (table[4] == table[5] && table[5] == table[6])
        return 1;

    else if (table[7] == table[8] && table[8] == table[9])
        return 1;

    else if (table[1] == table[4] && table[4] == table[7])
        return 1;

    else if (table[2] == table[5] && table[5] == table[8])
        return 1;

    else if (table[3] == table[6] && table[6] == table[9])
        return 1;

    else if (table[1] == table[5] && table[5] == table[9])
        return 1;

    else if (table[3] == table[5] && table[5] == table[7])
        return 1;

    else if (table[1] != '1' && table[2] != '2' && table[3] != '3' &&
             table[4] != '4' && table[5] != '5' && table[6] != '6' && table[7]
             != '7' && table[8] != '8' && table[9] != '9')

        return 0; // Game draw
    else
        return  - 1; //The game is not over
}

void board(char  *table,int n)  //function that create the board of the game
{
    system("cls"); //clear screen
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", table[1], table[2], table[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", table[4], table[5], table[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", table[7], table[8], table[9]);

    printf("     |     |     \n\n");
}



void Game(char  *table,int n)  //function for the double Game,between player and player
{

    player player1,player2;


    printf("Game between opponents!\n");
    int player = 1, i, choice;

    char name[STRING_SIZE];

    printf("Give a name for player 1:"); //Name for player 1
    scanf("%s",player1.name);
    printf("\n");
    printf("Give a name for player 2:"); //Name for player 2
    scanf("%s",player2.name);

    char mark;
    do
    {
        board(table,n);
        player = (player % 2) ? 1 : 2; //Check who plays

        if((player%2)==1) // According to who plays , copy the name
            strcpy(name,player1.name);
        else
            strcpy(name,player2.name);

        printf(" %s, enter a number:  ", name);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O'; //According to who plays , mark has the right character

        //Checks if the player's choice isn't mark ,and if it's not mark it
        if (choice == 1 && table[1] == '1')
            table[1] = mark;

        else if (choice == 2 && table[2] == '2')
            table[2] = mark;

        else if (choice == 3 && table[3] == '3')
            table[3] = mark;

        else if (choice == 4 && table[4] == '4')
            table[4] = mark;

        else if (choice == 5 && table[5] == '5')
            table[5] = mark;

        else if (choice == 6 && table[6] == '6')
            table[6] = mark;

        else if (choice == 7 && table[7] == '7')
            table[7] = mark;

        else if (choice == 8 && table[8] == '8')
            table[8] = mark;

        else if (choice == 9 && table[9] == '9')
            table[9] = mark;

        else // If it's mark
        {
            printf("Invalid move ");

            player--;
            getch();
        }
        i = wincondition(table,n); // call the function wincondition to check if there i a winner

        player++;

    }
    while (i ==  - 1); //Do the loop while there is  not  a winner or a draw

    board(table,n);


    if (i == 1) // Checks if there is a winner
    {

        printf("==>\a  %s wins ", name);

    }
    else
        printf("==>\a Game draw!");

    getch();


}


void  computer_move(char  *table,int n) // function for bot's move
{

    srand(time(NULL));
    int i;
    char botmark;
    botmark='O';

    do
    {
        i =( rand() % 9) +1 ; // choose random from 1-9
        printf("%d\n",i);
        if( table[i]!='X' && table[i]!='O' ) // If its not marked
        {
            table[i]=botmark; //marks on spot of the table
            break;
        }
    }
    while(table[i]!=botmark); // repeat while he can't find a not marked place in table


}

int whowins(char *table,int n) // Check who wins between Player-Bot
{

    if ( (table[1] == table[2] && table[2] == table[3] && table[1]=='X' && table[2]=='X' && table[3]=='X') || (table[4] == table[5] && table[5] == table[6] && table[4]=='X' && table[5]=='X' && table[6]=='X')
            || (table[7] == table[8] && table[8] == table[9] && table[7]=='X' && table[8]=='X' && table[9]=='X') || (table[1] == table[4] && table[4] == table[7] && table[1]=='X' && table[4]=='X' && table[7]=='X')
            || (table[2] == table[5] && table[5] == table[8] && table[2]=='X' && table[5]=='X' && table[8]=='X') || (table[3] == table[6] && table[6] == table[9] && table[3]=='X' && table[6]=='X' && table[9]=='X')
            || (table[1] == table[5] && table[5] == table[9] && table[1]=='X' && table[5]=='X' && table[9]=='X') || (table[3] == table[5] && table[5] == table[7] && table[3]=='X' && table[5]=='X' && table[7]=='X'))
    {
        return 1; //If the player wins
    }
    else
        return 0; //If the bot wins

}

void BotPlayer(char  *table,int n) //Game between Bot and Player
{
    player player;
    printf("Game between player and bot player!\n");
    int  i, choice,winner;
    char name[STRING_SIZE],botname[STRING_SIZE];
    printf("Give a name for player :"); //Give name for player
    scanf("%s",player.name);
    printf("\n");

    char mark;
    do
    {
        board(table,n); //Calls board to make the table
        strcpy(name,player.name);

        // Player plays , choose a place from table ,check if it's mark . If it's not mark it (X)
        printf(" %s, enter a number:  ", player.name);
        scanf("%d", &choice);

        mark =  'X' ;

        if (choice == 1 && table[1] == '1')
            table[1] = mark;

        else if (choice == 2 && table[2] == '2')
            table[2] = mark;

        else if (choice == 3 && table[3] == '3')
            table[3] = mark;

        else if (choice == 4 && table[4] == '4')
            table[4] = mark;

        else if (choice == 5 && table[5] == '5')
            table[5] = mark;

        else if (choice == 6 && table[6] == '6')
            table[6] = mark;

        else if (choice == 7 && table[7] == '7')
            table[7] = mark;

        else if (choice == 8 && table[8] == '8')
            table[8] = mark;

        else if (choice == 9 && table[9] == '9')
            table[9] = mark;

        else //If it's already mark
        {
            printf("Invalid move ");
            getch();
        }
        computer_move(table,n); //Bot playing

        i = wincondition(table,n); //Check is someone wins
    }
    while (i ==  - 1); // while there is not either a winner of draw

    board(table,n);

    winner= whowins(table,n); // calls the function whowins to find the winner
    printf("\n");

    if(i==1 && winner==1) // Player wins
    {
        printf("==>\a  %s  wins !",player.name);
    }
    else if(i==1 && winner==0) //Bot wins
    {
        printf("bot wins!");
    }
    else //draw
        printf("==>\a Game draw!");

    getch();

}


void Statistics()  //function for the statistics of the game
{
    FILE *fp;
    char nameplayer[STRING_SIZE];

    char  pinakas[]={"wins, " "loses, " "draw"};  // example of an character array
    int i;
    if ((fp = fopen("stats.txt","w"))!=NULL)
    {
        fputs(pinakas,fp);

        fclose(fp);

        fopen("stats.txt", "r");
        if(fp==NULL)
        {
            printf("Could not open file. \n");
            exit(0);
        }

        char c;
        c=fgetc(fp);

        while(c!=EOF)
        {
            printf("%c",c);
            c=fgetc(fp);
        }

        fclose(fp);
    }
    else
        printf("Error opening file\n");
}

int showMenu() //this function print the menu
{
    char k;
    do
    {
        printf("\n\n");
        printf(" TIC TAC TOE \n");
        printf("______________\n");
        printf("\n Menu:\n");
        printf("______________\n");
        printf("1. Single player Game \n");
        printf("2. 2 players game \n");
        printf("3. Statistics of player \n");
        printf("4. Exit \n");
        printf ("\nYour choice [1-4]:");
        k = getchar();
        fflush(stdin);

    }
    while (k<'1' || k>'6'); //Check if the player give a right choice , else he has to choose again
    return k-'0';
}

int main()
{
    int i,option;                    //Initial Construction of dynamic array table
    int  n = 1;
    char* table = malloc(n);
    for (i = 0; i < 10; i++)
    {
        table[i] = (char)('0' + i);
        n++;
        table = realloc(table, n);
    }



    do
    {

        option=showMenu();
        if(option==1)//If he choose option 1
        {
            printf("The Game begins:\n");

            free(table);
            int  n = 1;
            char* table = malloc(n);
            for (i = 0; i < 10; i++)
            {
                table[i] = (char)('0' + i);
                n++;
                table = realloc(table, n);
            }
            BotPlayer( table,n);

        }
        else if(option==2) //If he choose option 2
        {
            printf("The Game begins:\n");

            free(table);
            int  n = 1;
            char* table = malloc(n);
            for (i = 0; i < 10; i++)
            {
                table[i] = (char)('0' + i);
                n++;
                table = realloc(table, n);
            }
            Game(table,n);



        }
        else if(option==3) //If he choose option 3
        {
            Statistics();
        }

    }
    while(option!=4);//If he choose option 4 the game stops
    printf(" All the process has ended. \n");
    exit(1);

    system("pause");
    return 0;
}
