#include <future>
#include <iostream>

int f(int x) {
	return x + 1;
}

int main()
{
    // This will be the write-end
    std::promise<int> promise;

    // This will be the read-end
    auto future = promise.get_future();

    // Launch f asynchronously
    std::thread([&promise] (int x) {
        promise.set_value(f(x));
        // try {
        //     throw std::runtime_error("Foobar!");
        // } catch(...) {
        //     promise.set_exception(std::current_exception());
        // }
    },
    5
    ).detach();

    // t.join();
    
    // Get the value
    try
    {
        /* code */
        std::cout << future.get() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    auto result = std::move(std::async(std::launch::async, f, 6));
    std::cout << result.get() << std::endl;



    std::packaged_task<int(int)> task(f);
    std::future<int> result_future = task.get_future();

    std::thread(std::move(task), 7).detach();

    std::cout << result_future.get() << std::endl;

    return 0;
}