#include <stdio.h>      // rpintf, scanf
#include <stdint.h>     // int32_t
#include <stdlib.h>     // rand()
#include <time.h>       // initialisierung des Zufallsgenerators


#define foreach(item, array) \
    for(int keep = 1, \
            count = 0,\
            size = sizeof (array) / sizeof *(array); \
        keep && count != size; \
        keep = !keep, count++) \
      for(item = (array) + count; keep; keep = !keep)


int32_t ReadNumber()
{
    int32_t number;
    scanf_s("%i", &number);
    while (getchar() != '\n'); // this is needed to clear the buffer!
    return number;
}


void showNimGame(int nimdata[]);

void AskUser(int* arraylocation, int* num);


int main()
{
    int startflag = 0;
    char startgame[10];
    int num;
    int arraylocation;
    int nimdata[4] = { 1,3,5,7 };

    while (startflag != 1) {
        
        showNimGame(nimdata);
        AskUser(&arraylocation, &num);
        //printf("Arraylocation: %i", arraylocation+1);
        if (nimdata[arraylocation] - num >= 0) {
            nimdata[arraylocation] = nimdata[arraylocation] - num;
        }
        else { printf("Die Zahl ist zu hoch!"); }
        
        //showNimGame(nimdata);

        int countarray = 0;

        for (int i = 0; i < sizeof(nimdata);i++) {
            countarray += nimdata[i];
        }
        if (countarray = 0) { startflag = 1; }


        }
    }


void showNimGame(int nimdata[]) {
    int i;
    int count;
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


void AskUser(int* arraylocation, int* num) {
    printf("\nWhich row: ");
    scanf_s("%i", arraylocation);

    if (*arraylocation > 5) {}

   *arraylocation = *arraylocation - 1;
    //printf("Arraylocation in function: %i", *arraylocation);


    printf("\nHow much: ");
    scanf_s("%i", num);
}