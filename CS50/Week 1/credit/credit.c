#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int len;
    string cardnumber;
    while (true) // Evaluating card number's format
    {
        cardnumber = get_string("What is your credit card number? "); // VISA
        len = strlen(cardnumber);

        if ((len == 13 && cardnumber[0] == '4') || (len == 16 && cardnumber[0] == '4'))
        {
            printf("VISA\n");
            break;
        }

        else if ((len == 15 && cardnumber[0] == '3' && cardnumber[1] == '4') // AMEX
                 || (len == 15 && cardnumber[0] == '3' && cardnumber[1] == '7'))
        {
            printf("AMEX\n");
            break;
        }

        else if ((len == 16 && cardnumber[0] == '5') &&
                 (cardnumber[1] >= '1' && cardnumber[1] <= '5')) // MASTERCARD
        {
            printf("MASTERCARD\n");
            break;
        }

        else
        {
            printf("INVALID\n");
            break;
        }
    }
    int n = 0;
    while (n < len)                   // This is the Luhn's Algorithm implementation. We'll use it in order to checksum.
    {
        int i1 = cardnumber[n] - '0'; // This is how we're selecting the numbers in the first sweep.
        int i2 = i1 * 2;
        char i3[5];
        int i4;

        sprintf(i3, "%i", i2); // Now, we're summing only the digits of the numbers we got. We do this by
                              // converting the integers into strings and selecting the digits in [0] and [1] positions.
                             // Then, we convert them into integers again, summing them numerically this time.
        if (strlen(i3) > 1)
        {
            i4 = i3[0] - '0' + i3[1] - '0';
        }
        else
        {
            i4 = i3[0] - '0';
        }

        printf("%i\n", i4);
        n = n + 2;              // Couldn't make it work. Submitting it anyway.

    }
}
