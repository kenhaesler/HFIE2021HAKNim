#include <stdio.h>      // rpintf, scanf
#include <stdint.h>     // int32_t
#include <stdlib.h>     // rand()
#include <time.h>       // initialisierung des Zufallsgenerators


void showNimGame(int nimdata[]); // Function to disp

void AskUser(int* row, int* num);

void NewMove(int* row, int* num, int nimdata[]);

void ComputerMove(int nimdata[], const int difficulty);


int main()
{
    int startflag = 0; // Flag if the game is finished
    char startgame[5]; // Variable for the starting question
    int num; // Variable for the useriput
    int row; // Variable for the userinput
    int nimdata[4] = { 1,3,5,7 };
    int programstate = 1;

    printf("----WELCOME TO THE NIM GAME-----\n");

    if (programstate == 0) {
        printf("MODE: TESTING\n");
        getchar();
        showNimGame(nimdata);
        //ComputerMove(nimdata);
        showNimGame(nimdata);
    }
    else {
        while (startflag != 1) {

            showNimGame(nimdata);
            AskUser(&row, &num);
            //printf("row: %i", row+1);
            if (nimdata[row] - num >= 0) {
                nimdata[row] = nimdata[row] - num;
            }
            else { printf("Die Zahl ist zu hoch!"); }

            //showNimGame(nimdata);

            int countarray = 0; // Variable to count the nimarray

            for (int i = 0; i < sizeof(nimdata); i++) { //Loop to sum the array content
                countarray += nimdata[i];
            }
            if (countarray = 0) { startflag = 1; } // If the sum of the array is zero, the game is finished

        }
    }

    //}
}


void showNimGame(int nimdata[]) {
    int i;
    int count;
    system("cls");
    for (i = 0; 3 >= i; i++) {
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
    if (nimdata[row] - num >= 0 && num > nimdata[row]) {
        nimdata[row] = nimdata[row] - num;
    }
    else { printf("The number is invalid!"); }
}

void ComputerMove(int nimdata[], const int difficulty) {
    printf("Size of nimdata: %i", (sizeof(nimdata)));
    int stopflag = 0;
    int arraysize = sizeof(nimdata);
    while (stopflag == 0) {
        for (int count = arraysize; count <= arraysize; count++) {
            if (nimdata[count] != 0) {
                nimdata[count] = nimdata[count] - 1;
                stopflag = 1;
            }
        }
    }
}