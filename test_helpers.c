#include "hangman_helpers.c"

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    //test is_lowercase_letter
    bool test = is_lowercase_letter('c');
    printf("Test is_lowercase_letter(c): %d\n", test);
    test = is_lowercase_letter('A');
    printf("Test is_lowercase_letter(A): %d\n", test);

    //test validate_secret
    char secret[] = "ABCabc";
    test = validate_secret(secret);
    printf("Test validate_secret(ABCabc): %d\n", test);
    char secret2[] = "hi I just need this to fit 256 characters and I'm not sure how much this is "
                     "going to cover right now but I'm just going to keep typing until I get 256 "
                     "characters okay this seems like enough";
    test = validate_secret(secret2);
    printf("Test validate_secret() with 256+ characters: %d\n", test);

    //test string_contains_character()
    char testContains[] = "hi my name is";
    test = string_contains_character(testContains, 'h');
    printf("test string_contains_character() with h: %d\n", test);
    test = string_contains_character(testContains, 'i');
    printf("test string_contains_character() with i: %d\n", test);
    test = string_contains_character(testContains, 'j');
    printf("test string_contains_character() with j: %d\n", test);

    //test read_letter()
    char guess = read_letter();
    printf("%c\n", guess);

    return 0;
}
