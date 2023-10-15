ust_input = input().split()
height = int(ust_input[0])
width = int(ust_input[1])
def str_format(height, width):
    pattern = ""
    for i in range(height):
        if i <= (height - 1) / 2 - 1:
            pattern += (".|." + 2 * i * ".|.").center(width, "-") + "\n"
        elif (height + 1) / 2 - 1 < i <= height:
            pattern += (".|." + 2 * (height - i - 1) * ".|.").center(width, "-") + "\n"
        else:
            pattern += ("WELCOME").center(width, "-") + "\n"
    
    return pattern
print(str_format(height, width))
