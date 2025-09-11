#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long long credit = get_long("Credit card number: ");
    long long number = credit;

    int digits = 0;
    int checksum = 0;
    int mult = 1;

    // Luhn checksum
    while (number > 0)
    {
        int dig = number % 10;      // last digit
        int product = dig * mult;

        // if doubled digit > 9, add digits separately (i.e., 12 → 1 + 2)
        if (product > 9)
        {
            product = (product % 10) + (product / 10);
        }

        checksum += product;
        number /= 10;
        digits++;
        mult = (mult == 1) ? 2 : 1; // alternate 1,2,1,2...
    }

    // If checksum fails, it's invalid
    if (checksum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Find first two digits
    long long prefix = credit;
    while (prefix >= 100)
    {
        prefix /= 10;
    }
    int start_two = prefix;
    int start_one = prefix / 10;

    // Card type checks
    if (digits == 15 && (start_two == 34 || start_two == 37))
    {
        printf("AMEX\n");
    }
    else if (digits == 16 && (start_two >= 51 && start_two <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((digits == 13 || digits == 16) && start_one == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
