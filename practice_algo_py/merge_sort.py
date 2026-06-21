def merge(left: list,
          right: list) -> list:
    i = 0
    j = 0
    merge_arr = []
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            merge_arr.append(left[i])
            i = i+1
        else:
            merge_arr.append(right[j])
            j = j+1
    while j < len(right):
        merge_arr.append(right[j])
        j = j+1
    while i < len(left):
        merge_arr.append(left[i])
        i = i+1
    return merge_arr



def sort(arr: list) -> list:
    if len(arr) == 1:
        return arr
    start = 0
    end = len(arr)
    mid = start + end // 2
    left_arr = sort(arr[0: mid])
    right_arr = sort(arr[mid: end])

    return merge(left_arr, right_arr)

if __name__ == '__main__':
    arr = [7, 2, 21, 3, 19, 14, 22]
    print(sort(arr))
