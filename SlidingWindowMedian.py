from heapq import *
from typing import List


class SlidingWindowMedian:
    def __init__(self):
        self._min_heap: List = []
        self._max_heap: List = []

    def _calc_median(self) -> float:

        print ("self._min_heap: ", self._min_heap)
        print ("self._max_heap: ", self._max_heap)


        if len(self._min_heap) > len(self._max_heap):
            return self._min_heap[0]
        elif len(self._min_heap) < len(self._max_heap):
            return -self._max_heap[0]
        else:
            return (self._min_heap[0]-self._max_heap[0]) / 2.0

    def medianSlidingWindow(self, nums: list[int], k: int) -> list[float]:
        """
        Calculate the median for each sliding window of size k in the array nums.
        
        Args:
            nums: List of integers
            k: Size of the sliding window
            
        Returns:
            List of medians for each window
        """
        _results = []

        _len: int = len(nums)
        if _len < k:
            return None

        self._max_heap.append(nums[0])
        for i in range(1, k):
            num: int = nums[i]
            if len(self._max_heap) > len(self._min_heap):
                if -self._max_heap[0] > num:
                    heappush(self._min_heap, -heapreplace(self._max_heap, -num))
                else:
                    heappush(self._min_heap, num)
            else:
                if self._min_heap[0] < num:
                    heappush(self._max_heap, -heapreplace(self._min_heap, num))
                else:
                    heappush(self._max_heap, num)

        _median: int = self._calc_median()
        _results.append(_median)

        for i in range(1, _len - k + 1):
            # remove item[i] and add item[i+k-1]
            _new_value: int = nums[i+k-1]
            _del_value: int = nums[i-1]
            try:
                index_min = self._min_heap.index(_del_value)
                if _new_value < -self._max_heap[0]:
                    self._min_heap[index_min] = -self._max_heap[0]
                    heapreplace(self._max_heap, -_new_value)
                else:
                    self._min_heap[index_min] = _new_value
                heapify(self._min_heap)                
            except ValueError:
                index_max = self._max_heap.index(-_del_value)
                if _new_value > self._min_heap[0]:
                    self._max_heap[index_max] = -self._min_heap[0]
                    heapreplace(self._min_heap, _new_value)
                else:
                    self._max_heap[index_max] = -_new_value
                heapify(self._max_heap)

            _median = self._calc_median()
            _results.append(_median) 

        # pass
        return _results


def test_sliding_window_median():
    # Test case 1: Basic case
    solution = SlidingWindowMedian()
    nums = [1,3,-1,-3,5,3,6,7]
    k = 3
    expected = [1.0, -1.0, -1.0, 3.0, 5.0, 6.0]
    result = solution.medianSlidingWindow(nums, k)
    assert result == expected, f"Expected {expected}, but got {result}"
    print("All test cases passed!")

if __name__ == "__main__":
    test_sliding_window_median()