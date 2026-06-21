def perm(inp: str,
         out: str):
    if len(inp) == 0:
        print(out)
        return
    out1 = out
    out2 = out + inp[0]
    inp = inp[1:]
    perm(inp, out1)
    perm(inp, out2)


def permutation(n: int):
    def factorial(n: int):
        fact = 1
        for i in range(2, n+1):
            fact = fact*i
        return fact

    def perms(n: int, r: int):
        fn = factorial(n)
        fr = factorial(r)
        fnr = factorial(n-r)
        divisor = fr*fnr
        return int(fn/divisor)

    max = 2
    for i in range(1, n):
        max = max + perms(n, i)
    print(max)


def main():
    input = "abcdefghijklmnop"
    perm(input, "")
    permutation(len(input))


if __name__ == '__main__':
    main()
