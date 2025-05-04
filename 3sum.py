def three_sum(nums, target=0):
    """
    Find all unique triplets in the array which gives the sum of zero.

    :param nums: List[int] - List of integers
    :return: List[List[int]] - List of triplets
    """
    nums.sort()
    print(nums)
    result = []
    n = len(nums)

    for i in range(n - 2):
        value = nums[i]
        two_sum_target = target - value
        left, right = i + 1, n - 1
        while left < right:
            two_sum = nums[left] + nums[right]
            if two_sum < two_sum_target:
                left +=1
            elif two_sum > two_sum_target:
                right -= 1
            else:
                result.append([value, nums[left], nums[right]])
                left += 1
                right -= 1

    return result


# Example usage
if __name__ == "__main__":
    nums = [-1, 0, 1, 2, -1, -4]
    print(three_sum(nums))