#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Function Prototypes
int count_letters(char string[]);
int count_words(char string[]);
int count_sentences(char string[]);

int main(void){
    // Main input string has a buffer of 500 characters - the average length of one paragraph.
    char eval[500];

    printf("Text: ");
    scanf_s("%[^\n]s", &eval);

    // Calculate letters, words, and sentences from the evaluation string.
    float letters = count_letters(eval);
    float words = count_words(eval);
    float sentences = count_sentences(eval);

    // Pre-process L and S variables from Coleman-Liau index.
    float L = (letters / words) * 100;
    float S = (sentences / words) * 100;

    // Coleman-Liau index
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Determine output based on grade level, rounded to nearest integer.
    if (index < 1){
        printf("Before Grade 1\n");
    }
    else if (index > 16){
        printf("Grade 16+\n");
    }
    else{
        printf ("Grade %d\n", (int) round(index));
    }
}

int count_letters(char string[]){
    /*
    Counts letters by iterating through evaluation string and checking
    if the current character is alphanumeric. If yes, increment letter count.
    */
    int letters = 0;

    for (int i = 0, len = strlen(string); i < len; i++){
        if (isalnum(string[i])){
            letters += 1;
        }
    }
    return letters;
}

int count_words(char string[]){
    /*
    Counts words by iterating through evaluation string and checking for
    spaces. 'words' variable begins at 1 to account for first word, which will not be
    preceded by a space.
    */
    int words = 1;
    
    for (int i = 0, len = strlen(string); i < len; i++){
        if (string[i] == ' '){
            words += 1;
        }
    }
    return words;
}

int count_sentences(char string[]){
    /*
    Counts sentences by iterating through evaluation string and checking
    for sentence-terminating punctuation. If present, increment sentence count.
    */
    int sentences = 0;

    for (int i = 0, len = strlen(string); i < len; i++){
      if (string[i] == '.' || string[i] == '!' || string[i] == '?') {
        sentences += 1;
      }
    }
    return sentences;
}
