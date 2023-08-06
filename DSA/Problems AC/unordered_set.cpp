#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

template<typename Key>
class MyUnorderedSet {
private:
    std::vector<std::list<Key>> buckets;
    std::size_t numBuckets;

public:
    MyUnorderedSet(std::size_t numBuckets = 10) : numBuckets(numBuckets) {
        buckets.resize(numBuckets);
    }

    void insert(const Key& key) {
        std::size_t bucketIndex = hashFunction(key) % numBuckets;
        std::list<Key>& bucket = buckets[bucketIndex];

        if (std::find(bucket.begin(), bucket.end(), key) == bucket.end()) {
            bucket.push_back(key);
        }
    }

    void erase(const Key& key) {
        std::size_t bucketIndex = hashFunction(key) % numBuckets;
        std::list<Key>& bucket = buckets[bucketIndex];

        bucket.remove(key);
    }

    bool contains(const Key& key) const {
        std::size_t bucketIndex = hashFunction(key) % numBuckets;
        const std::list<Key>& bucket = buckets[bucketIndex];

        return (std::find(bucket.begin(), bucket.end(), key) != bucket.end());
    }

    std::size_t size() const {
        std::size_t count = 0;

        for (const auto& bucket : buckets) {
            count += bucket.size();
        }

        return count;
    }

    bool empty() const {
        return size() == 0;
    }

private:
    std::size_t hashFunction(const Key& key) const {
        // Simplified hash function using the modulo operator
        return std::hash<Key>()(key);
    }
};

int main() {
    MyUnorderedSet<int> mySet;
    
    mySet.insert(5);
    mySet.insert(2);
    mySet.insert(8);
    mySet.insert(3);
    mySet.insert(1);

    std::cout << "Size of the set: " << mySet.size() << std::endl;

    std::cout << "Is set empty? " << (mySet.empty() ? "Yes" : "No") << std::endl;

    mySet.erase(8);

    std::cout << "Is 8 present? " << (mySet.contains(8) ? "Yes" : "No") << std::endl;

    std::cout << "Size of the set after erasing: " << mySet.size() << std::endl;

    return 0;
}
/*
In this simplified implementation, we use a vector of linked lists to represent the hash table. Each bucket in the hash table is a linked list that stores elements with the same hash value. The hash function is simplified and uses the std::hash function to compute the hash value.

Please note that this implementation is for illustrative purposes only and lacks many features and optimizations of the standard library's unordered_set. The standard library's implementation is highly optimized and offers additional functionality, such as custom hash functions, iterators, load factor control, and more.
No, the standard library's unordered_set implementation does not necessarily use a vector with linked lists to store elements. The underlying data structure used by unordered_set is typically a hash table.

A hash table is a data structure that allows efficient insertion, deletion, and retrieval of elements based on their keys. It uses a hash function to map keys to specific positions in an array-like structure called buckets. Each bucket can contain zero or more elements. When a collision occurs (i.e., two keys map to the same bucket), separate chaining or open addressing techniques are used to handle it.

The exact implementation details of unordered_set can vary across different compilers and standard library implementations. The standard library may employ various optimizations, such as bucket arrays that store elements directly or use separate chaining with linked lists, dynamic arrays, or other data structures.

The choice of data structure depends on factors like performance, memory usage, and implementation complexity. The goal is to provide an efficient and flexible container for storing unique elements with constant-time average complexity for insertion, deletion, and lookup operations.

Therefore, while the simplified example I provided used a vector with linked lists to illustrate the basic principles, the actual implementation of unordered_set in the standard library may differ and could be more complex and optimized.*/

//for using the external library
#include <iostream>
#include <unordered_set>

int main() {
    // Create an unordered_set of integers
    std::unordered_set<int> mySet;

    // Insert elements into the set
    mySet.insert(5);
    mySet.insert(2);
    mySet.insert(8);
    mySet.insert(3);
    mySet.insert(1);

    // Iterate over the elements in the set
    std::cout << "Set elements: ";
    for (const auto& element : mySet) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Check the size of the set
    std::cout << "Size of the set: " << mySet.size() << std::endl;

    // Check if an element exists in the set
    int key = 3;
    if (mySet.count(key) > 0) {
        std::cout << "Element " << key << " exists in the set" << std::endl;
    } else {
        std::cout << "Element " << key << " does not exist in the set" << std::endl;
    }

    // Erase an element from the set
    mySet.erase(8);

    // Check the size of the set after erasing an element
    std::cout << "Size of the set after erasing: " << mySet.size() << std::endl;

    // Check if the set is empty
    if (mySet.empty()) {
        std::cout << "The set is empty" << std::endl;
    } else {
        std::cout << "The set is not empty" << std::endl;
    }

    // Clear the set
    mySet.clear();

    // Check the size of the set after clearing
    std::cout << "Size of the set after clearing: " << mySet.size() << std::endl;

    return 0;
}
