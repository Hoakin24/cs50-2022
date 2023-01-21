import csv
import sys


def main():

    # TODO: Check for command-line usage
    try:
        database = open(sys.argv[1], 'r')
    except FileNotFoundError as e:
        print(f"Database {sys.argv[1]} not found!", file=sys.stderr)
        sys.exit(1)
    try:
        sequence = open(sys.argv[2], 'r')
    except FileNotFoundError as e:
        print(f"Sequence {sys.argv[2]} not found!", file=sys.stderr)
        sys.exit(1)

    # TODO: Read database file into a variable
    readDatabase = csv.reader(database, delimiter=',')
    intoList = list(readDatabase)

    # TODO: Read DNA sequence file into a variable
    readSequence = sequence.read()

    # TODO: Find longest match of each STR in DNA sequence
    columnLength = len(intoList[0])
    dctnry = {}
    for a in range(1, columnLength):
        dctnry[intoList[0][a]] = 0
    longest = 0
    for b in range(len(dctnry)):
        longest = longest_match(readSequence, list(dctnry.keys())[b])
        dctnry[list(dctnry.keys())[b]] = longest

    # TODO: Check database for matching profiles
    dnaString = ""
    for c in range(len(dctnry)):
        dnaString += f"{str(dctnry[list(dctnry.keys())[c]])}"
    anoString = [''] * (len(intoList))
    for d in range(1, len(intoList)):
        for e in range(1, columnLength):
            anoString[d] += intoList[d][e]
    for f in range(len(anoString)):
        if dnaString == anoString[f]:
            print(intoList[f][0])
            sys.exit(0)
    print("No match")
    
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()