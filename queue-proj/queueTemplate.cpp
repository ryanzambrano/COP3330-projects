#include <iostream>
#include "queue.h"
using namespace std;

template <typename T>
queue<T>::queue() : capacity(10), front(0), back(0)
{
    contents = new T *[capacity];
}

template <typename T>
void queue<T>::resize()
{
    T **newcontents = new T *[capacity * 2];
    int currentSize = back - front;
    for (int i = 0; i < currentSize; ++i)
    {
        newcontents[i] = contents[front + i];
    }
    delete[] contents;
    contents = newcontents;
    front = 0;
    back = currentSize;
    capacity *= 2;
}

template <typename T>
void queue<T>::Enqueue(T element)
{
    if (back == capacity)
    {
        resize();
    }
    contents[back] = new T(element);
    back++;
}

template <typename T>
T queue<T>::Dequeue()
{
    if (IsEmpty())
    {
        throw out_of_range("Queue is empty");
    }
    T result = *contents[front];
    delete contents[front];
    front++;
    return result;
}

template <typename T>
bool queue<T>::IsEmpty() const
{
    return front == back;
}

template <typename T>
queue<T>::queue(const queue &other) : capacity(other.capacity), front(other.front), back(other.back)
{
    contents = new T *[capacity];
    for (int i = front; i < back; ++i)
    {
        contents[i] = new T(*other.contents[i]);
    }
}

template <typename T>
queue<T> &queue<T>::operator=(const queue &other)
{
    if (this != &other)
    {
        for (int i = front; i < back; ++i)
        {
            delete contents[i];
        }
        delete[] contents;

        capacity = other.capacity;
        front = other.front;
        back = other.back;
        contents = new T *[capacity];
        for (int i = front; i < back; ++i)
        {
            contents[i] = new T(*other.contents[i]);
        }
    }
    return *this;
}

template <typename T>
queue<T>::~queue()
{
    for (int i = front; i < back; ++i)
    {
        delete contents[i];
    }
    delete[] contents;
}
