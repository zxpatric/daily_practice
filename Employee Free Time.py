from typing import List
import heapq

# Definition for an Interval.
class Interval:
    def __init__(self, start: int, end: int):
        self.start = start
        self.end = end

    def __lt__(self, other):
        return self.start < other.start

class Solution:
    def employeeFreeTime(self, schedule: List[List[Interval]]) -> List[Interval]:
        """
        Finds the free time intervals for all employees.
        :param schedule: List of lists of Interval objects representing employee schedules.
        :return: List of Interval objects representing free time intervals.
        """
        pq = []
        for inters in schedule:
            for inter in inters:
                heapq.heappush(pq, inter)

        result = []
        interval = pq[0]
        heapq.heappop(pq)
        while pq:
            if interval.end < pq[0].start:
                result.append(Interval(interval.end, pq[0].start))
                interval = pq[0]
            else:
                interval.end = max(interval.end, pq[0].end)
            heapq.heappop(pq)

        return result


# Test case
if __name__ == "__main__":
    schedule = [
        [Interval(1, 2), Interval(5, 6)],
        [Interval(1, 3)],
        [Interval(4, 10)]
    ]
    solution = Solution()
    free_time = solution.employeeFreeTime(schedule)
    for interval in free_time:
        print(f"Free time: start={interval.start}, end={interval.end}")