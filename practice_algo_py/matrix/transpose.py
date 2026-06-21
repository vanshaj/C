def display(mat):
    for i in range(0, len(mat)):
        for j in range(0, len(mat[0])):
             print(mat[i][j],end=" ")
        print()

def rotate(mat):
    tmat = transpose(mat)
    for i in range(0, len(mat)):
        tmat[i].reverse()
    display(tmat)

def counter_rotate(mat):
    tmat = transpose(mat)
    mid = len(mat) // 2 
    for i in range(0, mid):
        smat = tmat[len(mat) - i - 1]
        tmat[len(mat) -i  -1] = tmat[i]
        tmat[i] = smat
    display(tmat)

def transpose(mat):
    m = len(mat)
    n = len(mat[0])
    for i in range(0, m):
        for j in range(i+1, n):
            mat[i][j], mat[j][i] = mat[j][i], mat[i][j]
    return mat

if __name__ == '__main__':
    mat = [[1,2,3,13],
           [4,5,6,14],
           [7,8,9,15],
           [10,11,12,16]]
    counter_rotate(mat)
