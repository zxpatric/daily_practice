def merge_intervals(intervals):
    """
    Merges overlapping intervals.

    Args:
        intervals (List[List[int]]): A list of intervals where each interval is represented as [start, end].

    Returns:
        List[List[int]]: A list of merged intervals.
    """
    # Implementation goes here
    # pass

    intervals.sort()

    result = None
    for inter in intervals:
        if result is None:
            result = inter
        else:
            if result[1] < inter[0]:
                yield result
                result = inter
            elif result[1] < inter[1]:
                result[1] = inter[1]

    yield result

if __name__ == "__main__":
    # Test case
    test_intervals = [[1, 3], [8, 10], [2, 6], [15, 18]]
    # print("Merged Intervals:", merge_intervals(test_intervals))
    for inter in merge_intervals(test_intervals):
        print (inter)