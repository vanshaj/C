def tower(s, d, h, n):
    if n == 1:
        print(f"Move plate from {s} to {d}")
        return
    tower(s, h, d, n-1)
    print(f"Move plate from {s} to {d}")
    tower(h, d, s, n-1)


def main():
    n = 3
    tower('A', 'C', 'B', n)


if __name__ == '__main__':
    main()
