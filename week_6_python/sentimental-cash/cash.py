# TODO
import math


def main():
    # Ask how many cents the customer is owed
    cents = getCents()

    # Calculate the number of quarters to give the customer
    quarters = calculateQuarters(cents)
    cents = round(cents - quarters * .25, 2)

    # Calculate the number of dimes to give the customer
    dimes = calculateDimes(cents)
    cents = round(cents - dimes * .10, 2)

    # Calculate the number of nickels to give the customer
    nickels = calculateNickels(cents)
    cents = round(cents - nickels * .05, 2)

    # Calculate the number of pennies to give the customer
    pennies = calculatePennies(cents)
    cents = round(cents - pennies * .01, 2)

    # Sum coins
    coins = quarters + dimes + nickels + pennies

    # Print total number of coins to give the customer
    print(f"{coins}")


def getCents():
    try:
        cents = float(input("Changes owed: "))
        if cents < 0:
            print("Negative numbers are not valid")
            cents = getCents()
    except ValueError:
        print("Not an integer")
        cents = getCents()
    return cents


def calculateQuarters(cents):
    return math.floor(cents / .25)


def calculateDimes(cents):
    return math.floor(cents / .10)


def calculateNickels(cents):
    return math.floor(cents / .05)


def calculatePennies(cents):
    return math.floor(cents / .01)


main()