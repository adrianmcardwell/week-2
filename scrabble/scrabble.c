/*
I am using my own installation of VSCode rather than using CS50.dev. I am doing this primarily because I
want to learn how to code in C properly without relying on the <cs50.h> library. That said, functions
such as 'get_string' will be omitted from any of my code and replaced with the standard method of
obtaining user input.
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points as defined by the points table in the assignment, where 0 = A etc.
int SCORES[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5,
   1, 3, 1, 1, 3, 10, 1, 1, 1,
   1, 4, 4, 8, 4, 10};

// Prototype Function
int compute_score(char word[]);

int main(void)
{
    /*
    Set word buffer equal to longest word in English language to account for any given word
    Fun fact: The longest word in the English language (that isn't a chemical composition) is
    Pneumono­ultra­micro­scopic­silico­volcano­coniosis, which is worth 68 points!
    */ 
    char word1[45];
    char word2[45];

    printf("Player 1: ");
    // scanf rather than fgets to only accept first input word rather than a sentence or more
    scanf_s("%s", &word1);

    printf("Player 2: ");
    scanf_s("%s", &word2);

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Determine outcome based on scoring
    if (score1 > score2)
    {
        printf("Player 1 Wins!");
    }
    else if (score1 < score2)
    {
        printf("Player 2 Wins!");
    }
    else {
        printf("It's a tie!");
    }
    // Print scores
    printf("Player 1's Score: %d\nPlayer 2's Score: %d", score1, score2);
}

int compute_score(char word[])
/*
Sanitizes input by homogenizing case, then assigns points based on SCORES table above.
Scores are assigned by subtracting the ASCII value of 'A' from the index position of the current letter,
and assigning the resulting number to the index position of SCORES, then adding all the values together. 
*/
{
    int score = 0;

    for (int i = 0, len = strlen(word); i < len; i++)
    {
        word[i] = toupper(word[i]);
        score += SCORES[word[i] - 'A'];

    }
    return score;
}