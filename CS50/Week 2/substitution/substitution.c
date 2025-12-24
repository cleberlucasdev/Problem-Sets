#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Evaluating argument and usage format
    // Usage example: ./substitution ABCDEFGHIJKLMNOPQRSTUVWXYZ
    if (argc != 2)
    {
        printf("Usage: ./substitution key \n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // -------------------------------------------------
    // Defining upper and lowercase keys
    string key = argv[1];
    char key_lowercase[28];
    char key_uppercase[28];

    // lowercase
    for (int m = 0; m < 26; m++)
    {
        key_lowercase[m] = tolower(key[m]);
    }
    key_lowercase[27] = '\0';

    // uppercase
    for (int n = 0; n < 26; n++)
    {
        key_uppercase[n] = toupper(key[n]);
    }
    key_uppercase[27] = '\0';

    // -------------------------------------------------
    for (int i = 0; i < 26; i++)
        if (!isalpha(key_uppercase[i]))
        {
            printf("Only alphabetic digits are allowed for the key. \n");
            return 1;
        }

    // Defining the alphabet and encrypting key
    string alphabet_uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alphabet_lowercase = "abcdefghijklmnopqrstuvwxyz";

    // Returning 1 if duplicated
    for (int b = 0; b < 26; b++)
    {
        int v = 1;
        while(v < 26)
        {
            if(key_lowercase[b] == key_lowercase[v] && v != b)
            {
                printf("Duplicate characters are not allowed.");
                return 1;
            }
            else
            {
                v++;
            }
        }
    }
    // Collecting text the user wants to encrypt
    string plaintext = get_string("plaintext: ");

    // Gathering positions
    int positions_uppercase[100];
    int positions_lowercase[100];
    char non_alphanum[100];
    int k = 0;
    int p = 0;
    while(p < strlen(plaintext))
    {
        if (isalpha(plaintext[p]))
        {
            if(isupper(plaintext[p]))
            {
                if (plaintext[p] == alphabet_uppercase[k])
                {
                    positions_uppercase[p] = k;
                    p++;
                    k = 0;
                }
                else
                {
                    k++;
                }
            }
            else if(islower(plaintext[p]))
            {
                if (plaintext[p] == alphabet_lowercase[k])
                {
                    positions_lowercase[p] = k;
                    p++;
                    k = 0;
                }
                else
                {
                    k++;
                }
            }
        }
        else
        {
            non_alphanum[p] = plaintext[p];
            p++;
        }
    }
    // Rearranging characters and printing
    printf("ciphertext: ");
    for (p = 0; p < strlen(plaintext); p++)
    {
        if (isalpha(plaintext[p]))
        {
            if(isupper(plaintext[p]))
            {
                printf("%c", key_uppercase[positions_uppercase[p]]);
            }

            if(islower(plaintext[p]))
            {
                printf("%c", key_lowercase[positions_lowercase[p]]);
            }
        }
        else
        {
            printf("%c", plaintext[p]);
        }
    }
    printf("\n");
}
