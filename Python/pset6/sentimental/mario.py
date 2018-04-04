from cs50 import get_int

def main():
    # Input
    while True:
        print("Height: ", end = "")
        height = get_int()
        if height >= 0 and height <= 23:
            break

    # Output
    h = 0
    while h<height:
        # print spaces depend on the height and the hashes
        for space in range(height-h-1):
            print(" ", end = "")
        # print hasches depend on the height
        for hash in range(h+2):
            print("#", end = "")
        print("")
        h+=1

if __name__ == "__main__":
    main()