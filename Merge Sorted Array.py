import unittest
from typing import List

# Merge Sorted Array - Boilerplate

def merge(nums1, m, nums2, n) -> List:
    """
    Merges two sorted arrays nums1 and nums2 into nums1 as one sorted array.
    Do not return anything, modify nums1 in-place instead.
    """
    # pass  # Implementation goes here

    result: list = []

    index1: int = 0
    index2: int = 0

    while index1 < m or index2 < n:

        if index1 == m:
            result.append(nums2[index2])
            index2 += 1
        elif index2 == n:
            result.append(nums1[index1])
            index1 += 1
        elif nums1[index1] < nums2[index2]:
            result.append(nums1[index1])
            index1 += 1
        else:
            result.append(nums2[index2])
            index2 += 1

    return result

# Tests

class TestMergeSortedArray(unittest.TestCase):
    def test_example_1(self):
        nums1 = [1,2,3,0,0,0]
        m = 3
        nums2 = [2,5,6]
        n = 3
        nums = merge(nums1, m, nums2, n)
        self.assertEqual(nums, [1,2,2,3,5,6])

    def test_example_2(self):
        nums1 = [1]
        m = 1
        nums2 = []
        n = 0
        nums = merge(nums1, m, nums2, n)
        self.assertEqual(nums, [1])

    def test_example_3(self):
        nums1 = [0]
        m = 0
        nums2 = [1]
        n = 1
        nums = merge(nums1, m, nums2, n)
        self.assertEqual(nums, [1])

if __name__ == "__main__":
    unittest.main()