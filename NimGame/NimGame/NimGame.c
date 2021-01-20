#include <stdio.h>      // rpintf, scanf
#include <stdint.h>     // int32_t
#include <stdlib.h>     // rand()
#include <time.h>       // initialisierung des Zufallsgenerators

#define nimarraysize 4
void CreateRandomNimNum(int nimdata[]); // Create random nim game array
void ShowNimGame(const int nimdata[]);
void NewMove(int* row, int* num, const int player, int nimdata[]);
void AskPlayer(int* row, int* num);
int CheckGameStatus(const int nimdata[]);

// vorschlag
typedef enum
{
    Human,
    Machine
} Player_t;


const char* text[] = {"winner message", "looser message"};

int main()
{
	int gamestate = 0; // Status of the running game -> 0 = Running / 1 = Finished
	int player = 1; // 0 = Player / 1 = Computer <== rla: das stimmt nicht mit dem Code überein! 0 und 1 waeren die bessere Wahl!
	int row = 0; // variable for userinput
	int num = 0; // variable for userinput
	int nimdata[nimarraysize] = { 0 };
	int winner = 0;

	CreateRandomNimNum(nimdata);

    // das entspricht nicht ihrem UML Diagramm!
    // - sie pruefen am Ende der Schlaufe ob das Spiel zuende ist
    // - sie fuehren abwechselnd einen Zug des Spielers und einen Zug der Maschine aus
    // - wenn ein Spieler einen ungueltigen Zug macht, wird ein 0-Zug ausgeführt.
	do {
		ShowNimGame(nimdata);
		NewMove( player, nimdata);  // wenn row und num ausserhalb der Funktion nie verwendet werden, weshalb sind es dann "Out-Parameter"?
		getchar();
		system("cls");
		player = (player == 1) ? 2 : 1;       // player = (player + 1) %2 wäre einfacher.
		gamestate = CheckGameStatus(nimdata);
	} while (gamestate == 0);

	winner = (player == 1) ? 2 : 1; 

    // mit player = 0 oder 1 könnte man einfach eine Meldung  aus einer entsprechenden tabelle abrufen und drucken
    // dann braucht es hier kein if mehr!
	if (winner == 1) { printf("\nThe Winner is: YOU!\n"); }
	else { printf("\nThe Winner is: COMPUTER!\n"); }
	getchar();
}


void CreateRandomNimNum(int nimdata[]) {
	for (int count = 0; count < nimarraysize; count++) {
		nimdata[count] = (rand() % 10) + 1;
	}
}

void ShowNimGame(const int nimdata[]) {
	int count = 0;
	char divider[] = "-------------------------";   // machen sie so etwas const und global!

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
		printf("\nPLAYER MAKING MOVE: ");
		AskPlayer(row, num);
		if (*row >= nimarraysize || *num > nimdata[*row] || *num <= 0) { 
        // das gilt nicht :-) Sie sollen den Benutzer zwingen eine sinnvolle eingabe zu machen. 
        // sie können nach einigen fehlversuchen abbrechen. Das Spiel darf aber nicht ohne Zug weiter gespielt werden.
			printf("\nDEAR USER: PLEASE PROVIDE CORRECT INPUT INFORMATION - 1 Move suspended\n");
			fflush(stdin);
			*row = 0;
			*num = 0;
			getchar();
		}
	}
	else {
		printf("\nCOMPUTER MAKING MOVE: ");
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
    // hier müssen zwei gültige Zahlen kommen!
	printf("Removing %i from row %i\n", *num, *row);
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

	if (sum != 0) { return 0; } // das können sie schreiben als return (sum == 0)
	else { return 1; }
}