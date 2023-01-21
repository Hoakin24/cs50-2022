# TODO

import math


def main():
    # gets credit card number from user
    creditCardNumber = ask()

    # counts the number of digits the user has typed
    digitCount = counter(creditCardNumber)
    # gets the first two digits
    firstTwo = firstTwoDigits(creditCardNumber)
    # applies luhn's algorithm
    luhns = luhnsAlgorithm(creditCardNumber, digitCount)

    if luhns == 0:
        if digitCount == 15:
            if firstTwo == 34 or firstTwo == 37:
                print("AMEX")
                return
            else:
                print("INVALID")
                return
        if digitCount == 13 or digitCount == 16:
            if firstTwo > 39 and firstTwo < 50:
                print("VISA")
                return
            if firstTwo > 50 and firstTwo < 56:
                print("MASTERCARD")
                return
            else:
                print("INVALID")
        else:
            print("INVALID")
    else:
        print("INVALID")


def ask():
    # prompts user for credit card number
    try:
        ccn = int(input("Number: "))
        if ccn < 0:
            print("Negative numbers are not valid")
            ccn = ask()
    except ValueError:
        print("Not an integer")
        ccn = ask()
    return ccn


def counter(toBeCounted):
    # returns the number of digits
    return len(str(toBeCounted))


def firstTwoDigits(find):
    # returns the first two digits
    return int(str(find)[:2])


def luhnsAlgorithm(ccnDigits, ccnLength):
    # uses the luhn's algorithm
    arrayLength = ccnLength - 2
    individualDigits = []

    for x in str(ccnDigits):
        individualDigits.append(int(x))

    for y in range(arrayLength, -1, -2):
        individualDigits[y] *= 2

    sum = 0
    for z in range(arrayLength, -1, -2):
        num1 = individualDigits[z] % 10
        individualDigits[z] = math.floor(individualDigits[z] / 10)
        num2 = individualDigits[z] % 10
        individualDigits[z] = math.floor(individualDigits[z] / 10)
        sum += num1
        sum += num2

    arrayLength += 1
    for a in range(arrayLength, -1, -2):
        sum += individualDigits[a]

    return round(sum % 10)


main()