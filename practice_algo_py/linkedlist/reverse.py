class Node:
    def __init__(self,
            val,
            nex):
        self.val = val
        self.nex = nex

def reverse(head: Node) -> Node:
    nex = None
    prev = None
    curr = head

    while curr != None:
        nex = curr.nex
        curr.nex = prev
        prev = curr
        curr = nex

    head = prev
    printLL(head)

def printLL(head: Node):
    ptr = head
    while ptr != None:
        print(ptr.val)
        ptr = ptr.nex

if __name__ == '__main__':
    n6 = Node(6, None)
    n5 = Node(5, n6)
    n4 = Node(4, n5)
    n3 = Node(3, n4)
    n2 = Node(2, n3)
    n1 = Node(1, n2)
    node = findN(n1, 2)
    printLL(n1)
    print('----Reverse------')
    reverse(n1)