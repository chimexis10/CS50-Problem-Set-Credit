#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get card number as input from user
    long num = get_long("Card number: ");

    // Compute first part of 'checksum'
    long p = num;
    int sum = 0;
    while (p >= 1)
    {
        long x = (long) p / 10;
        int y = x % 10;
        int z = y * 2;
        sum = sum + z;
        p = (long) x / 10;
    }
    printf("%i\n", sum);

    // Compute second part of 'checksum'
    long q = num;
    int suma = 0;
    while (q >= 1)
    {
        int a = q % 10;
        suma = suma + a;
        q = (long) q / 100;
    }
    printf("%i\n", suma);

    // Obtain length of card number
    long r = num;
    int length = 0;
    while (r != 0)
    {
        r /= 10;
        ++length;
    }

    // Obtain first digit of card
    long s = num;
    long b;
    while (s >=10)
    {
        b = (long) s / 10;
        s = b;
    }

    // Get final value of 'checksum'
    int check_sum = sum + suma;
    int g = check_sum % 10;
    printf("check: %i\n", g);
    printf("Card length: %i\n", length);
    printf("First digit: %li\n", b);

    // Determine type of card using checksum and first digit
    if (check_sum % 10 == 0 && b == 3)
    {
        printf("AMEX\n");
    }
    else if (check_sum % 10 == 0 && b == 5)
    {
        printf("MASTERCARD\n");
    }
    else if (check_sum % 10 == 0 && b == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
