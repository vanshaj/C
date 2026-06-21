r = 7
c = 19
matrix = [[-1 for _ in range(c)] for _ in range(r)]

def subset(arr: list,
        val: int) -> bool:
    n = len(arr)
    if n == 0 and val != 0:
        return False
    if val == 0:
        return True
    if matrix[n-1][val] != -1:
        return matrix[n-1][val]
    if arr[n-1] <= val:
        op = subset(arr[:n-1], val - arr[n-1]) or subset(arr[:n-1], val)
        matrix[n-1][val] = op
        return op
    else:
        op = subset(arr[:n-1], val)
        matrix[n-1][val] = op
        return op

if __name__ == '__main__':
    # arr = [5, 4, 6, 1, 2]
    arr = [11, 5, 10, 13, 2, 5]
    val = 18
    print(subset(arr, val))

