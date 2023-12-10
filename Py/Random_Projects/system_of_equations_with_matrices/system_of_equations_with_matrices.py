import numpy as np

# Define the coefficients matrix A
A = np.array([[2, 1], [1, -3]])

# Define the constants vector b
b = np.array([5, -4])

# Solve the system of equations
x = np.linalg.solve(A, b)

# Print the solution
print("Solution:", x)
