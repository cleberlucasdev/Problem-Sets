#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    // Getting user input
    string text = get_string("Input: \n");

    // Defining how many characters are there
    int characters = strlen(text);
    int spaces = 0;
    int sentences = 0;
    int letters = 0;
    // Defining how much spaces and words are there
    for(int i = 0; i < characters; i++)
    {
        if(text[i] == 32)
        {
            spaces++;
        }
    }
    int words = spaces + 1;

    // Defining how many sentences are there
    for (int i = 0; i < characters; i++)
    {
        if(text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            sentences++;
        }
    }

    // Defining the amount of letters
    for(int i = 0; i < characters; i++)
        if(isalpha(text[i]))
        {
            letters++;
        }

    // Defining the average amount of letters in 100 words.
    float avg_letters = (float)letters/words*100;

    // Defining the average amount of sentences in 100 words
    float avg_sentences = (float)sentences/words*100;

    // Coleman-Liau Index
    float index = 0.0588 * avg_letters - 0.296 * avg_sentences - 15.8;

    // Grades output (unfinished)
    if(index >= -9.285 && index < 2.37)
    printf("Before Grade 1\n");

    else if(index >= 2.37 && index < 3.04)
    printf("Grade 2\n");

    else if(index >= 3.04 && index < 4.555)
    printf("Grade 3\n");

    else if(index >= 4.555 && index < 7.455)
    printf("Grade 5\n");

    else if(index >= 7.455 && index < 7.711)
    printf("Grade 7\n");

    else if(index >= 7.711 && index < 8.81)
    printf("Grade 8\n");

    else if(index >= 8.81 && index < 9.85)
    printf("Grade 9\n");

    else if(index >= 9.85 && index < 18.14)
    printf("Grade 10\n");

    else if (index > 18.14)
    printf("Grade 16+\n");

}
