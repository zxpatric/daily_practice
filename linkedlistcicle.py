class ListNode:
    def __init__(self, value=0, next=None):
        self.value = value
        self.next = next

def _get_next (node: ListNode) -> ListNode:
    if node is None:
        return node
    return node.next


def is_circle (head: ListNode) -> bool:
    if head is None:
        return True

    slow = head
    fast = head.next

    while True:
        if fast is None:
            return False
        elif fast == slow:
            return True
        else:
            slow = _get_next(slow)
            fast = _get_next(_get_next(fast))


if __name__ == "__main__":
    # Test data
    node1 = ListNode(3)
    node2 = ListNode(2)
    node3 = ListNode(0)
    node4 = ListNode(-4)

    node1.next = node2
    node2.next = node3
    node3.next = node4
    node4.next = node2  # Creates a cycle

 

    # Example usage
    head = node1
    print(f"Is the circled linked list a circle? {is_circle(head)}")

    node4.next = None
    print(f"Is the non-circled linked list a circle? {is_circle(head)}")   