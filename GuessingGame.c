//Number guessing game

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

	setvbuf(stdout, NULL, _IONBF, 0);

	srand(time(NULL));

	int secret;
	int guess;
	int range;
	int tries;

	float allTries;
	float gameNum;
	float average;

	char ch;

	tries = 1;
	allTries = 0;
	gameNum = 0;
	range = 9999;
	average = 0;

	printf("WELCOME to the guessing game!\n");

	do {

		printf("MENU: (s) to start the game, (n) to set a new range for a secret number, or (q) to quit the game:\n");
		scanf(" %c", &ch);

		if (ch == 's') {

			secret = rand() % (range + 1);

			printf("The secret number is BETWEEN 0 AND %i. Guess a secret number:\n", range);

			do {

				scanf("%i", &guess);

				if (guess == secret) {

					printf("Your answer is correct: You TOOK %i guesses!\n", tries);
					allTries = allTries + tries;
					gameNum++;

				}

				else if (guess > secret) {

					printf("Too HIGH! Another variant:\n");

				}

				else {

					printf("Too LOW! Another variant:\n");

				}

				tries++;

			} while (guess != secret);

			tries = 1;

			continue;

		}

		if (ch == 'n') {

			printf("Enter a new MAXIMUM range:\n");
			scanf("%i", &range);

			continue;

		}

		if (ch != 's' && ch != 'n' && ch != 'q') {

			printf("UNRECOGNIZED command.\n");

		}

	} while (ch != 'q');

	if (gameNum != 0) {

		average = allTries / gameNum;
		printf("Thank you for playing. Your guess count AVERAGE %.1f\n", average);

	}

	else {

		printf("Thank you for playing. Your guess count AVERAGE %.1f\n", average);

	}

	return 0;

}
