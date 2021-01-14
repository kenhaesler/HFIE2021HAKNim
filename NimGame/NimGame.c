#include <stdio.h>      // rpintf, scanf
#include <stdint.h>     // int32_t
#include <stdlib.h>     // rand()
#include <time.h>       // initialisierung des Zufallsgenerators


void showNimGame(int nimdata[]); // Function to disp

void AskUser(int* row, int* num);

void NewMove(int row, int num, int nimdata[]);

void ComputerMove(int nimdata[]);

int CheckGameStatus(const int nimdata[]);


int main()
{
    int startflag = 0; // Flag if the game is finished
    char startgame[5]; // Variable for the starting question
    int num; // Variable for the useriput
    int row; // Variable for the userinput
    int nimdata[4] = { 1,3,5,7 };
    int programstate = 0;
    int lastpcmove = 0;

    printf("----WELCOME TO THE NIM GAME-----\n");

    if (programstate == 0) {
        printf("MODE: TESTING\n");
        while (startflag == 0) {
            showNimGame(nimdata);
            AskUser(&row, &num);
            NewMove(row, num, nimdata);
            showNimGame(nimdata);
            startflag = CheckGameStatus(nimdata);
            getchar();
            ComputerMove(nimdata,1);
            startflag = CheckGameStatus(nimdata);
            printf("Startflag: %i", startflag);
        }

    }
    else {
        while (startflag == 0) {

            showNimGame(nimdata);
            AskUser(&row, &num);
            NewMove(row, num, nimdata);
            startflag = CheckGameStatus(nimdata);
        }
    }

    return 0;
    exit;
}


void showNimGame(int nimdata[]) {
    int i;
    int count;
    int arraysize = sizeof(nimdata);
    system("cls");
    for (i = 0; i < arraysize; i++) {
        //printf("Die Zahl im array ist %i\n", nimdata[i]);
        if (i < 1) { 
            printf("\n"); 
            printf("--------------------------------\n");
        }
        for (count = nimdata[i] + 1; count > 1; count--) {
            printf("I ");
        }
        printf("\n");
       
    }
    
    printf("--------------------------------\n");
    getchar();
}


void AskUser(int* row, int* num) {
    printf("\nWhich row: ");
    scanf_s("%i", row);

    if (*row > 4) {
        printf("Input wrong - Number %i is over 4",*row);
        *row = 0;
        AskUser(&row, &num);
    }
    else {
        *row = *row - 1;
        //printf("row in function: %i", *row);

        printf("\nHow much: ");
        scanf_s("%i", num);
    }

}

void NewMove(int row, int num, int nimdata[]) {
    printf("\nMAKING MOVE: %i matches from row %i\n", num, row + 1);
    if (nimdata[row] - num >= 0 && num <= nimdata[row]) {
        //printf("Removing %i matches from row %i", num, row+1);
        nimdata[row] = nimdata[row] - num;
    }
    else { printf("The number is invalid!"); }
}

void ComputerMove(int nimdata[], const int difficulty) {
    printf("-The computer is now making a move-");

    int stopflag = 0;
    int arraysize = sizeof(nimdata);

    while (stopflag == 0) {

        for (int count = 0; count < arraysize; count++) {
            printf("Array: count: %i\n", count);
            if (nimdata[count] || nimdata[count] != 0) {
                printf("Setting nimdata: count: %i on %i\n", count, nimdata[count]-1);
                nimdata[count] = nimdata[count] - 1;
                stopflag = 1;
                break;
            }
            //stopflag = 1;
        }
        if (CheckGameStatus(nimdata) == 0) {
            printf("Congrats, you won!");
        }
        else {
            printf("My bad, the computer won!");
        }
        stopflag = 1;
    }

}

int CheckGameStatus(const int nimdata[]) {
    int countarray = 0; // Variable to count the nimarray

    for (int i = 0; i < sizeof(nimdata); i++) { //Loop to sum the array content
        countarray += nimdata[i];
        //printf("GameStatus: Nimdata Counter: %i", countarray);
        //getchar();
    }
    if (countarray == 0) { 

        return 1; 
    }
    else { return 0; }// If the sum of the array is zero, the game is finished
}