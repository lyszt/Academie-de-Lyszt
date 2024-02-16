#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //  f(n)=10⋅n/100+(n%10) where % is the usual computer science meaning of mod

    long id = get_long("Number: ");
    long first_id = id;
    long second_id = id;
    int sum;
    int first_digits = 0;
    // Check length
    int length = 0;
    long id_check = id;
    while (id_check > 0)
    {
        id_check = (id_check / 10) - (id_check % 10) / 10;
        length++;
    }

    // Luhn’s Algorithm
    // If number is odd, the second-to-last number is even
    if (length % 2 == 1)
    {
        for (int i = length; i > 0; i--)
        {
            if (i == 2)
            {
                first_digits = id;
            }
            int current_digit;
            int multiplied_digit;
            if (i % 2 == 0)
            {
                current_digit = (id % 10);
                multiplied_digit = current_digit * 2;
                if (multiplied_digit > 9)
                {
                    int digit_splitf = multiplied_digit % 10;
                    int digit_splitsec = multiplied_digit / 10;
                    sum = sum + digit_splitf + digit_splitsec;
                }
                else
                {
                    sum = sum + multiplied_digit;
                }
            }
            else if (i % 2 == 1)
            {
                current_digit = (id % 10);
                sum = sum + current_digit;
            }
            id = id / 10;
        }
    }
    // If number is odd, the second-to-last number is even
    else
    {
        for (int i = length; i > 0; i--)
        {
            if (i == 2)
            {
                first_digits = id;
            }
            int current_digit;
            int multiplied_digit;
            int current_id = id % 10;
            if (i % 2 == 1)
            {
                current_digit = (id % 10);
                multiplied_digit = current_digit * 2;
                if (multiplied_digit > 9)
                {
                    int digit_splitf = multiplied_digit % 10;
                    int digit_splitsec = multiplied_digit / 10;
                    sum = sum + digit_splitf + digit_splitsec;
                }
                else
                {
                    sum = sum + multiplied_digit;
                }
            }
            else if (i % 2 == 0)
            {
                current_digit = (id % 10);
                sum = sum + current_digit;
            }
            id = id / 10;
        }
    }
    bool validation = false;
    char card[50] = "";
    if (sum % 10 == 0)
    {
        validation = true;
    }
    // printf("%d\n", first_digits);
    // printf("%d\n", sum);
    // printf("%d\n", length);
    if ((first_digits == 34 || first_digits == 37) && (length == 15) && (validation == true))
    {
        printf("AMEX\n");
    }
    else if ((first_digits >= 51 && first_digits <= 55) && (length == 16) && (validation == true))
    {
        printf("MASTERCARD\n");
    }
    else if ((first_digits / 10 == 4) && ((length == 13) || (length == 16)) && (validation == true))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
