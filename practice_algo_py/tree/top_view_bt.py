class Node:
    def __init__(self,
                 val: int,
                 left = None,
                 right = None):
        self.val = val
        self.left = left
        self.right = right

def only_left(root: Node):
    st = []
    while (True):
        if root is not None:
            st.append(root)
            root = root.left
        else:
            break
    while (len(st) != 0):
        item = st.pop()
        print(item.val)

def only_right(root: Node):
    st = []
    while (True):
        if root is not None:
            st.append(root)
            root = root.right
        else:
            break
    while (len(st) !=0):
        item = st.pop(0)
        print(item.val)

if __name__ == '__main__':
    n4 = Node(4)
    n5 = Node(5)
    n6 = Node(6)
    n7 = Node(7)
    n2 = Node(2, n4, n5)
    n3 = Node(3, n6, n7)
    n1 = Node(1, n2, n3)
    only_left(n1.left)
    print(n1.val)
    only_right(n1.right)
