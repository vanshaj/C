def findLarr(arr: list) -> list:
    # larr = [0, 0, 2, 3, 2, 5]
    larr = []
    stack = []
    for i in range(0, len(arr)):
        if len(stack) == 0:
            larr.append(0)
        elif len(stack) > 0 and arr[stack[-1]] < arr[i]:
            larr.append(stack[-1]+1)
        elif len(stack) > 0 and arr[stack[-1]] >= arr[i]:
            while len(stack) > 0 and arr[stack[-1]] >= arr[i]:
                stack.pop()
            if len(stack) == 0:
                larr.append(0)
            elif len(stack) > 0 and arr[stack[-1]] < arr[i]:
                larr.append(stack[-1]+1)
        stack.append(i)
    print(larr)
    return larr


def findRarr(arr: list) -> list:
    # rarr = [0, 5, 3, 3, 5, 5]
    rarr = []
    stack = []
    for i in range(len(arr)-1, -1, -1):
        if len(stack) == 0:
            rarr.append(len(arr)-1)
        elif len(stack) > 0 and arr[stack[-1]] < arr[i]:
            rarr.append(stack[-1]-1)
        elif len(stack) > 0 and arr[stack[-1]] >= arr[i]:
            while len(stack) > 0 and arr[stack[-1]] >= arr[i]:
                stack.pop()
            if len(stack) == 0:
                rarr.append(len(arr)-1)
            elif arr[stack[-1]] < arr[i]:
                rarr.append(stack[-1]-1)
        stack.append(i)
    rarr.reverse()
    print(rarr)
    return rarr


def main(arr: list) -> int:
    larr = findLarr(arr)
    rarr = findRarr(arr)
    max_size = 0
    for i in range(0, len(arr)):
        width = rarr[i] - larr[i] + 1
        print(f"{width} is width of item {arr[i]}")
        size = width * arr[i]
        max_size = size if size > max_size else max_size
    return max_size


if __name__ == '__main__':
    hist = [2, 1, 5, 6, 2, 3]
    print(main(hist))
