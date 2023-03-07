#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_GUESSES 6
#define MAX_WORD_LENGTH 50

int main() {
    char word[MAX_WORD_LENGTH], guess[MAX_WORD_LENGTH], letter;
    int i, j, num_guesses = 0, word_length, correct_guesses = 0;
    int already_guessed[MAX_WORD_LENGTH] = {0};

    printf("Welcome to the 'Guess the Word' game!\n");
    printf("Enter a word for the player to guess: ");
    scanf("%s", word);

    word_length = strlen(word);
    for (i = 0; i < word_length; i++) {
        word[i] = tolower(word[i]);
    }

    printf("\n");

    while (num_guesses < MAX_GUESSES && correct_guesses < word_length) {
        printf("Guess a letter: ");
        scanf(" %c", &letter);

        letter = tolower(letter);

        if (already_guessed[letter-'a']) {
            printf("You already guessed that letter!\n\n");
            continue;
        }

        already_guessed[letter-'a'] = 1;

        int found_letter = 0;
        for (i = 0; i < word_length; i++) {
            if (word[i] == letter) {
                guess[i] = letter;
                correct_guesses++;
                found_letter = 1;
            }
        }

        if (found_letter) {
            printf("Good guess!\n");
        } else {
            printf("Sorry, that letter is not in the word.\n");
            num_guesses++;
        }

        printf("Word: %s\n", guess);
        printf("Guesses remaining: %d\n\n", MAX_GUESSES - num_guesses);
    }

    if (correct_guesses == word_length) {
        printf("Congratulations! You guessed the word '%s'!\n", word);
    } else {
        printf("Sorry, you failed. The word was '%s'.\n", word);
    }

    return 0;
}