import unittest
import heapq
from typing import List


class ScheduleTasksOnMinimumMachines:
    def __init__(self):
        pass

    def min_machines(self, tasks):
        """
        Given a list of tasks with start and end times, return the minimum number of machines required
        to schedule all tasks without overlap.

        :param tasks: List of tuples (start, end)
        :return: int
        """
        # pass

        if len(tasks) == 0:
            return 0

        sorted_tasks = sorted(tasks, key=lambda x: x[0])

        min_heap: List = [-1]

        for task in sorted_tasks:
            if min_heap[0] <= task[0]:
                heapq.heappushpop(min_heap, task[1])
            else:
                heapq.heappush(min_heap, task[1])

        return len(min_heap)



# ------------------ TESTS ------------------


class TestScheduleTasksOnMinimumMachines(unittest.TestCase):
    def setUp(self):
        self.scheduler = ScheduleTasksOnMinimumMachines()

    def test_empty_tasks(self):
        self.assertEqual(self.scheduler.min_machines([]), 0)

    def test_single_task(self):
        self.assertEqual(self.scheduler.min_machines([(1, 2)]), 1)

    def test_non_overlapping_tasks(self):
        self.assertEqual(self.scheduler.min_machines([(1, 2), (3, 4), (5, 6)]), 1)

    def test_overlapping_tasks(self):
        self.assertEqual(self.scheduler.min_machines([(1, 4), (2, 5), (3, 6)]), 3)

    def test_mixed_tasks(self):
        self.assertEqual(self.scheduler.min_machines([(1, 3), (2, 4), (3, 5)]), 2)

    def test_same_time_tasks(self):
        self.assertEqual(self.scheduler.min_machines([(1, 5), (1, 5), (1, 5)]), 3)

if __name__ == "__main__":
    unittest.main()