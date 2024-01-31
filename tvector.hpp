template <typename T>
TVector<T>::TVector() : capacity{SPARECAPACITY}, size{0}
{
    array = new T[capacity];
}

template <typename T>
TVector<T>::TVector(T val, int num) : capacity{val}, size{num}
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
TVector<T>::TVector(const TVector<T> &v) : capacity{v.capacity()}, size{v.size()}
{
    array = new T[capacity];
    for (int i = 0; i < size; ++i)
    {
        array[i] = v.array[i];
    }
}

template <typename T>
TVector<T>::TVector(TVector<T> &&v) : capacity{v.capacity()}, size{v.size()}
{
    v.array = nullptr;
    v.capacity = 0;
    v.size = 0;
}

template <typename T>
TVector<T> &TVector<T>::operator=(TVector<T> &&v)
{
    swap(capacity, v.capacity);
    swap(size, v.size);
    swap(v.array, v.array);
    return *this;
}

template <typename T>
bool TVector<T>::IsEmpty() const
{
    if (!size)
    {
        return false;
    }
    else
    {
        return true;
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
void TVector<T>::InsertBack(const T &d)
{
    if (size == capacity)
    {
        this->SetCapacity(capacity + SPARECAPACITY)
    }
    array[size] = d;
    size++;
}

template <typename T>
void TVector<T>::RemoveBack()
{

    array[size] = 0;
    --size;
}

template <typename T>
T &TVector<T>::GetFirst() const
{

    return &array[0];
}

template <typename T>
T &TVector<T>::GetLast() const
{

    return &array[size - 1];
}
