#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int change = get_int("Change owed: ");

    int coins = 0;
    while (change != 0)
    {

        while (change >= 25)
        {
            change = change - 25;
            coins++;
        }

        while (change < 25 && change >= 10)
        {
            change = change - 10;
            coins++;
        }

        while (change < 10 && change >= 5)
        {
            change = change - 5;
            coins++;
        }

        while (change < 5 && change >= 1)
        {
            change = change - 1;
            coins++;
        }
        while (change == 0)
        {
            printf("%i \n", coins);
            return 0;
        }
    }

}
