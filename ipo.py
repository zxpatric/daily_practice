from heapq import heappush, heappop


def maximum_capital(c, k, capitals, profits):

    capitals_min_heap = []

    # Insert all capitals values to a min-heap
    for x in range(0, len(capitals)):
        heappush(capitals_min_heap, (capitals[x], profits[x]))


    captials_max_heap = []

    capital_res = []

    while k > 0:
        capital_res.append(c)

        while len(capitals_min_heap) > 0 and capitals_min_heap[0][0] <= c:
            heappush(captials_max_heap, -capitals_min_heap[0][1])
            heappop(capitals_min_heap)

        c += -captials_max_heap[0]
        heappop(captials_max_heap)
        k -= 1

    capital_res.append(c)

    return capital_res, c


def print_capitals_min_heap(capitals):
    arr = []
    for i in range(len(capitals)):
        arr.append(capitals[i])
        print("\t", arr)


def main():
    input = (
            (1, 2, [1, 2, 2, 3], [2, 4, 6, 8]),
            (2, 3, [1, 3, 4, 5, 6], [1, 2, 3, 4, 5]),
            (1, 3, [1, 2, 3, 4], [1, 3, 5, 7]),
            (7, 2, [6, 7, 8, 10], [4, 8, 12, 14]),
            (2, 4, [2, 3, 5, 6, 8, 12], [1, 2, 5, 6, 8, 9])
            )
    num = 1
    for i in input:
        print(f"{num}.\tGiven Capitals: {i[2]}")
        print("\tAdding capital values...")
        capital_res, final = maximum_capital(i[0], i[1], i[2], i[3])
        print_capitals_min_heap(capital_res)
        print("Start captital", i[0], " Final capital: ", final)
        print("-" * 100, "\n")
        num += 1


if __name__ == "__main__":
    main()