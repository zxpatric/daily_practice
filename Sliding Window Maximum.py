from collections import deque

def max_sliding_window(nums, k):
    """
    Find the maximum value in each sliding window of size k in the array nums.
    
    :param nums: List[int] - The input array
    :param k: int - The size of the sliding window
    :return: List[int] - The list of maximums for each sliding window
    """
    # Implementation goes here
    pass

# Test case
if __name__ == "__main__":
    nums = [1, 3, -1, -3, 5, 3, 6, 7]
    k = 3
    print(max_sliding_window(nums, k))  # Expected output: [3, 3, 5, 5, 6, 7]
