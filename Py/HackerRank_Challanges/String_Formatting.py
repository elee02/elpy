def print_formatted(number):
    # your code goes here
    f_txt = ""
    for i in range(number + 1):
        f_dec = str(i).rjust(len(bin(i)) + 1)
        f_oct = oct(i)[2:].rjust(6)
        f_hex = hex(i)[2:].upper().rjust(6)
        f_bin = bin(i)[2:].rjust(6)
        f_txt += f_dec + f_oct + f_hex + f_bin + "\n"
    print(f_txt)



if __name__ == '__main__':
    n = int(input())
    print_formatted(n)