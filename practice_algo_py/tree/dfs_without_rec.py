class Node:
    def __init__(self,
                 val: int,
                 left=None,
                 right=None):
        self.val = val
        self.left = left
        self.right = right


def pre_order_traverse(root: Node):
    stack = []
    if root is None:
        return stack
    stack.append(root)
    while (len(stack) != 0):
        curr_node = stack.pop()
        print(curr_node.val)
        if curr_node.right is not None:
            stack.append(curr_node.right)
        if curr_node.left is not None:
            stack.append(curr_node.left)

def post_order_traversal(root: Node):
    st1 = []
    st2 = []
    if root is None:
        return None
    st1.append(root)
    while (len(st1) != 0):
        curr_node = st1.pop()
        st2.append(curr_node)
        if curr_node is not None:
            if curr_node.left is not None:
                st1.append(curr_node.left)
            if curr_node.right is not None:
                st1.append(curr_node.right)
    while (len(st2) != 0):
        print(st2.pop().val)


def inorder_traversal(root: Node):
    st = []
    node = root
    while (True):
        if (node is not None):
            st.append(node)
            node = node.left
        else:
            if len(st) == 0:
                break
            else:
                node = st.pop()
                print(node.val)
                node = node.right


if __name__ == '__main__':
    n4 = Node(4)
    n5 = Node(5)
    n6 = Node(6)
    n7 = Node(7)
    n2 = Node(2, n4, n5)
    n3 = Node(3, n6, n7)
    n1 = Node(1, n2, n3)
    # pre_order_traverse(n1)
    # post_order_traversal(n1)
    inorder_traversal(n1)
