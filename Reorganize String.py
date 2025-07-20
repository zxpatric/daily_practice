import unittest
import heapq
from collections import Counter

class Solution:
    def reorganizeString(self, s: str) -> str:
        """
        Rearranges the string so that no two adjacent characters are the same.
        If not possible, returns an empty string.
        """
        # pass  # To be implemented

        # a hash map of the alphabet and its frequency
        # 

        # if len(s) == 0:
        #     return s

        # Calculate the frequency of characters in string and store counts
        # of each character along with the character itself in hash map.
        char_counter = Counter(s)

        # initializing heap
        most_freq_chars = []

        # Store character and its negative frequency in the array
        for char, count in char_counter.items():
            most_freq_chars.append([-count, char])

        # Construct heap from the array
        heapq.heapify(most_freq_chars)

        # initializing variables
        previous = None
        result = ""

        while len(most_freq_chars) > 0 or previous:

            if previous and len(most_freq_chars) == 0:
                return ""

            count, char = heapq.heappop(most_freq_chars)
            result = result + char
            count = count + 1  # negative value

            # pushing the char back to heap
            if previous:
                heapq.heappush(most_freq_chars, previous)
                previous = None

            # setting previous to the most recent used char
            if count != 0:
                previous = [count, char]

        return result



class TestReorganizeString(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()

    def test_example1(self):
        s = "aab"
        # Possible outputs: "aba"
        result = self.solution.reorganizeString(s)
        self.assertTrue(result == "" or all(result[i] != result[i+1] for i in range(len(result)-1)))

    def test_example2(self):
        s = "aaab"
        # Not possible to reorganize
        result = self.solution.reorganizeString(s)
        self.assertEqual(result, "")

    def test_single_char(self):
        s = "a"
        result = self.solution.reorganizeString(s)
        self.assertEqual(result, "a")

    def test_empty_string(self):
        s = ""
        result = self.solution.reorganizeString(s)
        self.assertEqual(result, "")

    def test_longer_string(self):
        s = "vvvlo"
        result = self.solution.reorganizeString(s)
        self.assertTrue(result == "" or all(result[i] != result[i+1] for i in range(len(result)-1)))

if __name__ == "__main__":
    unittest.main()