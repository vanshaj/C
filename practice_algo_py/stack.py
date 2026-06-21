# find nearest largest item index on left
def fLarr(arr: list) -> list:
    # larr = [0, 0, 1, 0, 3, 0, 0, 6]
    larr = []
    stack = []
    for i in range(0, len(arr)):
        if len(stack) == 0:
            larr.append(0)
        elif len(stack) > 0 and arr[stack[-1]] > arr[i]:
            larr.append(stack[-1])
        elif len(stack) > 0 and arr[stack[-1]] <= arr[i]:
            while len(stack) > 0 and arr[stack[-1]] <= arr[i]:
                stack.pop()
            if len(stack) == 0:
                larr.append(0)
            elif arr[stack[-1]] > arr[i]:
                larr.append(stack[-1])
        stack.append(i)
    return larr


def main():
    arr = [3, 4, 2, 7, 5, 8, 10, 6]
    print(fLarr(arr))


if __name__ == '__main__':
    main()
