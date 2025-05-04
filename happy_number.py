"""
A happy number is a number defined by the following process: starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle that does not include 1. Those numbers for which this process ends in 1 are happy.
Write an algorithm to determine if a number n is happy.
"""
def is_happy(n: int) -> bool:
    """
    Determine if a number is happy.

    :param n: int - The number to check
    :return: bool - True if the number is happy, False otherwise
    """
    slow = n
    fast = n
    while True:
        slow = get_next(slow)
        fast = get_next(get_next(fast))
        if slow == 1 or fast == 1:
            return True
        if slow == fast:
            return False

def get_next(n: int) -> int:
    """
    Calculate the next number in the happy number sequence.

    :param n: int - The current number
    :return: int - The next number in the sequence
    """
    total_sum = 0
    while n > 0:
        digit = n % 10
        total_sum += digit ** 2
        n /= 10
    return total_sum

if __name__ == "__main__":
    # n = 19
    n = 2
    print(f"Is {n} a happy number? {is_happy(n)}")
