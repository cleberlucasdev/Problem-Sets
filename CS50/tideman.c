// Selection sort algorithm
#include <stdlib.h>
#include <stdio.h>

// Prototypes
void find_min(int unsorted[], int len, int i, int *min, int *index);
void swap_values(int unsorted[], int len, int *min, int *index);
void print_sorted(int unsorted[], int len);

// Main function
int main()
{
    // Sample array, unsorted
    int unsorted[] = {9, 5, 3, 7, 8};

    // Length of the unsorted array
    int len = sizeof(unsorted) / sizeof(int);

    // Initializing minimum at leftmost element
    int min = unsorted[0];
    int min_index = 0;

    // Calling functions
    swap_values(unsorted, len, &min, &min_index);
    print_sorted(unsorted, len);
}

void find_min(int unsorted[], int len, int i, int *min, int *index)
{
    // This variable i is imported from swap_values inner loop in order to separate the sorted and unsorted parts.
    while(i < len)
    {
        // If there's a value smaller than the current minimum, then that's the new minimum.
        if(*min > unsorted[i])
        {
            *min = unsorted[i];
            *index = i;
        }
        i++;
    }
    return;
}

void swap_values(int unsorted[], int len, int *min, int *index)
{
    for(int i = 0; i < len; i++)
    {
        *min = unsorted[i];
        *index = i;
        // Find the minimum value for the current portion
        find_min(unsorted, len, i, min, index);
        if(*min < unsorted[i])
        {
            int temp = unsorted[i];
            unsorted[i] = *min;
            unsorted[*index] = temp;
        }
    }
}

// Print sorted array
void print_sorted(int unsorted[], int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%i ", unsorted[i]);
    }
    printf("\n");
}
