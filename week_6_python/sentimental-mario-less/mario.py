# TODO

# main function
def main():
    h = checkInt()
    makeRow(h)


def checkInt():
    # checks if int is valid
    try:
        height = int(input("Height: "))
        if height < 1 or height > 8:
            print("Number is rejected")
            height = checkInt()
    except ValueError:
        print("Not an integer")
        checkInt()
    return height


def makeRow(num):
    # makes the rows
    for n in range(num):
        print(" " * ((num - n) - 1), end="")
        print("#" * (n + 1), end="")
        print("")


main()