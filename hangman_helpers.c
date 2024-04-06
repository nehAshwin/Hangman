#include "hangman_helpers.h"

#include <stdio.h>
#include <stdlib.h>

bool is_lowercase_letter(char c) {
    int cInt = c;
    //if the character is a lowercase letter (within ascii 97-122)
    if (cInt >= 97 && cInt <= 122) {
        return true;
    }
    return false;
}

bool validate_secret(const char *secret) {
    int secretLen = (int) strlen(secret);
    //if the length of the string (not including zero byte) is greater than 255
    if (secretLen > 256) {
        printf("the secret phrase is over 256 characters\n");
        return false;
    }
    //for each character in the string...
    char element = secret[0];
    for (int i = 1; i <= secretLen; ++i) {
        //if the character is not printable, non numeric, or uppercase
        if ((element >= 0 && element <= 31) || (element >= 33 && element <= 38)
            || (element >= 40 && element <= 44) || (element >= 46 && element <= 96)
            || (element >= 123 && element <= 127)) {
            printf("invalid character: '%c'\n", element);
            printf("the secret phrase must contain only lowercase letters, spaces, hyphens, and "
                   "apostrophes\n");
            return false;
        }
        element = secret[i];
    }
    return true;
}

bool string_contains_character(const char *s, char c) {
    int sLen = (int) strlen(s);
    for (int i = 0; i < sLen + 1; ++i) {
        if (s[i] == c) {
            return true;
        }
    }
    return false;
}

char read_letter(void) {
    char c;
    printf("Guess a letter: ");
    scanf("%c", &c);
    while ((getchar()) != '\n')
        ;
    return c;
}
