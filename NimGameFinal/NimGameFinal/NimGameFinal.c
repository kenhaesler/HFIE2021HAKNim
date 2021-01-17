#include <stdio.h>      // rpintf, scanf
#include <stdint.h>     // int32_t
#include <stdlib.h>     // rand()
#include <time.h>       // initialisierung des Zufallsgenerators

#define nimarraysize 4

// ----Functions----
void CreateRandomNimNum(int nimdata[]); // Create random nim game array
void ShowNimGame(int nimdata[]); // Show the created array with matches
void AskUserMove(int* row, int* num);
void NewMove(int row, int num, int nimdata[], int* player); // Make a new game move
int ComputerMove(int nimdata[]); // New move of the computer - Includes the NewMove function
int CheckGameStatus(const int nimdata[]); // Check wheter the game is still going or already finished
int CheckInput(int row, int num, const int nimdata[]);




int main()
{
	int gamestate = 0; // Status of the running game -> 0 = Running / 1 = Finished
	int player = 0; // 0 = Player / 1 = Computer
	int row = 0; // variable for userinput
	int num = 0; // variable for userinput
	int nimdata[nimarraysize] = { 0 };
	int datacheck = 0;

	CreateRandomNimNum(nimdata);

	if (player == 0) {
		
	}


	do {
		gamestate = CheckGameStatus(nimdata);
		player = 0;
		ShowNimGame(nimdata);
		AskUserMove(&row, &num);
		datacheck = CheckInput(row, num, nimdata);
		if (datacheck == 1) {
			ShowNimGame(nimdata);
			AskUserMove(&row, &num);
		}
		NewMove(row, num, nimdata, &player);
		gamestate = CheckGameStatus(nimdata);
		player = 1;
		ComputerMove(nimdata);

	} while (gamestate == 0);

	/*while (gamestate == 0) {
		gamestate = CheckGameStatus(nimdata);
		player = 0;
		ShowNimGame(nimdata);
		AskUserMove(&row, &num);
		datacheck = CheckInput(row, num, nimdata);
		if (datacheck == 1) { 
			ShowNimGame(nimdata);
			AskUserMove(&row, &num); 
		}
		NewMove(row, num, nimdata, &player);
		gamestate = CheckGameStatus(nimdata);
		player = 1;
		ComputerMove(nimdata);
	}*/

	system("cls");
	printf("GAME FINISHED!!!!");

	if (player == 1) { printf("\nTHE COMPUTER WON\n"); }
	else { printf("\nTHE PLAYER WON\n"); }
	getchar();
	
}


void CreateRandomNimNum(int nimdata[]) {
	int count;

	for (int count = 0; count < nimarraysize; count++) {
		nimdata[count] = (rand() % 10) + 1;
	}
}

void ShowNimGame(int nimdata[]) {
	int count = 0;
	char divider[] = "-------------------------";
	
	for (int count = 0; count < nimarraysize; count++) {
		
		if (count == 0) { printf("\n%s\n",divider); }

		printf("[Row: %i] = [Count: %i] ->  ", count, nimdata[count]);

		for (int nimvalue = nimdata[count]; nimvalue != 0; nimvalue--) { printf("I "); }
		

		printf("\n");
		if (count == nimarraysize-1) { printf("%s\n", divider); }
	}
	printf("\n");

}

void AskUserMove(int* row, int* num) {
	printf("\nPLEASE PROVIDE MOVE INFORMATION\n");
	printf("Which row do you choose: ");
	scanf_s("%i", row);
	printf("\nHow much matches do you want to remove: ");
	scanf_s("%i", num);
	system("cls");
}

void NewMove(int row, int num, int nimdata[], int* player) {
	system("cls");
	if (player == 0) { printf("PLAYER: NEW MOVE: "); }
	else { printf("COMPUTER: NEW MOVE: "); }
	printf("Removing %i from row %i", num, row);

	nimdata[row] = nimdata[row] - num;
}

int ComputerMove(int nimdata[]) {
	int movefound = 0;
	int row;
	int num;
	while (movefound != 1) {
		for (int count = 0; count < nimarraysize; count++) {
			if (nimdata[count] != 0) {
				row = count;
				num = (rand() % nimdata[count]) + 1;
				movefound = 1;
			}
		}
	}
	NewMove(row, num, nimdata, 1);
	//ShowNimGame(nimdata);
	getchar();
}

int CheckGameStatus(const int nimdata[]) {
	int isGameFinished = 0;
	int sum = 0;
	for (int count = 0; count < nimarraysize; count++) {
			sum = sum += nimdata[count];
	}

	if (sum != 0) { return 0; }
	else { 
		return 1;
		exit;
	}
}

int CheckInput(int row, int num, const int nimdata[]) {

	int dataatlocation = nimdata[row];

	int datacheck = 0;
	if (dataatlocation < num || row > nimarraysize || dataatlocation < 0) {
		datacheck = 1;
		system("cls");
		printf("DEAR USER! PLEASE PROVIDE CORRECT INPUT INFORMATION!!\n");
	}
	return datacheck;
}