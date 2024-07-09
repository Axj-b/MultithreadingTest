#include "src/ThreadPool.h"
#include <iostream>


void task1(std::condition_variable& cv, std::mutex& mtx, bool& ready)
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&ready] { return ready; });
        std::cout << "Task 1 is running..." << std::endl;
        ready = false; // Reset ready for the next wait
    }
}

void task2(std::condition_variable& cv, std::mutex& mtx, bool& ready)
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&ready] { return ready; });
        std::cout << "Task 2 is running..." << std::endl;
        ready = false; // Reset ready for the next wait
    }
}

void task3(std::condition_variable& cv, std::mutex& mtx, bool& ready)
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&ready] { return ready; });
        std::cout << "Task 3 is running..." << std::endl;
        ready = false; // Reset ready for the next wait
    }
}

int main()
{
    ThreadPool pool(3);

    std::condition_variable cv1, cv2, cv3;
    std::mutex mtx1, mtx2, mtx3;
    bool ready1 = false, ready2 = false, ready3 = false;

    pool.enqueue([&cv1, &mtx1, &ready1] { task1(cv1, mtx1, ready1); });
    pool.enqueue([&cv2, &mtx2, &ready2] { task2(cv2, mtx2, ready2); });
    pool.enqueue([&cv3, &mtx3, &ready3] { task3(cv3, mtx3, ready3); });

    // Simulate events to notify the tasks periodically
    for (;;)
    {
        {
            std::lock_guard<std::mutex> lock(mtx1);
            ready1 = true;
        }
        cv1.notify_one();

        {
            std::lock_guard<std::mutex> lock(mtx2);
            ready2 = true;
        }
        cv2.notify_one();

        {
            std::lock_guard<std::mutex> lock(mtx3);
            ready3 = true;
        }
        cv3.notify_one();

        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Just to simulate periodic events
    }

    return 0;
}