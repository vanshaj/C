# This will calculate maximum value for consecutive numbers
# KADANE'S Algorithm
def cons_max_sub(arr: list):
    max_val = arr[0]
    sum_val = arr[0]
    n = len(arr)
    for i in range(1, n):
        inc = sum_val + arr[i]
        if inc > max_val:
            max_val = inc
            sum_val = inc
        else:
            if inc > 0:
                sum_val = inc
            else:
                sum_val = 0
    return max_val


# This will calculate for any sequence
def max_sub(arr: list) -> int:
    n = len(arr)
    if n == 1:
        return arr[0]
    sum_inc = arr[n-1] + max_sub(arr[:n-1])
    sum_exc = max_sub(arr[:n-1])
    if sum_inc > sum_exc:
        return sum_inc
    else:
        return sum_exc

if __name__ == '__main__':
    # arr = [-1, -2, 4, 2, 1, -5, 10, 1]
    arr = [-1, -2, 4, 2, 1, -5, 1]
    print(max_sub(arr))
    print(cons_max_sub(arr))
