import ctypes

# Load the shared library
lib = ctypes.CDLL('/Users/elyordusyor-uglirasulov/elpy/Py/HackerRank_Challanges/minion_game.so')

# Define the argument and return types
lib.minion_game.argtypes = [ctypes.c_char_p, ctypes.c_int]
lib.minion_game.restype = None

# Call the function with a long string
s = 'dilshod' * 100000000
lib.minion_game(s.encode('utf-8'), len(s))
