import numpy as np

def task1():
    # Create a 2D array
    arr = np.array([[1, 2, 3], [4, 5, 6]])
    print("Array:\n", arr)
    print("Shape:", arr.shape)
    print("Mean:", np.mean(arr))
    print("Sum:", np.sum(arr))

    min_index = np.argmin(arr, axis=0)
    max_index = np.argmax(arr, axis=0)
    print(min_index, max_index)

    min_index = np.argmin(arr, axis=1)
    max_index = np.argmax(arr, axis=1)
    print(min_index, max_index)


def task2():
    # Example usage of numpy to create an array and perform basic operations
    np.random.seed(42)
    data = np.random.rand(100, 2)  # Generate 100 random points in 2D
    mean = np.mean(data, axis=0)
    std_dev = np.std(data, axis=0)

    print("Data Mean:", mean)
    print("Data Standard Deviation:", std_dev)
      

if __name__ == "__main__":
    task1()
    # task2()

