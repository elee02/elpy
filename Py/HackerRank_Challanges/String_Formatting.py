def print_formatted(number):
    # your code goes here
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