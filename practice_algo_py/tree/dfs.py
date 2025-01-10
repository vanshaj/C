class Node:
    def __init__(self, val, left, right):
        self.val = val
        self.left = left
        self.right = right


def dfs(node: Node):
    if node is None:
        return
    dfs(node.left)
    print(node.val)
    dfs(node.right)


def depth(node: Node) -> int:
    if node.left is None and node.right is None:
        return 1
    ld = 0
    rd = 0
    if node.left is not None:
        ld = depth(node.left)
    if node.right is not None:
        rd = depth(node.right)
    max = ld + 1 if ld > rd else rd+1
    return max


def main():
    n0 = Node(0, None, None)
    n1 = Node(1, n0, None)
    n2 = Node(2, None, None)
    n3 = Node(3, None, None)
    n8 = Node(8, None, None)
    n9 = Node(9, None, n8)
    n4 = Node(4, None, n9)
    n5 = Node(5, n1, n2)
    n6 = Node(6, n3, n4)
    n7 = Node(7, n5, n6)
    dfs(n7)
    dep = depth(n7)
    print(f"{dep} is the depth of the tree")


if __name__ == '__main__':
    main()
