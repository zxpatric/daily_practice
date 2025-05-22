from heapq import *

class MedianOfStream:
    def __init__(self):
        # Initialize your data structure here
        self._min_heap = []
        self._max_heap = []

        # pass

    def insert_num(self, num: int) -> None:
        # Insert a number into the stream
        # pass

        _len_min:int = len(self._min_heap)
        _len_max:int = len(self._max_heap)

        if _len_max < _len_min:
            if self._min_heap[0] < num:
                heappush(self._max_heap, -heapreplace(self._min_heap, num))
            else:
                heappush(self._max_heap, -num)
        elif _len_max == _len_min:
            if _len_min == 0 or self._min_heap[0] < num:
                heappush(self._min_heap, num)
            else:
                heappush(self._max_heap, -num)
        else:
            if -self._max_heap[0] > num:
                heappush(self._min_heap, -heapreplace(self._max_heap, -num))
            else:
                heappush(self._min_heap, num)

    def find_median(self) -> float:
        # Return the median of the stream
        _len_min:int = len(self._min_heap)
        _len_max:int = len(self._max_heap)

        if _len_max > _len_min:
            return -self._max_heap[0]
        elif _len_max < _len_min:
            return self._min_heap[0]
        else:
            return (self._min_heap[0] + -self._max_heap[0]) / 2.0


# Simple test case
if __name__ == "__main__":
    stream = MedianOfStream()
    stream.insert_num(1)
    stream.insert_num(2)
    print("Median:", stream.find_median())  # Expected output: 1.5
    stream.insert_num(3)
    print("Median:", stream.find_median())  # Expected output: 2.0