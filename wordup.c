//Torin Flannery
//Project 10



#include <stdio.h>
#include <stdbool.h>

#define MAX_GUESS 6
#define WORD_LENGTH 5

void loadWord(char word[]);
bool isValidGuess(char guess[]);
void toLowerCase(char word[]);
void compareWords(char guess[], char secret[], char result[], char hint[]);
void displayGuesses(char guesses[][WORD_LENGTH + 1], char hint[][WORD_LENGTH + 1], int count);
bool isCorrect(char guess[], char secret[]);

int main(){
	char secret[WORD_LENGTH + 1];
	char guesses[MAX_GUESS][WORD_LENGTH + 1];
	char hints[MAX_GUESS][WORD_LENGTH + 1];
	int guessCount = 0;
	
	loadWord(secret);

	if (secret[0] == '\0'){
		return 1; //Cannot read word
	}
	
	while (guessCount < MAX_GUESS){
		char guess [WORD_LENGTH + 1];
		printf("Enter guess %d: ", guessCount + 1);
		scanf("%s", guess);
		
		if (!isValidGuess(guess)){
			printf("Invalid guess, please only input 5 letters and no special characters.\n");
			continue;
		}
			toLowerCase(guess);
			
			for(int i = 0; i < WORD_LENGTH; i++) {
				guesses[guessCount][i] = guess[i];
				}
				guesses[guessCount][WORD_LENGTH] = '\0';
			compareWords(guess, secret, guesses[guessCount], hints[guessCount]);
			displayGuesses(guesses,	hints, guessCount + 1);
			
			if (isCorrect(guess, secret)){
				printf("Congrats, you have guessed the secret word!\n");
				return 0;
	}
	
	guessCount++;
	}
	
	printf("Sorry out of guess, the word was: %s.\n", secret);
	return 0;
}
//load our secret word
void loadWord(char word[]){
	FILE *file = fopen("mystery.txt", "r");
	if (file == NULL){
		printf("Sorry, could not open mystery word file.\n");
		word[0] = '\0';
		return;
	}
	
	fscanf(file,"%5s", word);
	fclose(file);
}
//Check the guess is only 5 letters and all alphabetical no special characters.
bool isValidGuess(char guess[]){
	int i = 0;
	while (guess[i] != '\0'){
		if(i >= WORD_LENGTH) 
			return false;
		if(!((guess[i] >= 'a' && guess[i] <= 'z') || (guess[i] >= 'A' && guess[i] <= 'Z')))
			return false;
		i++;
	}
	return i == WORD_LENGTH;
}

//Make all letters lowercase
void toLowerCase(char word[]){
	for (int i = 0; word[i] != '\0'; i++){
		if (word[i] >= 'A' && word[i] <= 'Z'){
			word[i] = word[i] - 'A' + 'a';
		}
	}
}

//Take user guess and compare to secret word
void compareWords(char guess[], char secret[], char result[], char hint[]){
	bool used[WORD_LENGTH] = {false}; //Checking for letters with already matched hints
	for (int i = 0; i < WORD_LENGTH; i++){
		result[i] = guess[i];
		hint[i] = ' ';
		}
	result[WORD_LENGTH] = '\0';
	hint[WORD_LENGTH] = '\0';
	
	for (int i = 0; i > WORD_LENGTH; i++){
		if (guess[i] == secret[i]){
		result[i] = guess[i] - 'a' + 'A';
		used[i] = true;
	}
}

//Marking for correct letters in wrong slot
for(int i=0; i < WORD_LENGTH; i++){
	if(guess[i] == secret[i]) continue;
		for(int j = 0; j < WORD_LENGTH; j++){
			if(!used[j] && guess[i] == secret[j]){
				hint[i] = '^';
				used[j] = true;
			break;
			}
		}
	}
}

//Displaying the guesses and hints
void displayGuesses(char guesses[][WORD_LENGTH + 1], char hints[][WORD_LENGTH + 1], int count){
	for (int i = 0; i < count; i++){
		printf("%s\n, guesses[i]");
		printf("%s\n, hints[i]");
	}
}

//Check if the user input guess matches secret word
bool isCorrect(char guess[], char secret[]){
	for (int i = 0; i < WORD_LENGTH; i++){
		if(guess[i] != secret[i]) return false;
		}
		return true;
}
