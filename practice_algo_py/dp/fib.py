"""
Fibonacci with DP
"""
r = 40
# Create a matrix to store the values already calculated
# initialize with -1
matrix = [-1 for _ in range(r+1)]
def fib(n: int) -> int:
    if n <= 1:
        return n
    # check if the matrix for that index already has some value if yes return that value
    if matrix[n] != -1:
        return matrix[n]
    else:
        fn = fib(n-1) + fib(n-2)
        # Store the value of fibonacci in the matrix
        matrix[n] = fn
        return fn
    

def main():
    n = 40
    print(fib(n))
    

if __name__ == '__main__':
    main()
