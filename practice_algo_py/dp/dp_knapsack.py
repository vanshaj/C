rows = 30
cols = 30
matrix = [[-1 for _ in range(cols)] for _ in range(rows)]
def dp_knapsack(wt: list,
                val: list,
                W: int) -> int:
    n = len(wt)
    max_val = 0
    # Base condition if there is no weight or if the max weight knapsack can handle is 0
    if n == 0 or W == 0:
        return 0
    # check if value is present in matrix
    if matrix[n][W] != -1:
        return matrix[n][W]
    # 2 conditions
    # First if weight of items is less than the weight knapsack can handle
    if wt[n-1] <= W:
        # Include the weight and identify the knapsack for the rest of the items
        v_inc = val[n-1] + dp_knapsack(wt[:n-1], val[:n-1], W-wt[n-1])
        # Donot include the weight and identify the knapsack for the rest of the items
        v_n_inc = dp_knapsack(wt[:n-1], val[:n-1], W)
        # Take the one with which we have max profit
        max_val = v_inc if v_inc > v_n_inc else v_n_inc
        matrix[n][W] = max_val
    # If it is greater than the knapsack then don't include the weight
    else:
        max_val = dp_knapsack(wt[:n-1], val[:n-1], W)
        matrix[n][W] = max_val
    return max_val

def main():
    wt = [1, 3, 5, 7, 5, 18, 9, 5, 12]
    val = [2, 10, 20, 3, 11, 12, 4, 14, 22]
    W = 20
    print(dp_knapsack(wt, val, W))

if __name__ == '__main__':
    main()

