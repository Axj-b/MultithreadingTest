#include <iostream>
#include "src/ThreadPool.h"

int main1() {
    ThreadPool pool(3);

    for (int i = 0; i < 10; ++i) {
        pool.enqueue([i] {
            std::cout << "Processing work: " << i << std::endl;
        });
    }

    return 0;
}




void task1()
{
    while (true)
    {
        std::cout << "Task 1 is running..." << std::endl;
        //std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void task2()
{
    while (true)
    {
        std::cout << "Task 2 is running..." << std::endl;
        ///std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void task3()
{
    while (true)
    {
        std::cout << "Task 3 is running..." << std::endl;
        //std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main()
{
    ThreadPool pool(3);

    pool.enqueue(task1);
    pool.enqueue(task2);
    pool.enqueue(task3);

    // Keep the main thread running to allow background tasks to execute
    std::this_thread::sleep_for(std::chrono::hours(1));

    return 0;
}