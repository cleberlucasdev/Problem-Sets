// Scrabble game
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Prototypes
char* allocate_mem();
void get_string(char* prompt, char* input);
void count(char* input, char alphabet[], int points[], int len_alpha, int len_input);

int main()
{
    // Alphabet and its length
    char alphabet[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int len_alpha = sizeof(alphabet) / sizeof(char);
    printf("len alpha %i", len_alpha);

    // Points
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    // Allocating memory and collecting user input's memory address
    char* input = allocate_mem();

    // Input's string length
    int len_input = strlen(input);
    printf("len input %i", len_input);

    // Defining input
    get_string("word: ", input);

    // Count points for player
    count(input, alphabet, points, len_alpha, len_input);
}

// Allocating memory
char* allocate_mem()
{
    char* input = malloc(sizeof(char) * 20);
    char* prompt = malloc(sizeof(char) * 20);
    return input;
}

// Collecting user input
void get_string(char* prompt, char* input)
{
    printf("%s", prompt);
    scanf("%s", input);
}

// Counting how many points for each letter of the input
void count(char* input, char alphabet[], int points[], int len_alpha, int len_input)
{
    for(int i = 0; i < len_input; i++)
    {
        for(int j = 0; j < len_alpha; j++)
        {
            char c = toupper(input[i]);
            if(c == alphabet[j])
        }
    }
}
