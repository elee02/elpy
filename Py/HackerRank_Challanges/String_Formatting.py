"""
This script defines a function that prints the decimal, octal, hexadecimal, and 
binary values of integers from 1 to the given number.

The function takes an integer representing the upper limit of the range of 
integers to be printed. It then formats the integers in decimal, octal, 
hexadecimal, and binary formats and prints them in a string.

Example:
    If the input number is 5, the function will print:
        1   1   1   1
        2   2   2  10
        3   3   3  11
        4   4   4 100
        5   5   5 101

This script can be run from the command line by providing an integer argument 
representing the upper limit of the range of integers to be printed.

Usage:
    python string_formatting.py 5
"""
def print_formatted(number):
    """
    Prints the decimal, octal, hexadecimal, and binary values of integers from 
    1 to the given number.

    Args:
    - number: An integer representing the upper limit of the range of integers 
    to be printed.

    Returns:
    - None. The function only prints the formatted string.
    """

    f_txt = ""
    for i in range(1, number + 1):
        width = len(bin(number)[2:])
        f_dec = str(i).rjust(width) + " "
        f_oct = oct(i)[2:].rjust(width) + " "
        f_hex = hex(i)[2:].upper().rjust(width) + " "
        f_bin = bin(i)[2:].rjust(width)
        f_txt += f_dec + f_oct + f_hex + f_bin + "\n"
    print(f_txt)



if __name__ == '__main__':
    n = int(input())
    print_formatted(n)
