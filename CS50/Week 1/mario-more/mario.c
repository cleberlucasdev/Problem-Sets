#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int main(void)
{
    // Getting height from user input
    int height;
    do
    {
        height = get_int("height: ");
    }
    while (height < 1 || height > 8);

    // Spotting incorrect inputs
    // Forming the pyramid's structure through loops
    for (int h = height; h > 0; h--)
    {
        for (int j = 0; j < h - 1; j++)
        {
            printf(" ");
        }
        for (int i = h - 1; i < height; i++)
        {
            printf("#");
        }
        printf("  ");
        for (int r = h - 1; r < height; r++)
        {
            printf("#");
        }
        printf("\n");
    }
}
