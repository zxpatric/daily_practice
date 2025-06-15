from typing import List
import unittest
import heapq

class KthSmallestInSortedLists:
    def find_kth_smallest(self, lists: List[List[int]], k: int) -> int:
        """
        Finds the Kth smallest number among M sorted lists.

        :param lists: List of sorted integer lists.
        :param k: The Kth position to find.
        :return: The Kth smallest number.
        """
        # TODO: Implement this method
        # pass

        min_heap: List = []

        # push all in and pop until k



        # or push M in and pushpop until k
        index_list: List  = []
        for i, num_list in enumerate(lists):
            if len(num_list) > 0:
                heapq.heappush(min_heap, (num_list[0], i))
                index_list.append(1)
            else:
                index_list.append(0)
                
        popped: int = 0
        value: int = -1
        while popped < k and len(min_heap) > 0:
            value, index = min_heap[0]
            popped += 1
            if index_list[index] < len(lists[index]):
                heapq.heappushpop(min_heap, (lists[index][index_list[index]], index))
                index_list[index] += 1
            else:
                heapq.heappop(min_heap)

        if popped != k:
            raise SystemError(f"Total available numbers are {popped} less than {k}")

        return value


# ------------------ Tests ------------------


class TestKthSmallestInSortedLists(unittest.TestCase):
    def setUp(self):
        self.solver = KthSmallestInSortedLists()

    def test_example_1(self):
        lists = [
            [2, 6, 8],
            [3, 6, 7],
            [1, 3, 4]
        ]
        k = 5
        # Expected: 4 (sorted order: 1,2,3,3,4,6,6,7,8)
        self.assertEqual(self.solver.find_kth_smallest(lists, k), 4)

    def test_example_2(self):
        lists = [
            [1, 5, 9],
            [2, 3, 7],
            [4, 6, 8]
        ]
        k = 7
        # Expected: 7 (sorted order: 1,2,3,4,5,6,7,8,9)
        self.assertEqual(self.solver.find_kth_smallest(lists, k), 7)

    def test_single_list(self):
        lists = [
            [1, 2, 3, 4, 5]
        ]
        k = 3
        self.assertEqual(self.solver.find_kth_smallest(lists, k), 3)

    def test_k_is_one(self):
        lists = [
            [10, 20, 30],
            [5, 15, 25]
        ]
        k = 1
        self.assertEqual(self.solver.find_kth_smallest(lists, k), 5)

    def test_empty_lists(self):
        lists = [
            [],
            [1, 2, 3]
        ]
        k = 2
        self.assertEqual(self.solver.find_kth_smallest(lists, k), 2)

if __name__ == "__main__":
    unittest.main()