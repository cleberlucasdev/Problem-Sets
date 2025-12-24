// This is a game of Scrabble, where players create words and make points according to each letter
// of the words.
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Assigning points to each character
int points[27] = {1, 3, 3,  2, 1, 4, 2, 4, 1, 8, 5, 1,  3, 1,
                  1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10, 0};
int total_points_p1 = 0;
int total_points_p2 = 0;

int main(void)
{
    // Getting user input
    string p1 = get_string("Player 1: \n");
    string p2 = get_string("Player 2: \n");

    // Defining the length of each word
    int p1_length = strlen(p1);
    int p2_length = strlen(p2);

    // Counting Player 1's points

    for (int i1 = 0; i1 < p1_length; i1++)
    {
        char p1_char = tolower(p1[i1]);

        int index_number = p1_char - 'a';

        if (!isalpha(p1_char)) // This condition is supposed to nullify non-alphanumeric characters
        {
            index_number = 26;
        }

        total_points_p1 = total_points_p1 + points[index_number];
    }
    // Counting Player 2's points
    for (int i2 = 0; i2 < p2_length; i2++)
    {

        char p2_char = tolower(p2[i2]);

        int index_number = p2_char - 'a';

        if (!isalpha(p2_char))
        {
            index_number = 26;
        }
        total_points_p2 = total_points_p2 + points[index_number];
    }

    // Defining who wins or if it's a tie
    if (total_points_p2 > total_points_p1)
    {
        printf("Player 2 wins! \n");
    }
    else if (total_points_p2 < total_points_p1)
    {
        printf("Player 1 wins! \n");
    }
    else
    {
        printf("Tie! \n");
    }
}
