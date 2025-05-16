class ListNode:
    def __init__(self, value=0, next=None):
        self.value = value
        self.next = next

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        """
        Reverses a singly linked list.
        :param head: ListNode
        :return: ListNode
        """
        # pass
        _previous: ListNode = None
        _current: ListNode = head

        if head is None or head.next is None:
            return head

        _next: ListNode = head.next
        while _next is not None:
            _current.next = _previous
            _previous = _current
            _current = _next
            _next = _next.next

        _current.next = _previous

        return _current




# Helper function to create a linked list from a list
def create_linked_list(values):
    if not values:
        return None
    head = ListNode(values[0])
    current = head
    for value in values[1:]:
        current.next = ListNode(value)
        current = current.next
    return head

# Helper function to convert a linked list to a list
def linked_list_to_list(head):
    result = []
    while head:
        result.append(head.value)
        head = head.next
    return result

# Test case
if __name__ == "__main__":
    # Input: 1 -> 2 -> 3 -> 4 -> 5
    head = create_linked_list([1, 2, 3, 4, 5])
    solution = Solution()
    reversed_head = solution.reverseList(head)
    # Expected Output: 5 -> 4 -> 3 -> 2 -> 1
    print(linked_list_to_list(reversed_head))