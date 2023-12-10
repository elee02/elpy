import numpy as np

# Define the coefficients matrix A
A = np.array([[1/4.7+2, -0.5, -1], 
              [-0.5, 3, -1],
              [1, 1, -2-1/4.7]])

# Define the constants vector b
b = np.array([2.5, 5, 0])

# Solve the system of equations
# x = np.linalg.solve(A, b)

A_inv = np.linalg.inv(A)
x = A_inv @ b

# Print the solution
print("Solution:", x)
