def two_sum(nums, target):
    num_index_map = {}
    for index, num in enumerate(nums):
        _complement = target - num
        if _complement in num_index_map:
            return (num_index_map[_complement], index)
        num_index_map[num] = index
    return ()

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 22
    result = two_sum(nums, target)
    print(result)  # Output: [0, 1]