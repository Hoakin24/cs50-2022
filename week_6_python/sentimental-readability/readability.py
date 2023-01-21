# TODO

def main():
    # prompts user for text
    text = input("Text: ")

    # assign the number of letters, words, and sentences to variables
    letters = countLetters(text)
    words = countWords(text)
    sentences = countSentences(text)

    # calculate for L
    L = (letters / words) * 100.0

    # calculate for S
    S = (sentences / words) * 100.0

    # calculate for Coleman-Liau index
    index = 0.0588 * L - 0.29 * S - 15.8
    index = round(index)
    ind = index

    # print grade level of text
    if index > 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {ind}")


def countLetters(txt):
    # count letters
    letterCount = 0
    alphabet = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
    text = list(txt)

    for i in range(len(txt)):
        for j in range(len(alphabet)):
            if alphabet[j] == text[i]:
                letterCount += 1

    print(f"letter count: {letterCount}")
    return letterCount


def countWords(txt):
    # count words
    wordCount = 0
    text = list(txt)

    if text[0] == "\0":
        wordCount = 0
    else:
        wordCount += 1
        for k in range(len(txt)):
            if text[k] == " " and text[k + 1] != " ":
                wordCount += 1

    print(f"word count: {wordCount}")
    return wordCount


def countSentences(txt):
    # count sentences
    sentencesCount = 0
    text = list(txt)

    for l in range(len(txt)):
        if text[l] == "." or text[l] == "?" or text[l] == "!":
            sentencesCount += 1

    print(f"sentences count: {sentencesCount}")
    return sentencesCount


main()