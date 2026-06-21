def trap_area(arr: list):
    w_cov_list = []
    left_max = []
    right_max = []
    left_max_val = 0
    right_max_val = 0
    for i in range(0, len(arr)):
        left_max_val = arr[i] if arr[i] > left_max_val else left_max_val
        left_max.append(left_max_val)
    for i in range(len(arr)-1, -1, -1):
        right_max_val = arr[i] if arr[i] > right_max_val else right_max_val
        right_max.append(right_max_val)
    for i in range(0, len(arr)):
        val = left_max[i] if left_max[i] < right_max[i] else right_max[i]
        w_cov = val - arr[i]
        w_cov_list.append(w_cov)
    print(w_cov_list)

def main():
    arr = [3, 0, 1, 4]
    trap_area(arr)

if __name__ == '__main__':
    main()
