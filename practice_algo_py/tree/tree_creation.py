class Node:
    def __init__(self, val, left, right):
        self.val = val
        self.left = left
        self.right = right


def find_index(li: list, item):
    count = 0
    for i in li:
        if i == item:
            return count
        count = count + 1


def cst(in_t: list,
        pre_t: list,
        node: Node):
    if len(in_t) == 1 and len(pre_t) == 1:
        node.val = pre_t.pop(0)
        return
    node.val = pre_t.pop(0)
    index = find_index(in_t, node.val)
    in_t_a = in_t[0:index]
    in_t_b = in_t[index+1:]
    pre_t_a = pre_t[0:len(in_t_a)]
    pre_t_b = pre_t[len(in_t_a):]
    node.left = Node(0, None, None)
    cst(in_t_a, pre_t_a, node.left)
    node.right = Node(0, None, None)
    cst(in_t_b, pre_t_b, node.right)


def dfs(node: Node):
    if node is None:
        return
    dfs(node.left)
    dfs(node.right)
    print(node.val)


def main():
    n1 = Node(0, None, None)
    in_t = [9, 3, 15, 20, 7]
    pre_t = [3, 9, 20, 15, 7]
    cst(in_t, pre_t, n1)
    dfs(n1)


if __name__ == '__main__':
    main()
