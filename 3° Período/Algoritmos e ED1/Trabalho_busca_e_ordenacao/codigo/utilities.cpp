#include <chrono>
#include <iostream>

using namespace std;

// https://www.youtube.com/watch?v=YG4jexlSAjc <- benchmark baseado nesse tutorial
class Timer
{
public:
    Timer()
    {
        start = chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        Stop();
    }

    void Stop()
    {
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = end - this->start;

        cout << "Duração: " << duration.count() << " segundos \n";
    }

private:
    chrono::time_point<chrono::high_resolution_clock> start;
};