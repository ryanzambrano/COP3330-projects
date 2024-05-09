#include "hashtable.h"

template <typename K, typename V>
HashTable<K, V>::HashTable(size_t size) : theLists(std::max(prime_below(size), static_cast<unsigned long>(default_capacity))), currentSize(0) {}

template <typename K, typename V>
HashTable<K, V>::~HashTable()
{
    clear();
}

template <typename K, typename V>
bool HashTable<K, V>::contains(const K &k) const
{
    auto &whichList = theLists[myhash(k)];
    return std::find_if(whichList.begin(), whichList.end(), [&](const std::pair<K, V> &item)
                        { return item.first == k; }) != whichList.end();
}

template <typename K, typename V>
bool HashTable<K, V>::match(const std::pair<K, V> &kv) const
{
    auto &whichList = theLists[myhash(kv.first)];
    return std::find(whichList.begin(), whichList.end(), kv) != whichList.end();
}

template <typename K, typename V>
bool HashTable<K, V>::insert(const std::pair<K, V> &kv)
{
    auto &whichList = theLists[myhash(kv.first)];
    if (std::find(whichList.begin(), whichList.end(), kv) != whichList.end())
        return false;
    whichList.push_back(kv);

    if (++currentSize > theLists.size())
        rehash();

    return true;
}

template <typename K, typename V>
bool HashTable<K, V>::insert(std::pair<K, V> &&kv)
{
    auto &whichList = theLists[myhash(kv.first)];
    if (std::find(whichList.begin(), whichList.end(), kv) != whichList.end())
        return false;
    whichList.push_back(std::move(kv));

    if (++currentSize > theLists.size())
        rehash();

    return true;
}

template <typename K, typename V>
bool HashTable<K, V>::remove(const K &k)
{
    auto &whichList = theLists[myhash(k)];
    auto itr = std::find_if(whichList.begin(), whichList.end(), [&](const std::pair<K, V> &item)
                            { return item.first == k; });
    if (itr == whichList.end())
        return false;

    whichList.erase(itr);
    --currentSize;
    return true;
}

template <typename K, typename V>
void HashTable<K, V>::clear()
{
    for (auto &thisList : theLists)
        thisList.clear();
    currentSize = 0;
}

template <typename K, typename V>
void HashTable<K, V>::rehash()
{
    std::vector<std::list<std::pair<K, V>>> oldLists = theLists;

    // Create new double-sized, empty table
    theLists.resize(prime_below(2 * theLists.size()));
    for (auto &thisList : theLists)
        thisList.clear();

    // Copy table over
    currentSize = 0;
    for (auto &list : oldLists)
        for (auto &item : list)
            insert(std::move(item));
}

template <typename K, typename V>
size_t HashTable<K, V>::myhash(const K &k) const
{
    static std::hash<K> hf;
    return hf(k) % theLists.size();
}

template <typename K, typename V>
void HashTable<K, V>::dump() const
{
    for (size_t i = 0; i < theLists.size(); ++i)
    {
        std::cout << "Bucket " << i << ":";
        for (auto &thisPair : theLists[i])
        {
            std::cout << " (" << thisPair.first << ", " << thisPair.second << ")";
        }
        std::cout << std::endl;
    }
}

template <typename K, typename V>
unsigned long HashTable<K, V>::prime_below(unsigned long n)
{
    if (n > max_prime)
    {
        std::cerr << "** input too large for prime_below()\n";
        return 0;
    }
    if (n == max_prime)
    {
        return max_prime;
    }
    if (n <= 1)
    {
        std::cerr << "** input too small \n";
        return 0;
    }

    // now: 2 <= n < max_prime
    std::vector<unsigned long> v(n + 1);
    setPrimes(v);
    while (n > 2)
    {
        if (v[n] == 1)
            return n;
        --n;
    }

    return 2;
}

template <typename K, typename V>
void HashTable<K, V>::setPrimes(vector<unsigned long> &vprimes)
{
    int i = 0;
    int j = 0;

    vprimes[0] = 0;
    vprimes[1] = 0;
    int n = vprimes.capacity();

    for (i = 2; i < n; ++i)
        vprimes[i] = 1;

    for (i = 2; i * i < n; ++i)
    {
        if (vprimes[i] == 1)
            for (j = i + i; j < n; j += i)
                vprimes[j] = 0;
    }
}

template <typename K, typename V>
bool HashTable<K, V>::load(const char *filename)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "Error: File could not be opened." << endl;
        return false;
    }

    K key;
    V value;
    while (file >> key >> value)
    {
        insert(make_pair(key, value));
    }

    file.close();
    return true;
}

template <typename K, typename V>
size_t HashTable<K, V>::size() const
{
    return currentSize; // Returns the number of elements in the hash table.
}

template <typename K, typename V>
bool HashTable<K, V>::write_to_file(const char *filename) const
{
    ofstream file(filename);
    if (!file)
    {
        cerr << "Error: File could not be opened." << endl;
        return false;
    }

    // Iterate over each bucket
    for (auto &thisList : theLists)
    {
        for (auto &thisPair : thisList)
        {
            file << thisPair.first << " " << thisPair.second << endl;
        }
    }

    file.close();
    return true;
}