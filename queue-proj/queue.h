#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

template <typename Template>

class queue
{
private:
    Template **contents;
    int capacity;
    int front;
    int back;

    void resize()
    {
        int oldCapacity = capacity;
        capacity *= 2;
        Template **newcontents = new Template *[capacity];

        for (int i = 0; i < back - front; ++i)
        {
            newcontents[i] = contents[(front + i) % oldCapacity];
        }

        delete[] contents;
        contents = newcontents;
        front = 0;
        back = oldCapacity;
    }

public:
    bool IsEmpty() const
    {
        return front == back;
    }
    queue() : capacity(10), front(0), back(0)
    {
        contents = new Template *[capacity];
    }

    queue(const queue &other) : capacity(other.capacity), front(other.front), back(other.back)
    {
        contents = new Template *[capacity];
        for (int i = 0; i < back - front; ++i)
        {
            contents[i] = new Template(*(other.contents[(front + i) % capacity]));
        }
    }

    queue &operator=(const queue &other)
    {
        if (this != &other)
        {
            for (int i = 0; i < back - front; ++i)
            {
                delete contents[(front + i) % capacity];
            }
            delete[] contents;

            capacity = other.capacity;
            front = other.front;
            back = other.back;
            contents = new Template *[capacity];
            for (int i = 0; i < back - front; ++i)
            {
                contents[i] = new Template(*(other.contents[(front + i) % capacity]));
            }
        }
        return *this;
    }

    ~queue()
    {
        for (int i = 0; i < back - front; ++i)
        {
            delete contents[(front + i) % capacity];
        }
        delete[] contents;
    }

    void Enqueue(Template element)
    {
        if ((back + 1) % capacity == front)
        {
            resize();
        }
        contents[back] = new Template(element);
        back = (back + 1) % capacity;
    }

    Template Dequeue()

    {

        if (IsEmpty() == true)
        {
            cout << "Queue is empty" << endl;
        }
        Template *temp = contents[front];
        front = (front + 1) % capacity;
        Template value = *temp;
        delete temp;
        return value;
    }
};

#endif // QUEUE_H
