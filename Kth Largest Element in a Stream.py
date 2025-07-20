import heapq
import unittest
from typing import List

class KthLargest:
    def __init__(self, k: int, nums: list[int]):
        """
        Initialize the object with the integer k and the stream of integers nums.
        """
        # pass
        self._min_heap: List = nums[0:k]
        heapq.heapify(self._min_heap)

        for i in range(k, len(nums)):
            if self._min_heap[0] < nums[i]:
                heapq.heappushpop(self._min_heap, nums[i])


    def add(self, val: int) -> int:
        """
        Appends the integer val to the stream and returns the element representing the kth largest element in the stream.
        """
        # pass
        if len(self._min_heap) == 0:
            heapq.heappush(self._min_heap, val)
        elif self._min_heap[0] < val:
            heapq.heappushpop(self._min_heap, val)

        return self._min_heap[0]



class TestKthLargest(unittest.TestCase):
    def test_example(self):
        kthLargest = KthLargest(3, [4, 5, 8, 2])
        self.assertEqual(kthLargest.add(3), 4)
        self.assertEqual(kthLargest.add(5), 5)
        self.assertEqual(kthLargest.add(10), 5)
        self.assertEqual(kthLargest.add(9), 8)
        self.assertEqual(kthLargest.add(4), 8)

    def test_empty_nums(self):
        kthLargest = KthLargest(1, [])
        self.assertEqual(kthLargest.add(-3), -3)
        self.assertEqual(kthLargest.add(-2), -2)
        self.assertEqual(kthLargest.add(-4), -2)
        self.assertEqual(kthLargest.add(0), 0)
        self.assertEqual(kthLargest.add(4), 4)

    def test_k_is_one(self):
        kthLargest = KthLargest(1, [2, 3, 4])
        self.assertEqual(kthLargest.add(1), 4)
        self.assertEqual(kthLargest.add(5), 5)

if __name__ == "__main__":
    unittest.main()