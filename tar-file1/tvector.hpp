#ifndef TVECTOR_HPP
#define TVECTOR_HPP

#include <iostream>
#include <string>
#include <utility>
using namespace std;
template <typename T>
TVector<T>::TVector() : capacity{SPARECAPACITY}, size{0}
{
    array = new T[capacity];
}

template <typename T>
TVector<T>::TVector(T val, int num) : capacity(num + SPARECAPACITY), size(num)
{
    array = new T[SPARECAPACITY + num];
    for (int i = 0; i < num; ++i)
    {
        array[i] = val;
    }
}

template <typename T>
TVector<T>::~TVector()
{
    delete[] array;
}

template <typename T>
TVector<T>::TVector(const TVector<T> &v) : capacity{v.capacity}, size{v.size()}
{
    array = new T[capacity];
    for (int i = 0; i < size; ++i)
    {
        array[i] = v.array[i];
    }
}

template <typename T>
TVector<T>::TVector(TVector<T> &&v) : capacity(v.capacity), size(v.size), array(v.array)
{
    v.array = nullptr;
    v.capacity = 0;
    v.size = 0;
}

// move assignment operator
template <typename T>
TVector<T> &TVector<T>::operator=(TVector<T> &&v)
{
    swap(capacity, v.capacity);
    swap(size, v.size);

    swap(array, v.array);

    return *this;
}

// assignment operator
template <typename T>
TVector<T> &TVector<T>::operator=(const TVector<T> &v)
{
    if (this == &v)
    {
        return *this; // Do nothing and return the current object
    }

    T *tempArray = new T[v.capacity];

    for (unsigned int i = 0; i < v.size; ++i)
    {
        tempArray[i] = v.array[i];
    }

    delete[] this->array;

    this->array = tempArray;
    this->size = v.size;
    this->capacity = v.capacity;

    return *this;
}

template <typename T>
bool TVector<T>::IsEmpty() const
{
    if (!size)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
void TVector<T>::Clear()
{
    delete[] array;
    array = new T[capacity];
    size = 0;
    capacity = 0;
}

template <typename T>
int TVector<T>::GetSize() const
{
    return size;
}

template <typename T>
void TVector<T>::InsertBack(const T &d)
{
    if (size == capacity)
    {
        this->SetCapacity(capacity + SPARECAPACITY);
    }
    array[size] = d;
    size++;
}

template <typename T>
void TVector<T>::RemoveBack()
{
    if (size > 0)
    {
        array[size] = 0;
        --size;
        // No need to explicitly clear or destroy the last element in most cases
    }
}

template <typename T>
T &TVector<T>::GetFirst() const
{

    return &array[0];
}

template <typename T>
T &TVector<T>::GetLast() const
{

    return array[size - 1];
}
template <typename T>
TVectorIterator<T>::TVectorIterator() : index(0), vsize(0), ptr(nullptr)
{
}

template <typename T>
TVectorIterator<T> TVector<T>::Insert(TVectorIterator<T> pos, const T &d)
{

    if (size == capacity)
    {
        // If the vector is at capacity, increase the capacity
        SetCapacity(capacity + SPARECAPACITY);
    }

    for (unsigned int i = size; i > pos.index; --i)
    {
        array[i] = array[i - 1];
    }

    array[pos.index] = d;
    ++size;

    pos.ptr = &array[pos.index];

    return pos; //
}

template <typename T>
TVectorIterator<T> TVector<T>::GetIterator() const
{
    TVectorIterator<T> itr1;
    itr1.vsize = size;
    itr1.index = 0;
    itr1.ptr = &array[0];
    return itr1;
}

template <typename T>
TVectorIterator<T> TVector<T>::Remove(TVectorIterator<T> pos)
{

    // Shift elements left to overwrite the element at pos.index
    TVectorIterator<T> ret_pos;
    for (int i = pos.index; i < size - 1; ++i)
    {
        array[i] = array[i + 1];
    }
    --size;
    ret_pos.vsize = size;
    ret_pos.index = pos.index - 1; // Decrement size to account for the removed element

    return ret_pos;
}

template <typename T>
TVectorIterator<T> TVector<T>::Remove(TVectorIterator<T> pos1, TVectorIterator<T> pos2)
{
    // Ensure pos1 is before pos2 and both are within bounds
    if (pos1.index > pos2.index || pos2.index >= size)
    {
        // You may want to handle this case more gracefully
        throw std::invalid_argument("Invalid iterator positions for Remove operation.");
    }

    // Calculate the number of elements to remove
    unsigned int diff = pos2.index - pos1.index;

    // Shift elements left to overwrite the elements being removed
    for (unsigned int i = pos1.index; i + diff < size; ++i)
    {
        array[i] = array[i + diff];
    }

    // Adjust the size of the vector
    size -= diff;

    // Prepare the return iterator
    TVectorIterator<T> ret_pos;
    ret_pos.vsize = size;
    ret_pos.index = pos1.index; // Point to where the first removed item was
    // Ensure the pointer in ret_pos points to the correct element
    ret_pos.ptr = size > 0 ? &array[ret_pos.index] : nullptr;

    return ret_pos;
}

template <typename T>
TVectorIterator<T> TVector<T>::GetIteratorEnd() const
{
    TVectorIterator<T> iter;
    iter.ptr = size > 0 ? &array[size] : nullptr; // Points one past the last element or nullptr if empty
    iter.index = size;                            // The index one past the last element
    iter.vsize = size;                            // The size of the vector, to maintain consistency with GetIterator()
    return iter;
}

template <typename T>
bool TVectorIterator<T>::HasNext() const
{
    cout << "hasnext index" << index << "vsize" << vsize << endl;

    if (index >= vsize)
    {
        cout << "false";
        return false;
    }
    else
    {
        cout << "false";

        return true;
    }
}

template <typename T>
bool TVectorIterator<T>::HasPrevious() const
{
    if (index < vsize)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
TVectorIterator<T> TVectorIterator<T>::Next()
{
    if (index < vsize - 1)
    {
        index += 1;
        // ptr += 1;
        //  cout << index << endl;
    }
    return *this;
}

template <typename T>
TVectorIterator<T> TVectorIterator<T>::Previous()
{
    // Ensure there is a previous element to move to by checking index is greater than 0
    if (index > 0)
    {
        index -= 1; // Move to the previous element by decrementing index
                    // ptr -= 1;
    }

    return *this; // Return the iterator itself to allow for chaining
}

template <typename T>
T &TVectorIterator<T>::GetData() const
{
    if (ptr)
    {
        return ptr[index];
    }
    // return *this;
}

template <typename T>
void TVector<T>::Print(std::ostream &os, char delim) const
{
    for (unsigned int i = 0; i < size; ++i)
    {
        os << array[i]; // Output the current element
        if (i < size - 1)
        {
            os << delim; // Output the delimiter if it's not the last element
        }
    }
}

template <typename T>
void TVector<T>::SetCapacity(unsigned int c)
{
    T *newArray = new T[c];
    unsigned int newSize;
    if (size > c)
    {
        newSize = c; // If the current size is greater than the new capacity, adjust newSize to c
    }
    else
    {
        newSize = size; // Otherwise, keep the size as is
    }

    for (unsigned int i = 0; i < newSize; ++i)
    {
        newArray[i] = array[i];
    }

    delete[] array;

    // Update the vector's array pointer, size, and capacity
    array = newArray;
    size = newSize;
    capacity = c;
}

template <typename T>
TVector<T> operator+(const TVector<T> &t1, const TVector<T> &t2)
{
    TVector<T> result; // Create a new vector to hold the result

    // Set the capacity to the sum of both vector sizes to avoid multiple reallocations
    result.SetCapacity(t1.GetSize() + t2.GetSize());

    TVectorIterator<T> it1 = t1.GetIterator();

    for (int i = 0; i < t1.GetSize(); ++i)
    {
        // Do something with the current element
        result.InsertBack(it1.GetData());

        // Advance to the next element
        it1.Next();
    }

    TVectorIterator<T> it2 = t2.GetIterator();

    for (int i = 0; i < t2.GetSize(); ++i)
    {
        // Do something with the current element
        result.InsertBack(it2.GetData());

        // Advance to the next element
        it2.Next();
    }

    return result; // Return the concatenated vector
}

#endif // TVECTOR_HPP