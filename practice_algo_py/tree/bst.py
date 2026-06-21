class Node:
    def __init__(self, val, left = None , right = None):
        self.val = val
        self.left = left
        self.right = right

def search(ele: int, 
           node: Node):
    if ele == node.val:
        return node
    if ele < node.val :
        return search(ele, node.left)
    else:
        return search(ele, node.right)

def minimum(node: Node) -> None:
    curr = root
    while curr.left is not None:
        curr = curr.left
    return curr

def maximum(root: Node) -> Node:
    curr = root
    while curr.right is not None:
        curr = curr.right
    return curr


def dfs(node: Node):
    if node is None:
        return
    dfs(node.left)
    print(node.val)
    dfs(node.right)

def inorder(node: Node,
            ele: int):
    if node is None:
        return
    inorder(node.left)
    inorder(node.right)
    print(node.val)

def insert(ele : int, 
           root: Node):
    # Base condition if element is less than root and root has no left insert
    if root.left == None and ele < root.val:
        n = Node(ele)
        root.left = n
        return
    # Second base condition if element is greater  than root and has no right ele insert
    if root.right == None and ele > root.val:
        n = Node(ele)
        root.right = n
        return
    if ele < root.val:
        insert(ele, root.left)
    elif ele > root.val:
        insert(ele, root.right)

def delete(ele: int,
           root: Node):
    """
    Delete node from the tree
    """
    if root is None:
        return root

    if root.val > ele:
        root.left = delete(ele, root.left)
    if root.val < ele:
        root.right = delete(ele, root.right)

    if root.left is None:
        return root.right
    if root.right is None:
        return root.left

    in_ele = find_successor(root.right)
    root.val = in_ele.val
    root.right = delete(root.val, root.right)

    return root
    
def find_successor(root):
    if root is None:
        return None
    while root.left is not None:
        root = root.left
    return root

if __name__ == '__main__':
    #arr = [15, 10, 20, 5, 12, 7, 3, 22, 17]
    arr = [7,1,3,12,10,5]
    root = Node(arr[0], None, None)
    for i in range(1, len(arr)):
         insert(arr[i], root)
    print(maximum(root).val)
    print(minimum(root).val)
    # delete(20, root)
    # dfs(root)
