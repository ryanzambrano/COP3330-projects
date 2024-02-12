#include <iostream>
#include "queue.h"
using namespace std;

int main()
{
    queue<int> intQueue;
    for (int i = 1; i <= 5; ++i)
    {
        intQueue.Enqueue(i);
    }

    for (int i = 0; i < 5; ++i)
    {
        cout << intQueue.Dequeue() << " ";
    }
    cout << endl;

    queue<string> stringQueue;
    for (int i = 1; i <= 5; ++i)
    {
        stringQueue.Enqueue("Item " + to_string(i));
    }

    for (int i = 0; i < 5; ++i)
    {
        cout << stringQueue.Dequeue() << " ";
    }
    cout << endl;

    return 0;
}
