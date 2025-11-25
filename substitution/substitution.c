#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Prototype Functions
int check_unique(char string[]);
void encrypt(char key[] ,char plaintext[]);

int main(int argc, char *argv[]) {

    char* key;
    key = argv[1];
    // Input validation section.

    // Check for empty command
    if (argc < 2) {
        printf("Please input your key\n");
        return 1;
    }
    // Check for too many commands
    else if (argc > 2) {
        printf("Please only input your key with no spaces.");
        return 1;
    }
    
    // Ensure key input is exactly 26 characters long
    if (strlen(key) != 26) {
        printf("Invalid number of letters in key.\nKey must be exactly 26 unique letters.");
        return 1;
    }
    // Make sure the key has no duplicate letters
    if (check_unique(key) == 0) {
        printf("Your key contains duplicate characters.\nKey must be exactly 26 unique letters.");
        return 1;
    }
    // Make sure the key has no numbers or punctuation
    for (int i = 0, len = strlen(key); i < len; i++) {
        if (!isalpha(key[i])){
            printf("Please only include letters in your key.\n");
            return 1;
        }
    }

    // Get plaintext, up to 100 characters long.
    char plain[100];
    printf("Plaintext: ");
    scanf_s("%[^\n]s", &plain);

    // Encrypt plaintext and print
    printf("Ciphertext: ");
    encrypt(key,plain);
}

// Function Definitions

int check_unique(char key[]) {
    /*
    Homogenize case and iterate through the key twice to check for duplicate characters
    */
    int len = strlen(key);
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (toupper(key[i]) == toupper(key[j])) {
            return 0;
            }
        }
    }
    return 1;
}

void encrypt(char key[], char plaintext[]) {
    /*
    Checks case of plaintext and key, and encrypts ciphertext congruent with plaintext case
    irrespective of key case. Intentionally ignores non-alphabetic characters. Adds a termination
    character at the end of the printed string to prevent artifacting.
    */
    int len = strlen(plaintext);
    char ciphertext[len + 1];

    for (int i = 0; i < len; i++) {
        if (isupper(plaintext[i])) {
            ciphertext[i] = toupper(key[plaintext[i] - 'A']);
        }
        else if (islower(plaintext[i])) {
            ciphertext[i] = tolower(key[plaintext[i] - 'a']);
        }

        if (!isalpha(plaintext[i])) {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[len] = '\0';
    printf("%s", ciphertext);
}
