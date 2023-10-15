def minion_game(string):
    # your code goes here
    consonant = "bcdfghjklmnpqrstvwxyz".upper()
    vowel = "aeiou".upper()
    numStuart = 0
    numKevin = 0
    for idx, let in enumerate(string):
        if let in consonant:
            numStuart += len(string) - idx
        if let in vowel:
            numKevin += len(string) - idx
    if numStuart > numKevin:
        print("Stuart ", numStuart)
    elif numKevin > numStuart:
        print("Kevin ", numKevin)
    else:
        print("Draw")

if __name__ == "__main__":
    s = input()
    minion_game(s)
