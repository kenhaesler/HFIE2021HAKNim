#include <stdio.h>      // rpintf, scanf
#include <stdint.h>     // int32_t
#include <stdlib.h>     // rand()
#include <time.h>       // initialisierung des Zufallsgenerators

#define nimarraysize 4
void CreateRandomNimNum(int nimdata[]); // Create random nim game array
void ShowNimGame(int nimdata[]);
void NewMove(int* row, int* num, const int player, int nimdata[]);
void AskPlayer(int* row, int* num);
int CheckGameStatus(const int nimdata[]);

int main()
{
	int gamestate = 0; // Status of the running game -> 0 = Running / 1 = Finished
	int player = 1; // 0 = Player / 1 = Computer
	int row = 0; // variable for userinput
	int num = 0; // variable for userinput
	int nimdata[nimarraysize] = { 0 };
	int winner = 0;

	CreateRandomNimNum(nimdata);

	do {
		ShowNimGame(nimdata);
		NewMove(&row, &num, player, nimdata);
		getchar();
		system("cls");
		player = (player == 1) ? 2 : 1;
		gamestate = CheckGameStatus(nimdata);
	} while (gamestate == 0);

	winner = (player == 1) ? 2 : 1;

	if (winner == 1) { printf("\nThe Winner is: YOU!\n"); }
	else { printf("\nThe Winner is: COMPUTER!\n"); }
	getchar();
}


void CreateRandomNimNum(int nimdata[]) {
	for (int count = 0; count < nimarraysize; count++) {
		nimdata[count] = (rand() % 10) + 1;
	}
}

void ShowNimGame(int nimdata[]) {
	int count = 0;
	char divider[] = "-------------------------";

	for (int count = 0; count < nimarraysize; count++) {

		if (count == 0) { printf("\n%s\n", divider); }

		printf("[Row: %i] = [Count: %i] ->  ", count, nimdata[count]);

		for (int nimvalue = nimdata[count]; nimvalue != 0; nimvalue--) { printf("I "); }


		printf("\n");
		if (count == nimarraysize - 1) { printf("%s\n", divider); }
	}
	printf("\n");
}

void NewMove(int* row, int* num, const int player, int nimdata[]) {
	if (player == 1) {
		printf("\n PLAYER MAKING MOVE\n");
		AskPlayer(row, num);
		if (*row >= nimarraysize || *num > nimdata[*row]) {
			printf("DEAR USER: PLEASE PROVIDE CORRECT INPUT INFORMATION - 1 Move suspended");
			fflush(stdin);
			*row = 0;
			*num = 0;
			getchar();
		}
	}
	else {
		printf("\n COMPUTER MAKING MOVE\n");
		int movefound = 0;
		while (movefound != 1) {
			for (int count = 0; count < nimarraysize; count++) {
				if (nimdata[count] != 0) {
					*row = count;
					*num = (rand() % nimdata[count]) + 1;
					movefound = 1;
				}
			}
		}
	}
	printf("Removing %i from row %i", *num, *row);
	nimdata[*row] = nimdata[*row] - *num;
}

void AskPlayer(int* row, int* num) {
	printf("\nPLEASE PROVIDE MOVE INFORMATION\n");
	printf("Which row do you choose: ");
	scanf_s("%i", row);
	printf("\nHow much matches do you want to remove: ");
	scanf_s("%i", num);
	system("cls");
}

int CheckGameStatus(const int nimdata[]) {
	int isGameFinished = 0;
	int sum = 0;
	for (int count = 0; count < nimarraysize; count++) {
		sum = sum += nimdata[count];
	}

	if (sum != 0) { return 0; }
	else {return 1;}
}