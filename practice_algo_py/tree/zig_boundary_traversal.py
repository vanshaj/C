class Node:
    def __init__(self,
                 val: int,
                 left=None,
                 right=None):
        self.val = val
        self.left = left
        self.right = right


def in_order(node: Node):
    if node is None:
        return
    print(node.val)
    in_order(node.left)
    in_order(node.right)


def reverse_in_order(node: Node, s: list):
    if node is None:
        return
    s.append(node.val)
    reverse_in_order(node.left, s)
    reverse_in_order(node.right, s)


def boundary_traversal(node: Node):
    print(node.val)
    in_order(node.left)
    right = []
    reverse_in_order(node.right, right)
    while (len(right) != 0):
        print(right.pop())


def zigzag_traversal(node: Node):
    isLR = True
    trList = [[node.val]]
    queue = []
    queue.append(node)
    while (len(queue) != 0):
        trRow = []
        for _ in range(0, len(queue)):
            item = queue.pop(0)
            if item is not None:
                if item.left is not None:
                    queue.append(item.left)
                    trRow.append(item.left.val)
                if item.right is not None:
                    queue.append(item.right)
                    trRow.append(item.right.val)
        trList.append(trRow)
    print(trList)
    while (len(trList) != 0):
        trRow = trList.pop(0)
        if isLR:
            while (len(trRow) != 0):
                print(trRow.pop(0))
            isLR = False
        else:
            while (len(trRow) != 0):
                print(trRow.pop())
            isLR = True


if __name__ == '__main__':
    n8 = Node(8)
    n9 = Node(9)
    n4 = Node(4, n8, None)
    n5 = Node(5)
    n6 = Node(6, None, n9)
    n7 = Node(7)
    n2 = Node(2, n4, n5)
    n3 = Node(3, None, n6)
    n1 = Node(1, n2, n3)
    # zigzag_traversal(n1)
    boundary_traversal(n1)

