#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

template <size_t SIZE>
class LockFreeQueue
{
private:
    int buffer[SIZE];

    atomic<size_t> head{0}; // Producer position
    atomic<size_t> tail{0}; // Consumer position

public:

    bool push(int value)
    {
        size_t currentHead = head.load(memory_order_relaxed);

        size_t nextHead = (currentHead + 1) % SIZE;

        // Queue full?
        if (nextHead == tail.load(memory_order_acquire))
        {
            return false;
        }

        // Put data into buffer
        buffer[currentHead] = value;

        // Publish the data
        head.store(nextHead, memory_order_release);

        return true;
    }

    bool pop(int& value)
    {
        size_t currentTail = tail.load(memory_order_relaxed);

        // Queue empty?
        if (currentTail == head.load(memory_order_acquire))
        {
            return false;
        }

        // Read data
        value = buffer[currentTail];

        // Move consumer position
        tail.store((currentTail + 1) % SIZE,
                   memory_order_release);

        return true;
    }
};


LockFreeQueue<8> q;


void producer()
{
    for (int i = 1; i <= 5; i++)
    {
        // Keep trying until space is available
        while (!q.push(i))
        {
        }

        cout << "Produced : " << i << endl;
    }
}


void consumer()
{
    for (int i = 1; i <= 5; i++)
    {
        int value;

        // Keep trying until data is available
        while (!q.pop(value))
        {
        }

        cout << "Consumed : " << value << endl;
    }
}


int main()
{
    thread t1(producer);
    thread t2(consumer);

    t1.join();
    t2.join();

    return 0;
}
