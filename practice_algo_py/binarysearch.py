def bs(arr: list,
       item: int) -> int:
    start = 0
    end = len(arr) - 1
    while start <= end:
        mid = start + (end - start) // 2
        if arr[mid] == item:
            return mid
        else:
            if arr[mid] > item:
                end = mid - 1
            else:
                start = mid + 1


def main():
    arr = [1, 2, 4, 6, 9, 11, 13, 15, 17, 20]
    item = 17
    index = bs(arr, item)
    print(index)


if __name__ == '__main__':
    main()

