from cs50 import get_int
import math


def main():
    # The input should to be not more than 16 digits
    while True:
        input = get_int("Number: ")
        if (input < 9999999999999999):
            break

    # Variables identification
    digits = intlist(input)
    digits_sum_with_multiply = 0
    digits_sum_without_multiply = 0
    digits_with_mul_array = []
    counter = 0

    # a summation operation the first part of the digits sequences without multiply by 2
    for index in range(0, len(digits), 2):
        digits_sum_without_multiply += digits[index]

    # a summation operation the second part of the digits sequences with multiply by 2
    for index in range(1, len(digits), 2):
        counter += 1
        num = digits[index] * 2
        # if a number is more than one digit , this operation break it down to two digits separately
        # print ("get_count_digits is ",get_count_digits(num))
        if(get_count_digits(num) == 2):
            if num == 10:
                x = math.floor(num / 10)
                #x = num
                # print ("math.floor is ",x)
                digits_with_mul_array.insert(counter, x)
                digits_sum_with_multiply += x
            else:
                x = math.floor(num / 10)
                y = num % 10
                digits_with_mul_array.insert(counter, num)
                digits_sum_with_multiply += x
                digits_sum_with_multiply += y
        else:
            # if a number is one digit
            digits_with_mul_array.insert(counter, digits[index] * 2)
            digits_sum_with_multiply += digits[index] * 2
    result = digits_sum_with_multiply + digits_sum_without_multiply
    # print ("digits_with_mul_array is",digits_with_mul_array)
    # if the number of the final result gives second digit 0 , that means the operation is correct
    if check_card(result):
        # check the kind of the Credit Card
        check_card_company(digits)
    else:
        if (check_card_company_return(digits)):
            check_card_company(digits)
        else:
            print("INVALID")
            #print (result)
            #print (check_card(result))

# check the company of the Card


def check_card_company(digits):
    if (len(digits) == 16):
        if (digits[0] == 5) and (digits[1] in (1, 2, 3, 4, 5)):
            print("MASTERCARD")
            return 1
        elif (digits[0] == 4):
            print("VISA")
            return 1
    elif (len(digits) == 15) and (digits[0] == 3) and (digits[1] in (4, 7)):
        print("AMEX")
        return 1
    elif (len(digits) == 13) and (digits[0] == 4):
        print("VISA")
        return 1
    else:
        return 0

# check the company of the Card


def check_card_company_return(digits):
    if (len(digits) == 16):
        if (digits[0] == 5) and (digits[1] in (1, 2, 3, 4, 5)):
            return 1
        elif (digits[0] == 4):
            return 1
    elif (len(digits) == 15) and (digits[0] == 3) and (digits[1] in (4, 7)):
        return 1
    elif (len(digits) == 13) and (digits[0] == 4):
        return 1
    else:
        return 0

# check if the Card is Valid or Invalid


def check_card(r):
    if r % 10 == 0:
        # "Valid Card"
        return 1
    else:
        # "Invalid Card"
        return 0

# give the count of digits


def get_count_digits(number: int):
    """Return number of digits in a number."""
    if number == 0:
        return 1
    number = abs(number)
    if number <= 999999999999997:
        return math.floor(math.log10(number)) + 1
    count = 0
    while number:
        count += 1
        number //= 10
    return

# convert the integer number which inputting by the user to a list


def intlist(n):
    q = n
    ret = []
    while q != 0:
        q, r = divmod(q, 10)  # Divide by 10, see the remainder
        ret.insert(0, r)  # The remainder is the first to the right digit
    return ret


if __name__ == "__main__":
    main()