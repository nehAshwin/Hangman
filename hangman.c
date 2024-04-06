#include "hangman_helpers.h"
#include <stdbool.h>
#include <stdio.h>

int main(int argc, char **argv) {
    char alphabet[27];
    int numMistakes = 0;
    bool winner = false;
    int secretLen = (int) strlen(argv[1]);

    for (int i = 0; i < 27; ++i) {
        alphabet[i] = '0';
    }

    //if more than two arguments in command line prompt, return error
    if (argc != 2) {
        printf("wrong number of arguments\nusage: ./hangman");
        return 1;
    }
    //if the secret message is not valid, return error
    bool valid = validate_secret(argv[1]);
    if (!valid) {
        return 1;
    }

    char phrase[secretLen + 1];
    for (int i = 0; i < secretLen; ++i) {
        if (is_lowercase_letter(argv[1][i])) {
            phrase[i] = '_';
        } else {
            phrase[i] = argv[1][i];
        }
    }
    phrase[secretLen] = '\0';
    printf("%s", CLEAR_SCREEN);
    printf("%s\n\n", arts[numMistakes]);
    printf("    Phrase: %s\n", phrase);
    printf("Eliminated: ");
    for (int i = 0; i < 26; ++i) {
        if (alphabet[i] != 48) {
            printf("%c", alphabet[i]);
        }
    }
    printf("\n\n");

    winner = !string_contains_character(phrase, '_');
    if (winner) {
        printf("You win! The secret phrase was: %s\n", argv[1]);
    }

    //while loop start here
    while ((numMistakes < LOSING_MISTAKE) && !(winner)) {
        char guess = read_letter();
        //printf("%s\n",alphabet);
        while (!(guess >= 97 && guess <= 122) || string_contains_character(alphabet, guess)
               || string_contains_character(phrase, guess)) {

            //printf("%s\n",alphabet);
            guess = read_letter();
        }
        /*while (string_contains_character(alphabet, guess)) {
            guess = read_letter();
        }*/
        //printf("%c\n", guess);
        bool guessedCorrect = string_contains_character(argv[1], guess);
        if (guessedCorrect) {
            for (int i = 0; i < secretLen; ++i) {
                if (argv[1][i] == guess) {
                    phrase[i] = guess;
                }
            }
        } else {
            int index = guess - 'a';
            alphabet[index] = guess;
            numMistakes += 1;
        }
        for (int i = 0; i < secretLen; ++i) {
            if (argv[1][i] == guess) {
                phrase[i] = guess;
            }
        }
        printf("%s", CLEAR_SCREEN);
        printf("%s\n\n", arts[numMistakes]);
        printf("    Phrase: %s\n", phrase);
        printf("Eliminated: ");
        for (int i = 0; i < 26; ++i) {
            if (alphabet[i] != '0') {
                printf("%c", alphabet[i]);
            }
        }
        printf("\n\n");

        winner = !string_contains_character(phrase, '_');
        if (winner) {
            printf("You win! The secret phrase was: %s\n", argv[1]);
        }
        if (numMistakes == LOSING_MISTAKE) {
            printf("You lose! The secret phrase was: %s\n", argv[1]);
        }
    }
    return 0;
}
