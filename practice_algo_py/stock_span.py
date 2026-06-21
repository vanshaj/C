def stock_span(arr: list) -> int:
    max_val = 0
    le_right = []
    # Identify the largest element on right array
    for i in range(len(arr) - 1, -1, -1):
        max_val = max_val if max_val > arr[i] else arr[i]
        le_right.append(max_val)

    le_right.reverse()
    max_profit = 0
    # Create a profit array by subtracting all values of le_right and arr
    for i in range(0, len(arr)):
        profit = le_right[i] - arr[i]
        max_profit = max_profit if max_profit > profit else profit
    return max_profit



def main():
    arr = [2, 5, 1, 6, 3, 10]
    print(stock_span(arr))

if __name__ == '__main__':
    main()
