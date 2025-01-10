class Node:
    def __init__(self,
                 val: int,
                 left = None,
                 right = None):
        self.val = val
        self.left = left
        self.right = right

def dfs_postorder(node: Node):
    if node is None:
        return
    dfs_postorder(node.right)
    print(node.val)
    dfs_postorder(node.left)


def populate():
    val = input('Enter the root node\n')
    root = Node(val)
    return populate_value(root)

def populate_value(root: Node):
    left = input(f"Do you want to add to the left of {root.val}\n")
    if left in ['y', 'Y', 'YES', 'yes']:
        left_value = input('Enter the value\n')
        left_node = Node(left_value, None, None)
        root.left = left_node
        populate_value(root.left)
    right = input(f"Do you want to add to the right of {root.val}\n")
    if right in ['y', 'Y', 'YES', 'yes']:
        right_value = input('Enter the value\n')
        right_node = Node(right_value, None, None)
        root.right = right_node
        populate_value(root.right)
    return root

if __name__ == '__main__':
    root = populate()
    dfs_postorder(root)
