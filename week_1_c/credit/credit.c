#include <cs50.h>
#include <stdio.h>
#include <math.h>

long counter(long toBeCounted);
long reverser(long toBeReversed);
long findLastTwoDigits(long find);
long luhnsAlgorithm(long creditCard, long length);

int main(void)
{
    // gets credit card number from user
    long creditCardNumber = get_long("Number: ");
    long digitCount = 0;
    long digits = creditCardNumber;
    long toBeReversedCCN = creditCardNumber;
    long toBeCheckedWithLuhn = creditCardNumber;

    // counts the number of digits the user has typed
    digitCount = counter(digits);

    // reverse the credit card number
    long reversedCCN = reverser(toBeReversedCCN);

    // find last two digits
    long lastTwoDigits = findLastTwoDigits(reversedCCN);

    // reverse the last two digits
    long revertedLastTwo = reverser(lastTwoDigits);

    // applies luhn's algorithm
    long luhns = luhnsAlgorithm(toBeCheckedWithLuhn, digitCount);

    if (luhns == 0) {
        if (digitCount == 15)
        {
            if (revertedLastTwo == 34 || revertedLastTwo == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (digitCount == 13 || digitCount == 16)
        {
            if (revertedLastTwo == 4 || (revertedLastTwo > 39 && revertedLastTwo < 50))
            {
                printf("VISA\n");
            }
            else if (revertedLastTwo > 50 && revertedLastTwo < 56)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

// digit counter
long counter(long toBeCounted)
{
    long numberOfDigits = 0;
    while (toBeCounted != 0)
    {
        toBeCounted /= 10;
        numberOfDigits++;
    }
    return numberOfDigits;
}

// number reverser
long reverser(long toBeReversed)
{
    long reversedNum = 0;
    while (toBeReversed > 0)
    {
        long split = toBeReversed % 10;
        reversedNum = reversedNum * 10 + split;
        toBeReversed = toBeReversed / 10;
    }
    return reversedNum;
}

// find last two digits
long findLastTwoDigits(long find)
{
    long temp = 0;
    temp = find % 100;
    return temp;
}

// use the luhn's algorithm
long luhnsAlgorithm(long creditCard, long length)
{
    long individualDigits[50];
    long arrayLength = length - 1;
    for (long i = arrayLength; i >= 0; i--)
    {
        individualDigits[i] = creditCard % 10;
        creditCard /= 10;
    }

    arrayLength--;
    for (long j = arrayLength; j >= 0; j -= 2)
    {
        individualDigits[j] *= 2;
    }

    long sum = 0;
    for (long k = arrayLength; k >= 0; k -= 2)
    {
        long num1 = individualDigits[k] % 10;
        individualDigits[k] /= 10;
        long num2 = individualDigits[k] % 10;
        individualDigits[k] /= 10;
        sum += num1;
        sum += num2;
    }

    arrayLength++;
    for (long m = arrayLength; m >= 0; m -= 2)
    {
        sum += individualDigits[m];
    }

    long moduloTen = sum % 10;
    return moduloTen;
}