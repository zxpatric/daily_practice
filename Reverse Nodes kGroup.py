class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        """
        Reverse nodes in k-group.
        :param head: ListNode - Head of the linked list.
        :param k: int - Size of the group to reverse.
        :return: ListNode - Head of the modified linked list.
        """
        # Implementation goes here
        # pass
        _previous: ListNode = None
        _current: ListNode = head

        if head is None or head.next is None:
            return head

        _next: ListNode = head.next
        while _next is not None and k > 0:
            _current.next = _previous
            _previous = _current
            _current = _next
            _next = _next.next
            k -= 1

        if _next is None and k > 0:
            _current.next = _previous
            head.next = None
            return _current
        else:
            head.next = _current
            return _previous


# Helper function to create a linked list from a list
def create_linked_list(values):
    dummy = ListNode(0)
    current = dummy
    for value in values:
        current.next = ListNode(value)
        current = current.next
    return dummy.next

# Helper function to convert a linked list to a list
def linked_list_to_list(head):
    result = []
    while head:
        result.append(head.val)
        head = head.next
    return result

# Test case
if __name__ == "__main__":
    solution = Solution()
    head = create_linked_list([1, 2, 3, 4, 5])
    k = 4
    new_head = solution.reverseKGroup(head, k)
    print(linked_list_to_list(new_head))  # Expected output depends on implementation