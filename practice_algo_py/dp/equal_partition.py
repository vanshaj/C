def partition(arr: list,
              sum_arr: int) -> bool:
    n = len(arr)
    if sum_arr == 0:
        return True
    if n == 0 and sum_arr != 0:
        return False
    if arr[n-1] <= sum_arr:
        return partition(arr[:n-1], sum_arr - arr[n-1]) or partition(arr[:n-1], sum_arr)
    else:
        return partition(arr[:n-1], sum_arr)
        

if __name__ == '__main__':
    arr = [1,6,12,5]
    sum_arr = 0
    for val in arr:
        sum_arr = sum_arr + val
    if sum_arr %2 != 0:
        print(False)
    else:
        print(partition(arr, sum_arr//2))
