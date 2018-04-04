import cs50
import sys
import string


def main():
    # Input, enter the key
    # and check the count of arguments and the key should to be positive
    if (len(sys.argv) != 2) and (int(sys.argv[1]) < 0):
        print("Usage: ./caesar k")
        return 1
    key = int(sys.argv[1])

    # Input, enter the plaintext
    plaintext = input("plaintext: ")
    ciphertext = []

    # The encoding operation
    for i in range(len(plaintext)):
        char = plaintext[i]
        if (char.isalpha()):
            if (char.isupper()):
                result = chr(65 + (ord(char) - 65 + key) % 26)
                ciphertext.insert(i, result)
            else:
                result = chr(97 + (ord(char) - 97 + key) % 26)
                ciphertext.insert(i,result)
        else:
              ciphertext.insert(i, char)
# output, The last result
    print("ciphertext: ", end="")
    for i in range(len(ciphertext)):
        print(ciphertext[i], end="")
    print("")


if __name__ == "__main__":
    main()