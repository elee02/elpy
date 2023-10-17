''' You are given a string S and width w.'''
import textwrap

def wrap(var_str, max_wd):
    '''Return a textwraped string'''
    return textwrap.fill(var_str, max_wd)

if __name__ == '__main__':
    string, max_width = input(), int(input())
    result = wrap(string, max_width)
    print(result)
