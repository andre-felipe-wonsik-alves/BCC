#include <chrono>
#include <iostream>

using namespace std;

class Utilities
{
public:
    Utilities() {}

    void count_duration() const
    {
        Timer timer;
    }
};

class Timer
{
public:
    Timer()
    {
        start_time = std::chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        stop();
    }

    void stop()
    {
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end_time - start_time;
        std::cout << "Duração: " << duration.count() << " segundos\n";
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
};