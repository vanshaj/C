def sub(arr: list,
        n: int):
    st = 0
    end = n
    max = 0
    for i in range(0, n):
        max = max + arr[i]
    sum = max
    while end < len(arr):
        sum = sum + arr[end] - arr[st]
        max = sum if sum > max else max
        end = end + 1
        st = st + 1
    print(max)


def main():
    arr = [1, 3, 7, 6, 5, 2, 15]
    n = 4
    sub(arr, n)


if __name__ == '__main__':
    main()
