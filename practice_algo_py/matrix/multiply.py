def display(mat):
    for i in range(0, len(mat)):
        for j in range(0, len(mat[0])):
             print(mat[i][j],end=" ")
        print()

def multiply(arr, arr2):
    r = len(arr)
    c = len(arr2[0])
    mul = [[0] * c for _ in range(r)]
    for i in range(0, r):
        for j in range(0, c):
            for k in range(0, len(arr2)):
                val = arr[i][k] * arr2[k][j]
                mul[i][j] = mul[i][j] + val
    display(mul)
                

if __name__ == '__main__':
    arr = [[1,2,3],
            [4,5,6]]
    arr2 = [[1,2,7],
            [3,4,8],
            [5,6,9]]
    multiply(arr, arr2)
